cmake_minimum_required(VERSION 3.14.0)

project(union-find-algs LANGUAGES CXX)

add_library(union-find-algs STATIC include/union-find.h  src/union-find.cpp
                                   include/quick-find.h  src/quick-find.cpp
                                   include/quick-union.h src/quick-union.cpp
                                   include/weighted-quick-union.h src/weighted-quick-union.cpp)

target_sources(union-find-algs PRIVATE src/union-find.cpp src/quick-find.cpp src/quick-union.cpp)
target_include_directories(union-find-algs PRIVATE "${CMAKE_SOURCE_DIR}")

set(OUTPUT_INCLUDES_DIR "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}")
set(PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/union-find.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/quick-find.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/quick-union.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/weighted-quick-union.h)

set(LIB_PATH $<TARGET_FILE:union-find-algs>)
set(LIB_NAME $<TARGET_FILE_NAME:union-find-algs>)

add_custom_command(TARGET union-find-algs
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_INCLUDES_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${PUBLIC_HEADER} ${OUTPUT_INCLUDES_DIR}
)
add_custom_command(TARGET union-find-algs
    POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy ${LIB_PATH} ${CMAKE_SOURCE_DIR}/libs/${LIB_NAME}
)

add_subdirectory(test)

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

add_custom_target(make-output-includes-dir ALL COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_INCLUDES_DIR})
add_custom_target(copy-includes ALL COMMAND ${CMAKE_COMMAND} -E copy ${PUBLIC_HEADER} ${OUTPUT_INCLUDES_DIR})
add_custom_target(copy-lib ALL COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:union-find-algs> ${CMAKE_SOURCE_DIR}/libs)

add_subdirectory(test)

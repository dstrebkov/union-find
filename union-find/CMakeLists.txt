cmake_minimum_required(VERSION 3.14.0)

project(union-find LANGUAGES CXX)

add_library(union-find STATIC src/union-find.cpp include/union-find.h src/quick-find.cpp include/quick-find.h)

target_sources(union-find PRIVATE src/union-find.cpp src/quick-find.cpp)
target_include_directories(union-find PRIVATE "${CMAKE_SOURCE_DIR}")

set(PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/union-find.h ${CMAKE_CURRENT_SOURCE_DIR}/include/quick-find.h)
set(OUTPUT_INCLUDES_DIR "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}")

add_custom_target(make-output-includes-dir ALL COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_INCLUDES_DIR})
add_custom_target(copy-includes ALL COMMAND ${CMAKE_COMMAND} -E copy ${PUBLIC_HEADER} ${OUTPUT_INCLUDES_DIR})
add_custom_target(copy-lib ALL COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:union-find> ${CMAKE_SOURCE_DIR}/libs)

add_subdirectory(test)

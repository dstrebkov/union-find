cmake_minimum_required(VERSION 3.18)

project(app-union-find LANGUAGES CXX)

add_executable(app-union-find)

file(ARCHIVE_EXTRACT INPUT "${union-find-algs-tests_SOURCE_DIR}/test-data/test-data.tar.gz" DESTINATION "${union-find-algs-tests_SOURCE_DIR}/test-data")

target_sources(app-union-find PRIVATE src/main.cpp)
target_include_directories(app-union-find PRIVATE "${CMAKE_SOURCE_DIR}")
target_link_libraries(app-union-find PRIVATE union-find-algs)
target_compile_options(app-union-find PRIVATE -g -O0 -fno-elide-constructors)

cmake_minimum_required(VERSION 3.14.0)

project("union-find" VERSION 0.1 LANGUAGES CXX)

# Enable CTest at the current directory and below (before add_subdirectory())
enable_testing()

add_subdirectory(union-find-algs)
add_subdirectory(app-union-find)

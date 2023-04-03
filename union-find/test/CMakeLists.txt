cmake_minimum_required(VERSION 3.18)

project(union-find-tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.13.0
    GIT_SHALLOW    TRUE)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(ARCHIVE_EXTRACT INPUT "${CMAKE_CURRENT_LIST_DIR}/test-data/input.tar.gz" DESTINATION "${CMAKE_CURRENT_LIST_DIR}/test-data")
file(ARCHIVE_EXTRACT INPUT "${CMAKE_CURRENT_LIST_DIR}/test-data/gold.tar.gz" DESTINATION "${CMAKE_CURRENT_LIST_DIR}/test-data")

add_executable(union-find-tests src/union-find-test.cpp include/regression-inputs.h include/regression-golds.h)
target_include_directories(union-find-tests PUBLIC "${CMAKE_SOURCE_DIR}")
target_link_libraries(union-find-tests GTest::gtest union-find)

target_compile_options(union-find-tests PRIVATE -g -O0 -fno-elide-constructors)

include(GoogleTest)
gtest_discover_tests(union-find-tests)

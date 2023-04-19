cmake_minimum_required(VERSION 3.18)

project(union-find-algs-tests LANGUAGES CXX)

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

file(ARCHIVE_EXTRACT INPUT "${CMAKE_CURRENT_LIST_DIR}/test-data/test-data.tar.gz" DESTINATION "${CMAKE_CURRENT_LIST_DIR}/test-data")

add_executable(union-find-algs-tests include/union-find-tester.h src/union-find-tester.cpp
                                     include/regression-inputs.h include/regression-golds.h
                                     src/union-find-test.cpp src/union-find-regression.cpp
)

target_include_directories(union-find-algs-tests PUBLIC "${CMAKE_SOURCE_DIR}")
target_link_libraries(union-find-algs-tests GTest::gtest union-find-algs)

target_compile_options(union-find-algs-tests PRIVATE -g -O0 -fno-elide-constructors)

include(GoogleTest)

set(REGRESSION_DATA_DIR "${PROJECT_SOURCE_DIR}/test-data")

# Use "EXTRA_ARGS --regressionDataDir=" to provide path to directory with regression file pairs (input + gold)
# Value of the argument should be double-quoted, i.e. "${REGRESSION_DATA_DIR}"
gtest_discover_tests(union-find-algs-tests EXTRA_ARGS --regressionDataDir="${REGRESSION_DATA_DIR}")

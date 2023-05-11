include(${CTEST_SCRIPT_DIRECTORY}/../cmake/CTestConfig.cmake)

site_name(CTEST_SITE)
set(CTEST_BUILD_NAME "${CMAKE_SYSTEM_NAME}${EXTRA_BUILD_NAME}")
set(CTEST_SOURCE_DIRECTORY "${CTEST_SCRIPT_DIRECTORY}/..")
set(CTEST_BINARY_DIRECTORY "${CTEST_SCRIPT_DIRECTORY}/../build-test")

set(CTEST_CMAKE_GENERATOR "Unix Makefiles")
set(CTEST_CONFIGURATION_TYPE Debug)

set(CTEST_COVERAGE_COMMAND gcov)
set(CTEST_COVERAGE_EXTRA_FLAGS "--demangled-names")
set(CTEST_CUSTOM_COVERAGE_EXCLUDE "_deps;/test/")

ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})

ctest_start(Experimental)
ctest_configure(OPTIONS "-DCMAKE_CXX_FLAGS_INIT=--coverage")
#ctest_submit(PARTS Start Configure)
ctest_build()
#ctest_submit(PARTS Build)
ctest_test()
#ctest_submit(PARTS Test)
ctest_coverage()
#ctest_submit(PARTS Coverage Done)

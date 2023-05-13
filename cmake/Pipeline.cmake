site_name(CTEST_SITE)
set(CTEST_BUILD_NAME "${CMAKE_SYSTEM_NAME}${EXTRA_BUILD_NAME}")
set(CTEST_SOURCE_DIRECTORY "${CTEST_SCRIPT_DIRECTORY}/..")
set(CTEST_BINARY_DIRECTORY "${CTEST_SCRIPT_DIRECTORY}/../build-test")

set(CTEST_CMAKE_GENERATOR "Unix Makefiles")
set(CTEST_CONFIGURATION_TYPE Debug)

set(CTEST_COVERAGE_COMMAND gcov)
set(CTEST_COVERAGE_EXTRA_FLAGS "--demangled-names")
set(CTEST_CUSTOM_COVERAGE_EXCLUDE "_deps;/test/;[^/]app[-_][-_a-z0-9]+/")

ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})

ctest_start(Experimental)
ctest_configure(OPTIONS "-DCMAKE_CXX_FLAGS_INIT=--coverage")
ctest_build()
ctest_test()
ctest_coverage()

find_package(Python3 COMPONENTS Interpreter REQUIRED)

set(VENV_PATH "${CTEST_BINARY_DIRECTORY}/py_env")
set(GCOVR_EXCLUDE "(.*/_deps/.*|.*/test/.*|.*/CMakeFiles/.*|^app[-_][-_a-z0-9]+/.*)")
set(GCOVR_XML_FILE "${CTEST_BINARY_DIRECTORY}/coverage/coverage.xml")
set(GCOVR_HTML_FILE "${CTEST_BINARY_DIRECTORY}/coverage/coverage.html")

execute_process(COMMAND "${Python3_EXECUTABLE}" -m venv "${VENV_PATH}")
execute_process(COMMAND ${VENV_PATH}/bin/python -m pip install --upgrade pip --no-warn-script-location)
execute_process(COMMAND ${VENV_PATH}/bin/pip install gcovr==6.0)
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CTEST_BINARY_DIRECTORY}/coverage)
execute_process(COMMAND ${VENV_PATH}/bin/gcovr --root ${CTEST_SOURCE_DIRECTORY} --exclude ${GCOVR_EXCLUDE} --xml=${GCOVR_XML_FILE} --html-details=${GCOVR_HTML_FILE})

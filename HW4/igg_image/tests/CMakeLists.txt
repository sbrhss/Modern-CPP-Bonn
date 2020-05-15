add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
set(TEST_BINARY ${PROJECT_NAME}_test)
# add_executable(
#  ${TEST_BINARY}
#  # test_init.cpp
#  # test_resize.cpp
#  # test_dummy_strategy.cpp
#  # test_histogram.cpp
#  # test_from_ppm.cpp
#  # test_from_png.cpp
# )
# target_link_libraries(${TEST_BINARY}
#   image
#   gtest gtest_main
# )
# add_test(
#   NAME ${TEST_BINARY}
#   COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY})

add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
set(TEST_BINARY ${PROJECT_NAME}_test)



add_executable(${TEST_BINARY}
               digit_counting_test.cpp)
# Link the executable to needed libraries.
target_link_libraries(${TEST_BINARY}
  digits
  gtest gtest_main  # GTest libraries
)
# Add gtest to be able to run ctest
add_test(
  NAME ${TEST_BINARY}
  COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY})

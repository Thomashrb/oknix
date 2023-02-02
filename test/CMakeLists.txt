set(TEST_LIBS Catch2 oknix_lib)
set(UNIT_TESTS
    json_test
)

foreach(_test ${UNIT_TESTS})
  add_executable(${_test} ./${_test}.cpp)
  # Each test is its own executable : link dependencies
  target_link_libraries(${_test} ${TEST_LIBS} Catch2::Catch2WithMain)
  # enable running of test executables with `ctest`
  add_test(${_test} ${_test})
endforeach()

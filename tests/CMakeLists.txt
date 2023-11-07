# add_executable(tests tests.cpp adder_t.cpp)
# target_link_libraries(tests PUBLIC adder)
# target_include_directories(tests PUBLIC ../ext)

add_executable(tests tests.cpp slinked_list_t.cpp)
target_include_directories(tests PUBLIC ../include/data_structures)
target_include_directories(tests PUBLIC ../ext)

# allow user to run tests with `make test` or `ctest`
include(../cmake/Catch.cmake)
catch_discover_tests(tests)

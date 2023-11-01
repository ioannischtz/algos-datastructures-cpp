# add_executable(adder_app adder_app.cpp)
# target_link_libraries(adder_app PRIVATE adder)
add_executable(data_structures_app data_structures_app.cpp)
target_include_directories(data_structures_app PUBLIC
  ../include/data_structures)

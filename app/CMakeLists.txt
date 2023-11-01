# add_executable(adder_app adder_app.cpp)
# target_link_libraries(adder_app PRIVATE adder)
add_executable(array_buffer_app array_buffer_app.cpp)
target_include_directories(array_buffer_app PUBLIC
  ../include/data_structures)

add_executable(slinked_list_app slinked_list_app.cpp)
target_include_directories(slinked_list_app PUBLIC
  ../include/data_structures)



#include "SLinkedList.hpp"
#include <cassert>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <optional>
#include <string>

int main() {
  data_structures::SLinkedList<float> slist;
  auto inserted_node = slist.insertLast(5);
  inserted_node = slist.insertLast(7);
  inserted_node = slist.insertLast(9);

  auto data = slist.getDataAt(2).value_or(-1);
  std::cout << data << std::endl;
  assert(data == 9);

  auto removed_data = slist.removeAt(1).value_or(-1.0f);
  std::cout << removed_data << std::endl;
  assert(removed_data == 7);
  assert(slist.getLength() == 2);

  auto last_node_ptr = slist.insertLast(11);
  removed_data = slist.removeAt(1).value_or(-1.0f);
  assert(removed_data == 9);
  assert(!slist.remove(9).has_value());
  removed_data = slist.removeAt(0).value_or(-1.0f);
  assert(removed_data == 5);
  removed_data = slist.removeAt(0).value_or(-1.0f);
  assert(removed_data == 11);
  assert(slist.getLength() == 0);

  auto first_node_ptr = slist.insertFirst(5);
  first_node_ptr = slist.insertFirst(7);
  first_node_ptr = slist.insertFirst(9);

  data = slist.getDataAt(2).value_or(-1.0f);
  assert(data == 5);
  assert(slist.getDataAt(0).value_or(-1.0f) == 9);
  assert(slist.remove(9).value_or(-1.0f) == 9);
  assert(slist.getLength() == 2);
  assert(slist.getDataAt(0).value_or(-1.0f) == 7);

  return 0;
}

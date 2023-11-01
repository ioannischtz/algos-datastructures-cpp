
#include "SLinkedList.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <optional>
#include <string>

int main() {
  data_structures::SLinkedList<float> floatSList;
  auto node1 = floatSList.insertFirst(0.1f);
  auto node2 = floatSList.insertFirst(0.2f);
  auto node4 = floatSList.insertAfter(node2, 0.4f);

  std::cout << "node4 = " << (node4.has_value() ? node4.value() : nullptr)
            << std::endl;

  auto first_node = floatSList.first();
  if (first_node.has_value()) {
    std::cout << "first = " << first_node.value()->getElement() << std::endl;
  }
  auto node_with_val = floatSList.find(0.1f);
  if (node_with_val.has_value()) {
    std::cout << node_with_val.value()->getElement() << std::endl;
  }

  floatSList.printAll();

  return 0;
}

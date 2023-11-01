
#include "ArrayBuffer.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <optional>
#include <string>

int main() {
  auto array_buff = data_structures::ArrayBuffer<int, 5>{1, 2, 3, 4, 5};
  array_buff.fill(0);
  array_buff[1] = 5;
  array_buff[4] = 8;
  for (size_t i = 0; i < array_buff.getSize(); i++) {
    std::cout << array_buff[i] << std::endl;
  }

  auto str_buff =
      data_structures::ArrayBuffer<std::string, 2>{"John", "Chatzi"};

  str_buff[1] += "anagnostou";
  for (size_t i = 0; i < str_buff.getSize(); i++) {
    std::cout << str_buff[i] << std::endl;
  }

  str_buff.fill("Hey");
  for (size_t i = 0; i < str_buff.getSize(); i++) {
    std::cout << str_buff[i] << std::endl;
  }

  return 0;
}

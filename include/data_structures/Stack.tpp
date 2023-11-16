#pragma once

#include "Stack.hpp"
#include <optional>

namespace data_structures {

template <typename T> Stack<T>::~Stack() {
  while (head != nullptr) {
    auto current_head = head;
    head = head->prev;
    delete current_head;
  }
}

template <typename T> auto Stack<T>::peek() -> std::optional<T> {
  if (head == nullptr) {
    return std::nullopt;
  }

  return std::optional<T>{head->data};
}

template <typename T> auto Stack<T>::push(const T &data) -> void {
  auto new_node = new STNode<T>{data, nullptr};
  length++;
  if (head == nullptr) {
    head = new_node;
    return;
  }
  new_node->prev = head;
  head = new_node;
}

template <typename T> auto Stack<T>::pop() -> std::optional<T> {
  if (length == 0) {
    return std::nullopt;
  }
  auto popped_head = head;
  auto popped_data = head->data;
  head = head->prev;
  delete popped_head;
  length--;
  return std::optional<T>{popped_data};
}

} // namespace data_structures

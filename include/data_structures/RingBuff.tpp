#pragma once

#include "RingBuff.hpp"
#include <cstddef>
#include <iostream>
#include <optional>
#include <stdexcept>

namespace data_structures {

template <typename T, std::size_t Cap>
auto RingBuff<T, Cap>::push(const T &value) -> void {
  if (isFull()) {
    throw std::overflow_error("Ring Buffer is full");
  }

  data[head] = value;
  head = (head + 1) % Cap;
  length++;
}

template <typename T, std::size_t Cap> auto RingBuff<T, Cap>::pop() -> void {
  if (isEmpty()) {
    throw std::underflow_error("Ring Buffer is empty.");
  }

  tail = (tail + 1) % Cap;
  length--;
}

template <typename T, std::size_t Cap>
auto RingBuff<T, Cap>::peek() const -> std::optional<T> {

  if (isEmpty()) {
    return std::nullopt;
  }
  return data[tail];
}

template <typename T, std::size_t Cap>
auto RingBuff<T, Cap>::isEmpty() const -> bool {
  return length == 0;
}

template <typename T, std::size_t Cap>
auto RingBuff<T, Cap>::isFull() const -> bool {
  return length == Cap;
}

template <typename T, std::size_t Cap>
auto RingBuff<T, Cap>::getLength() const -> std::size_t {
  return length;
}

template <typename T, std::size_t Cap> auto RingBuff<T, Cap>::clear() -> void {
  head = 0;
  tail = 0;
  length = 0;
  data.fill(0);
}

} // namespace data_structures

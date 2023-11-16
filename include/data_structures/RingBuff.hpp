#pragma once

#include <array>
#include <cstddef>
#include <optional>
namespace data_structures {

template <typename T, std::size_t Cap> class RingBuff {
public:
  RingBuff() : data{}, head{0}, tail{0}, length{0} {}

public:
  auto push(const T &value) -> void;
  auto pop() -> void;
  auto peek() const -> std::optional<T>;

  auto isEmpty() const -> bool;
  auto isFull() const -> bool;
  auto getLength() const -> std::size_t;

  auto clear() -> void;

private:
  std::array<T, Cap> data;
  std::size_t head;   // index for push
  std::size_t tail;   // index for pop
  std::size_t length; // current length of the buffer
};

} // namespace data_structures

#include "RingBuff.tpp"

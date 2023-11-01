#pragma once

#include <cstddef>
#include <initializer_list>

namespace data_structures {

template <typename T, size_t S> class ArrayBuffer {
public:
  // Default Constructor
  ArrayBuffer() = default;
  // Constructor for uniform initialization
  ArrayBuffer(std::initializer_list<T> init_list);
  // Copy Constructor
  ArrayBuffer(const ArrayBuffer &) = default;
  // Move Constructor
  ArrayBuffer(ArrayBuffer &&) = default;
  // Copy assignment operator
  ArrayBuffer &operator=(const ArrayBuffer &) = default;
  // Move assignment operator
  ArrayBuffer &operator=(ArrayBuffer &&) = default;

public:
  constexpr auto getSize() const -> size_t;
  auto operator[](size_t index) -> T &;
  auto operator[](size_t index) const -> const T &;
  auto getData() -> T *;
  auto getData() const -> const T *;
  auto fill(T val) -> void;

private:
  T data_[S];
};

} // namespace data_structures

#include "ArrayBuffer.tpp"

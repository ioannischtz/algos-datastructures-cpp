#pragma once

#include "ArrayBuffer.hpp"
#include <cstddef>
#include <cstring>
#include <initializer_list>
#include <stdexcept>

namespace data_structures {

template <typename T, size_t S>
ArrayBuffer<T, S>::ArrayBuffer(std::initializer_list<T> init_list) {
  size_t idx = 0;
  for (const T &val : init_list) {
    if (idx >= S) {
      break;
    }
    data_[idx] = val;
    idx++;
  }
}

template <typename T, size_t S>
constexpr auto ArrayBuffer<T, S>::getSize() const -> size_t {
  return S;
}

template <typename T, size_t S>
auto ArrayBuffer<T, S>::operator[](size_t index) -> T & {
#ifndef NDEBUG
  if (!(index < S)) {
    throw std::out_of_range("index out of range");
  }
#endif
  return data_[index];
}

template <typename T, size_t S>
auto ArrayBuffer<T, S>::operator[](size_t index) const -> const T & {
#ifndef NDEBUG
  if (!(index < S)) {
    throw std::out_of_range("index out of range");
  }
#endif
  return data_[index];
}

template <typename T, size_t S> auto ArrayBuffer<T, S>::getData() -> T * {
  return data_;
}

template <typename T, size_t S>
auto ArrayBuffer<T, S>::getData() const -> const T * {
  return data_;
}

template <typename T, size_t S> auto ArrayBuffer<T, S>::fill(T val) -> void {
  if constexpr (std::is_trivially_copyable<T>::value) {
    // If T is trivially copyable, you can use memset
    std::memset(data_, val, S * sizeof(T));
  } else {
    // If T is not trivially copyable, use a loop
    for (size_t i = 0; i < S; ++i) {
      data_[i] = val;
    }
  }
}
} // namespace data_structures

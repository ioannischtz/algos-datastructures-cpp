#pragma once

#include <cstddef>
#include <optional>
namespace data_structures {

template <typename T> struct STNode {
  T data;
  STNode<T> *prev;
};

template <typename T> class Stack {
public:
  Stack() : length{0}, head{nullptr} {}
  ~Stack();

public:
  auto push(const T &data) -> void;
  auto pop() -> std::optional<T>;
  auto peek() -> std::optional<T>;

public:
  size_t length;

private:
  STNode<T> *head;
};

} // namespace data_structures
#include "Stack.tpp"

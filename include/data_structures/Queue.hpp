#pragma once

#include "SLinkedList.hpp"
#include <cstddef>
#include <memory>
namespace data_structures {

template <typename T> class QNode {
public:
  QNode(const T &data) : data{data}, next{nullptr} {}

public:
  // Accesors
  [[nodiscard]] auto getNext() const -> QNode<T> *;
  [[nodiscard]] auto ownNext() -> std::unique_ptr<QNode<T>>;
  [[nodiscard]] auto getData() const -> const T &;
  [[nodiscard]] auto getDataCopy() const -> T;
  // Modifiers
  auto setNext(std::unique_ptr<QNode<T>> node) -> void;
  auto setData(const T &d) -> void;

private:
  T data;
  std::unique_ptr<QNode<T>> next;
};

template <typename T> class Queue {
public:
  Queue() : length{0}, head{nullptr}, tail{nullptr} {}

public:
  auto enqueue(const T &data) -> void;
  auto dequeue() -> std::optional<T>;

  auto peek() const -> std::optional<T>;
  auto getLength() const -> size_t;

private:
  size_t length;
  std::unique_ptr<QNode<T>> head;
  QNode<T> *tail;
};

} // namespace data_structures
#include "Queue.tpp"

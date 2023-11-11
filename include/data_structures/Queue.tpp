#pragma once

#include "Queue.hpp"
#include "SLinkedList.hpp"
#include <cstddef>
#include <memory>
#include <optional>
#include <type_traits>

namespace data_structures {

// -----------------
// ----- QNode -----
// -----------------

// --- Accessors ---

template <typename T> auto QNode<T>::getNext() const -> QNode<T> * {
  return next.get();
}

template <typename T> auto QNode<T>::ownNext() -> std::unique_ptr<QNode<T>> {
  return std::unique_ptr<QNode<T>>(next.release());
}

template <typename T> auto QNode<T>::getData() const -> const T & {
  return data;
}

template <typename T> auto QNode<T>::getDataCopy() const -> T { return data; }

// --- Modifiers ---
template <typename T>
auto QNode<T>::setNext(std::unique_ptr<QNode<T>> node) -> void {
  next = std::move(node);
}

template <typename T> auto QNode<T>::setData(const T &d) -> void {
  if constexpr (std::is_trivially_copyable_v<T>) {
    data = d; // Regular assignment for is_trivially_copyable types
  } else {
    data = std::move(d); // Move semantics for non-trivially copyable data
  }
}

// -----------------
// ----- Queue -----
// -----------------

template <typename T> auto Queue<T>::enqueue(const T &data) -> void {
  // Create a new Node
  auto new_node = std::make_unique<QNode<T>>(data);

  // If queue is empty, set head = tail
  if (length == 0) {
    head = std::move(new_node);
    tail = head.get();
  } else {
    // if not empty, insert new node at end of queue
    tail->setNext(std::move(new_node));
    tail = tail->getNext();
  }
  // Incerement the length since we inserted a new node
  length++;
}

template <typename T> auto Queue<T>::dequeue() -> std::optional<T> {
  if (!head) {
    return std::nullopt;
  }

  length--;
  auto prev_head = std::move(head);
  head = std::move(prev_head->ownNext());

  if (length == 0) {
    tail = nullptr;
  }

  return std::optional<T>(prev_head->getDataCopy());
}

template <typename T> auto Queue<T>::peek() const -> std::optional<T> {
  if (!head) {
    return std::nullopt;
  }
  return std::optional<T>(head->getDataCopy());
}

template <typename T> auto Queue<T>::getLength() const -> size_t {
  return length;
}

} // namespace data_structures

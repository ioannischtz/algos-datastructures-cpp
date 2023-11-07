#pragma once

#include "SLinkedList.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <vector>

namespace data_structures {

// ====== SNode ======

// ------ Ctors ------

// Copy constructor
template <typename T>
SNode<T>::SNode(const SNode &other) : data{other.data}, next{nullptr} {
  std::cout << "SNode: Copy ctor" << std::endl;
  if (other.next) {
    next = std::make_unique<SNode<T>>(*other.next);
  }
}

// Move constructor
template <typename T>
SNode<T>::SNode(SNode &&other) noexcept
    : data(std::move(other.data)), next(std::move(other.next)) {
  std::cout << "SNode: Move ctor" << std::endl;
  other.next.reset();
}

// Copy assignment
template <typename T> auto SNode<T>::operator=(const SNode &other) -> SNode & {
  std::cout << "SNode: Copy assignment" << std::endl;
  if (this != &other) {
    data = other.data;
    if (other.next) {
      next = std::make_unique<SNode>(*other.next);
    } else {
      next.reset();
    }
  }
  return *this;
}

// Move assignment operator
template <typename T>
auto SNode<T>::operator=(SNode &&other) noexcept -> SNode & {
  std::cout << "SNode: Move assignment" << std::endl;

  if (this != &other) {
    data = std::move(other.data);
    next = std::move(other.next);
  }
  return *this;
}

// ------ getters ------
template <typename T> auto SNode<T>::getData() const -> const T & {
  return data;
}

template <typename T>
auto SNode<T>::getNext() const -> std::unique_ptr<SNode<T>> {
  return std::move(next);
}

// ------ setters ------
template <typename T> auto SNode<T>::setData(T elm) -> void {
  if constexpr (std::is_trivially_copyable_v<T>) {
    data = elm; // Regular assignment for trivially copyable types.
  } else {
    data = std::move(elm); // Move semantics for non-trivially
    // copyable datas
  }
}

template <typename T>
auto SNode<T>::setNext(std::unique_ptr<SNode<T>> next_node) -> void {
  next = std::move(next_node);
}

// ====== SLinkedList ======

// ------ Constructors ------

// Default Ctor
template <typename T>
SLinkedList<T>::SLinkedList() : length{0}, head{nullptr}, tail{nullptr} {
  std::cout << "SLinkedList: Default Ctor" << std::endl;
}

// Copy ctor
template <typename T>
SLinkedList<T>::SLinkedList(const SLinkedList &other)
    : length(0), head(nullptr), tail(nullptr) {
  // Create a deep copy of the other linked list
  auto current = other.head.get();

  while (current) {
    insertLast(current->getData());
    current = current->getNext().get();
  }
}

// Move Ctor
template <typename T>
SLinkedList<T>::SLinkedList(SLinkedList &&other)
    : length{other.length}, head(std::move(other.head)),
      tail(std::move(other.tail)) {
  std::cout << "SLinkedList: Move Ctor" << std::endl;

  other.length = 0;
  other.head.reset();
  other.tail.reset();
}

// Copy assignment
template <typename T>
auto SLinkedList<T>::operator=(const SLinkedList &other) -> SLinkedList & {
  std::cout << "SLinkedList: Copy assignment" << std::endl;

  if (this != &other) {
    // Clear the current list
    clear();

    SNode<T> *current = other.head.get();
    while (current) {
      insertLast(current->getData());
      current = current->getNext().get();
    }
  }
  return *this;
}

// Move assignment
template <typename T>
auto SLinkedList<T>::operator=(SLinkedList &&other) -> SLinkedList & {
  std::cout << "SLinkedList: Move assignment" << std::endl;

  if (this != &other) {
    // Clear the current list
    clear();

    // Move ther resources from the other list
    length = other.length;
    head = std::move(other.head);
    tail = std::move(other.tail);

    // Reset the other list
    other.length = 0;
    other.head.reset();
    other.tail.reset();
  }
  return *this;
}

// Dtor
template <typename T> SLinkedList<T>::~SLinkedList() {
  std::cout << "SLinkedList: Dtor" << std::endl;

  // Clear the list to release memory managed by unique_ptr
  clear();
}

// ------ Accessors ------

template <typename T> auto SLinkedList<T>::getLength() const -> size_t {
  return length;
}

template <typename T> auto SLinkedList<T>::isEmpty() const -> bool {
  return (length < 1);
}

template <typename T>
auto SLinkedList<T>::isFirst(const SNode<T> &node) const -> bool {
  return (&node == head.get());
}

template <typename T>
auto SLinkedList<T>::isLast(const SNode<T> &node) const -> bool {
  return (&node == tail.get());
}

template <typename T>
auto SLinkedList<T>::first() const -> std::optional<std::unique_ptr<SNode<T>>> {
  std::cout << "SLinkedList: first()" << std::endl;
  if (isEmpty()) {
    return std::nullopt;
  } else {
    return std::optional<std::unique_ptr<SNode<T>>>(std::move(head));
  }
}

template <typename T>
[[nodiscard]] auto SLinkedList<T>::last() const
    -> std::optional<std::unique_ptr<SNode<T>>> {
  if (isEmpty()) {
    return std::nullopt; // Return an empty optional if the list is empty
  } else {
    return std::make_optional(
        std::move(tail)); // Return the actual node's std::unique_ptr
  }
}

template <typename T>
auto SLinkedList<T>::getDataAt(size_t index) -> std::optional<T> {
  std::cout << "SLinkedList: getDataAt()" << std::endl;
  if (index >= length) {
    return std::nullopt;
  }

  SNode<T> *current = head.get();
  for (size_t i = 0; i < index; ++i) {
    current = current->getNext().get();
  }
  // Return the data at the specified index
  return std::optional<T>(current->getData());
}

template <typename T>
[[nodiscard]] auto SLinkedList<T>::find(const T &data) const
    -> std::optional<std::unique_ptr<SNode<T>>> {
  auto current = head.get();

  while (current) {
    if (current->getData() == data) {
      return std::make_optional(std::move(std::make_unique<SNode<T>>(
          *current))); // Return a copy of the found node
    }
    current = current->getNext().get();
  }

  return std::nullopt; // Data not found, return an empty optional
}

template <typename T>
[[nodiscard]] auto SLinkedList<T>::findAll(const T &data) const
    -> std::optional<std::vector<std::unique_ptr<SNode<T>>>> {
  std::vector<std::unique_ptr<SNode<T>>> found_nodes;
  auto current = head.get();

  while (current) {
    if (current->getData() == data) {
      found_nodes.push_back(std::make_unique<SNode<T>>(*current));
    }
    current = current->getNext().get();
  }

  if (found_nodes.empty()) {
    return std::nullopt; // Return an empty optional if no nodes match the data
  } else {
    return std::make_optional(std::move(found_nodes));
  }
}

// ------ Modifiers ------

template <typename T>
auto SLinkedList<T>::insertFirst(const T &data) -> std::unique_ptr<SNode<T>> {
  // Create a new node
  auto new_node = std::make_unique<SNode<T>>(data);

  if (isEmpty()) {
    // If the list is empty, set the new_node as both the head and tail
    head = std::move(new_node);
    tail = head.get();
  } else {
    // If the list is not empty, the new_node will become our head
    // Set its nextNode to the current head
    new_node->setNext(std::move(head));
    head = std::move(new_node);
  }

  // Increment the length of the list since we inserted a new node
  length++;

  // Return a copy of the newly inserted node (the head)
  return std::make_unique<SNode<T>>(*head);
}

template <typename T>
auto SLinkedList<T>::insertLast(const T &data) -> std::unique_ptr<SNode<T>> {
  auto newNode = std::make_unique<SNode<T>>(data);

  if (!head) {
    // If the list is empty, set the new node as both the head and tail.
    head = std::move(newNode);
    tail = head.get();
  } else {
    // Otherwise, add the new node to the end of the list and update the tail.
    tail->setNext(std::move(newNode));
    tail = tail->getNext().get();
  }

  length++;
  return tail;
}

template <typename T>
auto SLinkedList<T>::insertAfter(SNode<T> *node, const T &data)
    -> std::optional<std::unique_ptr<SNode<T>>> {
  if (isEmpty()) {
    return std::nullopt; // Return an empty optional if the list is empty
  }

  // Create a new node
  auto new_node = std::make_unique<SNode<T>>(data);

  auto next = node->getNext().get();

  if (!next) {
    // If the specified node is the last node, insert the new node after it
    node->setNext(std::move(new_node));
    tail = node->getNext().get();
  } else {
    // Insert the new node between the specified node and the next node
    new_node->setNext(std::move(node->getNext()));
    node->setNext(std::move(new_node));
  }

  // Increment the length of the list since we inserted a new node
  length++;

  // Return a pointer to the newly inserted node (node->getNext())
  // return std::make_optional(node->getNext());
  // Return a copy of the newly inserted node
  return std::make_optional(std::make_unique<SNode<T>>(*node->getNext()));
}

template <typename T>
auto SLinkedList<T>::insertAt(size_t index, const T &data) -> std::optional<T> {
  if (index >= length) {
    return std::nullopt;
  }

  if (index == 0) {
    insertFirst(data);
    return std::make_optional(data);
  } else {
    auto new_node = std::make_unique<SNode<T>>(data);
    SNode<T> *current = head.get();
    SNode<T> *prev = nullptr;

    for (size_t i = 0; i < index; ++i) {
      prev = current;
      current = current->getNext().get();
    }
    new_node->setNext(std::move(prev->getNext()));
    prev->setNext(std::move(new_node));
    length++;
    return std::make_optional(data);
  }
}

template <typename T>
auto SLinkedList<T>::removeAfter(SNode<T> *node) -> std::optional<T> {
  if (node == nullptr) {
    return std::nullopt; // Invalid node
  }

  auto node_to_del = std::move(node->getNext());

  if (!node_to_del) {
    return std::nullopt; // Nothing to remove
  }

  auto next = node_to_del->getNext();

  node->setNext(std::move(next));

  length--;

  return std::make_optional(node_to_del->getData());
}

template <typename T>
auto SLinkedList<T>::remove(const T &data) -> std::optional<T> {
  auto removed_data = std::optional<T>(std::nullopt);

  if (!head) {
    return removed_data; // List is empty, return nullopt
  }

  if (head->getData() == data) {
    removed_data = std::make_optional(head->getData());
    head = std::move(head->getNext());
    length--;
    return removed_data;
  }

  SNode<T> *current = head.get();
  SNode<T> *prev = nullptr;

  while (current && current->getData() != data) {
    prev = current;
    current = current->getNext().get();
  }

  if (current) {
    removed_data = std::make_optional(current->getData());
    prev->setNext(std::move(current->getNext()));
    length--;
  }

  return removed_data;
}

template <typename T>
auto SLinkedList<T>::removeAt(size_t index) -> std::optional<T> {
  if (index >= length) {
    return std::nullopt; // Index is out of bounds
  }

  auto removed_data = std::optional<T>(std::nullopt);

  if (!head) {
    return removed_data; // List is empty, return nullopt
  }

  if (index == 0) {
    removed_data = std::make_optional(head->getData());
    head = std::move(head->getNext());
    length--;
    return removed_data;
  }

  SNode<T> *current = head.get();
  SNode<T> *prev = nullptr;

  for (size_t i = 0; i < index; i++) {
    prev = current;
    current = current->getNext().get();
  }

  if (current) {
    removed_data = std::make_optional(current->getData());
    prev->setNext(std::move(current->getNext()));
    length--;
  }

  return removed_data;
}

template <typename T> auto SLinkedList<T>::clear() -> void {
  while (head) {
    head = std::move(head->getNext());
  }
  length = 0;
  tail.reset();
}

template <typename T> auto SLinkedList<T>::printAll() -> void {
  SNode<T> *current = head.get();
  std::cout << "SLinkedList: printAll()" << std::endl;

  while (current) {
    std::cout << current->getData();
    current = current->getNext();
    if (current) {
      std::cout << " --> ";
    }
  }

  std::cout << " (x)" << std::endl;
}

} // namespace data_structures

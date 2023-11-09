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

template <typename T> auto SNode<T>::getDataCopy() const -> T { return data; }

template <typename T> auto SNode<T>::getNext() const -> SNode<T> * {
  return next.get();
}

template <typename T>
[[nodiscard]] auto SNode<T>::ownNext() -> std::unique_ptr<SNode<T>> {
  return std::unique_ptr<SNode<T>>(next.release());
}

// ------ setters ------
template <typename T> auto SNode<T>::setData(T data) -> void {
  if constexpr (std::is_trivially_copyable_v<T>) {
    this->data = data; // Regular assignment for trivially copyable types.
  } else {
    data = std::move(data); // Move semantics for non-trivially
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
  std::cout << "SLinkedList: Copy Ctor" << std::endl;

  // Create a deep copy of the other linked list
  auto current = other.head.get();

  while (current) {
    insertLast(current->getData());
    current = current->getNext();
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
      current = current->getNext();
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
  std::cout << "SLinkedList: getLength()" << std::endl;
  return length;
}

template <typename T> auto SLinkedList<T>::isEmpty() const -> bool {
  std::cout << "SLinkedList: isEmpty()" << std::endl;
  return (length < 1);
}

template <typename T>
auto SLinkedList<T>::isFirst(const SNode<T> &node) const -> bool {
  std::cout << "SLinkedList: isFirst()" << std::endl;
  return (&node == head.get());
}

template <typename T>
auto SLinkedList<T>::isLast(const SNode<T> &node) const -> bool {
  std::cout << "SLinkedList: isLast()" << std::endl;
  return (&node == tail);
}

template <typename T>
auto SLinkedList<T>::first() const -> std::optional<SNode<T> *> {
  std::cout << "SLinkedList: first()" << std::endl;
  if (isEmpty()) {
    return std::nullopt;
  } else {
    return std::optional(head.get());
  }
}

template <typename T>
auto SLinkedList<T>::firstCopy() const -> std::optional<SNode<T>> {
  std::cout << "SLinkedList: firstCopy()" << std::endl;
  if (isEmpty()) {
    return std::nullopt;
  } else {
    return std::optional(*head);
  }
}

template <typename T>
auto SLinkedList<T>::last() const -> std::optional<SNode<T> *> {
  std::cout << "SLinkedList: last()" << std::endl;
  if (isEmpty()) {
    return std::nullopt;
  } else {
    return std::optional<SNode<T> *>(tail);
  }
}

template <typename T>
auto SLinkedList<T>::lastCopy() const -> std::optional<SNode<T>> {
  std::cout << "SLinkedList: lastCopy()" << std::endl;
  if (isEmpty()) {
    return std::nullopt;
  } else {
    return std::optional<SNode<T>>(*tail);
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
    current = current->getNext();
  }
  // Return the data at the specified index
  return std::optional<T>(current->getDataCopy());
}

template <typename T>
auto SLinkedList<T>::find(const T &data) const -> std::optional<SNode<T> *> {
  std::cout << "SLinkedList: find()" << std::endl;
  SNode<T> *current = head.get();

  while (current) {
    if (current->getData() == data) {
      return std::optional<SNode<T> *>(current);
    }
    current = current->getNext();
  }

  return std::nullopt;
}

template <typename T>
auto SLinkedList<T>::findCopy(const T &data) const -> std::optional<SNode<T>> {
  std::cout << "SLinkedList: findCopy()" << std::endl;
  SNode<T> *current = head.get();

  while (current) {
    if (current->getData() == data) {
      return std::optional<SNode<T>>(*current);
    }
    current = current->getNext();
  }

  return std::nullopt;
}

template <typename T>
auto SLinkedList<T>::findAll(const T &data) const
    -> std::optional<std::vector<SNode<T> *>> {
  std::cout << "SLinkedList: findAll()" << std::endl;
  std::vector<SNode<T> *> found_nodes;
  SNode<T> *current = head.get();

  while (current) {
    if (current->getData() == data) {
      found_nodes.push_back(current);
    }
    current = current->getNext();
  }

  if (found_nodes.empty()) {
    return std::nullopt;
  } else {
    return std::optional<std::vector<SNode<T> *>>(found_nodes);
  }
}

template <typename T>
auto SLinkedList<T>::findAllCopy(const T &data) const
    -> std::optional<std::vector<SNode<T>>> {
  std::cout << "SLinkedList: findAllCopy()" << std::endl;
  std::vector<SNode<T>> found_nodes;
  SNode<T> *current = head.get();

  while (current) {
    if (current->getData() == data) {
      found_nodes.push_back(*current);
    }
    current = current->getNext();
  }

  if (found_nodes.empty()) {
    return std::nullopt;
  } else {
    return std::optional<std::vector<SNode<T>>>(found_nodes);
  }
}

// ------ Modifiers ------

template <typename T>
auto SLinkedList<T>::insertFirst(const T &data) -> SNode<T> * {
  std::cout << "SLinkedList: insertFirst()" << std::endl;
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

  // Return a raw pointer to the newly inserted node (the head)
  return head.get();
}

template <typename T>
auto SLinkedList<T>::insertLast(const T &data) -> SNode<T> * {
  // Create a new node
  auto new_node = std::make_unique<SNode<T>>(data);

  if (isEmpty()) {
    // If the list is empty, set the new_node as both the head and tail
    head = std::move(new_node);
    tail = head.get();
  } else {
    // If the list is not empty, insert the new_node at the end
    tail->setNext(std::move(new_node));
    tail = tail->getNext();
  }

  // Increment the length of the list since we inserted a new node
  length++;

  // Return a raw pointer to the newly inserted node (the tail)
  return tail;
}

template <typename T>
auto SLinkedList<T>::insertAfter(SNode<T> *node, const T &data)
    -> std::optional<SNode<T> *> {
  if (!node || isEmpty()) {
    return std::nullopt; // Cannot insert if list isEmpty or node is nullptr
  }

  // Create a new node
  auto new_node = std::make_unique<SNode<T>>(data);
  SNode<T> *next = node->getNext();

  // Increment the length of the list since we inserted a new node
  length++;

  if (!next) { // Insert at the end
    node->setNext(std::move(new_node));
    tail = node->getNext();
  } else {
    new_node->setNext(std::move(node->ownNext()));
    node->setNext(std::move(new_node));
  }

  // Return a raw pointer to the newly inserted node
  return std::optional<SNode<T> *>(node->getNext());
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
      current = current->getNext();
    }
    new_node->setNext(std::move(prev->ownNext()));
    prev->setNext(std::move(new_node));
    length++;
    return std::make_optional(new_node->getData());
  }
}

template <typename T>
auto SLinkedList<T>::removeAfter(SNode<T> *node) -> std::optional<T> {
  if (node == nullptr) {
    return std::nullopt; // Invalid node
  }

  auto node_to_del = std::move(node->ownNext());

  if (!node_to_del) {
    return std::nullopt; // Nothing to remove
  }

  node->setNext(std::move(node_to_del->ownNext()));

  length--;

  return std::make_optional(node_to_del->getDataCopy());
}

template <typename T>
auto SLinkedList<T>::remove(const T &data) -> std::optional<T> {
  auto removed_data = std::optional<T>(std::nullopt);

  if (!head) {
    return removed_data; // List is empty, return nullopt
  }

  if (head->getDataCopy() == data) {
    removed_data = std::make_optional(head->getDataCopy());
    head = std::move(head->ownNext());
    length--;
    return removed_data;
  }

  SNode<T> *current = head.get();
  SNode<T> *prev = nullptr;

  while (current && current->getDataCopy() != data) {
    prev = current;
    current = current->getNext();
  }

  if (current) {
    removed_data = std::make_optional(current->getDataCopy());
    prev->setNext(current->ownNext());
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
    removed_data = std::make_optional(head->getDataCopy());
    head = std::move(head->ownNext());
    length--;
    return removed_data;
  }

  SNode<T> *current = head.get();
  SNode<T> *prev = nullptr;

  for (size_t i = 0; i < index; i++) {
    prev = current;
    current = current->getNext();
  }

  if (current) {
    removed_data = std::make_optional(current->getDataCopy());
    prev->setNext(current->ownNext());
    length--;
  }

  return removed_data;
}

template <typename T> auto SLinkedList<T>::clear() -> void {
  std::cout << "SLinkedList: clear()" << std::endl;
  while (head) {
    head = std::move(head->ownNext());
  }
  length = 0;
  tail = nullptr;
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

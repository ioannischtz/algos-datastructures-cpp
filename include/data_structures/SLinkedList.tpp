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
SNode<T>::SNode(const SNode &other) : element{other.element}, next{nullptr} {
  std::cout << "SNode: Copy ctor" << std::endl;
  if (other.next) {
    next = std::make_unique<SNode<T>>(*other.next);
  }
}

// Move constructor
template <typename T>
SNode<T>::SNode(SNode &&other) noexcept
    : element(std::move(other.element)), next(std::move(other.next)) {
  std::cout << "SNode: Move ctor" << std::endl;
  other.next.reset();
}

// Copy assignment
template <typename T> auto SNode<T>::operator=(const SNode &other) -> SNode & {
  std::cout << "SNode: Copy assignment" << std::endl;
  if (this != &other) {
    element = other.element;
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
    element = std::move(other.element);
    next = std::move(other.next);
  }
  return *this;
}

// ------ getters ------
template <typename T> auto SNode<T>::getElement() const -> const T & {
  return element;
}

template <typename T>
auto SNode<T>::getNext() const -> std::optional<SNode<T> *> {
  if (next != nullptr) {
    return std::optional<SNode<T> *>(next.get());
  } else {
    return std::nullopt;
  }
}

// ------ setters ------
template <typename T> auto SNode<T>::setElement(T elm) -> void {
  if constexpr (std::is_trivially_copyable_v<T>) {
    element = elm; // Regular assignment for trivially copyable types.
  } else {
    element = std::move(elm); // Move semantics for non-trivially
    // copyable elements
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
template <typename T> SLinkedList<T>::SLinkedList(const SLinkedList &other) {
  std::cout << "SLinkedList: Copy Ctor" << std::endl;

  SNode<T> *current = other.head.get();
  while (current) {
    insertLast(current->getElement());
    auto opt_next = current->getNext();
    current = opt_next.has_value() ? opt_next.value() : nullptr;
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
      insertLast(current->getElement());
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
auto SLinkedList<T>::first() const -> std::optional<SNode<T> *> {
  std::cout << "SLinkedList: first()" << std::endl;
  if (isEmpty()) {
    return std::nullopt;
  } else {
    return std::optional<SNode<T> *>(head.get());
  }
}

template <typename T>
auto SLinkedList<T>::last() const -> std::optional<SNode<T> *> {
  std::cout << "SLinkedList: last()" << std::endl;
  if (isEmpty()) {
    return std::nullopt;
  } else {
    return std::optional<SNode<T> *>(tail.get());
  }
}

template <typename T>
auto SLinkedList<T>::getElementAt(size_t index) -> std::optional<T> {
  std::cout << "SLinkedList: getElementAt()" << std::endl;
  if (index < 0 || index >= length) {
    return std::nullopt;
  }

  SNode<T> *current = head.get();
  for (size_t i = 0; i < index; ++i) {
    auto opt_next = current->getNext();
    current = opt_next.has_value() ? opt_next.value() : nullptr;
  }
  // Return the element at the specified index
  return std::optional<T>(current->getElement());
}

template <typename T>
auto SLinkedList<T>::find(const T &element) const -> std::optional<SNode<T> *> {
  SNode<T> *current = head.get();
  while (current) {
    std::cout << "SLinkedList: find(), current elm = " << current->getElement()
              << std::endl;
    if (current->getElement() == element) {
      return std::optional<SNode<T> *>(current);
    }
    auto opt_next = current->getNext();
    current = opt_next.has_value() ? opt_next.value() : nullptr;
  }
  return std::nullopt; // Return empty std::optional if the element is not found
}

template <typename T>
auto SLinkedList<T>::findAll(const T &element) const
    -> std::optional<std::vector<SNode<T> *>> {
  std::cout << "SLinkedList: findAll()" << std::endl;
  std::vector<SNode<T> *> found_nodes;
  SNode<T> *current = head.get();

  while (current) {
    if (current->getElement() == element) {
      found_nodes.push_back(current);
    }
    auto opt_next = current->getNext();
    current = opt_next.has_value() ? opt_next.value() : nullptr;
  }

  if (found_nodes.empty()) {
    return std::nullopt;
  } else {
    return std::optional<std::vector<SNode<T> *>>(found_nodes);
  }
}

// ------ Modifiers ------

template <typename T>
auto SLinkedList<T>::insertFirst(const T &elm) -> SNode<T> * {
  std::cout << "SLinkedList: insertFirst()" << std::endl;
  // Create a new node
  auto new_node = std::make_unique<SNode<T>>(elm);
  if (isEmpty()) {
    head = std::move(new_node);
  } else {
    // If the list is not empty, the new_node will become our head,
    // therefore, its nextNode == current head
    new_node->setNext(std::move(head));
    head = std::move(new_node);
  }

  // Increment the length of the list, since we inserted a new node
  length++;

  // Return a copy of the newly inserted node(new_node is moved into head)
  return head.get();
}

template <typename T>
auto SLinkedList<T>::insertAfter(SNode<T> *node, const T &elm)
    -> std::optional<SNode<T> *> {
  std::cout << "SLinkedList: insertAfter()" << std::endl;
  if (isEmpty()) {
    return std::nullopt;
  }
  // Create new node
  auto new_node = std::make_unique<SNode<T>>(elm);
  auto opt_next = node->getNext();
  auto next = opt_next.has_value() ? opt_next.value() : nullptr;
  // Increment the length of the list, since we inserted a new node
  length++;

  if (next == nullptr) { // this means we insert at the end
    tail = std::move(new_node);
    node->setNext(std::move(tail));

    return (node->getNext());
  }

  new_node->setNext(std::make_unique<SNode<T>>(*next));
  node->setNext(std::move(new_node));

  return node->getNext();
}

// TODO:  [[nodiscard]] auto removeAfter(SNode<T> &node) -> std::optional<T>;
// TODO:  [[nodiscard]] auto remove(SNode<T> *node) -> std::optional<T>;

template <typename T> auto SLinkedList<T>::clear() -> void {
  std::cout << "SLinkedList: clear()" << std::endl;
  length = 0;
  head.reset();
  tail.reset();
}

template <typename T> auto SLinkedList<T>::printAll() -> void {
  SNode<T> *current = head.get();
  std::cout << "\n\nSLinkedList: printAll()\n";
  while (current) {
    std::cout << "(" << current->getElement() << ")"
              << "-->";
    auto opt_next = current->getNext();
    current = opt_next.has_value() ? opt_next.value() : nullptr;
  }
  std::cout << "(x)" << std::endl;
}

} // namespace data_structures

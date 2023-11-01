#pragma once

#include <cstddef>
#include <memory>
#include <optional>
namespace data_structures {

template <typename T> class SNode {
public:
  // Constructor to initialize the element and set the next pointer to nullptr
  SNode(const T &elm) : element(elm), next(nullptr) {}

public:
  auto getElement() const -> const T &;
  auto getNext() -> SNode<T> *;
  auto setElement(const T &element) -> void;
  auto setNext(SNode<T> *nextNode) -> void;

private:
  T element;
  std::unique_ptr<SNode<T>> next;
};

template <typename T> class SLinkedList {
public:
  SLinkedList() = default;

public:
  // Accessors
  auto getLength() const -> size_t;
  auto isEmpty() const -> bool;
  auto isFirst(const SNode<T> &node) const -> bool;
  auto isLast(const SNode<T> &node) const -> bool;
  auto first() const -> SNode<T> *;
  auto last() const -> SNode<T> *;
  auto find(const T &element) -> std::optional<SNode<T> *>;

  // Modifiers
  auto insertAfter(SNode<T> *node, const T &element) -> void;
  auto remove(SNode<T> *node) -> std::optional<SNode<T> *>;
  auto removeAfter(SNode<T> &node) -> std::optional<SNode<T> *>;
  auto append(const T &element) -> void;
  auto prepend(const T &element) -> void;

private:
  size_t length;
  std::unique_ptr<SNode<T>> head;
  std::unique_ptr<SNode<T>> tail;
};

} // namespace data_structures

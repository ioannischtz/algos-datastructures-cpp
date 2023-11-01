#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>
namespace data_structures {

template <typename T> class SNode {
public:
  // Constructor to initialize the element and set the next pointer to nullptr
  SNode(const T &elm) : element(elm), next(nullptr) {
    std::cout << "SNode: ctor with elm" << std::endl;
  }
  SNode() : element(), next{nullptr} {
    std::cout << "SNode: default ctor" << std::endl;
  }
  SNode(const SNode &other);
  SNode(SNode &&other) noexcept;
  auto operator=(const SNode &other) -> SNode &;
  auto operator=(SNode &&other) noexcept -> SNode &;
  ~SNode() {
    std::cout << "SNode: Dtor" << std::endl;
    next.reset();
  }

public:
  [[nodiscard]] auto getElement() const -> const T &;
  [[nodiscard]] auto getNext() const -> std::optional<SNode<T> *>;
  auto setElement(T elm) -> void;
  auto setNext(std::unique_ptr<SNode<T>> next_node) -> void;

private:
  T element;
  std::unique_ptr<SNode<T>> next;
};

template <typename T> class SLinkedList {
public:
  // Default Constructor
  SLinkedList();
  // Copy Constructor
  SLinkedList(const SLinkedList &other);
  // Move Constructor
  SLinkedList(SLinkedList &&other);
  // Copy assignment operator
  auto operator=(const SLinkedList &other) -> SLinkedList &;
  // Move assignment operator
  auto operator=(SLinkedList &&other) -> SLinkedList &;
  // Destructor
  ~SLinkedList();

public:
  // Accessors
  auto getLength() const -> size_t;
  auto isEmpty() const -> bool;
  auto isFirst(const SNode<T> &node) const -> bool;
  auto isLast(const SNode<T> &node) const -> bool;
  [[nodiscard]] auto first() const -> std::optional<SNode<T> *>;
  [[nodiscard]] auto last() const -> std::optional<SNode<T> *>;
  [[nodiscard]] auto getElementAt(size_t index) -> std::optional<T>;
  [[nodiscard]] auto find(const T &element) const -> std::optional<SNode<T> *>;
  [[nodiscard]] auto findAll(const T &element) const
      -> std::optional<std::vector<SNode<T> *>>;

  // Modifiers
  [[nodiscard]] auto insertFirst(const T &element) -> SNode<T> *;
  [[nodiscard]] auto insertAfter(SNode<T> *node, const T &element)
      -> std::optional<SNode<T> *>;
  [[nodiscard]] auto removeAfter(SNode<T> &node) -> std::optional<T>;
  [[nodiscard]] auto remove(SNode<T> *node) -> std::optional<T>;
  auto clear() -> void;

  // print
  auto printAll() -> void;

private:
  size_t length;
  std::unique_ptr<SNode<T>> head, tail;
};

} // namespace data_structures
#include "SLinkedList.tpp"

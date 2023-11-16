#include "RingBuff.hpp"
#include "catch2/catch.hpp"
#include <iostream>
#include <stdexcept>

using namespace data_structures;

RingBuff<int, 5> ring_buffer;

TEST_CASE("RingBuff basic operations", "[RingBuff]") {

  SECTION("Check if buffer is initially empty") {
    REQUIRE(ring_buffer.isEmpty());
  }

  SECTION("Push element and check peek()") {
    ring_buffer.push(5);
    REQUIRE(ring_buffer.peek().value_or(-1) == 5);
  }

  SECTION("Pop element and check length") {
    ring_buffer.pop();
    REQUIRE(ring_buffer.getLength() == 0);
  }

  SECTION("Pop from an empty buffer should throw an exception") {
    REQUIRE_THROWS_AS(ring_buffer.pop(), std::underflow_error);
  }

  SECTION("Push multiple elements, check peek, and pop") {
    ring_buffer.push(42);
    ring_buffer.push(9);
    REQUIRE(ring_buffer.peek().value_or(-1) == 42);
    ring_buffer.pop();
    REQUIRE(ring_buffer.peek().value_or(-1) == 9);
  }

  SECTION("Pop from an empty buffer after pushing should throw an exception") {
    ring_buffer.pop();
    ring_buffer.push(42);
    ring_buffer.pop();
    REQUIRE_THROWS_AS(ring_buffer.pop(), std::underflow_error);
  }

  SECTION("Check if buffer is full after pushing to capacity") {
    ring_buffer.push(1);
    ring_buffer.push(2);
    ring_buffer.push(3);
    ring_buffer.push(4);
    ring_buffer.push(5);
    REQUIRE(ring_buffer.isFull());
  }

  SECTION("Clear the buffer and check if it is empty") {
    ring_buffer.clear();
    REQUIRE(ring_buffer.isEmpty());
  }

  SECTION("Check if buffer is not full before reaching capacity") {
    ring_buffer.push(1);
    ring_buffer.push(2);
    REQUIRE_FALSE(ring_buffer.isFull());
  }
}

#include "Queue.hpp"
#include "catch2/catch.hpp"

// Write your test cases
TEST_CASE("Queue basic operations", "[Queue]") {
  data_structures::Queue<int> queue;

  SECTION("Enqueue and dequeue data") {
    queue.enqueue(5);
    queue.enqueue(7);
    queue.enqueue(9);

    REQUIRE(queue.dequeue().value_or(-1) == 5);
    REQUIRE(queue.getLength() == 2);

    queue.enqueue(11);

    REQUIRE(queue.dequeue().value_or(-1) == 7);
    REQUIRE(queue.dequeue().value_or(-1) == 9);
    REQUIRE(queue.peek() == 11);
    REQUIRE(queue.dequeue().value_or(-1) == 11);
    REQUIRE(!queue.dequeue().has_value());
    REQUIRE(queue.getLength() == 0);

    queue.enqueue(69);
    REQUIRE(queue.peek() == 69);
    REQUIRE(queue.getLength() == 1);
  }
}

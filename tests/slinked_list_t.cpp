#include "SLinkedList.hpp"
#include "catch2/catch.hpp"

// Write your test cases
TEST_CASE("SLinkedList basic operations", "[SLinkedList]") {
  data_structures::SLinkedList<int> list;

  SECTION("Empty list") {
    REQUIRE(list.isEmpty() == true);
    REQUIRE(list.getLength() == 0);
  }

  SECTION("Insert and retrieve elements") {
    auto firstNode_ptr = list.insertFirst(1);
    auto lastNode_ptr = list.insertLast(2);

    REQUIRE(list.isEmpty() == false);
    REQUIRE(list.getLength() == 2);

    auto firstNode = list.first();
    auto lastNode = list.last();

    REQUIRE(firstNode.has_value());
    REQUIRE(lastNode.has_value());

    REQUIRE(firstNode.value()->getDataCopy() == 1);
    REQUIRE(lastNode.value()->getDataCopy() == 2);
  }

  SECTION("Remove elements") {
    auto firstNode_ptr = list.insertFirst(1);
    auto lastNode_ptr = list.insertLast(2);

    auto removed1 = list.remove(1);
    auto removed2 = list.remove(2);

    REQUIRE(removed1.has_value());
    REQUIRE(removed2.has_value());

    REQUIRE(removed1.value() == 1);
    REQUIRE(removed2.value() == 2);

    REQUIRE(list.isEmpty() == true);
    REQUIRE(list.getLength() == 0);
  }
}

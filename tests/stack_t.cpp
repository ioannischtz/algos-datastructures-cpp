#include "Stack.hpp"
#include "catch2/catch.hpp"

TEST_CASE("Stack badic operations", "[Stack]") {
  data_structures::Stack<int> stack;

  SECTION("Push and Pop data") {

    stack.push(5);
    stack.push(7);
    stack.push(9);

    REQUIRE(stack.pop().value_or(-1) == 9);
    REQUIRE(stack.length == 2);

    stack.push(11);

    REQUIRE(stack.pop().value_or(-1) == 11);
    REQUIRE(stack.pop().value_or(-1) == 7);
    REQUIRE(stack.peek().value_or(-1) == 5);
    REQUIRE(stack.pop().value_or(-1) == 5);
    REQUIRE(!stack.pop().has_value());

    stack.push(69);
    REQUIRE(stack.peek().value_or(-1) == 69);
    REQUIRE(stack.length == 1);
  }
}

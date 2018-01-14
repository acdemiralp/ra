#include "catch.hpp"

#include <cstddef>

#include <ra/container.hpp>

struct test_resource
{
  std::size_t index;
  std::size_t value;
};

TEST_CASE("Container is tested.", "[container]") 
{
  ra::container<test_resource> test;

  test.storage().push_back({1, 2});
  test.storage().push_back({3, 4});
  test.storage().push_back({5, 6});

  REQUIRE(test.storage()[0].index == 1);
  REQUIRE(test.storage()[0].value == 2);
  REQUIRE(test.storage()[1].index == 3);
  REQUIRE(test.storage()[1].value == 4);
  REQUIRE(test.storage()[2].index == 5);
  REQUIRE(test.storage()[2].value == 6);
}
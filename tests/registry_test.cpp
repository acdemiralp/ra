#include "catch.hpp"

#include <cstddef>

#include <ra/registry.hpp>

struct resource_1 { std::size_t value; };
struct resource_2 { std::size_t value; };
struct resource_3 { std::size_t value; };

TEST_CASE("Registry is tested.", "[registry]") 
{
  ra::registry<resource_1, resource_2, resource_3> registry;
  auto& resource_1s = registry.get<resource_1>();
  auto& resource_2s = registry.get<resource_2>();
  auto& resource_3s = registry.get<resource_3>();
  
  resource_1s.storage().push_back(resource_1{1});
  resource_2s.storage().push_back(resource_2{3});
  resource_3s.storage().push_back(resource_3{5});

  REQUIRE(resource_1s.storage()[0].value == 1);
  REQUIRE(resource_2s.storage()[0].value == 3);
  REQUIRE(resource_3s.storage()[0].value == 5);
}
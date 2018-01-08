#include "catch.hpp"

#include <ra/registry.hpp>

class resource_1 { };
class resource_2 { };
class resource_3 { };

TEST_CASE("Registry is tested.", "[registry]") 
{
  ra::registry<resource_1, resource_2, resource_3> registry;
  auto& resource_1s = registry.get<resource_1>();
  auto& resource_2s = registry.get<resource_2>();
  auto& resource_3s = registry.get<resource_3>();
}
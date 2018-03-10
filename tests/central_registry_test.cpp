#include "catch.hpp"

#include <cstddef>

#include <ra/central_registry.hpp>

struct resource_1 { std::size_t value; };
struct resource_2 { std::size_t value; };
struct resource_3 { std::size_t value; };

TEST_CASE("Registry is tested.", "[registry]") 
{
  auto& instance      = ra::central_registry<resource_1, resource_2, resource_3>::instance();
  auto& resource_1s   = instance.get<resource_1>();
  auto& resource_2s   = instance.get<resource_2>();
  auto& resource_3s   = instance.get<resource_3>();
  
  auto& instance_2    = ra::central_registry<resource_1, resource_2, resource_3>::instance();
  auto& resource_1s_2 = instance_2.get<resource_1>();
  auto& resource_2s_2 = instance_2.get<resource_2>();
  auto& resource_3s_2 = instance_2.get<resource_3>();

  REQUIRE(&resource_1s == &resource_1s_2);
  REQUIRE(&resource_2s == &resource_2s_2);
  REQUIRE(&resource_3s == &resource_3s_2);
}
#ifndef RA_CENTRAL_REGISTRY_HPP_
#define RA_CENTRAL_REGISTRY_HPP_

#include <ra/registry.hpp>
#include <ra/singleton.hpp>

namespace ra
{
template<typename... types>
class central_registry : public registry<types...>, public singleton<central_registry<types...>>
{
public:
  virtual ~central_registry() = default;
};
}

#endif

#ifndef RA_LOAD_HPP_
#define RA_LOAD_HPP_

#include <type_traits>

namespace ra
{
template <typename description_type, typename resource_type>
struct missing_load_implementation : std::false_type { };

template<typename description_type, typename resource_type>
void load(const description_type& description, resource_type* resource)
{
  static_assert(missing_load_implementation<description_type, resource_type>::value, "Missing load implementation for description - resource pair.");
}
}

#endif

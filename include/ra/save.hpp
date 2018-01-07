#ifndef RA_SAVE_HPP_
#define RA_SAVE_HPP_

#include <type_traits>

namespace ra
{
template <typename description_type, typename resource_type>
struct missing_save_implementation : std::false_type { };

template<typename description_type, typename resource_type>
void save(const description_type& description, resource_type* resource)
{
  static_assert(missing_save_implementation<description_type, resource_type>::value, "Missing save implementation for description - resource pair.");
}
}

#endif

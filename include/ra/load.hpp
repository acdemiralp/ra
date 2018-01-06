#ifndef RA_LOAD_HPP_
#define RA_LOAD_HPP_

#include <type_traits>

namespace ra
{
template <typename description_type, typename resource_type>
struct missing_load_implementation : std::false_type { };

// The load(er) is just a stateless function which accepts a resource description and sets a resource accordingly.
// Example implementation:
// template<> 
// void load(const image_description& description, image* image)
// {
//   image->set_pixel_data(FreeImage_Load(description.format, description.filename, description.flags));
// }
template<typename description_type, typename resource_type>
void load(const description_type& description, resource_type* resource)
{
  static_assert(missing_load_implementation<description_type, resource_type>::value, "Missing load implementation for description - resource pair.");
}
}

#endif

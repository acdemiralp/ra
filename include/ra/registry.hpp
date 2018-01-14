#ifndef RA_REGISTRY_HPP_
#define RA_REGISTRY_HPP_

#include <cstddef>
#include <tuple>
#include <type_traits>

#include <ra/container.hpp>

namespace ra
{
template<typename... types>
class registry
{
public:
  virtual ~registry() = default;

  template<typename type>
  const container<type>& get() const
  {
    return find<0, type, std::tuple<container<types>...>, is_same<0, type>::value>::get(containers_);
  }
  template<typename type>
  container<type>&       get()
  {
    return find<0, type, std::tuple<container<types>...>, is_same<0, type>::value>::get(containers_);
  }
  
protected:
  template<std::size_t index, typename type>
  struct is_same : std::is_same<type, typename std::tuple_element<index, std::tuple<container<types>...>>::type::value_type>
  {
    
  };
  template<std::size_t index, typename type, typename tuple, bool match = false>
  struct find
  {
    static container<type>& get(tuple& value)
    {
      return find<index + 1, type, tuple, is_same<index + 1, type>::value>::get(value);
    }
  };
  template<std::size_t index, typename type, typename tuple>
  struct find<index, type, tuple, true>
  {
    static container<type>& get(tuple& value)
    {
      return std::get<index>(value);
    }
  };
  
  std::tuple<container<types>...> containers_;
};
}

#endif

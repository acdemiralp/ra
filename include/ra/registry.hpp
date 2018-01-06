#ifndef RA_REGISTRY_HPP_
#define RA_REGISTRY_HPP_

#include <tuple>
#include <type_traits>
#include <vector>

namespace ra
{
template<typename... types>
class registry final
{
public:
  template<typename type>
  const std::vector<type>& access()
  {
    return matching_vector<0, type, std::tuple<std::vector<types>...>, vector_of_type<0, type>::value>::get(vectors_);
  }
  void                     resize(std::size_t size)
  {
    for_each(vectors_, [size] (auto& vector)
    {
      vector.resize(size);
    });
  }

private:
  template<std::size_t index, typename type>
  struct vector_of_type : std::is_same<type, typename std::tuple_element<index, std::tuple<std::vector<types>...>>::type::value_type>
  {
    
  };
  template<std::size_t index, typename type, typename tuple, bool match = false>
  struct matching_vector
  {
    static std::vector<type>& get(tuple& value)
    {
      return matching_vector<index + 1, type, tuple, vector_of_type<index + 1, type>::value>::get(value);
    }
  };
  template<std::size_t index, typename type, typename tuple>
  struct matching_vector<index, type, tuple, true>
  {
    static std::vector<type>& get(tuple& value)
    {
      return std::get<index>(value);
    }
  };
  
  template<std::size_t index = 0, typename function_type, typename... tuple_types>
  typename std::enable_if<index == sizeof...(tuple_types), void>::type for_each(std::tuple<tuple_types...>&      , function_type) { }
  template<std::size_t index = 0, typename function_type, typename... tuple_types>
  typename std::enable_if<index <  sizeof...(tuple_types), void>::type for_each(std::tuple<tuple_types...>& tuple, function_type function)
  {
    function(std::get<index>(tuple));
    for_each<index + 1, function_type, tuple_types...>(tuple, function);
  }

  std::tuple<std::vector<types>...> vectors_;
};
}

#endif

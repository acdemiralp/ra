#ifndef RA_CONTAINER_HPP_
#define RA_CONTAINER_HPP_

#include <algorithm>
#include <cstddef>
#include <vector>

#include <foonathan/memory/memory_pool.hpp>
#include <foonathan/memory/namespace_alias.hpp>
#include <foonathan/memory/std_allocator.hpp>

namespace ra
{
template<typename type, std::size_t block_size = 4096>
class container
{
public:
  using value_type     = type;
  using allocator_type = memory::memory_pool<>;
  using storage_type   = std::vector<value_type, memory::std_allocator<value_type, allocator_type>>;
  using iterator       = typename storage_type::iterator;
  using const_iterator = typename storage_type::const_iterator;
  
  iterator       begin       ()
  {
    return storage_.begin();
  }
  const_iterator begin       () const
  {
    return storage_.begin();
  }
  iterator       end         ()
  {
    return storage_.end  ();
  }
  const_iterator end         () const
  {
    return storage_.end  ();
  }
  iterator       rbegin      ()
  {
    return storage_.rbegin();
  }
  const_iterator rbegin      () const
  {
    return storage_.rbegin();
  }
  iterator       rend        ()
  {
    return storage_.rend  ();
  }
  const_iterator rend        () const
  {
    return storage_.rend  ();
  }
  const_iterator cbegin      () const
  {
    return storage_.cbegin();
  }
  const_iterator cend        () const
  {
    return storage_.cend  ();
  }
  const_iterator crbegin     () const
  {
    return storage_.crbegin();
  }
  const_iterator crend       () const
  {
    return storage_.crend  ();
  }
                             
  std::size_t    size        () const
  {
    return storage_.size();
  }
  std::size_t    max_size    () const
  {
    return storage_.max_size();
  }
  bool           empty       () const
  {
    return storage_.empty();
  }

  template<typename... argument_types>
  type*          emplace_back(argument_types&&... arguments)
  {
    storage_.emplace_back(arguments...);
    return &storage_.back();
  }
  void           erase_remove(const type*         object   )
  {
    storage_.erase(std::remove_if(begin(), end(), [&object] (const type& iteratee) { return object == &iteratee; }));
  }
  void           clear       ()
  {
    storage_.clear();
  }

  const type*    data        () const
  {
    return storage_.data();
  }
  type*          data        ()
  {
    return storage_.data();
  }

protected:
  allocator_type allocator_ = allocator_type(sizeof type, block_size);
  storage_type   storage_   = storage_type  (allocator_);
};
}

#endif

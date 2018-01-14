#ifndef RA_CONTAINER_HPP_
#define RA_CONTAINER_HPP_

#include <vector>

#include <foonathan/memory/memory_pool.hpp>
#include <foonathan/memory/namespace_alias.hpp>
#include <foonathan/memory/std_allocator.hpp>

namespace ra
{
template<
  typename    type           , 
  std::size_t block_size     = 4096, 
  typename    allocator_type = memory::memory_pool<>, 
  typename    storage_type   = std::vector<type, memory::std_allocator<type, allocator_type>>>
class container
{
public:
  using value_type = type;

  const allocator_type& allocator() const
  {
    return allocator_;
  }
  const storage_type&   storage  () const
  {
    return storage_;
  }
  storage_type&         storage  ()
  {
    return storage_;
  }

protected:
  allocator_type allocator_ = allocator_type(sizeof(type) + alignof(type), block_size);
  storage_type   storage_   = storage_type  (allocator_);
};
}

#endif

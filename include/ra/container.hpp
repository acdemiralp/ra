#ifndef RA_CONTAINER_HPP_
#define RA_CONTAINER_HPP_

#include <foonathan/memory/container.hpp>
#include <foonathan/memory/memory_pool.hpp>
#include <foonathan/memory/namespace_alias.hpp>

namespace ra
{
template<typename type, std::size_t block_size = 4096>
class container
{
public:
  

protected:
  memory::memory_pool<>                       pool_   = memory::memory_pool<>(sizeof type, block_size);
  memory::vector<type, memory::memory_pool<>> vector_ = memory::vector<type, memory::memory_pool<>>(pool_);
};
}

#endif

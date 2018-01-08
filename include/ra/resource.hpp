#ifndef RA_RESOURCE_HPP_
#define RA_RESOURCE_HPP_

#include <ra/load.hpp>
#include <ra/save.hpp>

namespace ra
{
// Optionally derive from this class to obtain load/save functionality.
template<typename derived>
class resource
{
public:
  resource           (const resource&  that) = default;
  resource           (      resource&& temp) = default;
  virtual ~resource  ()                      = default;
  resource& operator=(const resource&  that) = default;
  resource& operator=(      resource&& temp) = default;

  template<typename description_type>
  void load  (const description_type& description)
  {
    ra::load(description, static_cast<      derived*>(this));
  }
  template<typename description_type>
  void save  (const description_type& description) const
  {
    ra::save(description, static_cast<const derived*>(this));
  }

protected:
  resource() = default;
};
}

#endif

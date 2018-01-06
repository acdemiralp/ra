#ifndef RA_ASPECTS_NAMED_HPP_
#define RA_ASPECTS_NAMED_HPP_

#include <string>

namespace mak
{
class named
{
public:
  explicit named  (const std::string& name = "") : name_(name)
  {
    
  }
  named           (const named&  that) = default;
  named           (      named&& temp) = default;
  virtual ~named  ()                   = default;
  named& operator=(const named&  that) = default;
  named& operator=(      named&& temp) = default;

  void               set_name(const std::string& name)
  {
    name_ = name;
  }
  const std::string& name    () const
  {
    return name_;
  }
  
protected:
  std::string name_;
};
}

#endif
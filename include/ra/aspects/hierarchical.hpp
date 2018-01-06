#ifndef RA_ASPECTS_HIERARCHICAL_HPP_
#define RA_ASPECTS_HIERARCHICAL_HPP_

#include <algorithm>
#include <cstddef>
#include <vector>

namespace mak
{
template<class derived>
class hierarchical
{
public:
  virtual ~hierarchical() = default;

  void           set_parent     (derived* parent)
  {
    if (parent_ != nullptr)
      parent_->children_.erase(std::remove(parent_->children_.begin(), parent_->children_.end(), static_cast<derived*>(this)), parent_->children_.end());
    parent_ = parent;
    if (parent_ != nullptr)
      parent_->children_.push_back(static_cast<derived*>(this));
  }
  const derived* get_parent     ()                        const
  {
    return parent_;
  }
  derived*       get_parent     ()
  {
    return parent_;
  }
  const derived* get_child      (const std::size_t index) const
  {
    return index < children_.size() ? children_[index] : nullptr;
  }
  derived*       get_child      (const std::size_t index)
  {
    return index < children_.size() ? children_[index] : nullptr;
  }
  std::size_t    get_child_count()                        const
  {
    return children_.size();
  }

protected:
  derived*              parent_  = nullptr;
  std::vector<derived*> children_;
};
}

#endif
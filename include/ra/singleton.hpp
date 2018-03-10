#ifndef RA_SINGLETON_HPP_
#define RA_SINGLETON_HPP_

#include <memory>
#include <mutex>

namespace ra
{
template<typename type>
class singleton
{
public:
  template <typename... arguments>
  static type& instance(arguments&&... args)
  {
    std::call_once(get_once_flag(), [](arguments&&... args)
    {
      instance_.reset(new type(std::forward<arguments>(args)...));
    }, std::forward<arguments>(args)...);
    return *instance_.get();
  }

protected:
  explicit singleton  ()                       = default;
  singleton           (const singleton&  that) = delete ;
  singleton           (      singleton&& temp) = default;
  virtual ~singleton  ()                       = default;
  singleton& operator=(const singleton&  that) = delete ;
  singleton& operator=(      singleton&& temp) = default;

private:
  static std::once_flag& get_once_flag()
  {
    static std::once_flag once;
    return once;
  }

  static std::unique_ptr<type> instance_;
};
template<class type>
std::unique_ptr<type> singleton<type>::instance_ = nullptr;
}

#endif

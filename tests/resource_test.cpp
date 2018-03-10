#include "catch.hpp"

#include <fstream>
#include <streambuf>
#include <string>

#include <ra/resource.hpp>

class text_resource : public ra::resource<text_resource>
{
public:
  struct description
  {
    std::string filename;
  };
  std::string text;
};

template <>
void ra::load(const text_resource::description& description,       text_resource* resource)
{
  std::ifstream stream(description.filename);
  resource->text = std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
}

template <>
void ra::save(const text_resource::description& description, const text_resource* resource)
{
  std::ofstream stream(description.filename);
  stream << resource->text;
  stream.close();
}

TEST_CASE("Resource is tested.", "[resource]") 
{
  text_resource resource;
  resource.text = "test contents";
  resource.save(text_resource::description{"test.txt"});
  resource.text = "";
  resource.load(text_resource::description{"test.txt"});
  REQUIRE(resource.text == "test contents");
}
#include "catch.hpp"

#include <fstream>
#include <streambuf>
#include <string>

#include <ra/save.hpp>

class text_resource
{
public:
  struct description
  {
    std::string filename;
  };
  std::string text;
};

template <>
void ra::save(const text_resource::description& description, const text_resource* resource)
{
  std::ofstream stream(description.filename);
  stream << resource->text;
  stream.close();
}

TEST_CASE("Resource saving is tested.", "[save]") 
{
  text_resource::description description {"test.txt"     };
  text_resource              resource    {"test contents"};
  ra::save(description, &resource);
  
  std::ifstream input_stream("test.txt");
  auto text = std::string(std::istreambuf_iterator<char>(input_stream), std::istreambuf_iterator<char>());
  REQUIRE(text == "test contents");
}
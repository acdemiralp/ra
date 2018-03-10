#include "catch.hpp"

#include <fstream>
#include <streambuf>
#include <string>

#include <ra/load.hpp>

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
void ra::load(const text_resource::description& description, text_resource* resource)
{
  std::ifstream stream(description.filename);
  resource->text = std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
}

TEST_CASE("Resource loading is tested.", "[load]") 
{
  std::ofstream output_stream("test.txt");
  output_stream << "test contents";
  output_stream.close();

  text_resource::description description {"test.txt"};
  text_resource              resource   ;
  ra::load(description, &resource);
  REQUIRE(resource.text == "test contents");
}
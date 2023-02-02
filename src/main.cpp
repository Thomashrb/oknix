#include <iostream>
#include <string>
#include <variant>

#include "json.hpp"
#include "validator.hpp"

int main(int argc, char **argv)
{
  const std::string     onixpath = "Onix3sample_refnames.xml";  // TODO
  const std::variant<Err, Ok> r        = xmlValidate(onixpath, SCHEMA_PATH);

  if constexpr (std::is_same_v<std::decay_t<decltype(r)>, Err>)
  {
    Err         e       = std::get<Err>(r);
    std::string jstring = jsonEncode(e);
    std::cout << jstring + "\n";
  }
  if constexpr (std::is_same_v<std::decay_t<decltype(r)>, Ok>)
  {
    Ok          ok      = std::get<Ok>(r);
    std::string jstring = jsonEncode(ok);
    std::cout << jstring + "\n";
  }
  return 0;
}

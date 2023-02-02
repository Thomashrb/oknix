#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <string>
#include <variant>

const std::string SCHEMA_PATH = "ONIX_BookProduct_3.0_reference.xsd";

struct Err
{
  int         line;
  int         col;
  int         code;
  std::string file;
  std::string msg;
};
struct Ok
{
};

const std::variant<Err, Ok> xmlValidate(const std::string onix, const std::string schema);

#endif

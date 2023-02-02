#include "json.hpp"

#include <nlohmann/json.hpp>
#include <string>

#include "validator.hpp"

const std::string jsonEncode(const Err err)
{
  nlohmann::json j =
  {
    {"status", "FAILURE"},
    {"file", err.file},
    {"line", err.line},
    {"col", err.col},
    {"error_code", err.code},
    {"message", err.msg},
  };

  return j.dump();
}

const std::string jsonEncode(const Ok ok [[maybe_unused]])
{
  nlohmann::json j =
  {
    {"status", "SUCCESS"}
  };

  return j.dump();
}

#ifndef JSON_HPP
#define JSON_HPP

#include <string>

#include "validator.hpp"

const std::string jsonEncode(const Err err);
const std::string jsonEncode(const Ok ok);

#endif

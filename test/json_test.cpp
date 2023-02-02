#include <catch2/catch_test_macros.hpp>
#include <json.cpp>
#include <string>
#include <validator.hpp>

TEST_CASE("Ok returns known json string")
{
  Ok          result  = Ok{};
  std::string jstring = jsonEncode(result);
  REQUIRE(jstring == R"V0G0N({"status":"SUCCESS"})V0G0N");
}

TEST_CASE("Err returns known json string")
{
  Err result          = Err{};
  result.line         = 42;
  result.col          = 24;
  result.code         = 4242;
  result.file         = "test.xml";
  result.msg          = "test message";
  std::string jstring = jsonEncode(result);

  REQUIRE(jstring == R"V0G0N({"col":24,"error_code":4242,"file":"test.xml","line":42,"message":"test message","status":"FAILURE"})V0G0N");
}

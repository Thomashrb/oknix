#include <strings.h>

#include <iostream>
#include <variant>

#include "json.hpp"
#include "validator.hpp"

void printHelp()
{
  std::cout << "oknix is a command line tool and server for validating ONIX metadata\n";
  std::cout << "\n";
  std::cout << "Usage:\n";
  std::cout << "  oknix --help\n";
  std::cout << "  oknix --file [filepath]\n";
  std::cout << "  oknix --server --host localhost --port 8016\n";
}

int main(int argc, char **argv)
{
  if (argc < 2 || strcasecmp(argv[1], "--help") == 0)
  {
    printHelp();
    return EXIT_SUCCESS;
  }

  if (strcasecmp(argv[1], "--file") == 0)
  {
    const std::variant<Err, Ok> r = xmlValidate(argv[2], SCHEMA_PATH);

    if (std::holds_alternative<Err>(r))
    {
      Err         e       = std::get<Err>(r);
      std::string jstring = jsonEncode(e);
      std::cout << jstring + "\n";
    }
    if (std::holds_alternative<Ok>(r))
    {
      Ok          ok      = std::get<Ok>(r);
      std::string jstring = jsonEncode(ok);
      std::cout << jstring + "\n";
    }

    return EXIT_SUCCESS;
  }

  if (strcasecmp(argv[1], "--server") == 0)
  {
    std::cout << "TODO do the server thing";
    return EXIT_SUCCESS;
  }

  std::cout << "Command not recognized \n\n";
  printHelp();
  return EXIT_FAILURE;
}

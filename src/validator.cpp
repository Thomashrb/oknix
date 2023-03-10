#include "validator.hpp"

#include <libxml2/libxml/encoding.h>
#include <libxml2/libxml/xmlreader.h>
#include <libxml2/libxml/xmlwriter.h>

#include <cstdio>
#include <string>
#include <variant>


static void parseErrorHandler(void *arg, xmlErrorPtr xmlErr [[maybe_unused]]) { *((bool *)arg) = true; }

const std::variant<Err, Ok> xmlValidate(const std::string onixpath, const std::string schemapath)
{
  xmlInitParser();

  auto pctxt  = xmlSchemaNewParserCtxt(schemapath.c_str());
  auto schema = xmlSchemaParse(pctxt);
  auto vctxt  = xmlSchemaNewValidCtxt(schema);
  auto reader = xmlReaderForFile(onixpath.c_str(), nullptr, 0);
  int  is_err = 0;
  xmlSchemaSetValidStructuredErrors(vctxt, parseErrorHandler, &is_err);
  xmlTextReaderSchemaValidateCtxt(reader, vctxt, 0);
  int                   iter = xmlTextReaderRead(reader);
  std::variant<Err, Ok> ret;

  while (iter == 1 && !is_err)
  {
    iter = xmlTextReaderRead(reader);
  }

  if (iter != 0)
  {
    xmlErrorPtr xmlErr = xmlGetLastError();

    Err err;
    err.line = xmlErr->line;
    err.col  = xmlErr->int2;
    err.code = xmlErr->code;
    err.file = xmlErr->file;
    err.msg  = xmlErr->message;

    ret = err;
  }
  else
  {
    ret = Ok{};
  }

  xmlFreeTextReader(reader);
  xmlCleanupParser();
  return ret;
}

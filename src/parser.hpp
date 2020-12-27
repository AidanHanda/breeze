#ifndef SRC_PARSER_HPP
#define SRC_PARSER_HPP

#include <string>

/**
 * This file contains the Parser and ParserResult class which work
 * in tandem to respond to language requests made by a user.
 */

struct ParserResult {
  bool success;
  std::string result;
};

class Parser {
private:
  const std::string query_string;
public:
  Parser(const std::string& query_string);
  ParserResult perform_action();
private:
  bool is_valid_query();
};


#endif /* SRC_PARSER_HPP */

#include "parser.hpp"

Parser::Parser(const std::string &query_string) : query_string(query_string) {
  
}

bool Parser::is_valid_query() {
  return false;
}

ParserResult Parser::perform_action() { return ParserResult{true, "None"}; }




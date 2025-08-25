#ifndef LEXER_HPP
#define LEXER_HPP

#include "Token.hpp"
#include <string>
class Lexer
{
  public:
    Lexer(const char* source);
    Lexer(std::string_view source);
    void nextChar();
    char peek();
    void abort(const char* message);
    void skipWhitespace();
    void skipComment();
    Token getToken();

    std::string m_source{};
    char m_curChar{};
    int m_curPos{};
};
#endif

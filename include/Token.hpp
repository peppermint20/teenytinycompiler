#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include <string_view>

enum class TokenType
{
    END_OF_FILE = -1,
    NEWLINE = 0,
    NUMBER = 1,
    IDENT = 2,
    STRING = 3,
    // Keywords.
    LABEL = 101,
    GOTO = 102,
    PRINT = 103,
    INPUT = 104,
    LET = 105,
    IF = 106,
    THEN = 107,
    ENDIF = 108,
    WHILE = 109,
    REPEAT = 110,
    ENDWHILE = 111,
    // Operators.
    EQ = 201,
    PLUS = 202,
    MINUS = 203,
    ASTERISK = 204,
    SLASH = 205,
    EQEQ = 206,
    NOTEQ = 207,
    LT = 208,
    LTEQ = 209,
    GT = 210,
    GTEQ = 211,
};

class Token
{
  public:
    Token(char text, TokenType kind);
    Token(Token&& token);
    Token();
    Token& operator=(Token&& token);

  public:
    std::string m_text{};
    TokenType m_kind{};

    friend std::ostream& operator<<(std::ostream& out, const Token& token);

  private:
};

#endif

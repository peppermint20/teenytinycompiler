#include "Lexer.hpp"
#include "Token.hpp"
#include <iostream>

std::string source;

auto main(int argc, char* argv[]) -> int
{
    if (argc > 1)
    {
        source = argv[1];
    }
    else
    {
        source = "+- /*";
    }
    Lexer lexer = Lexer(source);
    Token token = lexer.getToken();
    std::cout << lexer.m_source << '\n';
    int index = 0;
    while (token.m_kind != TokenType::END_OF_FILE)
    {
        // std::cout << "ITERATION: " << index++ << '\n';
        // std::cout << "CUR_POS: " << lexer.m_curPos << '\n';
        std::cout << token << '\n';
        token = lexer.getToken();
    }
    return 0;
}

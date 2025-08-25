#include "Lexer.hpp"
#include <format>
#include <print>

Lexer::Lexer(const char* source)
    : m_source{std::string(source)}, m_curChar{}, m_curPos{-1}

{
    std::cout << "Size: " << m_source.size() << '\n';
    nextChar();
}

Lexer::Lexer(std::string_view source)
    : m_source{std::string(source)}, m_curChar{}, m_curPos{-1}
{

    std::cout << "Size: " << m_source.size() << '\n';
    nextChar();
}

void Lexer::nextChar()
{
    m_curPos += 1;
    if (m_curPos >= m_source.size())
    {
        m_curChar = '\0';
    }
    else
    {
        m_curChar = m_source[m_curPos];
    }
}

char Lexer::peek()
{
    if (m_curPos + 1 >= m_source.size())
    {
        return '\0';
    }
    return m_source[m_curPos + 1];
}

Token Lexer::getToken()
{
    skipWhitespace();
    Token token{};
    if (m_curChar == '+')
    {
        token = Token(m_curChar, TokenType::PLUS);
    }
    else if (m_curChar == '-')
    {
        token = Token(m_curChar, TokenType::MINUS);
    }
    else if (m_curChar == '*')
    {
        token = Token(m_curChar, TokenType::ASTERISK);
    }
    else if (m_curChar == '/')
    {
        token = Token(m_curChar, TokenType::SLASH);
    }
    else if (m_curChar == '\n')
    {
        token = Token(m_curChar, TokenType::NEWLINE);
    }
    else if (m_curChar == '\0')
    {
        token = Token(m_curChar, TokenType::END_OF_FILE);
    }
    else if (m_curChar == '=')
    {
        // == operator
        if (peek() == '=')
        {
            char lastChar = m_curChar;
            nextChar();
            token = Token(lastChar + m_curChar, TokenType::GTEQ);
        }
        else
        {
            token = Token(m_curChar, TokenType::EQ);
        }
    }
    else
    {
        abort(std::format("Token Unimplemented:{}", m_curChar).c_str());
    }

    nextChar();
    return token;
}

void Lexer::abort(const char* message)
{
    std::print(stdout, "{}, exiting program", message);
    std::exit(1);
}

void Lexer::skipWhitespace()
{
    while (m_curChar == ' ' || m_curChar == '\t' || m_curChar == '\r')
        nextChar();
}

void Lexer::skipComment() {}

#include "Token.hpp"

Token::Token() : m_text{""}, m_kind{} {}
Token::Token(char text, TokenType kind) : m_text{text}, m_kind{kind} {}

Token::Token(Token&& token)
    : m_text{std::move(token.m_text)}, m_kind{std::move(token.m_kind)}
{
}

Token& Token::operator=(Token&& token)
{
    m_kind = std::move(token.m_kind);
    m_text = std::move(token.m_text);
    return *this;
}
// Helper functions
std::ostream& operator<<(std::ostream& out, const Token& token)
{
    switch (token.m_kind)
    {
        // clang-format off
        case TokenType::END_OF_FILE: {out << "TokenType::END_OF_FILE";} break;
        case TokenType::NEWLINE:{out << "TokenType::NEWLINE";} break;
        case TokenType::NUMBER:{out << "TokenType::NUMBER";} break;
        case TokenType::IDENT:{out << "TokenType::IDENT";} break;
        case TokenType::STRING:{out << "TokenType::STRING";} break;
        case TokenType::LABEL:{out << "TokenType::LABEL";} break;
        case TokenType::GOTO:{out << "TokenType::GOTO";} break;
        case TokenType::PRINT:{out << "TokenType::PRINT";} break;
        case TokenType::INPUT:{out << "TokenType::INPUT";} break;
        case TokenType::LET:{out << "TokenType::LET";} break;
        case TokenType::IF:{out << "TokenType::IF";} break;
        case TokenType::THEN:{out << "TokenType::THEN";} break;
        case TokenType::ENDIF:{out << "TokenType::ENDIF";} break;
        case TokenType::WHILE:{out << "TokenType::WHILE";} break;
        case TokenType::REPEAT:{out << "TokenType::REPEAT";} break;
        case TokenType::ENDWHILE:{out << "TokenType::ENDWHILE";} break;
        case TokenType::EQ:{out << "TokenType::EQ";} break;
        case TokenType::PLUS:{out << "TokenType::PLUS";} break;
        case TokenType::MINUS:{out << "TokenType::MINUS";} break;
        case TokenType::ASTERISK:{out << "TokenType::ASTERISK";} break;
        case TokenType::SLASH:{out << "TokenType::SLASH";} break;
        case TokenType::EQEQ:{out << "TokenType::EQEQ";} break;
        case TokenType::NOTEQ:{out << "TokenType::NOTEQ";} break;
        case TokenType::LT:{out << "TokenType::LT";} break;
        case TokenType::LTEQ:{out << "TokenType::LTEQ";} break;
        case TokenType::GT:{out << "TokenType::GT";} break;
        case TokenType::GTEQ:{out << "TokenType::GTEQ";} break;

    }
    return out;
}

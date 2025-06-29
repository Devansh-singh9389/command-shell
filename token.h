#ifndef TOKEN_H
#define TOKEN_H

#include<string>
using namespace std;

enum class TokenType {
    IDENTIFIER,
    ASSIGN,       // '='
    PLUS,         // '+'
    MINUS,        // '-'
    NUMBER,       // literals like '10'
    SEMICOLON,    // ';'
    PRINT,
    END_OF_FILE,
    UNKNOWN
};

struct Token {
    TokenType type;
    string value;
    // it is just like cunstructors in c++
    Token(TokenType type, const std::string& value)
    : type(type), value(value) {}// type in effective way
};
#endif
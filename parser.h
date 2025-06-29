#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <map>
#include <string>
#include "lexer.h"
#include "token.h"
using namespace std;

class Parser {
public:
    Parser(Lexer& lexer);
    void parse();

private:
    Token currentToken;
    Lexer& lexer;
    map<string, int> variables;

    void advance();
    void match(TokenType type);
    void statement();
    int expression();
    int term();
};

#endif
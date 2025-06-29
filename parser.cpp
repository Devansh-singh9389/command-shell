#include "parser.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Parser::Parser(Lexer& lexer) : currentToken(TokenType::END_OF_FILE, ""), lexer(lexer) {
    advance();
}
void Parser::advance() {
    currentToken = lexer.getNextToken();
}

void Parser::match(TokenType type) {
    if (currentToken.type == type) advance();
    else throw runtime_error("Unexpected token: " + currentToken.value);
}

void Parser::parse() {
    if (currentToken.type != TokenType::END_OF_FILE) {
        statement();
    }
}

void Parser::statement() {
    if (currentToken.type == TokenType::IDENTIFIER) {
        string varname = currentToken.value;
        advance();
        match(TokenType::ASSIGN);
        int value = expression();
        variables[varname] = value;
        match(TokenType::SEMICOLON);
    } else if (currentToken.type == TokenType::PRINT) {
        advance();
        string varname = currentToken.value;
        match(TokenType::IDENTIFIER);
        match(TokenType::SEMICOLON);
        if (variables.count(varname)) {
            cout << varname << " = " << variables[varname] << endl;
        } else {
            cerr << "Error: undefined variable " << varname << endl;
        }
    } else {
        throw runtime_error("Unknown statement start: " + currentToken.value);
    }
}

int Parser::expression() {
    int result = term();
    while (currentToken.type == TokenType::PLUS || currentToken.type == TokenType::MINUS) {
        if (currentToken.type == TokenType::PLUS) {
            advance();
            result += term();
        } else if (currentToken.type == TokenType::MINUS) {
            advance();
            result -= term();
        }
    }
    return result;
}

int Parser::term() {
    if (currentToken.type == TokenType::NUMBER) {
        int value = std::stoi(currentToken.value);
        advance();
        return value;
    } else if (currentToken.type == TokenType::IDENTIFIER) {
        std::string var = currentToken.value;
        advance();
        if (variables.count(var)) return variables[var];
        else throw std::runtime_error("Undefined variable: " + var);
    }
    throw std::runtime_error("Expected number or variable, got: " + currentToken.value);
}

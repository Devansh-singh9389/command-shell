#include "lexer.h"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("example.txt");
    std::string input((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    Lexer Lexer(input);

    Token token = Lexer.getNextToken();
    while (token.type != TokenType::END_OF_FILE) {
        std::cout << "Token: " << token.value << "\n";
        token = Lexer.getNextToken();
    }

    return 0;
}

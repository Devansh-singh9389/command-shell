#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "token.h"

using namespace std;



 class Lexer {
    public:
        Lexer(const string& input);
        Token getNextToken();
    
        private:
            string input;
            size_t pos; //size_t is an unsigned integer type
            char peek();
            char advance();//Has () — means it's a method that does something.
            void skipWhitespace();
            Token identifier();
            Token number();
 };

 #endif
#include "lexer.h"
#include <cctype>
using namespace std;
Lexer::Lexer(const string& input) : input(input), pos(0) {}


//pos is the intex on which we are working on string




//this is use to return current char or token
char Lexer::peek() {
    return pos < input.size() ? input[pos] : '\0';
}

    //.Returns the current character we're looking at in the string.
    //.If we're at the end of the string, it returns '\0' (null character) to say "nothing left".


//this is use to move foerward on string
char Lexer::advance() {
    return pos < input.size() ? input[pos++] : '\0';
}


//this is use to skip spaces,tabs,newlines etc
void Lexer :: skipWhitespace(){
    while (std::isspace(peek())) advance();
}

// this return Token
Token Lexer :: identifier(){
    string result;
    // isalnum(n) return true untill n is digit or letter like not = or , - + etc 
    while (isalnum(peek()))result += advance();
    if (result == "print") return Token(TokenType::PRINT, result);
    return Token(TokenType::IDENTIFIER, result);
}

Token Lexer :: number(){
    string result;
    while (isdigit(peek()))
    {
        result += advance();
    }
    return Token(TokenType :: NUMBER,result);
}


Token Lexer :: getNextToken(){
    skipWhitespace();
    char current = peek();


    if (std::isalpha(current)) return identifier();  // check if it's a word
    if (std::isdigit(current)) return number();      // check if it's a number


    switch (current)
    {
        case '=': advance(); return Token(TokenType::ASSIGN, "=");
        case '+': advance(); return Token(TokenType::PLUS, "+");
        case '-': advance(); return Token(TokenType::MINUS, "-");
        case ';': advance(); return Token(TokenType::SEMICOLON, ";");
        case '\0': advance(); return Token(TokenType::END_OF_FILE, "");
        
        default: advance(); return Token(TokenType::UNKNOWN, std::string(1, current));
    }
}

// Step | What It Sees | Function Called | Returns Token
// 1    | x            | identifier()    | IDENTIFIER("x")
// 2    | =            | switch case     | ASSIGN("=")
// 3    | 10           | number()        | NUMBER("10")
// 4    | +            | switch case     | PLUS("+")
// 5    | 20           | number()        | NUMBER("20")
// 6    | ;            | switch case     | SEMICOLON(";")
// 7    | End          | —               | END_OF_FILE
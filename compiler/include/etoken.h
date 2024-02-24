#ifndef ETOKEN_H
#define ETOKEN_H

#define ECTER_COMPILER

#include <cstddef>
#include <iostream>
#include <regex>
#include <cstring>
#include <unordered_set>
#include <string>

enum TokenType {
    NumericLiteral,
    TextLiteral,
    Separator,
    Operator,
    Identifier,
    Keyword,
    EOL,
    Newline,
    RParenth,
    RBracket,
    LBracket,
    LParenth,
    Comment,
    None
};

class Token {
    public:
        Token(TokenType t, const char* v) : type(t), value(strdup(v)) {}
        TokenType type;
        char* value;
        ~Token() {
            free(value);
        }
};

int isKeyword(const char* word) {
    static const std::unordered_set<std::string> keywords = {
        "if", "else", "while", "else if", "accesible", "internal", "static", "const"
    };
    return keywords.find(word) != keywords.end();
}

class Tokenizer {
    private:
        std::string input;
        size_t position;

    public:
        Tokenizer(const std::string& input) : input(input), position(0) {}
        ~Tokenizer() {}
        char currentChar();
        void advance();
        void skipWhitespace();
        Token* extractNumericLiteral();
        Token* extractTextLiteral();
        Token* extractOperator();
        Token* extractKeywordOrIdentifier();
        Token* getNextToken();
};

#endif

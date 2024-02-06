#ifndef ETOKEN_H
#define ETOKEN_H

#define ECTER_COMPILER

#include "eerror.h"
#include <cstddef>
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
        Token(TokenType t, const char* v) : type(t) {
            TokenType type;
            char* value;
        }

        TokenType type;
        char* value;

        ~Token() {
            free(value);
        }
};

int isKeyword(const char* word);

class Tokenizer {
    private:
        char* input;
        size_t position;

    public:
        Tokenizer(const char* input);
        ~Tokenizer();
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

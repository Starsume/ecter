#include <cstring>
#include <cstdlib>
#include <string>

#ifndef ETOKEN_H
#define ETOKEN_H

#define ECTER_COMPILER

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

const char* keywords[11] = {
    "class",
    "accesible",
    "abstract",
    "while",
    "if",
    "for",
    "internal",
    "function",
    "return",
    "import",
    "const"
};

typedef struct Token {
    enum TokenType type;
    char* value;
} Token;

char* strndup(const char* str, size_t n) {
    char* copy = (char*)malloc(n + 1);
    if (copy != NULL) {
        strncpy(copy, str, n);
        copy[n] = '\0';
    }
    return copy;
}

int isKeyword(const char* word) {
    for (int i=0;i<11;i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    
    return 0;
}

Token* createToken(enum TokenType type, const char* value);
void destroyToken(Token* token);

typedef struct Tokenizer Tokenizer;

Tokenizer* createTokenizer(const char* input);
void destroyTokenizer(Tokenizer* tokenizer);
Token* getNextToken(Tokenizer* tokenizer);

int tokenM(const char* inputy, Token*** tokenlist);

#endif
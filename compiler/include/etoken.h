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

struct Token {
    enum TokenType type;
    char* value;
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

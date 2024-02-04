#define ECTER_COMPILER

#include "etoken.h"
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cctype>

Token::Token(TokenType type, const char* value) {
    this->type = type;
    this->value = strdup(value);
}

Token::~Token() {
    free(value);
}

int isKeyword(const char* word) {
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
        "const",
        "static"
    };

    for (int i = 0; i < 11; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

Tokenizer::Tokenizer(const char* input) {
    this->input = strdup(input);
    position = 0;
}

Tokenizer::~Tokenizer() {
    free(input);
}

char Tokenizer::currentChar() {
    if (input[position] != '\0') {
        return input[position];
    } else {
        return '\0';
    }
}

void Tokenizer::advance() {
    position++;
}

void Tokenizer::skipWhitespace() {
    while (isspace(currentChar())) {
        advance();
    }
}

Token* Tokenizer::extractNumericLiteral() {
    char num[50];
    size_t index = 0;
    while (isdigit(currentChar())) {
        num[index++] = currentChar();
        advance();
    }
    num[index] = '\0';
    return new Token(NumericLiteral, num);
}

Token* Tokenizer::extractTextLiteral() {
    char text[100];
    size_t index = 0;
    advance();
    while (currentChar() != '"' && currentChar() != '\0') {
        text[index++] = currentChar();
        advance();
    }
    text[index] = '\0';
    advance();
    return new Token(TextLiteral, text);
}

Token* Tokenizer::extractOperator() {
    char op[2] = {currentChar(), '\0'};
    advance();
    return new Token(Operator, op);
}

Token* Tokenizer::extractKeywordOrIdentifier() {
    size_t index = position;
    while (isalnum(currentChar()) || currentChar() == '_') {
        advance();
    }
    char* word = strndup(input + index, position - index);
    TokenType type = isKeyword(word) ? Keyword : Identifier;
    return new Token(type, word);
}

Token* Tokenizer::getNextToken() {
    while (currentChar() != '\0') {
        if (isspace(currentChar())) {
            if (currentChar() == '\n') {
                advance();
                return new Token(Newline, "\n");
            }
            skipWhitespace();
            continue;
        }

        if (isdigit(currentChar())) {
            return extractNumericLiteral();
        }

        if (currentChar() == '"') {
            return extractTextLiteral();
        }

        if (currentChar() == '.') {
            advance();
            return new Token(Separator, ".");
        }

        if (currentChar() == ')') {
            advance();
            return new Token(RParenth, ")");
        }

        if (currentChar() == '}') {
            advance();
            return new Token(RBracket, "}");
        }

        if (currentChar() == '(') {
            advance();
            return new Token(LParenth, "(");
        }

        if (currentChar() == '{') {
            advance();
            return new Token(LBracket, "{");
        }

        if (currentChar() == '+' || currentChar() == '-' || currentChar() == '=' || currentChar() == '*' || currentChar() == '/') {
            return extractOperator();
        }

        if (isalpha(currentChar()) || currentChar() == '_') {
            return extractKeywordOrIdentifier();
        }

        advance();
        return new Token(None, "");
    }

    if (currentChar() == '\0') {
        return new Token(EOL, "");
    }

    return new Token(None, "");
}

std::vector<Token*> tokenM(const std::string code) {
    std::vector<Token*> tokens;

    Tokenizer tokenizer(code);

    Token* token;
    while((token = tokenizer.getNextToken()) != nullptr) {
        tokens.push_back(token);
    }

    return tokens;
}
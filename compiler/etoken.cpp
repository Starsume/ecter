#define ECTER_COMPILER

#include "compiler/etoken.h"
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cctype>
#include <iostream>

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
    char* word = new char[position - index + 1];
    strncpy(word, input + index, position - index);
    word[position - index] = '\0';
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

    Tokenizer tokenizer(code.c_str());

    Token* token;
    while((token = tokenizer.getNextToken()) != nullptr) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    std::string code = "int ut = 10";
    std::vector<Token*> tokens = tokenM(code);

    for (Token* token : tokens) {
        std::cout << token->getValue() << " ";
    }
    std::cout << std::endl;

    for (Token* token : tokens) {
        delete token;
    }
    
    return 0;
}

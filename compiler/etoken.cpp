#define ECTER_COMPILER

#include "include/etoken.h"
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cctype>
#include <iostream>
#include <regex>

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
    std::regex numericRegex("[0-9]+");
    std::smatch match;
    std::string num;

    while (std::regex_search(input + position, match, numericRegex)) {
        num = match.str();
        position += num.length();
        return new Token(NumericLiteral, num.c_str());
    }

    return nullptr;
}

Token* Tokenizer::extractTextLiteral() {
    advance();
    std::string text;
    while (currentChar() != '"' && currentChar() != '\0') {
        text += currentChar();
        advance();
    }
    advance();
    return new Token(TextLiteral, text.c_str());
}

Token* Tokenizer::extractOperator() {
    char op[2] = {currentChar(), '\0'};
    advance();
    return new Token(Operator, op);
}

Token* Tokenizer::extractKeywordOrIdentifier() {
    std::regex wordRegex("[a-zA-Z_][a-zA-Z0-9_]*");
    std::smatch match;
    std::string word;

    if (std::regex_search(input + position, match, wordRegex)) {
        word = match.str();
        position += word.length();
        TokenType type = isKeyword(word.c_str()) ? Keyword : Identifier;
        return new Token(type, word.c_str());
    }

    return nullptr;
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

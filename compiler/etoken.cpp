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

    std::string inputSubstring = input.substr(position);

    if (std::regex_search(inputSubstring, match, wordRegex)) {
        word = match.str();
        position += word.length();
        TokenType type = isKeyword(word.c_str()) ? Keyword : Identifier;
        return new Token(type, word.c_str());
    }

    return nullptr;
}


Token* Tokenizer::extractNumericLiteral() {
    std::regex numericRegex("[0-9]+");
    std::smatch match;
    std::string num;

    std::string inputSubstring = input.substr(position);

    if (std::regex_search(inputSubstring, match, numericRegex)) {
        num = match.str();
        position += num.length(); // Update position
        return new Token(NumericLiteral, num.c_str());
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

    std::string mutableCode = code;
    Tokenizer tokenizer(&mutableCode[0]);

    Token* token;
    while((token = tokenizer.getNextToken()) != nullptr) {
        tokens.push_back(token);
    }

    return tokens;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_string>" << std::endl;
        return 1;
    }

    std::string g;
    for(int i=1;i<argc;++i) {
        g += argv[i];
    }

    std::vector<Token*> rawTokens = tokenM(g);
    std::vector<std::unique_ptr<Token>> tokens;

    for (auto* rawToken : rawTokens) {
        tokens.push_back(std::unique_ptr<Token>(rawToken));
    }

    for (const auto& token : tokens) {
        std::cout << token->value << " ";
    }
    std::cout << std::endl;

    for (auto token : tokens) {
        delete token;
    }

    return 0;
}

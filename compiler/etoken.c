#define ECTER_COMPILER

#include "etoken.h"
#include "eutil.h"

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Tokenizer {
    char* input;
    size_t position;
};

Token* createToken(enum TokenType type, const char* value) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->type = type;
    token->value = strdup(value);
    return token;
}

void destroyToken(Token* token) {
    free(token->value);
    free(token);
}

Tokenizer* createTokenizer(const char* input) {
    Tokenizer* tokenizer = (Tokenizer*)malloc(sizeof(Tokenizer));
    tokenizer->input = strdup(input);
    tokenizer->position = 0;
    return tokenizer;
}

void destroyTokenizer(Tokenizer* tokenizer) {
    free(tokenizer->input);
    free(tokenizer);
}

char currentChar(Tokenizer* tokenizer) {
    if (tokenizer->input[tokenizer->position] != '\0') {
        return tokenizer->input[tokenizer->position];
    } else {
        return '\0';
    }
}

void advance(Tokenizer* tokenizer) {
    tokenizer->position++;
}

void skipWhitespace(Tokenizer* tokenizer) {
    while (isspace(currentChar(tokenizer))) {
        advance(tokenizer);
    }
}

Token* extractNumericLiteral(Tokenizer* tokenizer) {
    char num[50];
    size_t index = 0;
    while (isdigit(currentChar(tokenizer))) {
        num[index++] = currentChar(tokenizer);
        advance(tokenizer);
    }
    num[index] = '\0';
    return createToken(NumericLiteral, num);
}

Token* extractTextLiteral(Tokenizer* tokenizer) {
    char text[100]; 
    size_t index = 0;
    advance(tokenizer); 
    while (currentChar(tokenizer) != '"' && currentChar(tokenizer) != '\0') {
        text[index++] = currentChar(tokenizer);
        advance(tokenizer);
    }
    text[index] = '\0';
    advance(tokenizer);
    return createToken(TextLiteral, text);
}

Token* extractOperator(Tokenizer* tokenizer) {
    char op[2] = {currentChar(tokenizer), '\0'};
    advance(tokenizer);
    return createToken(Operator, op);
}

Token* extractKeywordOrIdentifier(Tokenizer* tokenizer) {
    size_t index = tokenizer->position;
    while (isalnum(currentChar(tokenizer)) || currentChar(tokenizer) == '_') {
        advance(tokenizer);
    }
    char* word = strndup(tokenizer->input + index, tokenizer->position - index);
    enum TokenType type;

    if (isKeyword(word)) {
        type = Keyword;
    } else {
        type = Identifier;
    }
    
    return createToken(type, word);
}

Token* getNextToken(Tokenizer* tokenizer) {
    while (currentChar(tokenizer) != '\0') {
        if (isspace(currentChar(tokenizer))) {
            if (currentChar(tokenizer) == '\n') {
                advance(tokenizer);
                return createToken(Newline, "\n");
            }
            skipWhitespace(tokenizer);
            continue;
        }

        if (isdigit(currentChar(tokenizer))) {
            return extractNumericLiteral(tokenizer);
        }

        if (currentChar(tokenizer) == '"') {
            return extractTextLiteral(tokenizer);
        }

        if (currentChar(tokenizer) == '.') {
            advance(tokenizer);
            return createToken(Separator, ".");
        }

        if (currentChar(tokenizer) == ')') {
            advance(tokenizer);
            return createToken(RParenth, ")");
        }

        if (currentChar(tokenizer) == '}') {
            advance(tokenizer);
            return createToken(RBracket, "}");
        }

        if (currentChar(tokenizer) == '(') {
            advance(tokenizer);
            return createToken(LParenth, "(");
        }

        if (currentChar(tokenizer) == '{') {
            advance(tokenizer);
            return createToken(LBracket, "{");
        }

        if (currentChar(tokenizer) == '+' || currentChar(tokenizer) == '-' || currentChar(tokenizer) == '=' || currentChar(tokenizer) == '*' || currentChar(tokenizer) == '/') {
            return extractOperator(tokenizer);
        }

        if (isalpha(currentChar(tokenizer)) || currentChar(tokenizer) == '_') {
            return extractKeywordOrIdentifier(tokenizer);
        }

        advance(tokenizer);
        return createToken(None, "");
    }

    if (currentChar(tokenizer) == '\0') {
        return createToken(EOL, "");
    }

    return createToken(None, "");
}


int tokenM(const char* inputy, Token*** tokenlist) {
    Tokenizer* tokenizer = createTokenizer(inputy);

    int numTokens = 0;
    int maxTokens = 100; 
    *tokenlist = (Token**)malloc(maxTokens * sizeof(Token*));

    const char* tokenTypeText[] = {
        "NumericLiteral",
        "TextLiteral",
        "Separator",
        "Operator",
        "Identifier",
        "Keyword",
        "EOL",
        "Newline",
        "RParenth",
        "RBracket",    
        "LBracket",
        "LParenth",
        "None"
    };

    Token* token = getNextToken(tokenizer);
    while (token->type != EOL) {
        if (numTokens >= maxTokens) {
            maxTokens *= 2;
            *tokenlist = (Token**)realloc(*tokenlist, maxTokens * sizeof(Token*));
        }
        (*tokenlist)[numTokens++] = token;
        token = getNextToken(tokenizer);
    }

    if (numTokens >= maxTokens) {
        maxTokens++;
        *tokenlist = (Token**)realloc(*tokenlist, maxTokens * sizeof(Token*));
    }
    (*tokenlist)[numTokens++] = createToken(EOL, "");

    printf("Tokens:\n[");
    for (int i = 0; i < numTokens; i++) {
        printf("{Type=%s, Value='%s'}", tokenTypeText[(*tokenlist)[i]->type], (*tokenlist)[i]->value);
        if (i < numTokens - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    destroyTokenizer(tokenizer);

    return numTokens;
}

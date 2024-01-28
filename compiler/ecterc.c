#define ECTER_COMPILER

#include <stdio.h>
#include "etoken.c"

const char* tokenTypeNames[] = {
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

int main(int argc, char* argv[]) {
    const char* input = "class waiting() { int hard = 0 }";
    Token** tokenlist;
    int numTokens = tokenM(input, &tokenlist);

    printf("Tokens:\n");
    for (int i = 0; i < numTokens; i++) {
        printf("Token %d: Type=%s, Value='%s'\n", i + 1, tokenTypeNames[tokenlist[i]->type], strcmp(tokenlist[i]->value, "\n") == 0 ? "\\n" : tokenlist[i]->value);
        destroyToken(tokenlist[i]);
    }
    free(tokenlist);

    return 0;
}
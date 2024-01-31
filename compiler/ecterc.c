#define ECTER_COMPILER

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#include "emem.h"
#include "eoptions.h"
#include "ecterc.h"
#include "etoken.h"

extern const CompilerInstance instance;

void stop(CompilerInstance inst) {
    exit(0);
}

void checkArguments(char* args[]) {
    Options* optionist;
    int optionsize = sizeof(optionist);

    for(int z=0;z<optionsize;z++) {
        optionist[z] = createOption();
    }

    int size = sizeof(args[]);

    for(int x=0;x<size;x++) {
        validateOption();
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *sourceCode = (char *)alloc(fileSize + 1);
    if (!sourceCode) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    size_t bytesRead = fread(sourceCode, 1, fileSize, file);
    if (bytesRead != fileSize) {
        printf("Error: Failed to read file %s\n", filename);
        fclose(file);
        free(sourceCode);
        return 1;
    }
    sourceCode[fileSize] = '\0';

    Token **tokens;
    int numTokens = tokenM(sourceCode, &tokens);

    if (numTokens == 0) {
        printf("Error: Failed to tokenize input\n");
        free(sourceCode);
        return 1;
    }

    printf("Tokens:\n[");
    for (int i = 0; i < numTokens; i++) {
        printf("{Type=%d, Value='%s'}", tokens[i]->type, tokens[i]->value);
        if (i < numTokens - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free allocated memory
    free(sourceCode);
    for (int i = 0; i < numTokens; i++) {
        destroyToken(tokens[i]);
    }
    free(tokens);

    return 0;
}
#define ECTER_COMPILER

#include <stdlib.h>
#include <string.h>

#include "eutil.h"
#include "eparse.h"

ASTNode* createNode(const char* type, const char* value, ASTNode** children, int child_num) {
    ASTNode* node = (ASTNode*)alloc(sizeof(ASTNode));
    if (node == NULL) {
        return NULL;
    }

    node->type = strdup(type);
    node->value = strdup(value);
    node->children = children;
    node->child_num = child_num;

    return node;
}

void freeNode(ASTNode* node) {
    if (node == NULL) {
        return;
    }

    free(node->type);
    free(node->value);

    if (node->children != NULL) {
        for (int i=0;i<child_num;i++) {
            freeNode(node->children[i]);
        }
        free(node->children);
    }
    
    free(node);
}
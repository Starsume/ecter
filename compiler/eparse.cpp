#ifndef ECTER_COMPILER
#define ECTER_COMPILER

#include <cstdlib>
#include <cstring>

#include "include/eutil.h"
#include "include/eparse.h"

ASTNode* createNode(const char* type, const char* value, ASTNode** children, int child_num) {
    ASTNode* node = new ASTNode;
    if (node == nullptr) {
        return nullptr;
    }

    node->type = strdup(type);
    node->value = strdup(value);
    node->children = children;
    node->child_num = child_num;

    return node;
}

void freeNode(ASTNode* node) {
    if (node == nullptr) {
        return;
    }

    free(node->type);
    free(node->value);

    if (node->children != nullptr) {
        for (int i = 0; i < node->child_num; i++) {
            freeNode(node->children[i]);
        }
        delete[] node->children;
    }
    
    delete node;
}

#endif 
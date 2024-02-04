#ifndef EPARSE_H
#define EPARSE_H

#define ECTER_COMPILER

typedef struct ASTNode {
    char* type;
    char* value;
    struct ASTNode** children;
    int child_num;
} ASTNode;

ASTNode* createNode(const char* type, const char* value, ASTNode** children, int child_num);
void freeNode(ASTNode* node);

#endif
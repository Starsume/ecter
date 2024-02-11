#include "eas.h"

using namespace eas;

#define ECTER_COMPILER

void Assembler::generateAssembly(ASTNode* root, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    if (root != nullptr) {
        generateNodeAssembly(root, outFile);
    }

    outfile.close();
}

void Assembler::generateNodeAssembly(ASTNode* node, std::ofstream& outfile) {
    if (node == nullptr) {
        return;
    }

    if (strcmp(node->type, "ValueNode") == 0) {
        outFile << "push " << node->value << std::endl;
    } else if (strcmp(node->type, "AdditionNode") == 0) {
        generateNodeAssembly(node->children[0], outFile);
        generateNodeAssembly(node->children[1], outFile);
        outFile << "add" << std::endl;
    } else if (strcmp(node->type, "MultiplicationNode") == 0) {
        generateNodeAssembly(node->children[0], outFile);
        generateNodeAssembly(node->children[1], outFile);
        outFile << "mul" << std::endl;
    } else {
        std::cerr << "Unknown node type: " << node->type << std::endl;
    }
}

void SymbolTable::addEntry(const std::string& name) {
    table[name] = value;
}

bool SymbolTable::getSymbol(const std::string& name, int& value) const {
    auto it = table.find(name);
    if(it != table.end()) {
        value = it->second;
        return true;
    }
    return false;
}
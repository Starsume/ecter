#ifndef EAS_H
#define EAS_H

#include "eparse.h" 
#include <fstream>
#include <unordered_map>
#include <string>

namespace eas {
    class Assembler {
        public:
            void generateAssembly(ASTNode* root, const std::string& filename);

        private:
            void generateNodeAssembly(ASTNode* node, std::ofstream& outFile);
    };

    class SymbolTable {
        public:
            void addEntry(const std::string& name);
            bool getSymbol(const std::string& name, int& value) const;
        private:
            std::unordered_map<std::string, int> table;
    };
}


#endif
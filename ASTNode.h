#ifndef ASTNODE_H
#define ASTNODE_H

#include <string>
#include <vector>
#include "SymTable.h"
#include "Value.h"

using namespace std;

class ASTNode {
public:
    ASTNode *left;
    ASTNode *right;
    string root;   
    string type;  
    int lineNumber;
    
    vector<ASTNode*> args; 
    ASTNode(string r, string t, ASTNode* l = nullptr, ASTNode* r_ptr = nullptr, int line = 0) 
        : root(r), type(t), left(l), right(r_ptr), lineNumber(line) {}

    Value eval(SymTable* st);

private:
    Value combine(Value v1, Value v2, string op);
};
#endif
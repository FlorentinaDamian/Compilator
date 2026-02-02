#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Value.h"

using namespace std;

class ASTNode; 

class IdInfo {
public:
    string type;
    string name;
    string value;
    IdInfo() {}
    IdInfo(string type, string name) : type(type), name(name) {
        if(type == "int") value = "0";
        else if(type == "float") value = "0.0";
        else if(type == "bool") value = "false";
        else value = "null";
    }
};

class FuncInfo {
public:
    string returnType;
    vector<pair<string, string>> params;
    ASTNode* body; 
    FuncInfo() : body(nullptr) {}
};

class ClassInfo {
public:
    string name;
    class SymTable* classScope;
};

class SymTable {
    string name;
    SymTable* parent;

public:
    map<string, IdInfo> ids;
    map<string, FuncInfo> functions;
    map<string, ClassInfo> classes;

    SymTable(string n, SymTable* p = nullptr);

    void addVar(string type, string name);
    void addFunc(string type, string name, vector<pair<string, string>> params);
    void addClass(string name, SymTable* scope);

    bool existsId(string name);
    string getType(string name);
    
    SymTable* getClassScope(string className);
    FuncInfo* getFuncInfo(string funcName);
    Value getValue(string name);
    void setValue(string name, Value newValue);
    SymTable* createInstance(string className, string instanceName);

    SymTable* getParent() { return parent; }
    string getName() { return name; }
    void printToFile(ofstream& fout);
};
#endif
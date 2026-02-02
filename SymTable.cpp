#include "SymTable.h"

extern vector<SymTable*> allScopes; 
SymTable::SymTable(string n, SymTable* p) : name(n), parent(p) {}
void SymTable::addVar(string type, string name) {
    ids[name] = IdInfo(type, name);
}
void SymTable::addFunc(string type, string name, vector<pair<string, string>> params) {
    FuncInfo info;
    info.returnType = type;
    info.params = params;
    functions[name] = info;
}
void SymTable::addClass(string name, SymTable* scope) {
    ClassInfo info;
    info.name = name;
    info.classScope = scope;
    classes[name] = info;
}
bool SymTable::existsId(string name) {
    if (ids.count(name)) return true;
    if (parent != nullptr) return parent->existsId(name);
    return false;
}
string SymTable::getType(string name) {
    if (ids.count(name)) return ids[name].type;
    if (parent != nullptr) return parent->getType(name);
    return "undefined";
}
SymTable* SymTable::getClassScope(string className) {
    if (classes.count(className)) return classes[className].classScope;
    if (parent != nullptr) return parent->getClassScope(className);
    return nullptr;
}
FuncInfo* SymTable::getFuncInfo(string funcName) {
    if (functions.count(funcName)) return &functions[funcName];
    if (parent != nullptr) return parent->getFuncInfo(funcName);
    return nullptr;
}
Value SymTable::getValue(string name) {
    if (ids.count(name)) return Value(ids[name].value, ids[name].type);
    if (parent != nullptr) return parent->getValue(name);
    return Value("0", "undefined");
}
void SymTable::setValue(string name, Value newValue) {
    if (ids.count(name)) {
        ids[name].value = newValue.strValue;
        ids[name].type = newValue.type;
    } else if (parent != nullptr) {
        parent->setValue(name, newValue);
    }
}
SymTable* SymTable::createInstance(string className, string instanceName) {
    SymTable* classScope = getClassScope(className);
    if (!classScope) return nullptr;
    SymTable* global = this;
    while(global->parent != nullptr) global = global->parent;

    SymTable* instance = new SymTable(instanceName, global);
    allScopes.push_back(instance); 
    for (auto const& [key, info] : classScope->ids) {
        instance->addVar(info.type, info.name);
    }
    return instance;
}

void SymTable::printToFile(ofstream& fout) {
    fout << "SCOPE: " << name;
    if(parent) fout << "  [PARENT: " << parent->getName() << "]";
    fout << endl;
    
    if(!ids.empty()) {
        fout << "  Variabile:" << endl;
        for (auto const& [name, info] : ids) 
            fout << "    " << info.type << " " << name << " = " << info.value << endl;
    }
    if(!functions.empty()) {
        fout << "  Functii:" << endl;
        for (auto const& [name, info] : functions) {
            fout << "    " << info.returnType << " " << name << "(";
            for(auto p : info.params) fout << p.first << " " << p.second << " ";
            fout << ")";
            if(info.body) fout << " [Defined]";
            fout << endl;
        }
    }
    if(!classes.empty()) {
        fout << "  Clase:" << endl;
        for (auto const& [name, info] : classes) fout << "    " << name << endl;
    }
    fout << "---------------------------------" << endl;
}
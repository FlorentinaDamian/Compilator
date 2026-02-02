#include "ASTNode.h"
#include <iostream>
#include <string>
using namespace std;
static SymTable* currentInstance = nullptr;
extern vector<SymTable*> allScopes;
Value ASTNode::eval(SymTable* st) {
    if (st == nullptr) return Value();
    if (root == "new") {
        string className = type; 
        if (st->getClassScope(className) == nullptr) {
            cout << "Eroare Semantică: Clasa '" << className << "' nu este definită." << endl;
        }
        return Value("0", className); 
    }
    if (type == "SELF_ACCESS") {
        string mem = root.substr(5);
        if (currentInstance) return currentInstance->getValue(mem);
        else cout << "Eroare Runtime: self in afara clasei." << endl;
    }
    if (root.find("call_") == 0 || root.find("mcall_") == 0) {
        string funcName;
        FuncInfo* func = nullptr;
        if (root.find("mcall_") == 0) {
            string fullPath = root.substr(6); 
            size_t dotPos = fullPath.find('.');
            string objName = fullPath.substr(0, dotPos);
            string methodName = fullPath.substr(dotPos + 1);
            if (!st->existsId(objName)) {
                cout << "Eroare Semantica: Obiectul '" << objName << "' nu este declarat." << endl;
                return Value("0", "int");
            }
            string className = st->getType(objName);
            SymTable* classScope = st->getClassScope(className);
            if (classScope) {
                func = classScope->getFuncInfo(methodName);
            }
            funcName = methodName;
        } 
        else {
            funcName = root.substr(5); 
            func = st->getFuncInfo(funcName);
        }
        if (!func) {
            cout << "Eroare Semantica: Functia/Metoda '" << funcName << "' nu a fost gasita in scopul curent." << endl;
        } else {
            if (args.size() != func->params.size()) {
                cout << "Eroare Semantica: Apelul functiei '" << funcName  << "' asteapta " << func->params.size() << " argumente, dar s-au primit "  << args.size() << "." << endl;
            }
            for (ASTNode* arg : args) {
                if (arg) arg->eval(st);
            }
        }
        return Value("0", (func ? func->returnType : "int"));
    }
    if (type == "for_statement") {
        if (left != nullptr) left->eval(st); 
        while (right != nullptr && right->left != nullptr && right->left->eval(st).asBool()) {
            if (right->right != nullptr && right->right->left != nullptr) {
                right->right->left->eval(st);
            }
            if (right->right != nullptr && right->right->right != nullptr) {
                right->right->right->eval(st);
            }
        }
        return Value();
    }
    if (type == "do_while_statement") {
        do {
            if (right != nullptr) right->eval(st);
        } while (left != nullptr && left->eval(st).asBool());
        return Value();
    }

    if (type == "if_statement") {
        if (left->eval(st).asBool()) return right->left->eval(st);
        else if (right->right) return right->right->eval(st);
        return Value();
    }

    if (type == "while_statement") {
        while (left->eval(st).asBool()) right->eval(st);
        return Value();
    }
    if (root == ":=") {
        Value val = right->eval(st);
        if (left->type == "SELF_ACCESS") {
             if(currentInstance) 
             currentInstance->setValue(left->root.substr(5), val);
        } 
        else if (left->type == "MEMBER_ACCESS") {
             size_t dot = left->root.find('.');
             Value objVal = st->getValue(left->root.substr(0, dot));
             SymTable* objScope = nullptr;
             for(auto s : allScopes) 
             if(s->getName() == objVal.strValue)
              { objScope = s; 
                break;
             }
             if(objScope) 
             objScope->setValue(left->root.substr(dot + 1), val);
        } else {
             st->setValue(left->root, val);
        }
        return val;
    }
    if (type == "sequence") {
        if (left) {
             Value v = left->eval(st);
             if(left->root == "RETURN") return v;
        }
        if (right) return right->eval(st);
        return Value();
    }

    if (root == "RETURN") 
    return left ? left->eval(st) : Value("void", "void");
    if (root == "Print") {
        Value v = left->eval(st);
        cout << "[PRINT] " << v.strValue << endl;
        return v;
    }
    if (type == "MEMBER_ACCESS") {
        size_t dot = root.find('.');
        Value objVal = st->getValue(root.substr(0, dot));
        for(auto s : allScopes) if(s->getName() == objVal.strValue) return s->getValue(root.substr(dot+1));
    }
    if (st->existsId(root)) return st->getValue(root);
    if (left == nullptr && right == nullptr) {
        if (type == "int" || type == "float" || type == "bool" || type == "string") {
            return Value(root, type);
        }
    }
    Value vL = left ? left->eval(st) : Value();
    Value vR = right ? right->eval(st) : Value();
    return combine(vL, vR, root);
}

Value ASTNode::combine(Value v1, Value v2, string op) {
    bool isFloat = (v1.type == "float" || v2.type == "float");
    if (op == "+") {
        if (isFloat) return Value(to_string(v1.asFloat() + v2.asFloat()), "float");
        return Value(to_string(v1.asInt() + v2.asInt()), "int");
    }
    if (op == "-") {
        if (isFloat) return Value(to_string(v1.asFloat() - v2.asFloat()), "float");
        return Value(to_string(v1.asInt() - v2.asInt()), "int");
    }
    if (op == "*") {
        if (isFloat) return Value(to_string(v1.asFloat() * v2.asFloat()), "float");
        return Value(to_string(v1.asInt() * v2.asInt()), "int");
    }
    if (op == "/") {
        if (v2.asFloat() == 0) { cout << "Eroare: Impartire la zero" << endl; return Value(); }
        if (isFloat) return Value(to_string(v1.asFloat() / v2.asFloat()), "float");
        return Value(to_string(v1.asInt() / v2.asInt()), "int");
    }
    if (op == "!" || op == "NOT") {
        return Value(!v1.asBool());
    }
    

    if (op == "&&") return Value(v1.asBool() && v2.asBool());
    if (op == "||") return Value(v1.asBool() || v2.asBool());
    if (op == "XOR") return Value(v1.asBool() != v2.asBool());
    if (op == "==") return Value(v1.strValue == v2.strValue);
    if (op == "!=") return Value(v1.strValue != v2.strValue);
    if (op == "<") return Value(v1.asFloat() < v2.asFloat());
    if (op == ">") return Value(v1.asFloat() > v2.asFloat());
    if (op == "<=") return Value(v1.asFloat() <= v2.asFloat());
    if (op == ">=") return Value(v1.asFloat() >= v2.asFloat());
    
    return Value("0", "int");
}
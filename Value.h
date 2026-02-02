#ifndef VALUE_H
#define VALUE_H

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class Value {
public:
    string type;     
    string strValue; 
    Value() : type("void"), strValue("") {}
    Value(string v, string t) : type(t), strValue(v) {
        if (v == "undefined" || v == "") {
            if (t == "int") strValue = "0";
            else if (t == "float") strValue = "0.0";
            else if (t == "bool") strValue = "false";
            else strValue = "";
        }
    }
    Value(int v) : type("int"), strValue(to_string(v)) {}
    Value(float v) : type("float"), strValue(to_string(v)) {}
    Value(bool v) : type("bool"), strValue(v ? "true" : "false") {}
    int asInt() const {
        if (type == "bool") return strValue == "true" ? 1 : 0;
        try { return stoi(strValue); } catch (...) { return 0; }
    }

    float asFloat() const {
        try { return stof(strValue); } catch (...) { return 0.0f; }
    }

    bool asBool() const {
        return strValue == "true";
    }
};
#endif
%code requires {
    #include <vector>
    #include <string>
    
}
%{
#include <iostream>
#include <string>
#include <vector>
#include "SymTable.h"
#include "ASTNode.h"
extern FILE* yyin; 
extern int yylineno;
extern int yylex();
extern char* yytext;
std::vector<SymTable*> allScopes;
std::vector<std::pair<std::string, std::string>> tempParams;
std::vector<ASTNode*> mainInstructions; 
std::string currentDeclType; 
void yyerror(const char * s);
class SymTable* current;
int errorCount = 0;
using namespace std;
%}
%union {
    int Int;
    float Float;
    int Bool;
    std::string* String;
    std::vector<std::string>* typeList;
    class ASTNode* node;
    std::vector<class ASTNode*>* argsList;
}

%token ASSIGN CLASS MAIN PRINT BGIN END
%token IF WHILE ELSE FOR DO
%token AND OR XOR NOT
%token MAI_MARE MAI_MARE_EGAL MAI_MIC MAI_MIC_EGAL EGAL NOT_EGAL
%token NEW SELF
%token<Int> INT
%token<Float> FLOAT
%token<Bool> BOOL_TRUE BOOL_FALSE
%token<String> STRING ID TYPE
%token RETURN
%type <node> expresie value access atribuire apel_print statement statement_cu_decl statements_bloc if_statement conditie expresie_logica expresie_comparatie while_statement do_while_statement for_statement corp_functie block_start block_end expresie_generala atom
%type <argsList> lista_apel lista_valori
%left OR
%left AND
%left XOR
%left EGAL NOT_EGAL
%left MAI_MIC MAI_MARE MAI_MIC_EGAL MAI_MARE_EGAL
%left '+' '-'
%left '*' '/'
%right NOT
%right ASSIGN

%%
program:
      globale main_function { if (errorCount == 0) cout << "The program is correct!" << endl; }
    ;

globale:
    | globale global
    ;

global:
      functie_def
    | clasa_def
    | declaratie_globala ';'
    ;

declaratie_globala:
      start_decl_vars rest_lista_vars
    | start_decl_objs rest_lista_vars
    ;

start_decl_vars:
      TYPE ID {
          currentDeclType = *$1; 
          if(!current->existsId(*$2)) current->addVar(*$1, *$2);
          else { errorCount++; yyerror("Variabila deja definita global"); }
      }
    | TYPE ID ASSIGN expresie_generala {
          currentDeclType = *$1;
          if(!current->existsId(*$2)) current->addVar(*$1, *$2);
          else { errorCount++; yyerror("Variabila deja definita global"); }
      }
    ;
start_decl_objs:
      ID ID {
          currentDeclType = *$1; 
          if(current->getClassScope(*$1)) current->addVar(*$1, *$2);
          else { errorCount++; yyerror("Tip clasa necunoscut"); }
      }
    | ID ID ASSIGN expresie_generala {
          currentDeclType = *$1;
          if(current->getClassScope(*$1)) current->addVar(*$1, *$2);
          else { errorCount++; yyerror("Tip clasa necunoscut"); }
      }
    ;
rest_lista_vars:
      /* epsilon */
    | ',' ID {
          if(!current->existsId(*$2)) current->addVar(currentDeclType, *$2);
          else { errorCount++; yyerror("Variabila deja definita in lista"); }
      } rest_lista_vars
      
    | ',' ID ASSIGN expresie_generala {
          if(!current->existsId(*$2)) current->addVar(currentDeclType, *$2);
      } rest_lista_vars
    ;
clasa_def:
      CLASS ID {
          SymTable* clasaScope = new SymTable(*$2, current);
          allScopes.push_back(clasaScope); 
          current->addClass(*$2, clasaScope);
          current = clasaScope;
      } BGIN membri_clasa END ';' {
          current = current->getParent();
      }
    ;

membri_clasa:
    | membri_clasa membru
    ;

membru:
      TYPE ID ';' { current->addVar(*$1, *$2); }     
    | functie_def        
    ;

functie_def:
      TYPE ID '(' { tempParams.clear(); } param_list ')' {
          current->addFunc(*$1, *$2, tempParams);
          SymTable* funcScope = new SymTable(*$2, current);
          allScopes.push_back(funcScope);
          for(auto p : tempParams) funcScope->addVar(p.first, p.second);
          current = funcScope;
      } BGIN corp_functie END {
          SymTable* fScope = current;
          current = current->getParent();
          FuncInfo* f = current->getFuncInfo(*$2);
          if(f) f->body = $9;
      }
    ;

param_list:
    | lista_parametri
    ;

lista_parametri:
      parametru
    | lista_parametri ',' parametru
    ;

parametru:
      TYPE ID { tempParams.push_back({*$1, *$2}); }
    ;

corp_functie:
      { $$ = nullptr; }
    | corp_functie statement_cu_decl {
         if ($1 == nullptr) $$ = $2; 
         else if ($2 != nullptr) $$ = new ASTNode("BLOCK", "sequence", $1, $2);
         else $$ = $1;
    }
    ;


statement_cu_decl:
      statement { $$ = $1; }
    | TYPE ID ';' { 
          if(current->existsId(*$2)) { errorCount++; yyerror("Variabila deja definita"); }
          else current->addVar(*$1,*$2);
          $$ = nullptr;
      }
    | TYPE ID ASSIGN expresie ';' { 
          current->addVar(*$1,*$2);
          $$ = new ASTNode(":=", "assign", new ASTNode(*$2, "ID"), $4);
      }
    | ID ID ASSIGN expresie ';' { 
           current->addVar(*$1,*$2);
           $$ = new ASTNode(":=", "assign", new ASTNode(*$2, "ID"), $4);
      }
    ;
statements_bloc:
      { $$ = nullptr; }
    | statements_bloc statement { 
        if ($1 == nullptr) {
            $$ = $2; 
        } else if ($2 != nullptr) {
            $$ = new ASTNode("BLOCK", "sequence", $1, $2);
        } else {
            $$ = $1;
        }
    }
    ;

statement:
      atribuire ';'        { $$ = $1; }
    | if_statement         { $$ = $1; }  
    | while_statement      { $$ = $1; }  
    | for_statement        { $$ = $1; }  
    | do_while_statement   { $$ = $1; }  
    | expresie ';'         { $$ = $1; }
    | apel_print           { $$ = $1; }
    | obiect_init ';'      { $$ = nullptr; } 
    | RETURN expresie ';'  { $$ = new ASTNode("RETURN", "return_statement", $2, nullptr); }
    | RETURN ';'           { $$ = new ASTNode("RETURN", "return_statement", nullptr, nullptr); }
    ;
value:
      ID { 
          if (current->getType(*$1) == "undefined") {
              errorCount++; yyerror(("Variable " + *$1 + " not defined").c_str());
          }
          string t = current->getType(*$1);
          $$ = new ASTNode(*$1, "ID");
          $$->type = t;
      }
    |ID '.' ID {
    string objName = *$1;
    string memberName = *$3;
    string className = current->getType(objName); 
    SymTable* classScope = current->getClassScope(className);
    if (classScope == nullptr) {
        yyerror("Obiectul nu apartine unei clase definite");
        $$ = new ASTNode(objName + "." + memberName, "undefined");
        $$->type = "undefined";
    } else {
        string tipMembru = classScope->getType(memberName); 
        $$ = new ASTNode(objName + "." + memberName, "ID");
        $$->type = tipMembru;
    }
}
  | SELF '.' ID { 
    string tipMembru = current->getType(*$3); 
    if (tipMembru == "undefined") {
        errorCount++;
        yyerror(("Membrul " + *$3 + " nu exista in clasa curenta").c_str());
    }
    $$ = new ASTNode("self." + *$3, "ID"); 
    $$->type = tipMembru; 
}
    ;

atribuire:
     value ASSIGN expresie_generala {
          string tipVariabila = $1->type; 
          string tipExpresie = $3->type; 

          if (tipVariabila == "undefined") {
              errorCount++;
              yyerror(("Variabila sau membrul '" + $1->root + "' nu este definit/a").c_str());
          }
          else if (tipVariabila != tipExpresie) {
              errorCount++;
              yyerror("Eroare Semantica: tipuri diferite.");
          }
          $$ = new ASTNode(":=", "void", $1, $3);
      };
expresie_generala:
    expresie_logica { $$ = $1; }
    ;
obiect_init:
      ID ID {
          if (current->getClassScope(*$1) == nullptr) {
              errorCount++; yyerror("Clasa nu este definita");
          } else {
              current->addVar(*$1, *$2);
          }
      }
    ;

conditie:
      expresie_generala { 
          if($1->type != "bool") {
              errorCount++;
              yyerror("Eroare Semantica: Conditia trebuie sa fie de tip bool.");
          }
          $$ = $1; 
      }
    ;
if_statement:
      IF '(' conditie ')' BGIN statements_bloc END ELSE BGIN statements_bloc END {
          ASTNode* branches = new ASTNode("BRANCHES", "branches", $6, $10);
          $$ = new ASTNode("IF", "if_statement", $3, branches);
      }
    | IF '(' conditie ')' BGIN statements_bloc END {
          ASTNode* branches = new ASTNode("BRANCHES", "branches", $6, nullptr);
          $$ = new ASTNode("IF", "if_statement", $3, branches);
      }
    ;
while_statement:
      WHILE '(' conditie ')' block_start statements_bloc block_end {
          $$ = new ASTNode("WHILE", "while_statement", $3, $6);
      }
    ;
for_statement:
      FOR '(' atribuire ';' conditie ';' atribuire ')' block_start statements_bloc block_end {
          ASTNode* forBody = new ASTNode("FOR_BODY", "sequence", $10, $7); 
          ASTNode* forCond = new ASTNode("FOR_COND", "sequence", $5, forBody); 
          $$ = new ASTNode("FOR", "for_statement", $3, forCond); 
      }
    ;

do_while_statement:
      DO block_start statements_bloc block_end WHILE '(' conditie ')' ';' {
          $$ = new ASTNode("DO_WHILE", "do_while_statement", $7, $3);
      }
    ;
block_start:
      BGIN {
          current = new SymTable("local_block", current);
          allScopes.push_back(current);
      }
    ;

block_end:
      END { current = current->getParent(); }
    ;


atom:
  INT         { $$ = new ASTNode(to_string($1), "int"); }
    | FLOAT       { $$ = new ASTNode(to_string($1), "float"); }
    | STRING      { $$ = new ASTNode(*$1, "string"); }
    | value  { 
        $$ = $1;
      }
    | BOOL_TRUE   { $$ = new ASTNode("true", "bool"); }
    | BOOL_FALSE  { $$ = new ASTNode("false", "bool"); }
    | access      { $$ = $1; }
    | '(' expresie_generala ')' { $$ = $2; }

expresie_logica:
      expresie_logica AND expresie_logica { $$ = new ASTNode("&&", "operator", $1, $3); $$->type = "bool";}
    | expresie_logica OR expresie_logica  { $$ = new ASTNode("||", "operator", $1, $3); $$->type = "bool";}
    | expresie_logica XOR expresie_logica { $$ = new ASTNode("XOR", "operator", $1, $3); $$->type = "bool";}
    | NOT expresie_logica{ 
          $$ = new ASTNode("!", "operator", $2, nullptr); 
          $$->type = "bool";
      }
    | expresie_comparatie                 { $$ = $1; }
    | expresie
    ;
expresie_comparatie:
      expresie EGAL expresie { $$ = new ASTNode("==", "operator", $1, $3); $$->type = "bool";}
    | expresie NOT_EGAL expresie { $$ = new ASTNode("!=", "operator", $1, $3); $$->type = "bool";}
    | expresie MAI_MARE expresie { $$ = new ASTNode(">", "operator", $1, $3); $$->type = "bool";}
    | expresie MAI_MARE_EGAL expresie { $$ = new ASTNode(">=", "operator", $1, $3); $$->type = "bool";}
    | expresie MAI_MIC expresie { $$ = new ASTNode("<", "operator", $1, $3);$$->type = "bool"; }
    | expresie MAI_MIC_EGAL expresie { $$ = new ASTNode("<=", "operator", $1, $3); $$->type = "bool";}
    ;

expresie:
     atom { $$ = $1; }
    | expresie '+' expresie {if ($1->type != $3->type) {
            yyerror("Operanzi de tipuri diferite la adunare!");
            errorCount++;
        }
        else
        if($1->type=="bool")
        {
            yyerror("Adunarea se poate efectua doar cu tipurile float, int, string");
            errorCount++;
        }
        else
        {
        $$ = new ASTNode("+", "op", $1, $3);}
        $$->type = $1->type; 
    }
    | expresie '-' expresie 
     {
        if ($1->type != $3->type) {
            yyerror("Operanzi de tipuri diferite la scadere!");
            errorCount++;
        }
        else
        if($1->type=="bool"||$1->type=="string")
        {
            yyerror("Scaderea se poate efectua doar cu tipurile float, int");
            errorCount++;
        }
        else
        {
        $$ = new ASTNode("-", "op", $1, $3);}
        $$->type =  $1->type; 
    }
    | expresie '*' expresie { if ($1->type != $3->type){
            yyerror("Operanzi de tipuri diferite la adunare!");
            errorCount++;
        }
        else
        if($1->type=="bool"||$1->type=="string")
        {
            yyerror("Inmultirea se poate efectua doar cu tipurile float, int");
            errorCount++;
        }
        else
        {
        $$ = new ASTNode("*", "op", $1, $3);}
        $$->type =  $1->type; 
    }
    | expresie '/' expresie { {if ($1->type != $3->type) {
            yyerror("Operanzi de tipuri diferite la adunare!");
            errorCount++;
        }
        else
        if($1->type=="bool"||$1->type=="string")
        {
            yyerror("Impartirea se poate efectua doar cu tipurile float, int");
            errorCount++;
        }
        else
        {
        $$ = new ASTNode("/", "op", $1, $3);}
        $$->type =  $1->type; 
    }
    }
    ;

access:
  ID '(' lista_apel ')' { 
         FuncInfo* f = current->getFuncInfo(*$1);
         if (!f) { 
             errorCount++; 
             string msg = "Functie nedefinita: " + *$1;
             yyerror(msg.c_str()); 
             $$ = new ASTNode("err", "void"); 
         }
         else {
             if(f->params.size() != $3->size()) { 
                 errorCount++; 
                 yyerror(("Numar incorect de argumente pentru functia '" + *$1 + "'").c_str()); 
             }
             $$ = new ASTNode("call_" + *$1, f->returnType); 
             $$->args = *$3; 
         }
    }
           | ID '.' ID '(' lista_apel ')' { 
         string objName = *$1;
         string methodName = *$3;
         string className = current->getType(objName);
         if (className == "undefined") {
             errorCount++;
             yyerror(("Obiect nedefinit: " + objName).c_str());
             $$ = new ASTNode("err", "void");
         } 
         else {
             SymTable* classScope = current->getClassScope(className);
             if (!classScope) {
                 errorCount++;
                 yyerror(("Variabila '" + objName + "' nu este o instanta a unei clase.").c_str());
                 $$ = new ASTNode("err", "void");
             } 
             else {
                 FuncInfo* f = classScope->getFuncInfo(methodName);
                 if (!f) {
                     errorCount++;
                     yyerror(("Metoda '" + methodName + "' nu este definita in clasa '" + className + "'").c_str());
                     $$ = new ASTNode("err", "void");
                 } 
                 else {
                     if (f->params.size() != $5->size()) {
                         errorCount++;
                         yyerror(("Numar incorect de argumente pentru metoda '" + methodName + "'").c_str());
                     }
                     $$ = new ASTNode("mcall_" + objName + "." + methodName, f->returnType);
                     $$->args = *$5;
                 }
             }
         }
    }
    | NEW ID '(' ')' { 
         if(!current->getClassScope(*$2)) { errorCount++; yyerror("Clasa inexistenta"); }
         $$ = new ASTNode("new", *$2); $$->type = *$2; 
    }
    ;
lista_apel: { $$ = new vector<ASTNode*>(); } | lista_valori { $$ = $1; };
lista_valori: expresie { $$ = new vector<ASTNode*>(); $$->push_back($1); } | lista_valori ',' expresie { $1->push_back($3); $$ = $1; };
apel_print:
      PRINT '(' expresie_generala ')' ';' { $$ = new ASTNode("Print", "void", $3, nullptr); }
    ;
main_function:
      MAIN BGIN statements_bloc END  {if ($3 != nullptr) {
              mainInstructions.push_back($3);
          }}
    ;
%%
void yyerror(const char* s) {
      cout << "error:" << s << " at line: " << yylineno << endl;
}
int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Utilizare: " << argv[0] << " <fisier_intrare>" << endl;
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) { perror("Eroare"); return 1; }
    current = new SymTable("global");
    allScopes.push_back(current);
    yyparse();
    if (errorCount == 0) {
        for (ASTNode* node : mainInstructions) {
            if (node != nullptr) {
                node->eval(current);
            }
        }
    }
    ofstream f("tables.txt"); 
    if(f.is_open()) {
        for(SymTable* s : allScopes) {
            s->printToFile(f);
        }
        f.close();
    }
    return 0;
}
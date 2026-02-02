%{
    #include <stdio.h>
    #include <string>
    #include "parser.tab.h" 
    using namespace std;
%}
%option noyywrap 


%%

"int"|"float"|"char"|"string"|"bool"|"void" {yylval.String = new std::string(yytext); return TYPE;}
"main" {return MAIN;}
"True"  { return BOOL_TRUE; }
"False" { return BOOL_FALSE; }
"new"     {return NEW;}      
"self"    {return SELF;}
"and" { return AND; }
"or" { return OR; }
"xor"  { return XOR; }
"!" {return NOT;}
"<=" {return MAI_MIC_EGAL;}
">=" {return MAI_MARE_EGAL;}
"==" {return EGAL;}
"<"  {return MAI_MIC;}
">"  {return MAI_MARE;}
"="  {return ASSIGN;}
"{" {return BGIN;}
"}" {return END;}
"class" {return CLASS;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"do" {return DO;}
"print" {return PRINT;}
"return" { return RETURN; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.String = new std::string(yytext); return ID; }
\"([^\\\"]|\\.)*\" { yylval.String = new std::string(yytext); return STRING; 
}
[0-9]+\.[0-9]+ { yylval.Float= atof(yytext);return FLOAT;} 
[0-9]+ {yylval.Int = atoi(yytext); return INT;}
[ \t] ; 
\n {yylineno++;} 
. {return yytext[0];}

%%


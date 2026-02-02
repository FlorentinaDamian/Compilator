/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

    #include <vector>
    #include <string>
    

#line 55 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASSIGN = 258,                  /* ASSIGN  */
    CLASS = 259,                   /* CLASS  */
    MAIN = 260,                    /* MAIN  */
    PRINT = 261,                   /* PRINT  */
    BGIN = 262,                    /* BGIN  */
    END = 263,                     /* END  */
    IF = 264,                      /* IF  */
    WHILE = 265,                   /* WHILE  */
    ELSE = 266,                    /* ELSE  */
    FOR = 267,                     /* FOR  */
    DO = 268,                      /* DO  */
    AND = 269,                     /* AND  */
    OR = 270,                      /* OR  */
    XOR = 271,                     /* XOR  */
    NOT = 272,                     /* NOT  */
    MAI_MARE = 273,                /* MAI_MARE  */
    MAI_MARE_EGAL = 274,           /* MAI_MARE_EGAL  */
    MAI_MIC = 275,                 /* MAI_MIC  */
    MAI_MIC_EGAL = 276,            /* MAI_MIC_EGAL  */
    EGAL = 277,                    /* EGAL  */
    NOT_EGAL = 278,                /* NOT_EGAL  */
    NEW = 279,                     /* NEW  */
    SELF = 280,                    /* SELF  */
    INT = 281,                     /* INT  */
    FLOAT = 282,                   /* FLOAT  */
    BOOL_TRUE = 283,               /* BOOL_TRUE  */
    BOOL_FALSE = 284,              /* BOOL_FALSE  */
    STRING = 285,                  /* STRING  */
    ID = 286,                      /* ID  */
    TYPE = 287,                    /* TYPE  */
    RETURN = 288                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

    int Int;
    float Float;
    int Bool;
    std::string* String;
    std::vector<std::string>* typeList;
    class ASTNode* node;
    std::vector<class ASTNode*>* argsList;

#line 115 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

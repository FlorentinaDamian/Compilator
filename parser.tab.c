/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "parser.y"

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

#line 91 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_CLASS = 4,                      /* CLASS  */
  YYSYMBOL_MAIN = 5,                       /* MAIN  */
  YYSYMBOL_PRINT = 6,                      /* PRINT  */
  YYSYMBOL_BGIN = 7,                       /* BGIN  */
  YYSYMBOL_END = 8,                        /* END  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_DO = 13,                        /* DO  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_XOR = 16,                       /* XOR  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_MAI_MARE = 18,                  /* MAI_MARE  */
  YYSYMBOL_MAI_MARE_EGAL = 19,             /* MAI_MARE_EGAL  */
  YYSYMBOL_MAI_MIC = 20,                   /* MAI_MIC  */
  YYSYMBOL_MAI_MIC_EGAL = 21,              /* MAI_MIC_EGAL  */
  YYSYMBOL_EGAL = 22,                      /* EGAL  */
  YYSYMBOL_NOT_EGAL = 23,                  /* NOT_EGAL  */
  YYSYMBOL_NEW = 24,                       /* NEW  */
  YYSYMBOL_SELF = 25,                      /* SELF  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_FLOAT = 27,                     /* FLOAT  */
  YYSYMBOL_BOOL_TRUE = 28,                 /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 29,                /* BOOL_FALSE  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
  YYSYMBOL_ID = 31,                        /* ID  */
  YYSYMBOL_TYPE = 32,                      /* TYPE  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_globale = 45,                   /* globale  */
  YYSYMBOL_global = 46,                    /* global  */
  YYSYMBOL_declaratie_globala = 47,        /* declaratie_globala  */
  YYSYMBOL_start_decl_vars = 48,           /* start_decl_vars  */
  YYSYMBOL_start_decl_objs = 49,           /* start_decl_objs  */
  YYSYMBOL_rest_lista_vars = 50,           /* rest_lista_vars  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_clasa_def = 53,                 /* clasa_def  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_membri_clasa = 55,              /* membri_clasa  */
  YYSYMBOL_membru = 56,                    /* membru  */
  YYSYMBOL_functie_def = 57,               /* functie_def  */
  YYSYMBOL_58_4 = 58,                      /* $@4  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_param_list = 60,                /* param_list  */
  YYSYMBOL_lista_parametri = 61,           /* lista_parametri  */
  YYSYMBOL_parametru = 62,                 /* parametru  */
  YYSYMBOL_corp_functie = 63,              /* corp_functie  */
  YYSYMBOL_statement_cu_decl = 64,         /* statement_cu_decl  */
  YYSYMBOL_statements_bloc = 65,           /* statements_bloc  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_value = 67,                     /* value  */
  YYSYMBOL_atribuire = 68,                 /* atribuire  */
  YYSYMBOL_expresie_generala = 69,         /* expresie_generala  */
  YYSYMBOL_obiect_init = 70,               /* obiect_init  */
  YYSYMBOL_conditie = 71,                  /* conditie  */
  YYSYMBOL_if_statement = 72,              /* if_statement  */
  YYSYMBOL_while_statement = 73,           /* while_statement  */
  YYSYMBOL_for_statement = 74,             /* for_statement  */
  YYSYMBOL_do_while_statement = 75,        /* do_while_statement  */
  YYSYMBOL_block_start = 76,               /* block_start  */
  YYSYMBOL_block_end = 77,                 /* block_end  */
  YYSYMBOL_atom = 78,                      /* atom  */
  YYSYMBOL_expresie_logica = 79,           /* expresie_logica  */
  YYSYMBOL_expresie_comparatie = 80,       /* expresie_comparatie  */
  YYSYMBOL_expresie = 81,                  /* expresie  */
  YYSYMBOL_access = 82,                    /* access  */
  YYSYMBOL_lista_apel = 83,                /* lista_apel  */
  YYSYMBOL_lista_valori = 84,              /* lista_valori  */
  YYSYMBOL_apel_print = 85,                /* apel_print  */
  YYSYMBOL_main_function = 86              /* main_function  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    36,    34,    39,    35,    42,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    62,    63,    67,    68,    69,    73,    74,
      78,    83,    90,    95,   101,   103,   103,   108,   108,   113,
     113,   123,   124,   128,   129,   133,   133,   133,   147,   148,
     152,   153,   157,   161,   162,   171,   172,   177,   181,   187,
     188,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   212,   220,   235,   247,   262,   265,   275,   284,   288,
     294,   299,   307,   312,   319,   324,   325,   326,   327,   330,
     331,   332,   333,   336,   337,   338,   339,   343,   344,   347,
     348,   349,   350,   351,   352,   356,   357,   372,   389,   404,
     423,   441,   476,   482,   482,   483,   483,   486,   490
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN", "CLASS",
  "MAIN", "PRINT", "BGIN", "END", "IF", "WHILE", "ELSE", "FOR", "DO",
  "AND", "OR", "XOR", "NOT", "MAI_MARE", "MAI_MARE_EGAL", "MAI_MIC",
  "MAI_MIC_EGAL", "EGAL", "NOT_EGAL", "NEW", "SELF", "INT", "FLOAT",
  "BOOL_TRUE", "BOOL_FALSE", "STRING", "ID", "TYPE", "RETURN", "'+'",
  "'-'", "'*'", "'/'", "';'", "','", "'('", "')'", "'.'", "$accept",
  "program", "globale", "global", "declaratie_globala", "start_decl_vars",
  "start_decl_objs", "rest_lista_vars", "$@1", "$@2", "clasa_def", "$@3",
  "membri_clasa", "membru", "functie_def", "$@4", "$@5", "param_list",
  "lista_parametri", "parametru", "corp_functie", "statement_cu_decl",
  "statements_bloc", "statement", "value", "atribuire",
  "expresie_generala", "obiect_init", "conditie", "if_statement",
  "while_statement", "for_statement", "do_while_statement", "block_start",
  "block_end", "atom", "expresie_logica", "expresie_comparatie",
  "expresie", "access", "lista_apel", "lista_valori", "apel_print",
  "main_function", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-148)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -148,    31,    25,  -148,     1,    47,    39,   100,  -148,    24,
      67,    67,  -148,  -148,  -148,  -148,  -148,   134,     8,  -148,
     109,  -148,  -148,    71,     9,    74,    74,  -148,   141,  -148,
     107,  -148,   114,   116,   127,   161,   138,   128,  -148,  -148,
    -148,  -148,  -148,   -15,    98,    74,  -148,   176,   145,   153,
    -148,  -148,  -148,  -148,  -148,    52,  -148,  -148,    74,    19,
    -148,  -148,    -2,  -148,   240,  -148,   160,    74,    67,    36,
      74,    74,    74,    54,  -148,  -148,   154,   162,  -148,   216,
     164,  -148,    75,   168,    74,  -148,  -148,   216,   216,   216,
     216,  -148,  -148,    74,    74,    74,   216,   216,   216,   216,
     216,   216,   182,   173,   177,  -148,  -148,  -148,   179,   184,
    -148,  -148,   178,  -148,   180,   194,   197,   176,   227,   172,
     225,  -148,    46,   226,   181,   228,  -148,  -148,  -148,   -13,
     -13,  -148,  -148,   202,    80,  -148,    46,    46,    46,    46,
      46,    46,  -148,  -148,   160,    67,  -148,    92,   231,   263,
     161,   241,    74,  -148,   261,  -148,  -148,   216,   216,   266,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   242,   238,    46,
     243,  -148,   198,   172,    54,    74,  -148,   133,   268,  -148,
     244,   245,  -148,    29,   250,  -148,  -148,   275,   161,   249,
     280,     3,  -148,  -148,  -148,   216,   216,  -148,   224,   172,
      81,   152,  -148,  -148,  -148,  -148
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     4,     0,
      14,    14,     6,     5,     2,    19,    39,    12,    10,     7,
       0,     8,     9,     0,     0,     0,     0,    25,    15,    21,
       0,    98,     0,     0,     0,     0,     0,     0,    65,    66,
      69,    70,    67,    51,     0,     0,    40,    68,     0,     0,
      42,    43,    44,    45,    85,     0,    71,    47,     0,    51,
      68,    13,    55,    77,    78,    11,    28,     0,    14,     0,
       0,     0,     0,     0,    63,    39,     0,     0,    56,    93,
       0,    50,     0,     0,     0,    41,    48,     0,     0,     0,
       0,    46,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    30,    17,    16,     0,     0,
      22,    24,     0,    57,     0,     0,    51,     0,     0,     0,
       0,    53,    95,     0,    94,    52,    49,    72,    54,    86,
      87,    88,    89,    73,    74,    75,    81,    82,    83,    84,
      79,    80,    32,    26,     0,    14,    20,     0,     0,     0,
       0,     0,     0,    64,     0,    92,    90,     0,    93,     0,
      31,    18,    23,    97,    39,    39,    52,     0,     0,    96,
       0,    33,     0,     0,     0,     0,    91,     0,    59,    60,
       0,     0,    27,    51,     0,    34,    35,     0,     0,     0,
      56,     0,    39,    39,    62,     0,     0,    36,     0,     0,
       0,     0,    58,    61,    38,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   -10,  -148,  -148,
    -148,  -148,  -148,  -148,   219,  -148,  -148,  -148,  -148,   146,
    -148,  -148,   -72,   112,   -22,   -66,   -17,  -148,   -68,  -148,
    -148,  -148,  -148,  -145,  -147,  -148,   -48,  -148,   -24,  -148,
     135,  -148,  -148,  -148
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,     9,    10,    11,    21,    68,   145,
      12,    23,    69,   110,    13,    66,   159,   103,   104,   105,
     177,   185,    24,    46,    60,    48,   113,    49,   114,    50,
      51,    52,    53,    75,   154,    54,    62,    63,    64,    56,
     123,   124,    57,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,    22,    47,   119,   115,   165,   196,   118,    61,    65,
      92,    26,    93,    94,    95,    30,    78,    31,    32,    33,
      82,    34,    35,    89,    90,    79,   179,    80,    83,     4,
       5,     3,    15,    36,    37,    38,    39,    40,    41,    42,
      43,   197,    44,   193,   108,   133,   134,   135,    27,    45,
     106,   117,   203,   112,    16,   122,     6,     7,   107,    79,
     190,    80,    19,   129,   130,   131,   132,   128,   109,    79,
      17,    80,   136,   137,   138,   139,   140,   141,    29,    37,
      87,    88,    89,    90,   167,   116,    87,    88,    89,    90,
      91,    58,   172,   173,    93,    55,    95,    47,    36,    37,
      38,    39,    40,    41,    42,    59,    20,   181,   180,    87,
      88,    89,    90,   126,    45,    87,    88,    89,    90,   204,
     198,   199,    36,    37,    38,    39,    40,    41,    42,    59,
     162,    18,    27,   169,   122,   161,    81,    25,    45,    30,
      28,   182,    32,    33,    67,    34,    35,    70,    55,    55,
      47,    47,   117,    55,    71,    47,    72,    36,    37,    38,
      39,    40,    41,    42,   183,   184,    44,    73,    74,    76,
      77,   200,   201,    45,    55,    55,    47,    47,    30,    84,
     153,    32,    33,    85,    34,    35,    87,    88,    89,    90,
     205,    86,   102,   121,   120,   125,    36,    37,    38,    39,
      40,    41,    42,    43,    30,    44,   178,    32,    33,   127,
      34,    35,    45,   142,   143,   147,   144,   146,    95,   148,
     157,   149,    36,    37,    38,    39,    40,    41,    42,    43,
      30,    44,   202,    32,    33,   150,    34,    35,    45,   151,
      36,    37,    38,    39,    40,    41,    42,    59,    36,    37,
      38,    39,    40,    41,    42,    43,    45,    44,    96,    97,
      98,    99,   100,   101,    45,   152,   155,   156,   158,   163,
     164,   168,   166,   171,    87,    88,    89,    90,   175,   187,
     174,   191,   192,   195,   176,   188,   189,   194,   111,   186,
     160,     0,     0,   170
};

static const yytype_int16 yycheck[] =
{
      24,    11,    24,    75,    72,   150,     3,    73,    25,    26,
      58,     3,    14,    15,    16,     6,    31,     8,     9,    10,
      44,    12,    13,    36,    37,    40,   173,    42,    45,     4,
       5,     0,    31,    24,    25,    26,    27,    28,    29,    30,
      31,    38,    33,   188,     8,    93,    94,    95,    40,    40,
      67,    73,   199,    70,     7,    79,    31,    32,    68,    40,
      31,    42,    38,    87,    88,    89,    90,    84,    32,    40,
      31,    42,    96,    97,    98,    99,   100,   101,     7,    25,
      34,    35,    36,    37,   152,    31,    34,    35,    36,    37,
      38,    17,   164,   165,    14,   119,    16,   119,    24,    25,
      26,    27,    28,    29,    30,    31,    39,   175,   174,    34,
      35,    36,    37,    38,    40,    34,    35,    36,    37,    38,
     192,   193,    24,    25,    26,    27,    28,    29,    30,    31,
      38,    31,    40,   157,   158,   145,    38,     3,    40,     6,
      31,     8,     9,    10,     3,    12,    13,    40,   172,   173,
     172,   173,   174,   177,    40,   177,    40,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    40,     7,    31,
      42,   195,   196,    40,   198,   199,   198,   199,     6,     3,
       8,     9,    10,    38,    12,    13,    34,    35,    36,    37,
      38,    38,    32,    31,    40,    31,    24,    25,    26,    27,
      28,    29,    30,    31,     6,    33,     8,     9,    10,    41,
      12,    13,    40,    31,    41,    31,    39,    38,    16,    41,
      39,    41,    24,    25,    26,    27,    28,    29,    30,    31,
       6,    33,     8,     9,    10,    41,    12,    13,    40,    42,
      24,    25,    26,    27,    28,    29,    30,    31,    24,    25,
      26,    27,    28,    29,    30,    31,    40,    33,    18,    19,
      20,    21,    22,    23,    40,    38,    41,    41,    40,    38,
       7,    10,    31,     7,    34,    35,    36,    37,    40,    11,
      38,    31,     7,     3,    41,    41,    41,    38,    69,   177,
     144,    -1,    -1,   158
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,     4,     5,    31,    32,    46,    47,
      48,    49,    53,    57,    86,    31,     7,    31,    31,    38,
      39,    50,    50,    54,    65,     3,     3,    40,    31,     7,
       6,     8,     9,    10,    12,    13,    24,    25,    26,    27,
      28,    29,    30,    31,    33,    40,    66,    67,    68,    70,
      72,    73,    74,    75,    78,    81,    82,    85,    17,    31,
      67,    69,    79,    80,    81,    69,    58,     3,    51,    55,
      40,    40,    40,    40,     7,    76,    31,    42,    31,    40,
      42,    38,    81,    69,     3,    38,    38,    34,    35,    36,
      37,    38,    79,    14,    15,    16,    18,    19,    20,    21,
      22,    23,    32,    60,    61,    62,    69,    50,     8,    32,
      56,    57,    69,    69,    71,    71,    31,    67,    68,    65,
      40,    31,    81,    83,    84,    31,    38,    41,    69,    81,
      81,    81,    81,    79,    79,    79,    81,    81,    81,    81,
      81,    81,    31,    41,    39,    52,    38,    31,    41,    41,
      41,    42,    38,     8,    77,    41,    41,    39,    40,    59,
      62,    50,    38,    38,     7,    76,    31,    71,    10,    81,
      83,     7,    65,    65,    38,    40,    41,    63,     8,    77,
      68,    71,     8,    31,    32,    64,    66,    11,    41,    41,
      31,    31,     7,    76,    38,     3,     3,    38,    65,    65,
      81,    81,     8,    77,    38,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    50,    51,    50,    52,    50,    54,
      53,    55,    55,    56,    56,    58,    59,    57,    60,    60,
      61,    61,    62,    63,    63,    64,    64,    64,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    68,    69,    70,    71,    72,    72,
      73,    74,    75,    76,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      82,    82,    82,    83,    83,    84,    84,    85,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     2,     2,     2,
       2,     4,     2,     4,     0,     0,     4,     0,     6,     0,
       7,     0,     2,     3,     1,     0,     0,    10,     0,     1,
       1,     3,     2,     0,     2,     1,     3,     5,     5,     0,
       2,     2,     1,     1,     1,     1,     2,     1,     2,     3,
       2,     1,     3,     3,     3,     1,     2,     1,    11,     7,
       7,    11,     9,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       4,     6,     4,     0,     1,     1,     3,     5,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: globale main_function  */
#line 59 "parser.y"
                            { if (errorCount == 0) cout << "The program is correct!" << endl; }
#line 1320 "parser.tab.c"
    break;

  case 10: /* start_decl_vars: TYPE ID  */
#line 78 "parser.y"
              {
          currentDeclType = *(yyvsp[-1].String); 
          if(!current->existsId(*(yyvsp[0].String))) current->addVar(*(yyvsp[-1].String), *(yyvsp[0].String));
          else { errorCount++; yyerror("Variabila deja definita global"); }
      }
#line 1330 "parser.tab.c"
    break;

  case 11: /* start_decl_vars: TYPE ID ASSIGN expresie_generala  */
#line 83 "parser.y"
                                       {
          currentDeclType = *(yyvsp[-3].String);
          if(!current->existsId(*(yyvsp[-2].String))) current->addVar(*(yyvsp[-3].String), *(yyvsp[-2].String));
          else { errorCount++; yyerror("Variabila deja definita global"); }
      }
#line 1340 "parser.tab.c"
    break;

  case 12: /* start_decl_objs: ID ID  */
#line 90 "parser.y"
            {
          currentDeclType = *(yyvsp[-1].String); 
          if(current->getClassScope(*(yyvsp[-1].String))) current->addVar(*(yyvsp[-1].String), *(yyvsp[0].String));
          else { errorCount++; yyerror("Tip clasa necunoscut"); }
      }
#line 1350 "parser.tab.c"
    break;

  case 13: /* start_decl_objs: ID ID ASSIGN expresie_generala  */
#line 95 "parser.y"
                                     {
          currentDeclType = *(yyvsp[-3].String);
          if(current->getClassScope(*(yyvsp[-3].String))) current->addVar(*(yyvsp[-3].String), *(yyvsp[-2].String));
          else { errorCount++; yyerror("Tip clasa necunoscut"); }
      }
#line 1360 "parser.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 103 "parser.y"
             {
          if(!current->existsId(*(yyvsp[0].String))) current->addVar(currentDeclType, *(yyvsp[0].String));
          else { errorCount++; yyerror("Variabila deja definita in lista"); }
      }
#line 1369 "parser.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 108 "parser.y"
                                      {
          if(!current->existsId(*(yyvsp[-2].String))) current->addVar(currentDeclType, *(yyvsp[-2].String));
      }
#line 1377 "parser.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 113 "parser.y"
               {
          SymTable* clasaScope = new SymTable(*(yyvsp[0].String), current);
          allScopes.push_back(clasaScope); 
          current->addClass(*(yyvsp[0].String), clasaScope);
          current = clasaScope;
      }
#line 1388 "parser.tab.c"
    break;

  case 20: /* clasa_def: CLASS ID $@3 BGIN membri_clasa END ';'  */
#line 118 "parser.y"
                                  {
          current = current->getParent();
      }
#line 1396 "parser.tab.c"
    break;

  case 23: /* membru: TYPE ID ';'  */
#line 128 "parser.y"
                  { current->addVar(*(yyvsp[-2].String), *(yyvsp[-1].String)); }
#line 1402 "parser.tab.c"
    break;

  case 25: /* $@4: %empty  */
#line 133 "parser.y"
                  { tempParams.clear(); }
#line 1408 "parser.tab.c"
    break;

  case 26: /* $@5: %empty  */
#line 133 "parser.y"
                                                         {
          current->addFunc(*(yyvsp[-5].String), *(yyvsp[-4].String), tempParams);
          SymTable* funcScope = new SymTable(*(yyvsp[-4].String), current);
          allScopes.push_back(funcScope);
          for(auto p : tempParams) funcScope->addVar(p.first, p.second);
          current = funcScope;
      }
#line 1420 "parser.tab.c"
    break;

  case 27: /* functie_def: TYPE ID '(' $@4 param_list ')' $@5 BGIN corp_functie END  */
#line 139 "parser.y"
                              {
          SymTable* fScope = current;
          current = current->getParent();
          FuncInfo* f = current->getFuncInfo(*(yyvsp[-8].String));
          if(f) f->body = (yyvsp[-1].node);
      }
#line 1431 "parser.tab.c"
    break;

  case 32: /* parametru: TYPE ID  */
#line 157 "parser.y"
              { tempParams.push_back({*(yyvsp[-1].String), *(yyvsp[0].String)}); }
#line 1437 "parser.tab.c"
    break;

  case 33: /* corp_functie: %empty  */
#line 161 "parser.y"
      { (yyval.node) = nullptr; }
#line 1443 "parser.tab.c"
    break;

  case 34: /* corp_functie: corp_functie statement_cu_decl  */
#line 162 "parser.y"
                                     {
         if ((yyvsp[-1].node) == nullptr) (yyval.node) = (yyvsp[0].node); 
         else if ((yyvsp[0].node) != nullptr) (yyval.node) = new ASTNode("BLOCK", "sequence", (yyvsp[-1].node), (yyvsp[0].node));
         else (yyval.node) = (yyvsp[-1].node);
    }
#line 1453 "parser.tab.c"
    break;

  case 35: /* statement_cu_decl: statement  */
#line 171 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1459 "parser.tab.c"
    break;

  case 36: /* statement_cu_decl: TYPE ID ';'  */
#line 172 "parser.y"
                  { 
          if(current->existsId(*(yyvsp[-1].String))) { errorCount++; yyerror("Variabila deja definita"); }
          else current->addVar(*(yyvsp[-2].String),*(yyvsp[-1].String));
          (yyval.node) = nullptr;
      }
#line 1469 "parser.tab.c"
    break;

  case 37: /* statement_cu_decl: TYPE ID ASSIGN expresie ';'  */
#line 177 "parser.y"
                                  { 
          current->addVar(*(yyvsp[-4].String),*(yyvsp[-3].String));
          (yyval.node) = new ASTNode(":=", "assign", new ASTNode(*(yyvsp[-3].String), "ID"), (yyvsp[-1].node));
      }
#line 1478 "parser.tab.c"
    break;

  case 38: /* statement_cu_decl: ID ID ASSIGN expresie ';'  */
#line 181 "parser.y"
                                { 
           current->addVar(*(yyvsp[-4].String),*(yyvsp[-3].String));
           (yyval.node) = new ASTNode(":=", "assign", new ASTNode(*(yyvsp[-3].String), "ID"), (yyvsp[-1].node));
      }
#line 1487 "parser.tab.c"
    break;

  case 39: /* statements_bloc: %empty  */
#line 187 "parser.y"
      { (yyval.node) = nullptr; }
#line 1493 "parser.tab.c"
    break;

  case 40: /* statements_bloc: statements_bloc statement  */
#line 188 "parser.y"
                                { 
        if ((yyvsp[-1].node) == nullptr) {
            (yyval.node) = (yyvsp[0].node); 
        } else if ((yyvsp[0].node) != nullptr) {
            (yyval.node) = new ASTNode("BLOCK", "sequence", (yyvsp[-1].node), (yyvsp[0].node));
        } else {
            (yyval.node) = (yyvsp[-1].node);
        }
    }
#line 1507 "parser.tab.c"
    break;

  case 41: /* statement: atribuire ';'  */
#line 200 "parser.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1513 "parser.tab.c"
    break;

  case 42: /* statement: if_statement  */
#line 201 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1519 "parser.tab.c"
    break;

  case 43: /* statement: while_statement  */
#line 202 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1525 "parser.tab.c"
    break;

  case 44: /* statement: for_statement  */
#line 203 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1531 "parser.tab.c"
    break;

  case 45: /* statement: do_while_statement  */
#line 204 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1537 "parser.tab.c"
    break;

  case 46: /* statement: expresie ';'  */
#line 205 "parser.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1543 "parser.tab.c"
    break;

  case 47: /* statement: apel_print  */
#line 206 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1549 "parser.tab.c"
    break;

  case 48: /* statement: obiect_init ';'  */
#line 207 "parser.y"
                           { (yyval.node) = nullptr; }
#line 1555 "parser.tab.c"
    break;

  case 49: /* statement: RETURN expresie ';'  */
#line 208 "parser.y"
                           { (yyval.node) = new ASTNode("RETURN", "return_statement", (yyvsp[-1].node), nullptr); }
#line 1561 "parser.tab.c"
    break;

  case 50: /* statement: RETURN ';'  */
#line 209 "parser.y"
                           { (yyval.node) = new ASTNode("RETURN", "return_statement", nullptr, nullptr); }
#line 1567 "parser.tab.c"
    break;

  case 51: /* value: ID  */
#line 212 "parser.y"
         { 
          if (current->getType(*(yyvsp[0].String)) == "undefined") {
              errorCount++; yyerror(("Variable " + *(yyvsp[0].String) + " not defined").c_str());
          }
          string t = current->getType(*(yyvsp[0].String));
          (yyval.node) = new ASTNode(*(yyvsp[0].String), "ID");
          (yyval.node)->type = t;
      }
#line 1580 "parser.tab.c"
    break;

  case 52: /* value: ID '.' ID  */
#line 220 "parser.y"
               {
    string objName = *(yyvsp[-2].String);
    string memberName = *(yyvsp[0].String);
    string className = current->getType(objName); 
    SymTable* classScope = current->getClassScope(className);
    if (classScope == nullptr) {
        yyerror("Obiectul nu apartine unei clase definite");
        (yyval.node) = new ASTNode(objName + "." + memberName, "undefined");
        (yyval.node)->type = "undefined";
    } else {
        string tipMembru = classScope->getType(memberName); 
        (yyval.node) = new ASTNode(objName + "." + memberName, "ID");
        (yyval.node)->type = tipMembru;
    }
}
#line 1600 "parser.tab.c"
    break;

  case 53: /* value: SELF '.' ID  */
#line 235 "parser.y"
                { 
    string tipMembru = current->getType(*(yyvsp[0].String)); 
    if (tipMembru == "undefined") {
        errorCount++;
        yyerror(("Membrul " + *(yyvsp[0].String) + " nu exista in clasa curenta").c_str());
    }
    (yyval.node) = new ASTNode("self." + *(yyvsp[0].String), "ID"); 
    (yyval.node)->type = tipMembru; 
}
#line 1614 "parser.tab.c"
    break;

  case 54: /* atribuire: value ASSIGN expresie_generala  */
#line 247 "parser.y"
                                    {
          string tipVariabila = (yyvsp[-2].node)->type; 
          string tipExpresie = (yyvsp[0].node)->type; 

          if (tipVariabila == "undefined") {
              errorCount++;
              yyerror(("Variabila sau membrul '" + (yyvsp[-2].node)->root + "' nu este definit/a").c_str());
          }
          else if (tipVariabila != tipExpresie) {
              errorCount++;
              yyerror("Eroare Semantica: tipuri diferite.");
          }
          (yyval.node) = new ASTNode(":=", "void", (yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1633 "parser.tab.c"
    break;

  case 55: /* expresie_generala: expresie_logica  */
#line 262 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1639 "parser.tab.c"
    break;

  case 56: /* obiect_init: ID ID  */
#line 265 "parser.y"
            {
          if (current->getClassScope(*(yyvsp[-1].String)) == nullptr) {
              errorCount++; yyerror("Clasa nu este definita");
          } else {
              current->addVar(*(yyvsp[-1].String), *(yyvsp[0].String));
          }
      }
#line 1651 "parser.tab.c"
    break;

  case 57: /* conditie: expresie_generala  */
#line 275 "parser.y"
                        { 
          if((yyvsp[0].node)->type != "bool") {
              errorCount++;
              yyerror("Eroare Semantica: Conditia trebuie sa fie de tip bool.");
          }
          (yyval.node) = (yyvsp[0].node); 
      }
#line 1663 "parser.tab.c"
    break;

  case 58: /* if_statement: IF '(' conditie ')' BGIN statements_bloc END ELSE BGIN statements_bloc END  */
#line 284 "parser.y"
                                                                                 {
          ASTNode* branches = new ASTNode("BRANCHES", "branches", (yyvsp[-5].node), (yyvsp[-1].node));
          (yyval.node) = new ASTNode("IF", "if_statement", (yyvsp[-8].node), branches);
      }
#line 1672 "parser.tab.c"
    break;

  case 59: /* if_statement: IF '(' conditie ')' BGIN statements_bloc END  */
#line 288 "parser.y"
                                                   {
          ASTNode* branches = new ASTNode("BRANCHES", "branches", (yyvsp[-1].node), nullptr);
          (yyval.node) = new ASTNode("IF", "if_statement", (yyvsp[-4].node), branches);
      }
#line 1681 "parser.tab.c"
    break;

  case 60: /* while_statement: WHILE '(' conditie ')' block_start statements_bloc block_end  */
#line 294 "parser.y"
                                                                   {
          (yyval.node) = new ASTNode("WHILE", "while_statement", (yyvsp[-4].node), (yyvsp[-1].node));
      }
#line 1689 "parser.tab.c"
    break;

  case 61: /* for_statement: FOR '(' atribuire ';' conditie ';' atribuire ')' block_start statements_bloc block_end  */
#line 299 "parser.y"
                                                                                             {
          ASTNode* forBody = new ASTNode("FOR_BODY", "sequence", (yyvsp[-1].node), (yyvsp[-4].node)); 
          ASTNode* forCond = new ASTNode("FOR_COND", "sequence", (yyvsp[-6].node), forBody); 
          (yyval.node) = new ASTNode("FOR", "for_statement", (yyvsp[-8].node), forCond); 
      }
#line 1699 "parser.tab.c"
    break;

  case 62: /* do_while_statement: DO block_start statements_bloc block_end WHILE '(' conditie ')' ';'  */
#line 307 "parser.y"
                                                                          {
          (yyval.node) = new ASTNode("DO_WHILE", "do_while_statement", (yyvsp[-2].node), (yyvsp[-6].node));
      }
#line 1707 "parser.tab.c"
    break;

  case 63: /* block_start: BGIN  */
#line 312 "parser.y"
           {
          current = new SymTable("local_block", current);
          allScopes.push_back(current);
      }
#line 1716 "parser.tab.c"
    break;

  case 64: /* block_end: END  */
#line 319 "parser.y"
          { current = current->getParent(); }
#line 1722 "parser.tab.c"
    break;

  case 65: /* atom: INT  */
#line 324 "parser.y"
              { (yyval.node) = new ASTNode(to_string((yyvsp[0].Int)), "int"); }
#line 1728 "parser.tab.c"
    break;

  case 66: /* atom: FLOAT  */
#line 325 "parser.y"
                  { (yyval.node) = new ASTNode(to_string((yyvsp[0].Float)), "float"); }
#line 1734 "parser.tab.c"
    break;

  case 67: /* atom: STRING  */
#line 326 "parser.y"
                  { (yyval.node) = new ASTNode(*(yyvsp[0].String), "string"); }
#line 1740 "parser.tab.c"
    break;

  case 68: /* atom: value  */
#line 327 "parser.y"
             { 
        (yyval.node) = (yyvsp[0].node);
      }
#line 1748 "parser.tab.c"
    break;

  case 69: /* atom: BOOL_TRUE  */
#line 330 "parser.y"
                  { (yyval.node) = new ASTNode("true", "bool"); }
#line 1754 "parser.tab.c"
    break;

  case 70: /* atom: BOOL_FALSE  */
#line 331 "parser.y"
                  { (yyval.node) = new ASTNode("false", "bool"); }
#line 1760 "parser.tab.c"
    break;

  case 71: /* atom: access  */
#line 332 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1766 "parser.tab.c"
    break;

  case 72: /* atom: '(' expresie_generala ')'  */
#line 333 "parser.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1772 "parser.tab.c"
    break;

  case 73: /* expresie_logica: expresie_logica AND expresie_logica  */
#line 336 "parser.y"
                                          { (yyval.node) = new ASTNode("&&", "operator", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->type = "bool";}
#line 1778 "parser.tab.c"
    break;

  case 74: /* expresie_logica: expresie_logica OR expresie_logica  */
#line 337 "parser.y"
                                          { (yyval.node) = new ASTNode("||", "operator", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->type = "bool";}
#line 1784 "parser.tab.c"
    break;

  case 75: /* expresie_logica: expresie_logica XOR expresie_logica  */
#line 338 "parser.y"
                                          { (yyval.node) = new ASTNode("XOR", "operator", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->type = "bool";}
#line 1790 "parser.tab.c"
    break;

  case 76: /* expresie_logica: NOT expresie_logica  */
#line 339 "parser.y"
                         { 
          (yyval.node) = new ASTNode("!", "operator", (yyvsp[0].node), nullptr); 
          (yyval.node)->type = "bool";
      }
#line 1799 "parser.tab.c"
    break;

  case 77: /* expresie_logica: expresie_comparatie  */
#line 343 "parser.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 1805 "parser.tab.c"
    break;

  case 79: /* expresie_comparatie: expresie EGAL expresie  */
#line 347 "parser.y"
                             { (yyval.node) = new ASTNode("==", "operator", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->type = "bool";}
#line 1811 "parser.tab.c"
    break;

  case 80: /* expresie_comparatie: expresie NOT_EGAL expresie  */
#line 348 "parser.y"
                                 { (yyval.node) = new ASTNode("!=", "operator", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->type = "bool";}
#line 1817 "parser.tab.c"
    break;

  case 81: /* expresie_comparatie: expresie MAI_MARE expresie  */
#line 349 "parser.y"
                                 { (yyval.node) = new ASTNode(">", "operator", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->type = "bool";}
#line 1823 "parser.tab.c"
    break;

  case 82: /* expresie_comparatie: expresie MAI_MARE_EGAL expresie  */
#line 350 "parser.y"
                                      { (yyval.node) = new ASTNode(">=", "operator", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->type = "bool";}
#line 1829 "parser.tab.c"
    break;

  case 83: /* expresie_comparatie: expresie MAI_MIC expresie  */
#line 351 "parser.y"
                                { (yyval.node) = new ASTNode("<", "operator", (yyvsp[-2].node), (yyvsp[0].node));(yyval.node)->type = "bool"; }
#line 1835 "parser.tab.c"
    break;

  case 84: /* expresie_comparatie: expresie MAI_MIC_EGAL expresie  */
#line 352 "parser.y"
                                     { (yyval.node) = new ASTNode("<=", "operator", (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->type = "bool";}
#line 1841 "parser.tab.c"
    break;

  case 85: /* expresie: atom  */
#line 356 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1847 "parser.tab.c"
    break;

  case 86: /* expresie: expresie '+' expresie  */
#line 357 "parser.y"
                            {if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) {
            yyerror("Operanzi de tipuri diferite la adunare!");
            errorCount++;
        }
        else
        if((yyvsp[-2].node)->type=="bool")
        {
            yyerror("Adunarea se poate efectua doar cu tipurile float, int, string");
            errorCount++;
        }
        else
        {
        (yyval.node) = new ASTNode("+", "op", (yyvsp[-2].node), (yyvsp[0].node));}
        (yyval.node)->type = (yyvsp[-2].node)->type; 
    }
#line 1867 "parser.tab.c"
    break;

  case 87: /* expresie: expresie '-' expresie  */
#line 373 "parser.y"
     {
        if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) {
            yyerror("Operanzi de tipuri diferite la scadere!");
            errorCount++;
        }
        else
        if((yyvsp[-2].node)->type=="bool"||(yyvsp[-2].node)->type=="string")
        {
            yyerror("Scaderea se poate efectua doar cu tipurile float, int");
            errorCount++;
        }
        else
        {
        (yyval.node) = new ASTNode("-", "op", (yyvsp[-2].node), (yyvsp[0].node));}
        (yyval.node)->type =  (yyvsp[-2].node)->type; 
    }
#line 1888 "parser.tab.c"
    break;

  case 88: /* expresie: expresie '*' expresie  */
#line 389 "parser.y"
                            { if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type){
            yyerror("Operanzi de tipuri diferite la adunare!");
            errorCount++;
        }
        else
        if((yyvsp[-2].node)->type=="bool"||(yyvsp[-2].node)->type=="string")
        {
            yyerror("Inmultirea se poate efectua doar cu tipurile float, int");
            errorCount++;
        }
        else
        {
        (yyval.node) = new ASTNode("*", "op", (yyvsp[-2].node), (yyvsp[0].node));}
        (yyval.node)->type =  (yyvsp[-2].node)->type; 
    }
#line 1908 "parser.tab.c"
    break;

  case 89: /* expresie: expresie '/' expresie  */
#line 404 "parser.y"
                            { {if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) {
            yyerror("Operanzi de tipuri diferite la adunare!");
            errorCount++;
        }
        else
        if((yyvsp[-2].node)->type=="bool"||(yyvsp[-2].node)->type=="string")
        {
            yyerror("Impartirea se poate efectua doar cu tipurile float, int");
            errorCount++;
        }
        else
        {
        (yyval.node) = new ASTNode("/", "op", (yyvsp[-2].node), (yyvsp[0].node));}
        (yyval.node)->type =  (yyvsp[-2].node)->type; 
    }
    }
#line 1929 "parser.tab.c"
    break;

  case 90: /* access: ID '(' lista_apel ')'  */
#line 423 "parser.y"
                        { 
         FuncInfo* f = current->getFuncInfo(*(yyvsp[-3].String));
         
         if (!f) { 
             errorCount++; 
             string msg = "Functie nedefinita: " + *(yyvsp[-3].String);
             yyerror(msg.c_str()); 
             (yyval.node) = new ASTNode("err", "void"); 
         }
         else {
             if(f->params.size() != (yyvsp[-1].argsList)->size()) { 
                 errorCount++; 
                 yyerror(("Numar incorect de argumente pentru functia '" + *(yyvsp[-3].String) + "'").c_str()); 
             }
             (yyval.node) = new ASTNode("call_" + *(yyvsp[-3].String), f->returnType); 
             (yyval.node)->args = *(yyvsp[-1].argsList); 
         }
    }
#line 1952 "parser.tab.c"
    break;

  case 91: /* access: ID '.' ID '(' lista_apel ')'  */
#line 441 "parser.y"
                                          { 
         string objName = *(yyvsp[-5].String);
         string methodName = *(yyvsp[-3].String);
         string className = current->getType(objName);

         if (className == "undefined") {
             errorCount++;
             yyerror(("Obiect nedefinit: " + objName).c_str());
             (yyval.node) = new ASTNode("err", "void");
         } 
         else {
             SymTable* classScope = current->getClassScope(className);
             if (!classScope) {
                 errorCount++;
                 yyerror(("Variabila '" + objName + "' nu este o instanta a unei clase.").c_str());
                 (yyval.node) = new ASTNode("err", "void");
             } 
             else {
                 FuncInfo* f = classScope->getFuncInfo(methodName);
                 if (!f) {
                     errorCount++;
                     yyerror(("Metoda '" + methodName + "' nu este definita in clasa '" + className + "'").c_str());
                     (yyval.node) = new ASTNode("err", "void");
                 } 
                 else {
                     if (f->params.size() != (yyvsp[-1].argsList)->size()) {
                         errorCount++;
                         yyerror(("Numar incorect de argumente pentru metoda '" + methodName + "'").c_str());
                     }
                     (yyval.node) = new ASTNode("mcall_" + objName + "." + methodName, f->returnType);
                     (yyval.node)->args = *(yyvsp[-1].argsList);
                 }
             }
         }
    }
#line 1992 "parser.tab.c"
    break;

  case 92: /* access: NEW ID '(' ')'  */
#line 476 "parser.y"
                     { 
         if(!current->getClassScope(*(yyvsp[-2].String))) { errorCount++; yyerror("Clasa inexistenta"); }
         (yyval.node) = new ASTNode("new", *(yyvsp[-2].String)); (yyval.node)->type = *(yyvsp[-2].String); 
    }
#line 2001 "parser.tab.c"
    break;

  case 93: /* lista_apel: %empty  */
#line 482 "parser.y"
            { (yyval.argsList) = new vector<ASTNode*>(); }
#line 2007 "parser.tab.c"
    break;

  case 94: /* lista_apel: lista_valori  */
#line 482 "parser.y"
                                                            { (yyval.argsList) = (yyvsp[0].argsList); }
#line 2013 "parser.tab.c"
    break;

  case 95: /* lista_valori: expresie  */
#line 483 "parser.y"
                       { (yyval.argsList) = new vector<ASTNode*>(); (yyval.argsList)->push_back((yyvsp[0].node)); }
#line 2019 "parser.tab.c"
    break;

  case 96: /* lista_valori: lista_valori ',' expresie  */
#line 483 "parser.y"
                                                                                                       { (yyvsp[-2].argsList)->push_back((yyvsp[0].node)); (yyval.argsList) = (yyvsp[-2].argsList); }
#line 2025 "parser.tab.c"
    break;

  case 97: /* apel_print: PRINT '(' expresie_generala ')' ';'  */
#line 486 "parser.y"
                                          { (yyval.node) = new ASTNode("Print", "void", (yyvsp[-2].node), nullptr); }
#line 2031 "parser.tab.c"
    break;

  case 98: /* main_function: MAIN BGIN statements_bloc END  */
#line 490 "parser.y"
                                     {if ((yyvsp[-1].node) != nullptr) {
              mainInstructions.push_back((yyvsp[-1].node));
          }}
#line 2039 "parser.tab.c"
    break;


#line 2043 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 495 "parser.y"


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

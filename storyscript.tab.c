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
#line 1 "storyscript.y"

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <unistd.h>

using namespace std;

extern int yylex();
extern FILE *yyin;
extern int yylineno;
void yyerror(const char *s);
typedef void* YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char *);

map<string,int> symbolTable;
bool hasSyntaxError = false;
bool hasSemanticError = false;

/* AST Node */
struct Node{
    string type;
    string id;
    int value;
    int line;

    Node *left;
    Node *right;

    vector<Node*> children;

    Node(string t){
        type=t;
        value=0;
        line=0; 
        left=right=nullptr;
    }
};

map<string, Node*> functionTable;

Node* root=nullptr;

int tempCount = 0;
int labelCount = 0;

string newTemp() {
    return "t" + to_string(tempCount++);
}

string newLabel() {
    return "L" + to_string(labelCount++);
}

int eval(Node* n);
void exec(Node* n);

string generateExpr(Node* n);
void generateIR(Node* n);

string genExpr(Node* n, int lang);
void generateCode(Node* n, int lang, int indent = 0);
string indentStr(int indent);

int getLine()
{
    return yylineno - 1;
}

void printCompilerHeader()
{
    cout << "\n=====================================\n";
    cout << "        StoryScript Compiler v1.0\n";
    cout << "=====================================\n";
}

void printPhase(string phase)
{
    cout << "[COMPILER] " << phase << " completed.\n";
}

#line 155 "storyscript.tab.c"

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

#include "storyscript.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STORY = 3,                      /* STORY  */
  YYSYMBOL_BEGINS = 4,                     /* BEGINS  */
  YYSYMBOL_ENDSTORY = 5,                   /* ENDSTORY  */
  YYSYMBOL_CHARACTER = 6,                  /* CHARACTER  */
  YYSYMBOL_HOLDS = 7,                      /* HOLDS  */
  YYSYMBOL_WHEN = 8,                       /* WHEN  */
  YYSYMBOL_OTHERWISE = 9,                  /* OTHERWISE  */
  YYSYMBOL_ENDCHOICE = 10,                 /* ENDCHOICE  */
  YYSYMBOL_DURING = 11,                    /* DURING  */
  YYSYMBOL_JOURNEY = 12,                   /* JOURNEY  */
  YYSYMBOL_ENDCYCLE = 13,                  /* ENDCYCLE  */
  YYSYMBOL_CHAPTER = 14,                   /* CHAPTER  */
  YYSYMBOL_TAKES = 15,                     /* TAKES  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_ENDCHAPTER = 17,                /* ENDCHAPTER  */
  YYSYMBOL_NARRATE = 18,                   /* NARRATE  */
  YYSYMBOL_LISTEN = 19,                    /* LISTEN  */
  YYSYMBOL_IDENTIFIER = 20,                /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 21,                    /* NUMBER  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_MUL = 24,                       /* MUL  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_ASSIGN = 27,                    /* ASSIGN  */
  YYSYMBOL_GT = 28,                        /* GT  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_GE = 30,                        /* GE  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_LBRACE = 37,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 38,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 39,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 40,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_statement_list = 45,            /* statement_list  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_declaration = 47,               /* declaration  */
  YYSYMBOL_assignment = 48,                /* assignment  */
  YYSYMBOL_output = 49,                    /* output  */
  YYSYMBOL_input = 50,                     /* input  */
  YYSYMBOL_conditional = 51,               /* conditional  */
  YYSYMBOL_loop = 52,                      /* loop  */
  YYSYMBOL_function = 53,                  /* function  */
  YYSYMBOL_parameter_list = 54,            /* parameter_list  */
  YYSYMBOL_argument_list = 55,             /* argument_list  */
  YYSYMBOL_condition = 56,                 /* condition  */
  YYSYMBOL_expression = 57                 /* expression  */
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
typedef yytype_int8 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   132,   132,   139,   145,   153,   154,   155,   156,   157,
     158,   159,   160,   168,   176,   184,   192,   200,   206,   214,
     223,   234,   244,   254,   270,   277,   287,   293,   305,   312,
     319,   326,   333,   340,   347,   354,   361,   367,   375,   382,
     389,   396,   403,   407,   413,   420
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
  "\"end of file\"", "error", "\"invalid token\"", "STORY", "BEGINS",
  "ENDSTORY", "CHARACTER", "HOLDS", "WHEN", "OTHERWISE", "ENDCHOICE",
  "DURING", "JOURNEY", "ENDCYCLE", "CHAPTER", "TAKES", "RETURN",
  "ENDCHAPTER", "NARRATE", "LISTEN", "IDENTIFIER", "NUMBER", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "ASSIGN", "GT", "LT", "GE", "LE", "EQ",
  "NE", "AND", "OR", "NOT", "LBRACE", "RBRACE", "LPAREN", "RPAREN",
  "SEMICOLON", "COMMA", "$accept", "program", "statement_list",
  "statement", "declaration", "assignment", "output", "input",
  "conditional", "loop", "function", "parameter_list", "argument_list",
  "condition", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-24)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -13,    20,    19,   -24,   183,    -8,     6,    -9,    -9,
      15,    -5,    30,    48,    91,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,    51,    23,   -24,    -9,    -9,    55,
     209,    55,    44,    -5,    29,    24,    -5,   -24,   -24,    -5,
      -5,   -24,   -16,   186,    -9,    -9,   106,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,   121,    47,   205,
     -24,   -24,    59,   182,    28,   -21,   -24,   -24,   -24,    37,
     183,   -15,   -15,   -24,   -24,   234,   234,   234,   234,   234,
     234,   -24,    22,   136,   -24,   -24,   -24,    -5,   152,    47,
      -5,   167,   -24,   -24,   -24,   226,    -5,   -24,   230,   -24
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     5,     6,    11,    10,
       7,     8,     9,    12,     0,    44,    43,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     2,     4,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    19,    16,    14,     0,    26,    37,    42,    34,    35,
       0,    38,    39,    40,    41,    28,    29,    32,    33,    30,
      31,    21,    24,     0,    15,    13,    45,     0,     0,     0,
       0,     0,    27,    20,    25,     0,     0,    23,     0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -24,   -24,   -23,     0,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -17,   -10,     4,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    83,    64,    29,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      34,    47,    48,    49,    50,     1,    46,     3,    57,    49,
      50,    25,    26,    31,    38,    25,    26,    43,    44,    45,
       4,    87,    59,     5,    66,    62,    24,    27,    63,    65,
      28,    41,    42,    23,    33,    32,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    38,    88,    68,    69,
      35,    47,    48,    49,    50,    36,     6,    38,    39,    58,
      91,     7,    40,     8,    89,    61,     9,    82,    86,    10,
      60,    44,    94,    11,    12,    13,    65,    92,     0,    95,
       0,    47,    48,    49,    50,    98,     0,     0,    38,    44,
      45,    38,     6,     0,     0,     0,    37,     7,     0,     8,
      84,     0,     9,     0,     0,    10,     0,     6,     0,    11,
      12,    13,     7,     0,     8,    70,     0,     9,     0,     0,
      10,     0,     6,     0,    11,    12,    13,     7,     0,     8,
       0,     0,     9,     0,    81,    10,     0,     6,     0,    11,
      12,    13,     7,     0,     8,     0,     0,     9,     0,     0,
      10,     0,    90,     6,    11,    12,    13,     0,     7,     0,
       8,     0,    93,     9,     0,     0,    10,     0,     6,     0,
      11,    12,    13,     7,     0,     8,     0,     0,     9,     0,
       0,    10,     0,    96,     6,    11,    12,    13,     0,     7,
       0,     8,     0,     0,     9,     0,     0,    10,     0,     0,
       0,    11,    12,    13,    47,    48,    49,    50,    47,    48,
      49,    50,     0,     0,    51,    52,    53,    54,    55,    56,
       0,     0,     0,    85,     0,     0,    67,    47,    48,    49,
      50,    47,    48,    49,    50,     0,     0,    51,    52,    53,
      54,    55,    56,    97,     0,    67,     0,    99,    47,    48,
      49,    50,    47,    48,    49,    50,    47,    48,    49,    50
};

static const yytype_int8 yycheck[] =
{
      11,    22,    23,    24,    25,     3,    29,    20,    31,    24,
      25,    20,    21,     9,    14,    20,    21,    28,    34,    35,
       0,    42,    33,     4,    40,    36,    20,    36,    39,    40,
      39,    27,    28,    41,    39,    20,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    46,    70,    44,    45,
      20,    22,    23,    24,    25,     7,     1,    57,     7,    15,
      83,     6,    39,     8,    42,    41,    11,    20,    40,    14,
      41,    34,    89,    18,    19,    20,    87,    87,    -1,    90,
      -1,    22,    23,    24,    25,    96,    -1,    -1,    88,    34,
      35,    91,     1,    -1,    -1,    -1,     5,     6,    -1,     8,
      41,    -1,    11,    -1,    -1,    14,    -1,     1,    -1,    18,
      19,    20,     6,    -1,     8,     9,    -1,    11,    -1,    -1,
      14,    -1,     1,    -1,    18,    19,    20,     6,    -1,     8,
      -1,    -1,    11,    -1,    13,    14,    -1,     1,    -1,    18,
      19,    20,     6,    -1,     8,    -1,    -1,    11,    -1,    -1,
      14,    -1,    16,     1,    18,    19,    20,    -1,     6,    -1,
       8,    -1,    10,    11,    -1,    -1,    14,    -1,     1,    -1,
      18,    19,    20,     6,    -1,     8,    -1,    -1,    11,    -1,
      -1,    14,    -1,    16,     1,    18,    19,    20,    -1,     6,
      -1,     8,    -1,    -1,    11,    -1,    -1,    14,    -1,    -1,
      -1,    18,    19,    20,    22,    23,    24,    25,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    41,    -1,    -1,    40,    22,    23,    24,
      25,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    32,    33,    17,    -1,    40,    -1,    17,    22,    23,
      24,    25,    22,    23,    24,    25,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    44,    20,     0,     4,     1,     6,     8,    11,
      14,    18,    19,    20,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    41,    20,    20,    21,    36,    39,    56,
      57,    56,    20,    39,    57,    20,     7,     5,    46,     7,
      39,    56,    56,    57,    34,    35,    45,    22,    23,    24,
      25,    28,    29,    30,    31,    32,    33,    45,    15,    57,
      41,    41,    57,    57,    55,    57,    40,    40,    56,    56,
       9,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    13,    20,    54,    41,    41,    40,    42,    45,    42,
      16,    45,    55,    10,    54,    57,    16,    17,    57,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      51,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     4,     4,     3,     3,     2,     3,
       6,     4,     8,     7,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     1,     1,     4
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: STORY IDENTIFIER BEGINS statement_list ENDSTORY  */
#line 133 "storyscript.y"
{
    root = (yyvsp[-1].node);
}
#line 1406 "storyscript.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 140 "storyscript.y"
{
    Node* n = new Node("block");
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
}
#line 1416 "storyscript.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 146 "storyscript.y"
{
    (yyvsp[-1].node)->children.push_back((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 1425 "storyscript.tab.c"
    break;

  case 12: /* statement: error SEMICOLON  */
#line 160 "storyscript.y"
                    { 
      hasSyntaxError = true; 
      yyerrok; 
      cout << "Recovered from syntax error\n"; 
  }
#line 1435 "storyscript.tab.c"
    break;

  case 13: /* declaration: CHARACTER IDENTIFIER HOLDS expression SEMICOLON  */
#line 169 "storyscript.y"
{
    Node* n = new Node("declare");
    n->id = (yyvsp[-3].id);
    n->left = (yyvsp[-1].node);
    n->line = (yylsp[-3]).first_line;
    (yyval.node) = n;
}
#line 1447 "storyscript.tab.c"
    break;

  case 14: /* declaration: CHARACTER IDENTIFIER HOLDS expression  */
#line 177 "storyscript.y"
{
    hasSyntaxError = true;
    cout << "Line " << (yylsp[0]).first_line << ": Missing ';' after declaration\n";
}
#line 1456 "storyscript.tab.c"
    break;

  case 15: /* assignment: IDENTIFIER HOLDS expression SEMICOLON  */
#line 185 "storyscript.y"
{
    Node* n = new Node("assign");
    n->id = (yyvsp[-3].id);
    n->left = (yyvsp[-1].node);
    n->line = (yylsp[-3]).first_line;
    (yyval.node) = n;
}
#line 1468 "storyscript.tab.c"
    break;

  case 16: /* assignment: IDENTIFIER HOLDS expression  */
#line 193 "storyscript.y"
{
    hasSyntaxError = true;
    cout << "Line " << (yylsp[0]).first_line << ": Missing ';' after assignment\n";
}
#line 1477 "storyscript.tab.c"
    break;

  case 17: /* output: NARRATE expression SEMICOLON  */
#line 201 "storyscript.y"
{
    Node* n = new Node("print");
    n->left = (yyvsp[-1].node);
    (yyval.node) = n;
}
#line 1487 "storyscript.tab.c"
    break;

  case 18: /* output: NARRATE expression  */
#line 207 "storyscript.y"
{
    hasSyntaxError = true;
    cout << "Line " << (yylsp[0]).first_line << ": Missing ';' after narrate\n";
}
#line 1496 "storyscript.tab.c"
    break;

  case 19: /* input: LISTEN IDENTIFIER SEMICOLON  */
#line 215 "storyscript.y"
{
    Node* n = new Node("input");
    n->id = (yyvsp[-1].id);
    (yyval.node) = n;
}
#line 1506 "storyscript.tab.c"
    break;

  case 20: /* conditional: WHEN condition statement_list OTHERWISE statement_list ENDCHOICE  */
#line 224 "storyscript.y"
{
    Node* n = new Node("if");
    n->left = (yyvsp[-4].node);
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-1].node));
    (yyval.node) = n;
}
#line 1518 "storyscript.tab.c"
    break;

  case 21: /* loop: DURING condition statement_list ENDCYCLE  */
#line 235 "storyscript.y"
{
    Node* n = new Node("loop");
    n->left = (yyvsp[-2].node);
    n->children.push_back((yyvsp[-1].node));
    (yyval.node) = n;
}
#line 1529 "storyscript.tab.c"
    break;

  case 22: /* function: CHAPTER IDENTIFIER TAKES parameter_list statement_list RETURN expression ENDCHAPTER  */
#line 245 "storyscript.y"
{
    Node* n = new Node("function");
    n->id = (yyvsp[-6].id);
    n->line = (yylsp[-6]).first_line;
    n->children.push_back((yyvsp[-4].node));
    n->children.push_back((yyvsp[-3].node));
    n->left = (yyvsp[-1].node);
    (yyval.node) = n;
}
#line 1543 "storyscript.tab.c"
    break;

  case 23: /* function: CHAPTER IDENTIFIER TAKES parameter_list RETURN expression ENDCHAPTER  */
#line 255 "storyscript.y"
{
    Node* n = new Node("function");
    n->id = (yyvsp[-5].id);
    n->line = (yylsp[-5]).first_line;
    n->children.push_back((yyvsp[-3].node));

    Node* emptyBody = new Node("block");   // ✅ empty body
    n->children.push_back(emptyBody);

    n->left = (yyvsp[-1].node);
    (yyval.node) = n;
}
#line 1560 "storyscript.tab.c"
    break;

  case 24: /* parameter_list: IDENTIFIER  */
#line 271 "storyscript.y"
{
    Node* n = new Node("param");
    n->id = (yyvsp[0].id);
    n->line = (yylsp[0]).first_line;
    (yyval.node) = n;
}
#line 1571 "storyscript.tab.c"
    break;

  case 25: /* parameter_list: IDENTIFIER COMMA parameter_list  */
#line 278 "storyscript.y"
{
    Node* n = new Node("param");
    n->id = (yyvsp[-2].id);
    if((yyvsp[0].node)) n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
}
#line 1582 "storyscript.tab.c"
    break;

  case 26: /* argument_list: expression  */
#line 288 "storyscript.y"
{
    Node* n = new Node("arg");
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
}
#line 1592 "storyscript.tab.c"
    break;

  case 27: /* argument_list: expression COMMA argument_list  */
#line 294 "storyscript.y"
{
    Node* n = new Node("arg");
    n->children.push_back((yyvsp[-2].node));
    if((yyvsp[0].node)) n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
}
#line 1603 "storyscript.tab.c"
    break;

  case 28: /* condition: expression GT expression  */
#line 306 "storyscript.y"
{
    Node* n = new Node("gt");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1614 "storyscript.tab.c"
    break;

  case 29: /* condition: expression LT expression  */
#line 313 "storyscript.y"
{
    Node* n = new Node("lt");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1625 "storyscript.tab.c"
    break;

  case 30: /* condition: expression EQ expression  */
#line 320 "storyscript.y"
{
    Node* n = new Node("eq");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1636 "storyscript.tab.c"
    break;

  case 31: /* condition: expression NE expression  */
#line 327 "storyscript.y"
{
    Node* n = new Node("ne");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1647 "storyscript.tab.c"
    break;

  case 32: /* condition: expression GE expression  */
#line 334 "storyscript.y"
{
    Node* n = new Node("ge");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1658 "storyscript.tab.c"
    break;

  case 33: /* condition: expression LE expression  */
#line 341 "storyscript.y"
{
    Node* n = new Node("le");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1669 "storyscript.tab.c"
    break;

  case 34: /* condition: condition AND condition  */
#line 348 "storyscript.y"
{
    Node* n = new Node("and");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1680 "storyscript.tab.c"
    break;

  case 35: /* condition: condition OR condition  */
#line 355 "storyscript.y"
{
    Node* n = new Node("or");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1691 "storyscript.tab.c"
    break;

  case 36: /* condition: NOT condition  */
#line 362 "storyscript.y"
{
    Node* n = new Node("not");
    n->left = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1701 "storyscript.tab.c"
    break;

  case 37: /* condition: LPAREN condition RPAREN  */
#line 368 "storyscript.y"
{
    (yyval.node) = (yyvsp[-1].node);
}
#line 1709 "storyscript.tab.c"
    break;

  case 38: /* expression: expression PLUS expression  */
#line 376 "storyscript.y"
{
    Node* n = new Node("add");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1720 "storyscript.tab.c"
    break;

  case 39: /* expression: expression MINUS expression  */
#line 383 "storyscript.y"
{
    Node* n = new Node("sub");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1731 "storyscript.tab.c"
    break;

  case 40: /* expression: expression MUL expression  */
#line 390 "storyscript.y"
{
    Node* n = new Node("mul");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1742 "storyscript.tab.c"
    break;

  case 41: /* expression: expression DIV expression  */
#line 397 "storyscript.y"
{
    Node* n = new Node("div");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1753 "storyscript.tab.c"
    break;

  case 42: /* expression: LPAREN expression RPAREN  */
#line 404 "storyscript.y"
{
    (yyval.node) = (yyvsp[-1].node);
}
#line 1761 "storyscript.tab.c"
    break;

  case 43: /* expression: NUMBER  */
#line 408 "storyscript.y"
{
    Node* n = new Node("num");
    n->value = (yyvsp[0].num);
    (yyval.node) = n;
}
#line 1771 "storyscript.tab.c"
    break;

  case 44: /* expression: IDENTIFIER  */
#line 414 "storyscript.y"
{
    Node* n = new Node("var");
    n->id = (yyvsp[0].id);
    n->line = (yylsp[0]).first_line;
    (yyval.node) = n;
}
#line 1782 "storyscript.tab.c"
    break;

  case 45: /* expression: IDENTIFIER LPAREN argument_list RPAREN  */
#line 421 "storyscript.y"
{
    Node* n = new Node("call");
    n->id = (yyvsp[-3].id);
    n->children.push_back((yyvsp[-1].node));
    n->line = (yylsp[-3]).first_line;
    (yyval.node) = n;
}
#line 1794 "storyscript.tab.c"
    break;


#line 1798 "storyscript.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 430 "storyscript.y"


/* expression evaluation */

int eval(Node* n)
{
    if(n->type=="num") return n->value;

    if(n->type=="var")
    {
        if(symbolTable.find(n->id) == symbolTable.end())
        {
            cout << "Semantic Error (Line " << n->line << "): Variable '" << n->id << "' not declared\n";
            hasSemanticError = true;
            return 0; // continue execution
        }
        return symbolTable[n->id];
    }

    if(n->type=="add") return eval(n->left)+eval(n->right);
    if(n->type=="sub") return eval(n->left)-eval(n->right);
    if(n->type=="mul") return eval(n->left)*eval(n->right);
    if(n->type=="div") return eval(n->left)/eval(n->right);

    if(n->type=="gt") return eval(n->left)>eval(n->right);
    if(n->type=="lt") return eval(n->left)<eval(n->right);
    if(n->type=="and") return eval(n->left)&&eval(n->right);
    if(n->type=="or") return eval(n->left)||eval(n->right);
    if(n->type=="not") return !eval(n->left);
    if(n->type=="eq") return eval(n->left)==eval(n->right);
    if(n->type=="ne") return eval(n->left)!=eval(n->right);
    if(n->type=="ge") return eval(n->left)>=eval(n->right);
    if(n->type=="le") return eval(n->left)<=eval(n->right);
    
    if(n->type == "call"){

       if(functionTable.find(n->id) == functionTable.end()){
           cout << "Semantic Error (Line " << n->line 
             << "): Function '" << n->id << "' not defined\n";
           hasSemanticError = true;
           return 0;
       }

       Node* func = functionTable[n->id];


       map<string,int> oldTable = symbolTable;

    
       vector<string> params;
       Node* p = func->children[0];

       while(p){
           params.push_back(p->id);
           if(p->children.empty()) break;
           p = p->children[0];
       }

   
       vector<int> args;
       Node* argNode = n->children[0];

       while(argNode){
           args.push_back(eval(argNode->children[0]));

           if(argNode->children.size() < 2) break;
           argNode = argNode->children[1];
       }

    
       if(params.size() != args.size()){
           cout << "Semantic Error (Line " << n->line 
             << "): Argument count mismatch in function '" << n->id << "'\n";
           hasSemanticError = true;
           return 0;
       }

    
       symbolTable.clear();

       for(int i = 0; i < params.size(); i++){
           symbolTable[params[i]] = args[i];
       }

   
       exec(func->children[1]);

    
       int ret = eval(func->left);

       symbolTable = oldTable;

       return ret;
    }

    return 0;
}

void checkParams(Node* p, string fname) {
    map<string, bool> seen;

    while(p){
        if(seen[p->id]){
            cout << "Semantic Error (Line " << p->line 
             << "): Duplicate parameter '" << p->id 
             << "' in function '" << fname << "'\n";
            hasSemanticError = true;
            return;
        }
        seen[p->id] = true;

        if(p->children.empty()) break;
        p = p->children[0];
    }
}

/* execute AST */

void exec(Node* n)
{
    if(!n) return;

    if(n->type=="block"){
        for(auto c:n->children)
            exec(c);
    }

    else if(n->type=="declare"){
        symbolTable[n->id]=eval(n->left);
        cout<<"Declared "<<n->id<<" = "<<symbolTable[n->id]<<endl;
    }

    else if(n->type=="assign"){
        int val = eval(n->left);

        if(symbolTable.find(n->id) == symbolTable.end()){
            cout << "Semantic Error (Line " << n->line << "): Variable '" << n->id << "' not declared\n";
            hasSemanticError = true;
        } else {
        symbolTable[n->id] = val;
        cout << n->id << " updated to " << symbolTable[n->id] << endl;
       }
    }

    else if(n->type=="print"){
        cout<<eval(n->left)<<endl;
    }

    else if(n->type=="input"){
        int val = 0;

        cout<<"Enter value for "<<n->id<<": ";

        if(!(cin >> val)){
             cout<<"Invalid input. Default value 0 used.\n";
             cin.clear();
        }

        symbolTable[n->id]=val;
   }

    else if(n->type=="if"){
        if(eval(n->left)){
             if(n->children.size()>0) exec(n->children[0]);
        }
        else{
             if(n->children.size()>1) exec(n->children[1]);
        }
    }

    else if(n->type=="loop"){
        while(eval(n->left)){
            exec(n->children[0]);
        }
    }

    else if(n->type=="function"){

    
        if(functionTable.find(n->id) != functionTable.end()){
            cout << "Semantic Error (Line " << n->line 
             << "): Function '" << n->id << "' already defined\n";
            hasSemanticError = true;
            return;
        }

    
        functionTable[n->id] = n;


        if(n->left == nullptr){
            cout << "Semantic Error (Line " << n->line 
             << "): Function '" << n->id 
             << "' missing return value\n";
            hasSemanticError = true;
        }

    
        checkParams(n->children[0], n->id);

        cout << "Function " << n->id << " registered" << endl;
     }
}

// ================= INTERMEDIATE CODE =================

string generateExpr(Node* n) {
    if (!n) return "";
    if (n->type == "num") return to_string(n->value);
    if (n->type == "var") return n->id;
    if (n->type == "call") {
       string temp = newTemp();

       string args = "";
       Node* argNode = n->children[0];

       vector<string> argList;

       while(argNode){
           argList.push_back(generateExpr(argNode->children[0]));

           if(argNode->children.size() < 2) break;
           argNode = argNode->children[1];
       }

       for(int i = 0; i < argList.size(); i++){
           args += argList[i];
           if(i != argList.size() - 1) args += ", ";
       }

       cout << temp << " = call " << n->id << ", " << args << endl;

       return temp;
    }
    

    string left = generateExpr(n->left);
    string right = generateExpr(n->right);

    string temp = newTemp();

    string op;
    if (n->type == "add") op = "+";
    if (n->type == "sub") op = "-";
    if (n->type == "mul") op = "*";
    if (n->type == "div") op = "/";
    if (n->type == "gt") op = ">";
    if (n->type == "lt") op = "<";
    if (n->type == "and") op = "&&";
    if (n->type == "or") op = "||";
    if (n->type == "eq") op = "==";
    if (n->type == "ne") op = "!=";
    if (n->type == "ge") op = ">=";
    if (n->type == "le") op = "<=";

    cout << temp << " = " << left << " " << op << " " << right << endl;

    return temp;
}

void generateIR(Node* n) {
    if (!n) return;

    if (n->type == "block") {
        for (auto c : n->children)
            generateIR(c);
    }

    else if (n->type == "declare") {
        string val = generateExpr(n->left);
        cout << n->id << " = " << val << endl;
    }

    else if (n->type == "assign") {
        string val = generateExpr(n->left);
        cout << n->id << " = " << val << endl;
    }

    else if (n->type == "print") {
        string val = generateExpr(n->left);
        cout << "print " << val << endl;
    }

    else if (n->type == "input") {
        cout << "read " << n->id << endl;
    }

    else if (n->type == "if") {
        string cond = generateExpr(n->left);

        string L1 = newLabel();
        string L2 = newLabel();

        cout << "ifFalse " << cond << " goto " << L1 << endl;

        generateIR(n->children[0]);
        cout << "goto " << L2 << endl;

        cout << L1 << ":" << endl;
        if (n->children.size() > 1)
            generateIR(n->children[1]);

        cout << L2 << ":" << endl;
    }

    else if (n->type == "loop") {
        string Lstart = newLabel();
        string Lend = newLabel();

        cout << Lstart << ":" << endl;

        string cond = generateExpr(n->left);
        cout << "ifFalse " << cond << " goto " << Lend << endl;

        generateIR(n->children[0]);

        cout << "goto " << Lstart << endl;
        cout << Lend << ":" << endl;
    }

    else if (n->type == "function") {
        cout << "\nfunction " << n->id << ":" << endl;

        Node* params = n->children[0];
        while (params) {
            cout << "param " << params->id << endl;
            if (params->children.empty()) break;
            params = params->children[0];
        }

        generateIR(n->children[1]);

        string ret = generateExpr(n->left);
        cout << "return " << ret << endl;

        cout << "end function\n";
    }
}

void generateFunctions(Node* n, int lang) {
    if (!n) return;

    if (n->type == "function") {
        generateCode(n, lang, 0); // print globally
    }

    for (auto c : n->children)
        generateFunctions(c, lang);
}

// ================= TARGET CODE GENERATION =================

string indentStr(int indent) {
    return string(indent * 4, ' ');
}

string genExpr(Node* n, int lang) {
    if (n->type == "num") return to_string(n->value);
    if (n->type == "var") return n->id;
    if (n->type == "call") {
       string args = "";

       Node* argNode = n->children[0];

       vector<string> argList;

       while(argNode){
           argList.push_back(genExpr(argNode->children[0], lang));

           if(argNode->children.size() < 2) break;
           argNode = argNode->children[1];
       }

       for(int i = 0; i < argList.size(); i++){
           args += argList[i];
           if(i != argList.size() - 1) args += ", ";
       }

       return n->id + "(" + args + ")";
   }
    

    string left = genExpr(n->left, lang);
    string right = (n->right) ? genExpr(n->right, lang) : "";

    string op;

    if (n->type == "add") op = "+";
    if (n->type == "sub") op = "-";
    if (n->type == "mul") op = "*";
    if (n->type == "div") op = "/";
    if (n->type == "gt") op = ">";
    if (n->type == "lt") op = "<";
    if (n->type == "eq") op = "==";
    if (n->type == "ne") op = "!=";
    if (n->type == "ge") op = ">=";
    if (n->type == "le") op = "<=";

    if (n->type == "and")
        op = (lang == 4) ? "and" : "&&";

    if (n->type == "or")
        op = (lang == 4) ? "or" : "||";

    if (n->type == "not") {
        if (lang == 4)
            return "not " + left;
        else
            return "!(" + left + ")";
    }

    return "(" + left + " " + op + " " + right + ")";
}

void generateCode(Node* n, int lang, int indent) {
    if (!n) return;

    string ind = indentStr(indent);

    if (n->type == "block") {
       for (auto c : n->children) {
           if (c->type != "function") 
               generateCode(c, lang, indent);
      }
    }

    else if (n->type == "declare") {
        string val = genExpr(n->left, lang);

        if (lang == 4)
            cout << ind << n->id << " = " << val << "\n";
        else
            cout << ind << "int " << n->id << " = " << val << ";\n";
    }

    else if (n->type == "assign") {
        string val = genExpr(n->left, lang);
        cout << ind << n->id << " = " << val << (lang==4 ? "" : ";") << "\n";
    }

    else if (n->type == "print") {
        string val = genExpr(n->left, lang);

        if (lang == 1)
            cout << ind << "printf(\"%d\\n\", " << val << ");\n";
        else if (lang == 2)
            cout << ind << "cout << " << val << " << endl;\n";
        else if (lang == 3)
            cout << ind << "System.out.println(" << val << ");\n";
        else
            cout << ind << "print(" << val << ")\n";
    }

    else if (n->type == "input") {
        if (lang == 1)
            cout << ind << "scanf(\"%d\", &" << n->id << ");\n";
        else if (lang == 2)
            cout << ind << "cin >> " << n->id << ";\n";
        else if (lang == 3)
            cout << ind << n->id << " = scanner.nextInt();\n";
        else
            cout << ind << n->id << " = int(input())\n";
    }

    else if (n->type == "if") {
        string cond = genExpr(n->left, lang);

        if (lang == 4)
            cout << ind << "if " << cond << ":\n";
        else
            cout << ind << "if (" << cond << ") {\n";

        generateCode(n->children[0], lang, indent + 1);

        if (lang == 4)
            cout << ind << "else:\n";
        else
            cout << ind << "} else {\n";

        if (n->children.size() > 1)
            generateCode(n->children[1], lang, indent + 1);

        if (lang != 4)
            cout << ind << "}\n";
    }

    else if (n->type == "loop") {
        string cond = genExpr(n->left, lang);

        if (lang == 4)
            cout << ind << "while " << cond << ":\n";
        else
            cout << ind << "while (" << cond << ") {\n";

        generateCode(n->children[0], lang, indent + 1);

        if (lang != 4)
            cout << ind << "}\n";
    }

    else if (n->type == "function") {

    // extract parameters
    vector<string> params;
    Node* p = n->children[0];

    while (p) {
        params.push_back(p->id);
        if (p->children.empty()) break;
        p = p->children[0];
    }

    if (lang == 4) {
        cout << "\ndef " << n->id << "(";
    }
    else if (lang == 3) {
        cout << "\nstatic int " << n->id << "(";
    }
    else {
        cout << "\nint " << n->id << "(";
    }

    // print params
    for (int i = 0; i < params.size(); i++) {
        if (lang == 4)
            cout << params[i];
        else
            cout << "int " << params[i];

        if (i != params.size() - 1) cout << ", ";
    }

    if (lang == 4)
        cout << "):\n";
    else
        cout << ") {\n";

    generateCode(n->children[1], lang, indent + 1);

    string ret = genExpr(n->left, lang);
    cout << indentStr(indent+1) << "return " << ret << (lang==4 ? "" : ";") << "\n";

    if (lang != 4)
        cout << "}\n";
}
}

void printErrorBanner()
{
    cout << "\n=====================================\n";
    cout << "           COMPILATION ERROR\n";
    cout << "=====================================\n";
}

void printAST(Node* n, int depth = 0)
{
    if(!n) return;

    for(int i=0;i<depth;i++)
        cout << "  ";

    cout << "|-- " << n->type;

    if(n->id != "")
        cout << " (" << n->id << ")";

    if(n->type == "num")
        cout << " = " << n->value;

    cout << endl;

    if(n->left)
        printAST(n->left, depth+1);

    if(n->right)
        printAST(n->right, depth+1);

    for(auto c : n->children)
        printAST(c, depth+1);
}

void printSymbolTable()
{
    cout << "\n---------------------------------\n";
    cout << "Symbol Table\n";
    cout << "---------------------------------\n";

    for(auto &p : symbolTable)
    {
        cout << p.first << " : " << p.second << endl;
    }

    cout << "---------------------------------\n";
}

void yyerror(const char *s)
{
    extern int yylineno;

    hasSyntaxError = true;

    printErrorBanner();

    cout << "Line: " << getLine() << endl;

    if(string(s) == "syntax error")
        cout << "Error: Invalid syntax near this line\n";
    else
        cout << "Error: " << s << endl;

    cout << "=====================================\n";
}

int main(int argc, char* argv[])
{
    printCompilerHeader();

    int targetLang;
    cout << "\nSelect Target Language:\n";
    cout << "1. C\n2. C++\n3. Java\n4. Python\nChoice: ";
    cin >> targetLang;

    cout << "\n[COMPILER] Starting Lexical Analysis...\n";

    /* Input handling */
    if(argc > 1)
    {
        FILE *fp = fopen(argv[1], "r");

        if(!fp)
        {
            cout << "Error: Cannot open " << argv[1] << endl;
            return 1;
        }

        yyin = fp;
    }
    else
    {
        cout << "[COMPILER] Enter StoryScript program (CTRL+D to finish)\n\n";

        string program;
        char buffer[1024];
        int n;

        while((n = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
        {
            program.append(buffer, n);
        }
        yylineno = 1;

        yy_scan_string(program.c_str());
    }

    /* Parsing */
    yyparse();

    /* STOP if syntax error */
    if(hasSyntaxError){
        cout << "\n[COMPILER] Syntax Analysis Failed\n";
        return 1;
    }

    printPhase("Lexical Analysis");
    printPhase("Syntax Analysis");
    printPhase("AST Generation");

    cout << "\n================ AST ================\n";
    if(root)
        printAST(root);
    cout << "=====================================\n";

    
    cout << "\n[COMPILER] Executing Program...\n\n";

    exec(root);

    
    if(hasSemanticError){
        cout << "\n[COMPILER] Semantic Analysis Failed\n";
        return 1;
    }

    cout << "\n[COMPILER] Intermediate Code Generation...\n\n";
    generateIR(root);
    
    cout << "\n[COMPILER] Target Code Generation...\n\n";
    
    

   /* ================= C ================= */
    if (targetLang == 1) {
       cout << "#include <stdio.h>\n\n";

       generateFunctions(root, targetLang);

       cout << "int main() {\n";
       generateCode(root, targetLang);
       cout << "return 0;\n}\n";
   }

   /* ================= C++ ================= */
    else if (targetLang == 2) {
       cout << "#include <iostream>\nusing namespace std;\n\n";

       generateFunctions(root, targetLang);   

       cout << "int main() {\n";
       generateCode(root, targetLang);
       cout << "return 0;\n}\n";
    }

    /* ================= JAVA ================= */
    else if (targetLang == 3) {
       cout << "import java.util.*;\n\n";
       cout << "public class Main {\n";
       cout << "    static Scanner scanner = new Scanner(System.in);\n\n";

       generateFunctions(root, targetLang);

       cout << "    public static void main(String[] args) {\n";
       generateCode(root, targetLang);
       cout << "    }\n";
       cout << "}\n";
    }

    /* ================= PYTHON ================= */
    else if (targetLang == 4) {

       generateFunctions(root, targetLang);   // functions first

       cout << "\nif __name__ == '__main__':\n";
       generateCode(root, targetLang, 1);     // indent main
    }

    

    

    printPhase("Execution");

    printSymbolTable();

    cout << "\n=====================================\n";
    cout << "Compilation Successful\n";
    cout << "=====================================\n";

    return 0;
}

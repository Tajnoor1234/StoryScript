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

Node* root=nullptr;

int eval(Node* n);
void exec(Node* n);

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

#line 135 "storyscript.tab.c"

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
  YYSYMBOL_condition = 55,                 /* condition  */
  YYSYMBOL_expression = 56                 /* expression  */
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
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  79

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
       0,   111,   111,   118,   126,   132,   133,   134,   135,   136,
     137,   138,   139,   147,   155,   163,   171,   179,   185,   193,
     202,   213,   224,   236,   242,   254,   261,   268,   275,   282,
     288,   297,   304,   311,   318,   325,   331
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
  "conditional", "loop", "function", "parameter_list", "condition",
  "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-20)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-5)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    -6,    16,    15,   -20,    89,   -16,     9,   108,   108,
      22,    20,    24,    45,    46,    73,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,    52,   -20,   -20,   108,   108,    12,
     130,    42,    34,   -19,    23,    20,   -20,   -20,    20,   -20,
      64,   108,   108,    54,    20,    20,    20,    20,    20,    20,
      57,    53,   -20,   -20,   -13,    44,   -20,   -20,    41,   104,
     -17,   -17,   -20,   -20,   138,   138,   -20,    38,   119,   -20,
     -20,    78,    53,    80,   -20,   -20,    20,   126,   -20
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,    11,    10,
       7,     8,     9,    12,     0,    36,    35,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     2,     3,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    19,    16,    14,    30,    27,    28,     0,
      31,    32,    33,    34,    25,    26,    21,    23,     0,    15,
      13,     0,     0,     0,    20,    24,     0,     0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,   -14,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,    29,    30,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    68,    29,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      33,    37,     1,    44,    45,    46,    47,    46,    47,    44,
      45,    46,    47,     6,     3,    43,     4,    50,     7,     5,
       8,    -4,    52,     9,    54,    23,    10,    55,    69,    24,
      11,    12,    13,    60,    61,    62,    63,    64,    65,    31,
      25,    26,    32,     6,    34,    71,    41,    42,     7,    51,
       8,    36,    35,     9,    73,    -4,    10,    39,    40,    38,
      11,    12,    13,    59,    53,    77,    44,    45,    46,    47,
      66,    57,    58,    67,     6,    41,    41,    42,    -4,     7,
      72,     8,    -4,    -4,     9,    70,    -4,    10,    74,    -4,
       6,    11,    12,    13,    -4,     7,    76,     8,    41,    42,
       9,    75,     0,    10,    56,     6,     0,    11,    12,    13,
       7,     0,     8,     0,    -4,     9,     0,     0,    10,     0,
       6,     0,    11,    12,    13,     7,     0,     8,    25,    26,
       9,     0,     0,    10,     0,    -4,     0,    11,    12,    13,
       0,     0,     0,    78,    27,     0,     0,    28,    44,    45,
      46,    47,    44,    45,    46,    47,     0,     0,    48,    49,
      44,    45,    46,    47
};

static const yytype_int8 yycheck[] =
{
      11,    15,     3,    22,    23,    24,    25,    24,    25,    22,
      23,    24,    25,     1,    20,    29,     0,    31,     6,     4,
       8,     9,    41,    11,    35,    41,    14,    38,    41,    20,
      18,    19,    20,    44,    45,    46,    47,    48,    49,     9,
      20,    21,    20,     1,    20,    59,    34,    35,     6,    15,
       8,     5,     7,    11,    68,    13,    14,    27,    28,     7,
      18,    19,    20,     9,    41,    76,    22,    23,    24,    25,
      13,    41,    42,    20,     1,    34,    34,    35,     5,     6,
      42,     8,     9,    10,    11,    41,    13,    14,    10,    16,
       1,    18,    19,    20,     5,     6,    16,     8,    34,    35,
      11,    72,    -1,    14,    40,     1,    -1,    18,    19,    20,
       6,    -1,     8,    -1,    10,    11,    -1,    -1,    14,    -1,
       1,    -1,    18,    19,    20,     6,    -1,     8,    20,    21,
      11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,    20,
      -1,    -1,    -1,    17,    36,    -1,    -1,    39,    22,    23,
      24,    25,    22,    23,    24,    25,    -1,    -1,    28,    29,
      22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    44,    20,     0,     4,     1,     6,     8,    11,
      14,    18,    19,    20,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    41,    20,    20,    21,    36,    39,    55,
      56,    55,    20,    56,    20,     7,     5,    45,     7,    55,
      55,    34,    35,    45,    22,    23,    24,    25,    28,    29,
      45,    15,    41,    41,    56,    56,    40,    55,    55,     9,
      56,    56,    56,    56,    56,    56,    13,    20,    54,    41,
      41,    45,    42,    45,    10,    54,    16,    56,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      51,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     4,     4,     3,     3,     2,     3,
       6,     4,     8,     1,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     1,     1
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
#line 112 "storyscript.y"
{
    root = (yyvsp[-1].node);
}
#line 1358 "storyscript.tab.c"
    break;

  case 3: /* statement_list: statement statement_list  */
#line 119 "storyscript.y"
{
    Node* n = new Node("block");
    n->children.push_back((yyvsp[-1].node));
    if((yyvsp[0].node)) n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
}
#line 1369 "storyscript.tab.c"
    break;

  case 4: /* statement_list: %empty  */
#line 126 "storyscript.y"
{
    (yyval.node) = nullptr;
}
#line 1377 "storyscript.tab.c"
    break;

  case 12: /* statement: error SEMICOLON  */
#line 139 "storyscript.y"
                    { 
      hasSyntaxError = true; 
      yyerrok; 
      cout << "Recovered from syntax error\n"; 
  }
#line 1387 "storyscript.tab.c"
    break;

  case 13: /* declaration: CHARACTER IDENTIFIER HOLDS expression SEMICOLON  */
#line 148 "storyscript.y"
{
    Node* n = new Node("declare");
    n->id = (yyvsp[-3].id);
    n->left = (yyvsp[-1].node);
    n->line = (yylsp[-3]).first_line;
    (yyval.node) = n;
}
#line 1399 "storyscript.tab.c"
    break;

  case 14: /* declaration: CHARACTER IDENTIFIER HOLDS expression  */
#line 156 "storyscript.y"
{
    hasSyntaxError = true;
    cout << "Line " << (yylsp[0]).first_line << ": Missing ';' after declaration\n";
}
#line 1408 "storyscript.tab.c"
    break;

  case 15: /* assignment: IDENTIFIER HOLDS expression SEMICOLON  */
#line 164 "storyscript.y"
{
    Node* n = new Node("assign");
    n->id = (yyvsp[-3].id);
    n->left = (yyvsp[-1].node);
    n->line = (yylsp[-3]).first_line;
    (yyval.node) = n;
}
#line 1420 "storyscript.tab.c"
    break;

  case 16: /* assignment: IDENTIFIER HOLDS expression  */
#line 172 "storyscript.y"
{
    hasSyntaxError = true;
    cout << "Line " << (yylsp[0]).first_line << ": Missing ';' after assignment\n";
}
#line 1429 "storyscript.tab.c"
    break;

  case 17: /* output: NARRATE expression SEMICOLON  */
#line 180 "storyscript.y"
{
    Node* n = new Node("print");
    n->left = (yyvsp[-1].node);
    (yyval.node) = n;
}
#line 1439 "storyscript.tab.c"
    break;

  case 18: /* output: NARRATE expression  */
#line 186 "storyscript.y"
{
    hasSyntaxError = true;
    cout << "Line " << (yylsp[0]).first_line << ": Missing ';' after narrate\n";
}
#line 1448 "storyscript.tab.c"
    break;

  case 19: /* input: LISTEN IDENTIFIER SEMICOLON  */
#line 194 "storyscript.y"
{
    Node* n = new Node("input");
    n->id = (yyvsp[-1].id);
    (yyval.node) = n;
}
#line 1458 "storyscript.tab.c"
    break;

  case 20: /* conditional: WHEN condition statement_list OTHERWISE statement_list ENDCHOICE  */
#line 203 "storyscript.y"
{
    Node* n = new Node("if");
    n->left = (yyvsp[-4].node);
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-1].node));
    (yyval.node) = n;
}
#line 1470 "storyscript.tab.c"
    break;

  case 21: /* loop: DURING condition statement_list ENDCYCLE  */
#line 214 "storyscript.y"
{
    Node* n = new Node("loop");
    n->left = (yyvsp[-2].node);
    n->children.push_back((yyvsp[-1].node));
    (yyval.node) = n;
}
#line 1481 "storyscript.tab.c"
    break;

  case 22: /* function: CHAPTER IDENTIFIER TAKES parameter_list statement_list RETURN expression ENDCHAPTER  */
#line 225 "storyscript.y"
{
    Node* n = new Node("function");
    n->id = (yyvsp[-6].id);
    n->children.push_back((yyvsp[-4].node));  // parameters
    n->children.push_back((yyvsp[-3].node));  // body
    n->left = (yyvsp[-1].node);               // return expression
    (yyval.node) = n;
}
#line 1494 "storyscript.tab.c"
    break;

  case 23: /* parameter_list: IDENTIFIER  */
#line 237 "storyscript.y"
{
    Node* n = new Node("param");
    n->id = (yyvsp[0].id);
    (yyval.node) = n;
}
#line 1504 "storyscript.tab.c"
    break;

  case 24: /* parameter_list: IDENTIFIER COMMA parameter_list  */
#line 243 "storyscript.y"
{
    Node* n = new Node("param");
    n->id = (yyvsp[-2].id);
    if((yyvsp[0].node)) n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
}
#line 1515 "storyscript.tab.c"
    break;

  case 25: /* condition: expression GT expression  */
#line 255 "storyscript.y"
{
    Node* n = new Node("gt");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1526 "storyscript.tab.c"
    break;

  case 26: /* condition: expression LT expression  */
#line 262 "storyscript.y"
{
    Node* n = new Node("lt");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1537 "storyscript.tab.c"
    break;

  case 27: /* condition: condition AND condition  */
#line 269 "storyscript.y"
{
    Node* n = new Node("and");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1548 "storyscript.tab.c"
    break;

  case 28: /* condition: condition OR condition  */
#line 276 "storyscript.y"
{
    Node* n = new Node("or");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1559 "storyscript.tab.c"
    break;

  case 29: /* condition: NOT condition  */
#line 283 "storyscript.y"
{
    Node* n = new Node("not");
    n->left = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1569 "storyscript.tab.c"
    break;

  case 30: /* condition: LPAREN condition RPAREN  */
#line 289 "storyscript.y"
{
    (yyval.node) = (yyvsp[-1].node);
}
#line 1577 "storyscript.tab.c"
    break;

  case 31: /* expression: expression PLUS expression  */
#line 298 "storyscript.y"
{
    Node* n = new Node("add");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1588 "storyscript.tab.c"
    break;

  case 32: /* expression: expression MINUS expression  */
#line 305 "storyscript.y"
{
    Node* n = new Node("sub");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1599 "storyscript.tab.c"
    break;

  case 33: /* expression: expression MUL expression  */
#line 312 "storyscript.y"
{
    Node* n = new Node("mul");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1610 "storyscript.tab.c"
    break;

  case 34: /* expression: expression DIV expression  */
#line 319 "storyscript.y"
{
    Node* n = new Node("div");
    n->left = (yyvsp[-2].node);
    n->right = (yyvsp[0].node);
    (yyval.node) = n;
}
#line 1621 "storyscript.tab.c"
    break;

  case 35: /* expression: NUMBER  */
#line 326 "storyscript.y"
{
    Node* n = new Node("num");
    n->value = (yyvsp[0].num);
    (yyval.node) = n;
}
#line 1631 "storyscript.tab.c"
    break;

  case 36: /* expression: IDENTIFIER  */
#line 332 "storyscript.y"
{
    Node* n = new Node("var");
    n->id = (yyvsp[0].id);
    n->line = (yylsp[0]).first_line;
    (yyval.node) = n;
}
#line 1642 "storyscript.tab.c"
    break;


#line 1646 "storyscript.tab.c"

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

#line 340 "storyscript.y"


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

    return 0;
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
        cout<<"Function "<<n->id<<" parsed"<<endl;
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

    /* Execution (also does semantic checking) */
    cout << "\n[COMPILER] Executing Program...\n\n";

    exec(root);

    /* STOP if semantic error */
    if(hasSemanticError){
        cout << "\n[COMPILER] Semantic Analysis Failed\n";
        return 1;
    }

    printPhase("Execution");

    printSymbolTable();

    cout << "\n=====================================\n";
    cout << "Compilation Successful\n";
    cout << "=====================================\n";

    return 0;
}

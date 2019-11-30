/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"


#include "symbol_table.h"
#include "abstract_syntax_tree.h"
#include "my_string.h"
#include "lexical_error_handler.h"
#include <stdio.h>
#include <assert.h>
#include "scope.h"
#include <string.h>

#define zero_allocate(type) ((type*)calloc(1, sizeof(type)))

extern FILE* yyin;
extern int yylex();
extern uint32_t line;
extern uint32_t column;
extern scope_error_t LAST_ERROR;
scope_t* root_scope;
scope_t* current_scope;
t_program* program;

void yyerror (char const *s)
{
  fprintf (stderr, "Location %d:%d - %s\n", line, column, s);
}


#line 99 "src/parser.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    STRING = 259,
    DIGIT = 260,
    INTEGER = 261,
    CHAR = 262,
    REAL = 263,
    LEFT_BRACE = 264,
    RIGHT_BRACE = 265,
    LEFT_BRACKET = 266,
    RIGHT_BRACKET = 267,
    LEFT_PAREN = 268,
    RIGHT_PAREN = 269,
    LEFT_ANGLE = 270,
    RIGHT_ANGLE = 271,
    EQUAL = 272,
    PLUS_EQUAL = 273,
    MINUS_EQUAL = 274,
    ASTERISK_EQUAL = 275,
    SLASH_EQUAL = 276,
    PERCENT_EQUAL = 277,
    LANGLE_EQUAL = 278,
    RANGLE_EQUAL = 279,
    EQUAL_EQUAL = 280,
    EXCL_EQUAL = 281,
    DOUBLE_LANGLE = 282,
    DOUBLE_RANGLE = 283,
    TILDE = 284,
    AND = 285,
    BAR = 286,
    CARET = 287,
    EXCL = 288,
    BAR_BAR = 289,
    AND_AND = 290,
    COMMA = 291,
    SEMICOLON = 292,
    PLUS = 293,
    MINUS = 294,
    ASTERISK = 295,
    SLASH = 296,
    PERCENT = 297,
    IN_RW = 298,
    RM_RW = 299,
    SIZEOF_RW = 300,
    VOID_RW = 301,
    BOOL_RW = 302,
    BYTE_RW = 303,
    CHAR_RW = 304,
    SHORT_RW = 305,
    INT_RW = 306,
    LONG_RW = 307,
    FLOAT_RW = 308,
    DOUBLE_RW = 309,
    PRINT_RW = 310,
    PRINTC_RW = 311,
    PRINTX_RW = 312,
    SCAN_RW = 313,
    SCANC_RW = 314,
    SCANF_RW = 315,
    IF_RW = 316,
    ELSE_RW = 317,
    WHILE_RW = 318,
    TRUE_RW = 319,
    FALSE_RW = 320,
    FOR_RW = 321,
    RETURN_RW = 322,
    UNDERSCORE = 323,
    NEWLINE = 324,
    REDUCE = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "src/parser.y"

    t_expression_type c_expression_type;
    t_constant_type c_constant_type;
    t_assignment_operator c_assignment_operator;
    t_primitive_type c_primitive_type;
    t_print_type c_print_type;
    t_scan_type c_scan_type;
    t_program* c_program;
    t_declaration_list* c_declaration_list;
    t_declaration* c_declaration;
    t_variable* c_variable;
    t_function* c_function;
    t_function_params* c_function_params;
    t_brace_enclosed_scope* c_brace_enclosed_scope;
    t_statement_list* c_statement_list;
    t_statement* c_statement;
    t_print* c_print;
    t_scan* c_scan;
    t_return* c_return;
    t_expression* c_expression;
    t_condition* c_condition;
    t_iteration* c_iteration;
    t_assignment* c_assignment;
    t_postfix_expression* c_postfix_expression;
    t_primary_expression* c_primary_expression;
    t_cast_expression* c_cast_expression;
    st_element_t* c_st_element;
    t_constant* c_constant;
    t_param_vals* c_param_vals;
    char* string_val;
    int64_t integer_val;
    double float_val;
    char char_val;

#line 248 "src/parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

#define YYUNDEFTOK  2
#define YYMAXUTOK   325

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   144,   150,   156,   159,   165,   185,   201,
     220,   233,   220,   250,   250,   273,   280,   290,   290,   301,
     307,   313,   319,   326,   334,   340,   346,   352,   359,   365,
     371,   377,   383,   401,   423,   456,   493,   496,   499,   505,
     508,   511,   517,   531,   545,   556,   570,   596,   603,   611,
     614,   620,   650,   657,   663,   678,   684,   699,   705,   720,
     726,   741,   747,   762,   768,   786,   804,   810,   841,   847,
     874,   900,   906,   924,   930,   954,   978,   984,  1008,  1014,
    1039,  1049,  1063,  1073,  1095,  1117,  1127,  1133,  1138,  1144,
    1154,  1168,  1175,  1183,  1193,  1200,  1207,  1217,  1218,  1219,
    1220,  1221,  1222,  1226,  1227,  1228,  1229,  1233,  1234,  1235,
    1236,  1237,  1241,  1242,  1243,  1247,  1250,  1253,  1256,  1259,
    1262,  1265,  1268,  1271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "DIGIT",
  "INTEGER", "CHAR", "REAL", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET",
  "RIGHT_BRACKET", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_ANGLE",
  "RIGHT_ANGLE", "EQUAL", "PLUS_EQUAL", "MINUS_EQUAL", "ASTERISK_EQUAL",
  "SLASH_EQUAL", "PERCENT_EQUAL", "LANGLE_EQUAL", "RANGLE_EQUAL",
  "EQUAL_EQUAL", "EXCL_EQUAL", "DOUBLE_LANGLE", "DOUBLE_RANGLE", "TILDE",
  "AND", "BAR", "CARET", "EXCL", "BAR_BAR", "AND_AND", "COMMA",
  "SEMICOLON", "PLUS", "MINUS", "ASTERISK", "SLASH", "PERCENT", "IN_RW",
  "RM_RW", "SIZEOF_RW", "VOID_RW", "BOOL_RW", "BYTE_RW", "CHAR_RW",
  "SHORT_RW", "INT_RW", "LONG_RW", "FLOAT_RW", "DOUBLE_RW", "PRINT_RW",
  "PRINTC_RW", "PRINTX_RW", "SCAN_RW", "SCANC_RW", "SCANF_RW", "IF_RW",
  "ELSE_RW", "WHILE_RW", "TRUE_RW", "FALSE_RW", "FOR_RW", "RETURN_RW",
  "UNDERSCORE", "NEWLINE", "REDUCE", "$accept", "program",
  "declaration-list", "declaration", "var-declaration", "fun-declaration",
  "$@1", "$@2", "$@3", "param-decs", "scope", "$@4", "statement-list",
  "statement", "print", "scan", "print-type", "scan-type", "condition",
  "iteration", "return", "optional-expression", "assignment", "expression",
  "and-expression", "or-expression", "bw-and-expression",
  "bw-or-expression", "bw-xor-expression", "eq-expression",
  "rel-expression", "shift-expression", "set-rm-expression",
  "add-expression", "mult-expression", "unary-expression",
  "cast-expression", "postfix-expression", "param-vals", "identifier",
  "primary-expression", "constant", "assignment-op", "unary-op", "rel-op",
  "mul-op", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -150,    18,    99,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,     3,  -150,    27,  -150,     6,    41,
      51,    56,  -150,    64,    99,    70,  -150,  -150,   -11,    93,
     107,  -150,    99,    43,  -150,  -150,   107,  -150,  -150,  -150,
      52,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   217,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   104,
     109,   110,   279,     4,  -150,  -150,  -150,  -150,   279,   117,
    -150,  -150,  -150,  -150,     5,   103,   100,   124,   126,   127,
     -13,    71,    44,   111,    35,   -14,  -150,  -150,  -150,   122,
    -150,  -150,   279,   144,   146,   239,   279,    30,   128,  -150,
    -150,  -150,     7,     8,  -150,  -150,   279,   279,   279,   279,
     279,   279,   279,  -150,  -150,  -150,  -150,  -150,   279,   279,
     279,   279,   279,   279,  -150,  -150,  -150,   279,   279,   279,
    -150,  -150,  -150,  -150,  -150,  -150,   279,  -150,    53,  -150,
     150,   152,   153,   171,  -150,   151,  -150,  -150,  -150,  -150,
    -150,   100,   124,   126,   127,   -13,    71,    71,    44,   111,
     111,    35,   -14,   -14,  -150,   179,  -150,    -7,  -150,   279,
     123,   123,   123,   279,  -150,  -150,   279,   178,  -150,   131,
    -150,   157,  -150,  -150,   123,   279,  -150,   181,   123,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     3,     0,     6,     0,     5,     7,     0,
       0,    10,     9,     0,     0,     0,     8,    16,     0,     0,
       0,    11,     0,     7,    17,    14,     0,    15,    20,    12,
       0,    31,    89,    92,    94,    95,    96,    18,     0,   105,
     103,   104,   106,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    50,     0,    21,    19,    24,    25,     0,     0,
      28,    29,    30,    52,     0,    53,    55,    57,    59,    61,
      63,    66,    68,    71,    73,    76,    78,    80,    82,    90,
      85,    91,     0,     0,     0,     0,     0,     0,     0,    49,
      23,    22,     0,     0,    27,    26,     0,     0,     0,     0,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,   112,   113,   114,     0,     0,    88,
      97,    98,    99,   100,   101,   102,     0,    79,    90,    93,
       0,     0,     0,     0,    47,     0,    48,    33,    32,    35,
      34,    54,    56,    58,    60,    62,    64,    65,    67,    69,
      70,    72,    74,    75,    77,     0,    87,     0,    51,     0,
       0,     0,     0,    50,    83,    84,     0,     0,    44,    42,
      45,     0,    86,    81,     0,    50,    43,     0,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,  -150,     0,  -150,  -150,  -150,  -150,  -150,
     -20,  -150,  -150,  -149,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,   -96,  -150,   -48,  -150,    90,    91,    89,   101,    98,
     -33,    81,   -37,    79,   -30,   -81,  -150,  -150,  -150,    95,
    -150,  -150,  -150,  -150,  -150,  -150,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    63,    15,    24,    36,    25,    28,
      64,    38,    40,    65,    66,    67,    68,    69,    70,    71,
      72,    98,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   167,    89,
      90,    91,   136,    92,   118,   127,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,   145,    14,    31,    16,   100,   104,   175,   147,   149,
      35,   137,   111,   112,    99,    19,    39,    20,     3,    21,
     102,   178,   179,   180,    27,    32,   124,   125,   126,   176,
      18,   144,    37,    42,    43,   186,    44,    45,    46,   189,
      17,   101,   105,    48,   148,   150,   164,   142,   143,    99,
      94,    22,    19,    41,    20,    42,    43,    23,    44,    45,
      46,    34,    47,    49,   128,    48,   129,   -50,    50,    51,
     -13,   119,   120,   122,   123,    52,    26,   181,   156,   157,
     165,   166,   159,   160,    30,    49,   113,   114,   168,   187,
      50,    51,   162,   163,   115,   116,    33,    52,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    53,    54,    55,
      56,    57,    58,    59,   117,    60,    34,    95,    61,    62,
      42,   177,    96,    97,    41,    99,    42,    43,   182,    44,
      45,    46,    34,   128,   107,   129,    48,    99,   106,   130,
     131,   132,   133,   134,   135,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   108,   121,    49,   109,   139,   110,
     140,    50,    51,   169,   103,   146,   170,   171,    52,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    53,    54,
      55,    56,    57,    58,    59,   172,    60,   138,   173,    61,
      62,   174,   183,   184,   185,   188,   151,   153,   152,   158,
     161,   138,   138,   138,   138,   138,   138,   138,   155,     0,
     154,     0,     0,   138,   138,   138,   138,   138,   138,     0,
      42,    43,   138,    44,    45,    46,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,    42,    43,     0,    44,    45,    46,     0,     0,
      49,     0,    48,     0,     0,    50,    51,     0,     0,     0,
       0,     0,    52,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    49,     0,     0,     0,     0,    50,    51,     0,
       0,     0,    42,    43,    52,    44,    45,    46,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,    50,    51,     0,
       0,     0,     0,     0,    52
};

static const yytype_int16 yycheck[] =
{
      48,    97,     2,    14,     2,     1,     1,    14,     1,     1,
      30,    92,    25,    26,    62,     9,    36,    11,     0,    13,
      68,   170,   171,   172,    24,    36,    40,    41,    42,    36,
       3,     1,    32,     3,     4,   184,     6,     7,     8,   188,
      37,    37,    37,    13,    37,    37,   127,    95,    96,    97,
      48,    10,     9,     1,    11,     3,     4,     6,     6,     7,
       8,     9,    10,    33,    11,    13,    13,    37,    38,    39,
      14,    27,    28,    38,    39,    45,    12,   173,   111,   112,
     128,   129,   119,   120,    14,    33,    15,    16,   136,   185,
      38,    39,   122,   123,    23,    24,     3,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    43,    63,     9,    13,    66,    67,
       3,   169,    13,    13,     1,   173,     3,     4,   176,     6,
       7,     8,     9,    11,    34,    13,    13,   185,    35,    17,
      18,    19,    20,    21,    22,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    30,    44,    33,    31,    14,    32,
      14,    38,    39,    13,    69,    37,    14,    14,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    14,    63,    92,    37,    66,
      67,    12,    14,    62,    37,    14,   106,   108,   107,   118,
     121,   106,   107,   108,   109,   110,   111,   112,   110,    -1,
     109,    -1,    -1,   118,   119,   120,   121,   122,   123,    -1,
       3,     4,   127,     6,     7,     8,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,    -1,    -1,
      33,    -1,    13,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,     3,     4,    45,     6,     7,     8,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,    73,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    74,    75,    76,   117,    37,     3,     9,
      11,    13,    10,     6,    77,    79,    12,    75,    80,   117,
      14,    14,    36,     3,     9,    81,    78,    75,    82,    81,
      83,     1,     3,     4,     6,     7,     8,    10,    13,    33,
      38,    39,    45,    55,    56,    57,    58,    59,    60,    61,
      63,    66,    67,    75,    81,    84,    85,    86,    87,    88,
      89,    90,    91,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   110,
     111,   112,   114,    94,   117,    13,    13,    13,    92,    94,
       1,    37,    94,   110,     1,    37,    35,    34,    30,    31,
      32,    25,    26,    15,    16,    23,    24,    43,   115,    27,
      28,    44,    38,    39,    40,    41,    42,   116,    11,    13,
      17,    18,    19,    20,    21,    22,   113,   106,   110,    14,
      14,     1,    94,    94,     1,    92,    37,     1,    37,     1,
      37,    96,    97,    98,    99,   100,   101,   101,   102,   103,
     103,   104,   105,   105,   106,    94,    94,   109,    94,    13,
      14,    14,    14,    37,    12,    14,    36,    94,    84,    84,
      84,    92,    94,    14,    62,    37,    84,    92,    14,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      77,    78,    76,    79,    76,    80,    80,    82,    81,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    86,    86,    87,    87,    87,    88,
      88,    88,    89,    89,    89,    90,    90,    90,    91,    92,
      92,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   101,   101,   102,
     102,   102,   103,   103,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   108,   109,   109,   109,   110,
     111,   111,   111,   111,   112,   112,   112,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   114,   115,   115,   115,
     115,   115,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     2,     5,     4,
       0,     0,     8,     0,     6,     3,     1,     0,     4,     2,
       0,     1,     2,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     5,     7,     5,     5,     9,     3,     3,     1,
       0,     3,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     2,
       1,     6,     1,     4,     4,     1,     3,     1,     0,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
  case 2:
#line 136 "src/parser.y"
    {
        program = zero_allocate(t_program);
        program->declaration_list = (yyvsp[0].c_declaration_list);
        (yyval.c_program) = program;
    }
#line 1533 "src/parser.c"
    break;

  case 3:
#line 144 "src/parser.y"
    {
        t_declaration_list* declaration_list = zero_allocate(t_declaration_list);
        declaration_list->prev = (yyvsp[-1].c_declaration_list);
        declaration_list->cur = (yyvsp[0].c_st_element);
        (yyval.c_declaration_list) = declaration_list;
    }
#line 1544 "src/parser.c"
    break;

  case 4:
#line 150 "src/parser.y"
    {
        (yyval.c_declaration_list) = NULL;
    }
#line 1552 "src/parser.c"
    break;

  case 5:
#line 156 "src/parser.y"
    {
        (yyval.c_st_element) = (yyvsp[-1].c_st_element);
    }
#line 1560 "src/parser.c"
    break;

  case 6:
#line 159 "src/parser.y"
    {
        (yyval.c_st_element) = (yyvsp[0].c_st_element);
    }
#line 1568 "src/parser.c"
    break;

  case 7:
#line 165 "src/parser.y"
    {
        t_variable* var = zero_allocate(t_variable);
        var->type_info.primitive_type = (yyvsp[-1].c_primitive_type);
        var->type_info.data_structure = PRIMITIVE;
        var->identifier = (yyvsp[0].string_val);
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = VAR_DECLARATION;
        dec->member.variable = var;
        scope_element_t* add = scope_add(current_scope, dec);
        if (LAST_ERROR == EXISTING_DECLARATION) {
            LAST_ERROR = 0;
            printf("Location %d:%d - Multiple declaration of identifier %s\n", line, column, (yyvsp[0].string_val));
            if (add->declaration->type != VAR_DECLARATION) {
                printf("Location %d:%d - Previous identifier was declared as function and not variable!\n", line, column);
            }
            add = NULL;
        }
        (yyval.c_st_element) = add;
    }
#line 1593 "src/parser.c"
    break;

  case 8:
#line 185 "src/parser.y"
    {
        t_variable* var = zero_allocate(t_variable);
        var->type_info.primitive_type = (yyvsp[-4].c_primitive_type);
        var->type_info.data_structure = ARRAY;
        var->identifier = (yyvsp[-3].string_val);
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = VAR_DECLARATION;
        dec->member.variable = var;
        scope_element_t* add = scope_add(current_scope, dec);
        if (LAST_ERROR == EXISTING_DECLARATION) {
            LAST_ERROR = 0;
            printf("Location %d:%d - Multiple declaration of identifier %s\n", line, column, (yyvsp[-3].string_val));
        }
        (yyval.c_st_element) = add;
    }
#line 1614 "src/parser.c"
    break;

  case 9:
#line 201 "src/parser.y"
    {
        t_variable* var = zero_allocate(t_variable);
        var->type_info.primitive_type = (yyvsp[-3].c_primitive_type);
        var->type_info.data_structure = SET;
        var->identifier = (yyvsp[-2].string_val);
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = VAR_DECLARATION;
        dec->member.variable = var;
        scope_element_t* add = scope_add(current_scope, dec);
        if (LAST_ERROR == EXISTING_DECLARATION) {
            LAST_ERROR = 0;
            printf("Location %d:%d - Multiple declaration of identifier %s\n", line, column, (yyvsp[-2].string_val));
        }
        (yyval.c_st_element) = add;
    }
#line 1635 "src/parser.c"
    break;

  case 10:
#line 220 "src/parser.y"
    {
        t_function* fun = zero_allocate(t_function);
        fun->type_info.primitive_type = (yyvsp[-2].c_primitive_type);
        fun->type_info.data_structure = FUNCTION;
        fun->identifier = (yyvsp[-1].string_val);
        fun->params = NULL;
        fun->body = NULL;
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = FUN_DECLARATION;
        dec->member.function = fun;
        scope_add(current_scope, dec);
        current_scope = scope_create(current_scope);
    }
#line 1654 "src/parser.c"
    break;

  case 11:
#line 233 "src/parser.y"
    {
        st_element_t* fun = scope_find(current_scope, (yyvsp[-4].string_val));
        if (fun == NULL) {
            printf("Location %d:%d - Should not happen, fun is null!\n", line, column);
            exit(55);
        }
        fun->declaration->member.function->params = (yyvsp[-1].c_function_params);
    }
#line 1667 "src/parser.c"
    break;

  case 12:
#line 240 "src/parser.y"
    {
        st_element_t* fun = scope_find(current_scope, (yyvsp[-6].string_val));
        if (fun == NULL) {
            printf("Location %d:%d - Should not happen, fun is null!\n", line, column);
            exit(55);
        }
        fun->declaration->member.function->body = (yyvsp[0].c_brace_enclosed_scope);
        (yyval.c_st_element) = fun;
        current_scope = current_scope->parent;
    }
#line 1682 "src/parser.c"
    break;

  case 13:
#line 250 "src/parser.y"
    {
        t_function* fun = zero_allocate(t_function);
        fun->type_info.primitive_type = (yyvsp[-2].c_primitive_type);
        fun->type_info.data_structure = FUNCTION;
        fun->identifier = (yyvsp[-1].string_val);
        fun->params = NULL;
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = FUN_DECLARATION;
        dec->member.function = fun;
        scope_add(current_scope, dec);
    }
#line 1699 "src/parser.c"
    break;

  case 14:
#line 261 "src/parser.y"
    {
        st_element_t* fun = scope_find(current_scope, (yyvsp[-4].string_val));
        if (fun == NULL) {
            printf("Location %d:%d - Should not happen, fun is null!\n", line, column);
            exit(55);
        }
        fun->declaration->member.function->body = (yyvsp[0].c_brace_enclosed_scope);
        (yyval.c_st_element) = fun;
    }
#line 1713 "src/parser.c"
    break;

  case 15:
#line 273 "src/parser.y"
    {
        t_function_params* fp = zero_allocate(t_function_params);
        assert((yyvsp[0].c_st_element)->declaration->type == VAR_DECLARATION);
        fp->cur = (yyvsp[0].c_st_element);
        fp->prev = (yyvsp[-2].c_function_params);
        (yyval.c_function_params) = fp; 
    }
#line 1725 "src/parser.c"
    break;

  case 16:
#line 280 "src/parser.y"
    {
        t_function_params* fp = zero_allocate(t_function_params);

        fp->cur = (yyvsp[0].c_st_element);
        fp->prev = NULL;
        (yyval.c_function_params) = fp; 
    }
#line 1737 "src/parser.c"
    break;

  case 17:
#line 290 "src/parser.y"
    {
        current_scope = scope_create(current_scope);
    }
#line 1745 "src/parser.c"
    break;

  case 18:
#line 292 "src/parser.y"
    {
        t_brace_enclosed_scope* scope = zero_allocate(t_brace_enclosed_scope);
        scope->statements = (yyvsp[-1].c_statement_list);
        (yyval.c_brace_enclosed_scope) = scope;
        current_scope = current_scope->parent;
    }
#line 1756 "src/parser.c"
    break;

  case 19:
#line 301 "src/parser.y"
    {
        t_statement_list* fp = zero_allocate(t_statement_list);
        fp->cur = (yyvsp[0].c_statement);
        fp->prev = (yyvsp[-1].c_statement_list);
        (yyval.c_statement_list) = fp; 
    }
#line 1767 "src/parser.c"
    break;

  case 20:
#line 307 "src/parser.y"
    {
    (yyval.c_statement_list) = NULL;
}
#line 1775 "src/parser.c"
    break;

  case 21:
#line 313 "src/parser.y"
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = BRACE_ENCLOSED_SCOPE_STATEMENT;
        stmt->member.scope = (yyvsp[0].c_brace_enclosed_scope);
        (yyval.c_statement) = stmt;
    }
#line 1786 "src/parser.c"
    break;

  case 22:
#line 319 "src/parser.y"
    {
        t_statement* stmt = zero_allocate(t_statement);
        assert((yyvsp[-1].c_st_element)->declaration->type == VAR_DECLARATION);
        stmt->type = VAR_DECLARATION_STATEMENT;
        stmt->member.variable = (yyvsp[-1].c_st_element);
        (yyval.c_statement) = stmt;
    }
#line 1798 "src/parser.c"
    break;

  case 23:
#line 326 "src/parser.y"
    {
        yyerrok;
        t_statement* stmt = zero_allocate(t_statement);
        assert((yyvsp[-1].c_st_element)->declaration->type == VAR_DECLARATION);
        stmt->type = VAR_DECLARATION_STATEMENT;
        stmt->member.variable = (yyvsp[-1].c_st_element);
        (yyval.c_statement) = stmt;
    }
#line 1811 "src/parser.c"
    break;

  case 24:
#line 334 "src/parser.y"
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = PRINT_STATEMENT;
        stmt->member.print = (yyvsp[0].c_print);
        (yyval.c_statement) = stmt;
    }
#line 1822 "src/parser.c"
    break;

  case 25:
#line 340 "src/parser.y"
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = SCAN_STATEMENT;
        stmt->member.scan = (yyvsp[0].c_scan);
        (yyval.c_statement) = stmt;
    }
#line 1833 "src/parser.c"
    break;

  case 26:
#line 346 "src/parser.y"
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = EXPRESSION_STATEMENT;
        stmt->member.expression = (yyvsp[-1].c_expression);
        (yyval.c_statement) = stmt;
    }
#line 1844 "src/parser.c"
    break;

  case 27:
#line 352 "src/parser.y"
    {
        yyerrok;
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = EXPRESSION_STATEMENT;
        stmt->member.expression = (yyvsp[-1].c_expression);
        (yyval.c_statement) = stmt;
    }
#line 1856 "src/parser.c"
    break;

  case 28:
#line 359 "src/parser.y"
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = CONDITION_STATEMENT;
        stmt->member.condition = (yyvsp[0].c_condition);
        (yyval.c_statement) = stmt;
    }
#line 1867 "src/parser.c"
    break;

  case 29:
#line 365 "src/parser.y"
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = ITERATION_STATEMENT;
        stmt->member.iteration = (yyvsp[0].c_iteration);
        (yyval.c_statement) = stmt;
    }
#line 1878 "src/parser.c"
    break;

  case 30:
#line 371 "src/parser.y"
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = RETURN_STATEMENT;
        stmt->member._return = (yyvsp[0].c_return);
        (yyval.c_statement) = stmt;
    }
#line 1889 "src/parser.c"
    break;

  case 31:
#line 377 "src/parser.y"
    {
        (yyval.c_statement) = NULL;
    }
#line 1897 "src/parser.c"
    break;

  case 32:
#line 383 "src/parser.y"
    {
        t_print* print = zero_allocate(t_print);
        print->type = (yyvsp[-2].c_print_type);
        print->expression = (yyvsp[-1].c_expression);
        (yyval.c_print) = print;

        if ((yyvsp[-1].c_expression)->type_info.data_structure != PRIMITIVE) {
            printf("Location %d:%d - You can only print primitive values, no sets, arrays or functions\n", line, column);
        }

        if ((yyvsp[-2].c_print_type) == PRINT_CHAR_TYPE) {
            assert(is_type_equivalent(
                LONG_TYPE, 
                (yyvsp[-1].c_expression)->type_info.primitive_type
                )
            );
        }
    }
#line 1920 "src/parser.c"
    break;

  case 33:
#line 401 "src/parser.y"
    {
        yyerrok;
        t_print* print = zero_allocate(t_print);
        print->type = (yyvsp[-2].c_print_type);
        print->expression = (yyvsp[-1].c_expression);
        (yyval.c_print) = print;

        if ((yyvsp[-1].c_expression)->type_info.data_structure != PRIMITIVE) {
            printf("Location %d:%d - You can only print primitive values, no sets, arrays or functions\n", line, column);
        }

        if ((yyvsp[-2].c_print_type) == PRINT_CHAR_TYPE) {
            assert(is_type_equivalent(
                LONG_TYPE, 
                (yyvsp[-1].c_expression)->type_info.primitive_type
                )
            );
        }
    }
#line 1944 "src/parser.c"
    break;

  case 34:
#line 423 "src/parser.y"
    {
        t_scan* scan = zero_allocate(t_scan);
        scan->type = (yyvsp[-2].c_scan_type);

        if ((yyvsp[-1].c_st_element) != NULL) {
            char* label = declaration_get_label((yyvsp[-1].c_st_element)->declaration);
            if ((yyvsp[-1].c_st_element)->declaration->type != VAR_DECLARATION) {
                printf("Location %d:%d - %s is not a variable and you can't scan to it.\n", line, column, label);
            }
            if ((yyvsp[-1].c_st_element)->declaration->member.variable->type_info.data_structure != PRIMITIVE) {
                printf("Location %d:%d - Variable %s is not primitive.\n", line, column, label);
            }

            if ((yyvsp[-2].c_scan_type) == SCAN_DEC_TYPE || (yyvsp[-2].c_scan_type) == SCAN_CHAR_TYPE) {
                if (!is_type_equivalent(
                    LONG_TYPE, 
                    (yyvsp[-1].c_st_element)->declaration->member.variable->type_info.primitive_type
                )) {
                    printf("Location %d:%d - Variable %s is not an integer or char.\n", line, column, label);
                }
            } else {
                if (!is_type_equivalent(
                    FLOAT_TYPE, 
                    (yyvsp[-1].c_st_element)->declaration->member.variable->type_info.primitive_type
                )) {
                    printf("Location %d:%d - scanf can't scan to variable that is not a float or double.\n", line, column);
                }
            }
        }
        
        scan->destiny = (yyvsp[-1].c_st_element);
        (yyval.c_scan) = scan;
    }
#line 1982 "src/parser.c"
    break;

  case 35:
#line 456 "src/parser.y"
    {
        yyerrok;
        t_scan* scan = zero_allocate(t_scan);
        scan->type = (yyvsp[-2].c_scan_type);

        if ((yyvsp[-1].c_st_element) != NULL) {
            char* label = declaration_get_label((yyvsp[-1].c_st_element)->declaration);
            if ((yyvsp[-1].c_st_element)->declaration->type != VAR_DECLARATION) {
                printf("Location %d:%d - %s is not a variable and you can't scan to it.\n", line, column, label);
            }
            if ((yyvsp[-1].c_st_element)->declaration->member.variable->type_info.data_structure != PRIMITIVE) {
                printf("Location %d:%d - Variable %s is not primitive.\n", line, column, label);
            }

            if ((yyvsp[-2].c_scan_type) == SCAN_DEC_TYPE || (yyvsp[-2].c_scan_type) == SCAN_CHAR_TYPE) {
                if (!is_type_equivalent(
                    LONG_TYPE, 
                    (yyvsp[-1].c_st_element)->declaration->member.variable->type_info.primitive_type
                )) {
                    printf("Location %d:%d - Variable %s is not an integer or char.\n", line, column, label);
                }
            } else {
                if (!is_type_equivalent(
                    FLOAT_TYPE, 
                    (yyvsp[-1].c_st_element)->declaration->member.variable->type_info.primitive_type
                )) {
                    printf("Location %d:%d - scanf can't scan to variable that is not a float or double.\n", line, column);
                }
            }
        }
        
        scan->destiny = (yyvsp[-1].c_st_element);
        (yyval.c_scan) = scan;
    }
#line 2021 "src/parser.c"
    break;

  case 36:
#line 493 "src/parser.y"
    {
        (yyval.c_print_type) = PRINT_DEC_TYPE;
    }
#line 2029 "src/parser.c"
    break;

  case 37:
#line 496 "src/parser.y"
    {
        (yyval.c_print_type) = PRINT_CHAR_TYPE;
    }
#line 2037 "src/parser.c"
    break;

  case 38:
#line 499 "src/parser.y"
    {
        (yyval.c_print_type) = PRINT_HEX_TYPE;
    }
#line 2045 "src/parser.c"
    break;

  case 39:
#line 505 "src/parser.y"
    {
        (yyval.c_scan_type) = SCAN_DEC_TYPE;
    }
#line 2053 "src/parser.c"
    break;

  case 40:
#line 508 "src/parser.y"
    {
        (yyval.c_scan_type) = SCAN_CHAR_TYPE;
    }
#line 2061 "src/parser.c"
    break;

  case 41:
#line 511 "src/parser.y"
    {
        (yyval.c_scan_type) = SCAN_FLOAT_TYPE;
    }
#line 2069 "src/parser.c"
    break;

  case 42:
#line 517 "src/parser.y"
    {
        assert((yyvsp[-2].c_expression) != NULL);

        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || !is_type_equivalent(LONG_TYPE, (yyvsp[-2].c_expression)->type_info.primitive_type)) {
            printf("Location %d:%d - Condition expression must return a primitive and integer type\n", line, column);
        };
        
        t_condition* cond = zero_allocate(t_condition);
        cond->condition = (yyvsp[-2].c_expression);
        cond->body = (yyvsp[0].c_statement);
        cond->else_body = NULL;

        (yyval.c_condition) = cond;  
    }
#line 2088 "src/parser.c"
    break;

  case 43:
#line 531 "src/parser.y"
    {   
        assert((yyvsp[-4].c_expression) != NULL);
        
        if ((yyvsp[-4].c_expression)->type_info.data_structure != PRIMITIVE || !is_type_equivalent(LONG_TYPE, (yyvsp[-4].c_expression)->type_info.primitive_type)) {
            printf("Location %d:%d - Condition expression must return a primitive and integer type\n", line, column);
        };

        t_condition* cond = zero_allocate(t_condition);
        cond->condition = (yyvsp[-4].c_expression);
        cond->body = (yyvsp[-2].c_statement);
        cond->else_body = (yyvsp[0].c_statement);

        (yyval.c_condition) = cond;
    }
#line 2107 "src/parser.c"
    break;

  case 44:
#line 545 "src/parser.y"
    {
        yyerrok;

        t_condition* cond = zero_allocate(t_condition);
        cond->body = (yyvsp[0].c_statement);

        (yyval.c_condition) = cond;
    }
#line 2120 "src/parser.c"
    break;

  case 45:
#line 556 "src/parser.y"
    {
        assert((yyvsp[-2].c_expression) != NULL);
        
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || !is_type_equivalent(LONG_TYPE, (yyvsp[-2].c_expression)->type_info.primitive_type)) {
            printf("Location %d:%d - Condition expression must return a primitive and integer type\n", line, column);
        };

        t_iteration* w = zero_allocate(t_iteration);
        w->initialization = NULL;
        w->condition = (yyvsp[-2].c_expression);
        w->step = NULL;
        w->body = (yyvsp[0].c_statement);
        (yyval.c_iteration) = w;
    }
#line 2139 "src/parser.c"
    break;

  case 46:
#line 570 "src/parser.y"
    {
        

        if ((yyvsp[-6].c_expression) != NULL) {
            if ((yyvsp[-6].c_expression)->type_info.data_structure != PRIMITIVE) {
                printf("Location %d:%d - Condition expression must return a primitive type\n", line, column);
            };
        }
        if ((yyvsp[-4].c_expression) != NULL) {
            if ((yyvsp[-4].c_expression)->type_info.data_structure != PRIMITIVE) {
                printf("Location %d:%d - Condition expression must return a primitive type\n", line, column);
            };
        }
        if ((yyvsp[-2].c_expression) != NULL) {
            if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE) {
                printf("Location %d:%d - Condition expression must return a primitive type\n", line, column);
            };
        }
        
        t_iteration* f = zero_allocate(t_iteration);
        f->initialization = (yyvsp[-6].c_expression);
        f->condition = (yyvsp[-4].c_expression);
        f->step = (yyvsp[-2].c_expression);
        f->body = (yyvsp[0].c_statement);
        (yyval.c_iteration) = f;
    }
#line 2170 "src/parser.c"
    break;

  case 47:
#line 596 "src/parser.y"
    {
        (yyval.c_iteration) = NULL;
        yyerrok;   
    }
#line 2179 "src/parser.c"
    break;

  case 48:
#line 603 "src/parser.y"
    {
        t_return* ret = zero_allocate(t_return);
        ret->expression = (yyvsp[-1].c_expression);
        (yyval.c_return) = ret;
    }
#line 2189 "src/parser.c"
    break;

  case 49:
#line 611 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2197 "src/parser.c"
    break;

  case 50:
#line 614 "src/parser.y"
    {
        (yyval.c_expression) = NULL;
    }
#line 2205 "src/parser.c"
    break;

  case 51:
#line 620 "src/parser.y"
    {
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE) {
            printf("Location %d:%d - Expression must have primitive type\n", line, column);
        } else if ((yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Expression must have a numeric value type\n", line, column);
        }

        t_type_info info = (yyvsp[0].c_expression)->type_info;

        if ((yyvsp[-2].c_st_element) != NULL) {
            info = get_type_info((yyvsp[-2].c_st_element));
            char* label = declaration_get_label((yyvsp[-2].c_st_element)->declaration);
            if (info.data_structure != PRIMITIVE) {
                printf("Location %d:%d - Identifier %s must have primitive type\n", line, column, label);
            }
            if (!is_type_equivalent((yyvsp[0].c_expression)->type_info.primitive_type, info.primitive_type)) {
                printf("Location %d:%d - Expression and variable must have equivalent types\n", line, column);
            }
        }

        t_assignment* exp = zero_allocate(t_assignment);
        exp->identifier = (yyvsp[-2].c_st_element);
        exp->operator = (yyvsp[-1].c_assignment_operator);
        exp->expression = (yyvsp[0].c_expression);
        exp->type_info = info;
        (yyval.c_assignment) = exp;
    }
#line 2237 "src/parser.c"
    break;

  case 52:
#line 650 "src/parser.y"
    {
        t_expression* exp = zero_allocate(t_expression);
        exp->type = ASSIGNMENT_EXPRESSION;
        exp->assignment = (yyvsp[0].c_assignment);
        exp->type_info = (yyvsp[0].c_assignment)->type_info;
        (yyval.c_expression) = exp;
    }
#line 2249 "src/parser.c"
    break;

  case 53:
#line 657 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2257 "src/parser.c"
    break;

  case 54:
#line 663 "src/parser.y"
    {
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = (yyvsp[-2].c_expression)->type_info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = AND_EXPRESSION;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2277 "src/parser.c"
    break;

  case 55:
#line 678 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2285 "src/parser.c"
    break;

  case 56:
#line 684 "src/parser.y"
    {
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = (yyvsp[-2].c_expression)->type_info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = OR_EXPRESSION;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2305 "src/parser.c"
    break;

  case 57:
#line 699 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2313 "src/parser.c"
    break;

  case 58:
#line 705 "src/parser.y"
    {
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = (yyvsp[-2].c_expression)->type_info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = BW_AND_EXPRESSION;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2333 "src/parser.c"
    break;

  case 59:
#line 720 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2341 "src/parser.c"
    break;

  case 60:
#line 726 "src/parser.y"
    {
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = (yyvsp[-2].c_expression)->type_info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = BW_OR_EXPRESSION;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2361 "src/parser.c"
    break;

  case 61:
#line 741 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2369 "src/parser.c"
    break;

  case 62:
#line 747 "src/parser.y"
    {
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = (yyvsp[-2].c_expression)->type_info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = BW_XOR_EXPRESSION;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2389 "src/parser.c"
    break;

  case 63:
#line 762 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2397 "src/parser.c"
    break;

  case 64:
#line 768 "src/parser.y"
    {
        t_type_info info;
        info.primitive_type = LONG_TYPE;
        info.data_structure = PRIMITIVE;
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_expression* exp = zero_allocate(t_expression);
        exp->type = EQ_EQ_EXPRESSION;
        exp->left = (yyvsp[-2].c_expression);
        exp->right = (yyvsp[0].c_expression);
        exp->type_info = info;
        (yyval.c_expression) = exp;
    }
#line 2420 "src/parser.c"
    break;

  case 65:
#line 786 "src/parser.y"
    {
        t_type_info info;
        info.primitive_type = LONG_TYPE;
        info.data_structure = PRIMITIVE;
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };
            
        t_expression* exp = zero_allocate(t_expression);
        exp->type = NOT_EQ_EXPRESSION;
        exp->left = (yyvsp[-2].c_expression);
        exp->right = (yyvsp[0].c_expression);
        exp->type_info = info;
        (yyval.c_expression) = exp;
    }
#line 2443 "src/parser.c"
    break;

  case 66:
#line 804 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2451 "src/parser.c"
    break;

  case 67:
#line 810 "src/parser.y"
    {
        t_type_info info;
        info.primitive_type = LONG_TYPE;
        info.data_structure = PRIMITIVE;

        if ((yyvsp[-1].c_expression_type) == IS_IN) {
            if ((yyvsp[-2].c_expression)->type_info.data_structure != SET) {
                printf("Location %d:%d - Can only use 'in' operator with sets on the left side.\n", line, column);
            }
            if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE) {
                printf("Location %d:%d - Can only check if primitive values are in a set.\n", line, column);
            }
            if (!is_type_equivalent((yyvsp[-2].c_expression)->type_info.primitive_type, (yyvsp[0].c_expression)->type_info.primitive_type)) {
                printf("Location %d:%d - Can only check primitive values of the same type of the set.\n", line, column);
            }
        } else {
            if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
                printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
            };
            if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
                printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
            };
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->left = (yyvsp[-2].c_expression);
        exp->type = (yyvsp[-1].c_expression_type);
        exp->right = (yyvsp[0].c_expression);
        exp->type_info = info;
        (yyval.c_expression) = exp;
    }
#line 2487 "src/parser.c"
    break;

  case 68:
#line 841 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2495 "src/parser.c"
    break;

  case 69:
#line 847 "src/parser.y"
    {
        t_structure_type e1 = (yyvsp[-2].c_expression)->type_info.data_structure;
        t_structure_type e2 = (yyvsp[0].c_expression)->type_info.data_structure;
        t_primitive_type t1 = (yyvsp[-2].c_expression)->type_info.primitive_type;
        t_primitive_type t2 = (yyvsp[0].c_expression)->type_info.primitive_type;

        if (e1 != SET && e1 != PRIMITIVE) {
            printf("Location %d:%d - Can only use >> with sets or primitives\n", line, column);
        } else if (e2 == SET) {
            printf("Location %d:%d - To remove elements from a set use the rm operator, not opposite angle brackets.\n", line, column);
        } else if (e2 != PRIMITIVE) {
            printf("Location %d:%d - Can only use << with sets or primitives.\n", line, column);
        } else if (e1 == SET) {
            if (!is_type_equivalent(t1, t2)) {
                printf("Location %d:%d - Trying to insert element of different type in set.\n", line, column);
            }
        } else if (!is_type_equivalent(t1, LONG_TYPE) || !is_type_equivalent(t2, LONG_TYPE)) {
            printf("Location %d:%d - Can only use << with integers.\n", line, column);
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = (yyvsp[-2].c_expression)->type_info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = LEFT_SHIFT_EXPRESSION;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2527 "src/parser.c"
    break;

  case 70:
#line 874 "src/parser.y"
    {
        t_structure_type e1 = (yyvsp[-2].c_expression)->type_info.data_structure;
        t_structure_type e2 = (yyvsp[0].c_expression)->type_info.data_structure;
        t_primitive_type t1 = (yyvsp[-2].c_expression)->type_info.primitive_type;
        t_primitive_type t2 = (yyvsp[0].c_expression)->type_info.primitive_type;
        if (e1 == SET) {
            printf("Location %d:%d - To remove elements from a set use the rm operator, not opposite angle brackets..\n", line, column);
        } else if (e1 != PRIMITIVE) {
            printf("Location %d:%d - Can only use << with sets or primitives.\n", line, column);
        } else if (e2 == SET) {
            if (!is_type_equivalent(t1, t2)) {
                printf("Location %d:%d - Trying to insert element of different type in set.\n", line, column);
            }
        } else if (e2 != PRIMITIVE) {
            printf("Location %d:%d - Can only use << with sets or primitives.\n", line, column);
        } else if (!is_type_equivalent(t1, LONG_TYPE) || !is_type_equivalent(t2, LONG_TYPE)) {
            printf("Location %d:%d - Can only use << with integers.\n", line, column);
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = (yyvsp[-2].c_expression)->type_info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = RIGHT_SHIFT_EXPRESSION;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2558 "src/parser.c"
    break;

  case 71:
#line 900 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2566 "src/parser.c"
    break;

  case 72:
#line 906 "src/parser.y"
    {
        if ((yyvsp[-2].c_expression)->type_info.data_structure != SET) {
            printf("Location %d:%d - Can only use 'rm' operator with sets on the left side.\n", line, column);
        }
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE) {
            printf("Location %d:%d - Can only remove primitive values from a set.\n", line, column);
        }
        if (!is_type_equivalent((yyvsp[-2].c_expression)->type_info.primitive_type, (yyvsp[0].c_expression)->type_info.primitive_type)) {
            printf("Location %d:%d - Can only remove primitive values of the same type of the set.\n", line, column);
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = (yyvsp[-2].c_expression)->type_info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = RM_EXPRESSION;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2589 "src/parser.c"
    break;

  case 73:
#line 924 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2597 "src/parser.c"
    break;

  case 74:
#line 930 "src/parser.y"
    {
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_type_info info;
        info.data_structure = PRIMITIVE;
        if (is_type_equivalent((yyvsp[-2].c_expression)->type_info.primitive_type, DOUBLE_TYPE) ||
            is_type_equivalent((yyvsp[0].c_expression)->type_info.primitive_type, DOUBLE_TYPE)) {
            info.primitive_type = DOUBLE_TYPE;
        } else {
            info.primitive_type = LONG_TYPE;
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = ADD_PLUS;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2626 "src/parser.c"
    break;

  case 75:
#line 954 "src/parser.y"
    {
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_type_info info;
        info.data_structure = PRIMITIVE;
        if (is_type_equivalent((yyvsp[-2].c_expression)->type_info.primitive_type, DOUBLE_TYPE) ||
            is_type_equivalent((yyvsp[0].c_expression)->type_info.primitive_type, DOUBLE_TYPE)) {
            info.primitive_type = DOUBLE_TYPE;
        } else {
            info.primitive_type = LONG_TYPE;
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = ADD_MINUS;
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2655 "src/parser.c"
    break;

  case 76:
#line 978 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2663 "src/parser.c"
    break;

  case 77:
#line 984 "src/parser.y"
    {
        if ((yyvsp[-2].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-2].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-2].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Left expression must return a primitive and integer type\n", line, column);
        };
        if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_type_info info;
        info.data_structure = PRIMITIVE;
        if (is_type_equivalent((yyvsp[-2].c_expression)->type_info.primitive_type, DOUBLE_TYPE) ||
            is_type_equivalent((yyvsp[0].c_expression)->type_info.primitive_type, DOUBLE_TYPE)) {
            info.primitive_type = DOUBLE_TYPE;
        } else {
            info.primitive_type = LONG_TYPE;
        }
        
        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = info;
        exp->left = (yyvsp[-2].c_expression);
        exp->type = (yyvsp[-1].c_expression_type);
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2692 "src/parser.c"
    break;

  case 78:
#line 1008 "src/parser.y"
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 2700 "src/parser.c"
    break;

  case 79:
#line 1014 "src/parser.y"
    {
        t_type_info info;
        if ((yyvsp[-1].c_expression_type) == UNARY_PLUS || (yyvsp[-1].c_expression_type) == UNARY_MINUS || (yyvsp[-1].c_expression_type) == UNARY_EXCL) {
            if ((yyvsp[0].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[0].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[0].c_expression)->type_info.primitive_type == STRING_TYPE) {
                printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
            };

            if ((yyvsp[-1].c_expression_type) == UNARY_EXCL) {
                if (is_type_equivalent((yyvsp[0].c_expression)->type_info.primitive_type, LONG_TYPE) == 0) {
                    printf("Location %d:%d - Can only negate integer types.\n", line, column);
                }
            }

            info = (yyvsp[0].c_expression)->type_info;
        } else {
            info.data_structure = PRIMITIVE;
            info.primitive_type = LONG_TYPE;
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = info;
        exp->type = (yyvsp[-1].c_expression_type);
        exp->right = (yyvsp[0].c_expression);
        (yyval.c_expression) = exp;
    }
#line 2730 "src/parser.c"
    break;

  case 80:
#line 1039 "src/parser.y"
    {
        t_expression* exp = zero_allocate(t_expression);
        exp->type = (yyvsp[0].c_cast_expression)->type;
        exp->value = (yyvsp[0].c_cast_expression);
        exp->type_info = (yyvsp[0].c_cast_expression)->type_info;
        (yyval.c_expression) = exp;
    }
#line 2742 "src/parser.c"
    break;

  case 81:
#line 1049 "src/parser.y"
    {
        if ((yyvsp[-1].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-1].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-1].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Right expression must return a primitive and integer type\n", line, column);
        };

        t_cast_expression* exp = zero_allocate(t_cast_expression);

        exp->cast_type = (yyvsp[-4].c_primitive_type);
        exp->right = (yyvsp[-1].c_expression);
        exp->type = CAST_EXPRESSION;
        exp->type_info.primitive_type = (yyvsp[-4].c_primitive_type);
        exp->type_info.data_structure = PRIMITIVE;
        (yyval.c_cast_expression) = exp;
    }
#line 2761 "src/parser.c"
    break;

  case 82:
#line 1063 "src/parser.y"
    {
        t_cast_expression* exp = zero_allocate(t_cast_expression);
        exp->left = (yyvsp[0].c_postfix_expression);
        exp->type = (yyvsp[0].c_postfix_expression)->type;
        exp->type_info = (yyvsp[0].c_postfix_expression)->type_info;
        (yyval.c_cast_expression) = exp;
    }
#line 2773 "src/parser.c"
    break;

  case 83:
#line 1073 "src/parser.y"
    {
        if ((yyvsp[-1].c_expression)->type_info.data_structure != PRIMITIVE || (yyvsp[-1].c_expression)->type_info.primitive_type == VOID_TYPE || (yyvsp[-1].c_expression)->type_info.primitive_type == STRING_TYPE) {
            printf("Location %d:%d - Index expression must return a primitive and integer type\n", line, column);
        };
        t_type_info id = (yyvsp[-1].c_expression)->type_info;
        
        if ((yyvsp[-3].c_st_element) != NULL) {
            id = get_type_info((yyvsp[-3].c_st_element));
            if (id.data_structure != ARRAY) {
                printf("Location %d:%d - Identifier must be array\n", line, column);
            };
        }

        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = ARRAY_ACCESS;
        exp->left = (yyvsp[-3].c_st_element);
        exp->member.array_index = (yyvsp[-1].c_expression);

        exp->type_info.primitive_type = id.primitive_type;
        exp->type_info.data_structure = PRIMITIVE;
        (yyval.c_postfix_expression) = exp;
    }
#line 2800 "src/parser.c"
    break;

  case 84:
#line 1095 "src/parser.y"
    {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = FUNCTION_CALL;
        exp->left = (yyvsp[-3].c_st_element);
        exp->member.function_params = (yyvsp[-1].c_param_vals);
        
        // TODO: assert param-vals

        t_type_info id;
        id.primitive_type = LONG_TYPE; // default

        if ((yyvsp[-3].c_st_element) != NULL) {
            id = get_type_info((yyvsp[-3].c_st_element));
            if (id.data_structure != FUNCTION) {
                printf("Location %d:%d - Identifier must be function\n", line, column);
            };
        }

        exp->type_info.primitive_type = id.primitive_type;
        exp->type_info.data_structure = PRIMITIVE;
        (yyval.c_postfix_expression) = exp;
    }
#line 2827 "src/parser.c"
    break;

  case 85:
#line 1117 "src/parser.y"
    {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->primary = (yyvsp[0].c_primary_expression);
        exp->type = (yyvsp[0].c_primary_expression)->type;
        exp->type_info = (yyvsp[0].c_primary_expression)->type_info;
        (yyval.c_postfix_expression) = exp;
    }
#line 2839 "src/parser.c"
    break;

  case 86:
#line 1127 "src/parser.y"
    {
        t_param_vals* pv = zero_allocate(t_param_vals);
        pv->prev = (yyvsp[-2].c_param_vals);
        pv->cur = (yyvsp[0].c_expression);
        (yyval.c_param_vals) = pv;
    }
#line 2850 "src/parser.c"
    break;

  case 87:
#line 1133 "src/parser.y"
    {
        t_param_vals* pv = zero_allocate(t_param_vals);
        pv->cur = (yyvsp[0].c_expression);
        (yyval.c_param_vals) = pv;
    }
#line 2860 "src/parser.c"
    break;

  case 88:
#line 1138 "src/parser.y"
    {
        (yyval.c_param_vals) = NULL;
    }
#line 2868 "src/parser.c"
    break;

  case 89:
#line 1144 "src/parser.y"
    {
        st_element_t* element = scope_find(current_scope, (yyvsp[0].string_val));
        if (element == NULL) {
            printf("Location %d:%d - Identifier %s not previously declared\n", line, column, (yyvsp[0].string_val));
        }
        free((yyvsp[0].string_val));
        (yyval.c_st_element) = element;
    }
#line 2881 "src/parser.c"
    break;

  case 90:
#line 1154 "src/parser.y"
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = IDENTIFIER_PRIMARY_EXPRESSION;
        exp->member.identifier = (yyvsp[0].c_st_element);

        if ((yyvsp[0].c_st_element) != NULL) {
            exp->type_info = get_type_info((yyvsp[0].c_st_element));
        } else {
            // default
            exp->type_info.primitive_type = LONG_TYPE;
            exp->type_info.data_structure = PRIMITIVE;
        }
        (yyval.c_primary_expression) = exp;
    }
#line 2900 "src/parser.c"
    break;

  case 91:
#line 1168 "src/parser.y"
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = CONSTANT_PRIMARY_EXPRESSION;
        exp->member.constant = (yyvsp[0].c_constant);
        exp->type_info = (yyvsp[0].c_constant)->type_info;
        (yyval.c_primary_expression) = exp;
    }
#line 2912 "src/parser.c"
    break;

  case 92:
#line 1175 "src/parser.y"
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = STRING_PRIMARY_EXPRESSION;
        exp->member.string = (yyvsp[0].string_val);
        exp->type_info.primitive_type = STRING_TYPE;
        exp->type_info.data_structure = PRIMITIVE;
        (yyval.c_primary_expression) = exp;
    }
#line 2925 "src/parser.c"
    break;

  case 93:
#line 1183 "src/parser.y"
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = NESTED_PRIMARY_EXPRESSION;
        exp->member.expression = (yyvsp[-1].c_expression);
        exp->type_info = (yyvsp[-1].c_expression)->type_info;
        (yyval.c_primary_expression) = exp;
    }
#line 2937 "src/parser.c"
    break;

  case 94:
#line 1193 "src/parser.y"
    {
        t_constant* c = zero_allocate(t_constant);
        c->type_info.primitive_type = LONG_TYPE;
        c->type_info.data_structure = PRIMITIVE;
        c->member.integer_val = (yyvsp[0].integer_val);
        (yyval.c_constant) = c;
    }
#line 2949 "src/parser.c"
    break;

  case 95:
#line 1200 "src/parser.y"
    {
        t_constant* c = zero_allocate(t_constant);
        c->type_info.primitive_type = CHAR_TYPE;
        c->type_info.data_structure = PRIMITIVE;
        c->member.char_val = (yyvsp[0].char_val);
        (yyval.c_constant) = c;
    }
#line 2961 "src/parser.c"
    break;

  case 96:
#line 1207 "src/parser.y"
    {
        t_constant* c = zero_allocate(t_constant);
        c->type_info.primitive_type = DOUBLE_TYPE;
        c->type_info.data_structure = PRIMITIVE;
        c->member.float_val = (yyvsp[0].float_val);
        (yyval.c_constant) = c;
    }
#line 2973 "src/parser.c"
    break;

  case 97:
#line 1217 "src/parser.y"
    { (yyval.c_assignment_operator) = EQUAL_OPERATOR; }
#line 2979 "src/parser.c"
    break;

  case 98:
#line 1218 "src/parser.y"
    { (yyval.c_assignment_operator) = PLUS_EQUAL_OPERATOR; }
#line 2985 "src/parser.c"
    break;

  case 99:
#line 1219 "src/parser.y"
    { (yyval.c_assignment_operator) = MINUS_EQUAL_OPERATOR; }
#line 2991 "src/parser.c"
    break;

  case 100:
#line 1220 "src/parser.y"
    { (yyval.c_assignment_operator) = ASTERISK_EQUAL_OPERATOR; }
#line 2997 "src/parser.c"
    break;

  case 101:
#line 1221 "src/parser.y"
    { (yyval.c_assignment_operator) = SLASH_EQUAL_OPERATOR; }
#line 3003 "src/parser.c"
    break;

  case 102:
#line 1222 "src/parser.y"
    { (yyval.c_assignment_operator) = PERCENT_EQUAL_OPERATOR; }
#line 3009 "src/parser.c"
    break;

  case 103:
#line 1226 "src/parser.y"
    { (yyval.c_expression_type) = UNARY_PLUS; }
#line 3015 "src/parser.c"
    break;

  case 104:
#line 1227 "src/parser.y"
    { (yyval.c_expression_type) = UNARY_MINUS; }
#line 3021 "src/parser.c"
    break;

  case 105:
#line 1228 "src/parser.y"
    { (yyval.c_expression_type) = UNARY_EXCL; }
#line 3027 "src/parser.c"
    break;

  case 106:
#line 1229 "src/parser.y"
    { (yyval.c_expression_type) = UNARY_SIZEOF; }
#line 3033 "src/parser.c"
    break;

  case 107:
#line 1233 "src/parser.y"
    { (yyval.c_expression_type) = LESS_THAN; }
#line 3039 "src/parser.c"
    break;

  case 108:
#line 1234 "src/parser.y"
    { (yyval.c_expression_type) = GREATER_THAN; }
#line 3045 "src/parser.c"
    break;

  case 109:
#line 1235 "src/parser.y"
    { (yyval.c_expression_type) = LESS_THAN_OR_EQUAL; }
#line 3051 "src/parser.c"
    break;

  case 110:
#line 1236 "src/parser.y"
    { (yyval.c_expression_type) = GREATER_THAN_OR_EQUAL; }
#line 3057 "src/parser.c"
    break;

  case 111:
#line 1237 "src/parser.y"
    { (yyval.c_expression_type) = IS_IN; }
#line 3063 "src/parser.c"
    break;

  case 112:
#line 1241 "src/parser.y"
    { (yyval.c_expression_type) = ASTERISK_OPERATOR; }
#line 3069 "src/parser.c"
    break;

  case 113:
#line 1242 "src/parser.y"
    { (yyval.c_expression_type) = SLASH_OPERATOR; }
#line 3075 "src/parser.c"
    break;

  case 114:
#line 1243 "src/parser.y"
    { (yyval.c_expression_type) = PERCENT_OPERATOR; }
#line 3081 "src/parser.c"
    break;

  case 115:
#line 1247 "src/parser.y"
    {
        (yyval.c_primitive_type) = VOID_TYPE;
    }
#line 3089 "src/parser.c"
    break;

  case 116:
#line 1250 "src/parser.y"
    {
        (yyval.c_primitive_type) = BYTE_TYPE;
    }
#line 3097 "src/parser.c"
    break;

  case 117:
#line 1253 "src/parser.y"
    {
        (yyval.c_primitive_type) = BYTE_TYPE;
    }
#line 3105 "src/parser.c"
    break;

  case 118:
#line 1256 "src/parser.y"
    {
        (yyval.c_primitive_type) = BYTE_TYPE;
    }
#line 3113 "src/parser.c"
    break;

  case 119:
#line 1259 "src/parser.y"
    {
        (yyval.c_primitive_type) = SHORT_TYPE;
    }
#line 3121 "src/parser.c"
    break;

  case 120:
#line 1262 "src/parser.y"
    {
        (yyval.c_primitive_type) = INT_TYPE;
    }
#line 3129 "src/parser.c"
    break;

  case 121:
#line 1265 "src/parser.y"
    {
        (yyval.c_primitive_type) = LONG_TYPE;
    }
#line 3137 "src/parser.c"
    break;

  case 122:
#line 1268 "src/parser.y"
    {
        (yyval.c_primitive_type) = FLOAT_TYPE;
    }
#line 3145 "src/parser.c"
    break;

  case 123:
#line 1271 "src/parser.y"
    {
        (yyval.c_primitive_type) = DOUBLE_TYPE;
    }
#line 3153 "src/parser.c"
    break;


#line 3157 "src/parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1275 "src/parser.y"


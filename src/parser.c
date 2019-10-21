/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/parser.y" /* yacc.c:339  */


#include "abstract_syntax_tree.h"
#include "my_string.h"
#include "lexical_error_handler.h"
#include "symbol_table.h"
#include <stdio.h>
#include <string.h>

#define zero_allocate(type) ((type*)calloc(1, sizeof(type)))

extern FILE* yyin;
extern int yylex();
extern uint32_t line;
extern uint32_t column;

t_symbol_table_list* sym_table = NULL;
node ast_root;

void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

void print_ast(node root, node_type type, int cur_level);
void free_ast(node root, node_type type);


#line 95 "src/parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
#line 53 "src/parser.y" /* yacc.c:355  */

    t_primary_expression_type c_primary_expression_type;
    t_constant_type c_constant_type;
    t_postfix_expression_type c_postfix_expression_type;
    t_unary_expression_type c_unary_expression_type;
    t_add_expression_type c_add_expression_type;
    t_eq_expression_type c_eq_expression_type;
    t_shift_expression_type c_shift_expression_type;
    t_rel_expression_type c_rel_expression_type;
    t_mult_operator c_mult_operator;
    t_assignment_operator c_assignment_operator;
    t_iteration_type c_iteration_type;
    t_primitive_type c_primitive_type;
    t_print_type c_print_type;
    t_scan_type c_scan_type;
    t_program* c_program;
    t_declaration_list* c_declaration_list;
    t_declaration* c_declaration;
    t_variable* c_variable;
    t_function* c_function;
    t_function_param* c_function_param;
    t_function_params* c_function_params;
    t_scope* c_scope;
    t_statement_list* c_statement_list;
    t_statement* c_statement;
    t_print* c_print;
    t_scan* c_scan;
    t_return* c_return;
    t_expression* c_expression;
    t_condition* c_condition;
    t_iteration* c_iteration;
    t_while* c_while;
    t_for* c_for;
    t_assignment* c_assignment;
    t_and_expression* c_and_expression;
    t_or_expression* c_or_expression;
    t_bw_or_expression* c_bw_or_expression;
    t_bw_xor_expression* c_bw_xor_expression;
    t_bw_and_expression* c_bw_and_expression;
    t_eq_expression* c_eq_expression;
    t_rel_expression* c_rel_expression;
    t_shift_expression* c_shift_expression;
    t_set_rm_expression* c_set_rm_expression;
    t_add_expression* c_add_expression;
    t_mult_expression* c_mult_expression;
    t_cast_expression* c_cast_expression;
    t_unary_expression* c_unary_expression;
    t_postfix_expression* c_postfix_expression;
    t_primary_expression* c_primary_expression;
    t_constant* c_constant;
    t_param_vals* c_param_vals;
    char* string_val;
    int64_t integer_val;
    double float_val;
    char char_val;

#line 263 "src/parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 280 "src/parser.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
       0,   160,   160,   171,   177,   183,   190,   200,   207,   214,
     221,   231,   243,   249,   255,   261,   268,   275,   282,   292,
     300,   306,   312,   318,   324,   330,   336,   342,   348,   354,
     363,   372,   381,   384,   387,   393,   396,   399,   405,   412,
     422,   428,   437,   446,   457,   465,   468,   474,   482,   489,
     497,   503,   511,   517,   525,   531,   539,   545,   553,   559,
     567,   574,   581,   589,   596,   604,   611,   618,   626,   632,
     640,   647,   654,   662,   669,   677,   683,   691,   697,   703,
     711,   718,   725,   733,   739,   744,   750,   756,   762,   768,
     777,   783,   789,   798,   799,   800,   801,   802,   803,   807,
     808,   809,   813,   814,   815,   816,   817,   821,   822,   823,
     827,   830,   833,   836,   839,   842,   845,   848,   851
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
  "param-decs", "param-dec", "scope", "statement-list", "statement",
  "print", "scan", "print-type", "scan-type", "condition", "iteration",
  "while-iteration", "for-iteration", "return", "optional-expression",
  "expression", "assignment", "and-expression", "or-expression",
  "bw-and-expression", "bw-or-expression", "bw-xor-expression",
  "eq-expression", "rel-expression", "shift-expression",
  "set-rm-expression", "add-expression", "mult-expression",
  "cast-expression", "unary-expression", "postfix-expression",
  "param-vals", "primary-expression", "constant", "assignment-op",
  "unary-op", "rel-op", "mul-op", "type", YY_NULLPTR
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

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -159,    19,   122,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,     7,    21,     5,    10,
     122,  -159,   -14,    32,   -10,    -5,  -159,    52,  -159,    31,
    -159,    63,   122,    15,  -159,  -159,  -159,  -159,    65,    57,
      89,  -159,    82,  -159,   160,  -159,  -159,  -159,  -159,  -159,
       0,  -159,  -159,  -159,    70,  -159,  -159,  -159,  -159,  -159,
    -159,    97,   101,   105,    78,  -159,  -159,  -159,  -159,  -159,
      78,   116,  -159,  -159,  -159,  -159,  -159,    83,  -159,    90,
      92,    99,   100,   119,    54,    13,    60,    88,    62,    25,
    -159,  -159,    30,  -159,  -159,    70,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,   219,   139,   140,  -159,    78,  -159,    78,
      78,    78,    96,  -159,   127,   128,  -159,   219,   219,   219,
     219,   219,   219,   219,  -159,  -159,  -159,  -159,  -159,   219,
     219,   219,   219,   219,   219,  -159,  -159,  -159,   219,    78,
      78,  -159,    90,  -159,   219,   145,   152,   146,  -159,  -159,
    -159,    92,    99,   100,   119,    54,    13,    13,    60,    88,
      88,    62,    25,    25,  -159,   172,  -159,     4,  -159,   154,
     154,    78,  -159,  -159,    78,   123,  -159,   149,  -159,   154,
      78,  -159,   174,   154,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     3,     5,     6,     0,     0,     0,     0,
      14,     7,     0,     0,     0,     0,    13,     0,    10,     0,
       9,     0,     0,    15,     8,    21,    11,    12,     0,     0,
       0,    18,     0,    17,    86,    88,    90,    91,    92,    19,
       0,   101,    99,   100,     0,    32,    33,    34,    35,    36,
      37,     0,     0,     0,    46,    23,    22,    20,    24,    25,
       0,     0,    27,    28,    40,    41,    29,     0,    47,    49,
      51,    53,    55,    57,    59,    62,    64,    67,    69,    72,
      74,    76,    79,    82,    87,     0,    16,    93,    94,    95,
      96,    97,    98,     0,     0,     0,    86,     0,    78,     0,
       0,    46,     0,    45,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   107,   108,   109,     0,     0,
      85,    77,    48,    89,     0,     0,     0,     0,    44,    30,
      31,    50,    52,    54,    56,    58,    60,    61,    63,    65,
      66,    68,    70,    71,    73,     0,    84,     0,    75,     0,
       0,    46,    80,    81,     0,    38,    42,     0,    83,     0,
      46,    39,     0,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,   187,  -159,  -159,  -159,   158,   163,  -159,
    -158,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -109,   -50,  -159,    93,    74,    77,    79,    98,    76,   -18,
      87,   -24,   102,   -21,   -74,   -53,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    65,    14,    15,    25,    26,    66,    40,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     112,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,   167,    93,    94,
     103,    95,   129,   138,    16
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     104,   108,   147,    44,    45,    27,    46,    47,    48,    31,
      17,   175,   176,    50,   113,    22,    23,    27,   173,     3,
     114,   181,    24,    28,    38,   184,    39,    30,   124,   125,
      18,    32,    19,    51,    20,   105,   126,   127,    52,    53,
     174,   139,   141,   140,    29,    54,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    33,   128,   104,    21,   145,
     146,   113,   177,    42,   164,   135,   136,   137,    34,    43,
     168,   182,    35,   106,    45,    41,    46,    47,    48,   122,
     123,    44,    45,   107,    46,    47,    48,   130,   131,   165,
     166,    50,    44,    45,    96,    46,    47,    48,    35,    49,
     133,   134,    50,    51,   156,   157,   159,   160,    52,    53,
     109,    51,   162,   163,   110,    54,    52,    53,   111,   115,
     116,   113,    51,    54,   178,   117,   118,    52,    53,   119,
     113,   120,   132,   148,    54,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    55,    56,    57,    58,    59,    60,
      61,   121,    62,   143,   144,    63,    64,    44,    45,   169,
      46,    47,    48,    35,   149,   150,   170,    50,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    97,    98,    99,
     100,   101,   102,   171,   172,   179,   180,    51,   183,    13,
      37,   151,    52,    53,    36,   152,   142,   155,   153,    54,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    55,
      56,    57,    58,    59,    60,    61,   158,    62,   154,     0,
      63,    64,   106,    45,     0,    46,    47,    48,     0,     0,
       0,     0,    50,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,    52,    53,     0,
       0,     0,     0,     0,    54
};

static const yytype_int16 yycheck[] =
{
      50,    54,   111,     3,     4,    20,     6,     7,     8,    14,
       3,   169,   170,    13,    64,    10,     6,    32,    14,     0,
      70,   179,    12,    37,     9,   183,    11,    37,    15,    16,
       9,    36,    11,    33,    13,    50,    23,    24,    38,    39,
      36,    11,    95,    13,    12,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     3,    43,   107,    37,   109,
     110,   111,   171,     6,   138,    40,    41,    42,    37,    12,
     144,   180,     9,     3,     4,    10,     6,     7,     8,    25,
      26,     3,     4,    13,     6,     7,     8,    27,    28,   139,
     140,    13,     3,     4,    12,     6,     7,     8,     9,    10,
      38,    39,    13,    33,   122,   123,   130,   131,    38,    39,
      13,    33,   133,   134,    13,    45,    38,    39,    13,     3,
      37,   171,    33,    45,   174,    35,    34,    38,    39,    30,
     180,    31,    44,    37,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    32,    63,    14,    14,    66,    67,     3,     4,    14,
       6,     7,     8,     9,    37,    37,    14,    13,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    17,    18,    19,
      20,    21,    22,    37,    12,    62,    37,    33,    14,     2,
      32,   117,    38,    39,    31,   118,   103,   121,   119,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   129,    63,   120,    -1,
      66,    67,     3,     4,    -1,     6,     7,     8,    -1,    -1,
      -1,    -1,    13,    -1,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,    73,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    74,    75,    76,   115,     3,     9,    11,
      13,    37,    10,     6,    12,    77,    78,   115,    37,    12,
      37,    14,    36,     3,    37,     9,    79,    78,     9,    11,
      80,    10,     6,    12,     3,     4,     6,     7,     8,    10,
      13,    33,    38,    39,    45,    55,    56,    57,    58,    59,
      60,    61,    63,    66,    67,    74,    79,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   109,   110,   112,    12,    17,    18,    19,
      20,    21,    22,   111,    92,   115,     3,    13,   106,    13,
      13,    13,    91,    92,    92,     3,    37,    35,    34,    30,
      31,    32,    25,    26,    15,    16,    23,    24,    43,   113,
      27,    28,    44,    38,    39,    40,    41,    42,   114,    11,
      13,   106,    94,    14,    14,    92,    92,    91,    37,    37,
      37,    95,    96,    97,    98,    99,   100,   100,   101,   102,
     102,   103,   104,   104,   105,    92,    92,   108,   105,    14,
      14,    37,    12,    14,    36,    81,    81,    91,    92,    62,
      37,    81,    91,    14,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      75,    76,    77,    77,    77,    78,    78,    78,    78,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    83,    84,    84,    84,    85,    85,    85,    86,    86,
      87,    87,    88,    89,    90,    91,    91,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,    99,   100,   100,   101,   101,   101,   102,   102,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   106,
     107,   107,   107,   108,   108,   108,   109,   109,   109,   109,
     110,   110,   110,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   113,   113,   113,   113,   113,   114,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     3,     6,     5,
       5,     6,     3,     1,     0,     2,     5,     4,     4,     3,
       2,     0,     1,     1,     1,     1,     2,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     5,     7,
       1,     1,     5,     9,     3,     1,     0,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     3,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     4,     1,     2,     2,     1,
       4,     4,     1,     3,     1,     0,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
| yyreduce -- Do a reduction.  |
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
#line 160 "src/parser.y" /* yacc.c:1646  */
    {
        t_program* program = zero_allocate(t_program);
        program->declarations = (yyvsp[0].c_declaration_list);
        ast_root.c_program = program;
        print_ast(ast_root, NT_PROGRAM, 0);
        print_symbol_table_list(sym_table);
        (yyval.c_program) = program;
    }
#line 1535 "src/parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 171 "src/parser.y" /* yacc.c:1646  */
    {
        t_declaration_list* declaration_list = zero_allocate(t_declaration_list);
        declaration_list->prev = (yyvsp[-1].c_declaration_list);
        declaration_list->cur = (yyvsp[0].c_declaration);
        (yyval.c_declaration_list) = declaration_list;
    }
#line 1546 "src/parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 177 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_declaration_list) = NULL;
    }
#line 1554 "src/parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 183 "src/parser.y" /* yacc.c:1646  */
    {
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = VAR_DECLARATION;
        dec->member.variable = (yyvsp[0].c_variable);
        append_symbol_table_node(sym_table, dec);
        (yyval.c_declaration) = dec;
    }
#line 1566 "src/parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 190 "src/parser.y" /* yacc.c:1646  */
    {
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = FUN_DECLARATION;
        dec->member.function = (yyvsp[0].c_function);  
        append_symbol_table_node(sym_table, dec); 
        (yyval.c_declaration) = dec;  
    }
#line 1578 "src/parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 200 "src/parser.y" /* yacc.c:1646  */
    {
        t_variable* var = zero_allocate(t_variable);
        var->type = (yyvsp[-2].c_primitive_type);
        var->structure = PRIMITIVE_TYPE;
        var->identifier = (yyvsp[-1].string_val);
        (yyval.c_variable) = var;
    }
#line 1590 "src/parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 207 "src/parser.y" /* yacc.c:1646  */
    {
        t_variable* var = zero_allocate(t_variable);
        var->type = (yyvsp[-5].c_primitive_type);
        var->structure = ARRAY_TYPE;
        var->identifier = (yyvsp[-4].string_val);
        (yyval.c_variable) = var;
    }
#line 1602 "src/parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 214 "src/parser.y" /* yacc.c:1646  */
    {
        t_variable* var = zero_allocate(t_variable);
        var->type = (yyvsp[-4].c_primitive_type);
        var->structure = ARRAY_TYPE;
        var->identifier = (yyvsp[-3].string_val);
        (yyval.c_variable) = var;
    }
#line 1614 "src/parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 221 "src/parser.y" /* yacc.c:1646  */
    {
        t_variable* var = zero_allocate(t_variable);
        var->type = (yyvsp[-4].c_primitive_type);
        var->structure = SET_TYPE;
        var->identifier = (yyvsp[-3].string_val);
        (yyval.c_variable) = var;
    }
#line 1626 "src/parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 231 "src/parser.y" /* yacc.c:1646  */
    {
        t_function* fun = zero_allocate(t_function);
        fun->return_type = (yyvsp[-5].c_primitive_type);
        fun->return_structure = PRIMITIVE_TYPE;
        fun->identifier = (yyvsp[-4].string_val);
        fun->params = (yyvsp[-2].c_function_params);
        fun->body = (yyvsp[0].c_scope);
        (yyval.c_function) = fun;
    }
#line 1640 "src/parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 243 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_params* fp = zero_allocate(t_function_params);
        fp->cur = (yyvsp[0].c_function_param);
        fp->prev = (yyvsp[-2].c_function_params);
        (yyval.c_function_params) = fp; 
    }
#line 1651 "src/parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 249 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_params* fp = zero_allocate(t_function_params);
        fp->cur = (yyvsp[0].c_function_param);
        fp->prev = NULL;
        (yyval.c_function_params) = fp; 
    }
#line 1662 "src/parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 255 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_function_params) = NULL;
    }
#line 1670 "src/parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 261 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = (yyvsp[-1].c_primitive_type);
        var->structure = PRIMITIVE_TYPE;
        var->identifier = (yyvsp[0].string_val);
        (yyval.c_function_param) = var;
    }
#line 1682 "src/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 268 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = (yyvsp[-4].c_primitive_type);
        var->structure = ARRAY_TYPE;
        var->identifier = (yyvsp[-3].string_val);
        (yyval.c_function_param) = var;
    }
#line 1694 "src/parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 275 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = (yyvsp[-3].c_primitive_type);
        var->structure = ARRAY_TYPE;
        var->identifier = (yyvsp[-2].string_val);
        (yyval.c_function_param) = var;
    }
#line 1706 "src/parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 282 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = (yyvsp[-3].c_primitive_type);
        var->structure = SET_TYPE;
        var->identifier = (yyvsp[-2].string_val);
        (yyval.c_function_param) = var;
    }
#line 1718 "src/parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 292 "src/parser.y" /* yacc.c:1646  */
    {
        t_scope* scope = zero_allocate(t_scope);
        scope->statements = (yyvsp[-1].c_statement_list);
        (yyval.c_scope) = scope;
    }
#line 1728 "src/parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 300 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement_list* fp = zero_allocate(t_statement_list);
        fp->cur = (yyvsp[0].c_statement);
        fp->prev = (yyvsp[-1].c_statement_list);
        (yyval.c_statement_list) = fp; 
    }
#line 1739 "src/parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 306 "src/parser.y" /* yacc.c:1646  */
    {
    (yyval.c_statement_list) = NULL;
}
#line 1747 "src/parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 312 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = SCOPE_STATEMENT;
        stmt->member.scope = (yyvsp[0].c_scope);
        (yyval.c_statement) = stmt;
    }
#line 1758 "src/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 318 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = DECLARATION_STATEMENT;
        stmt->member.declaration = (yyvsp[0].c_declaration);
        (yyval.c_statement) = stmt;
    }
#line 1769 "src/parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 324 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = PRINT_STATEMENT;
        stmt->member.print = (yyvsp[0].c_print);
        (yyval.c_statement) = stmt;
    }
#line 1780 "src/parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 330 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = SCAN_STATEMENT;
        stmt->member.scan = (yyvsp[0].c_scan);
        (yyval.c_statement) = stmt;
    }
#line 1791 "src/parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 336 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = EXPRESSION_STATEMENT;
        stmt->member.expression = (yyvsp[-1].c_expression);
        (yyval.c_statement) = stmt;
    }
#line 1802 "src/parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 342 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = CONDITION_STATEMENT;
        stmt->member.condition = (yyvsp[0].c_condition);
        (yyval.c_statement) = stmt;
    }
#line 1813 "src/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 348 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = ITERATION_STATEMENT;
        stmt->member.iteration = (yyvsp[0].c_iteration);
        (yyval.c_statement) = stmt;
    }
#line 1824 "src/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 354 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = RETURN_STATEMENT;
        stmt->member._return = (yyvsp[0].c_return);
        (yyval.c_statement) = stmt;
    }
#line 1835 "src/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 363 "src/parser.y" /* yacc.c:1646  */
    {
        t_print* print = zero_allocate(t_print);
        print->type = (yyvsp[-2].c_print_type);
        print->expression = (yyvsp[-1].c_expression);
        (yyval.c_print) = print;
    }
#line 1846 "src/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 372 "src/parser.y" /* yacc.c:1646  */
    {
        t_scan* scan = zero_allocate(t_scan);
        scan->type = (yyvsp[-2].c_scan_type);
        scan->destiny = (yyvsp[-1].string_val);
        (yyval.c_scan) = scan;
    }
#line 1857 "src/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 381 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_print_type) = PRINT_DEC_TYPE;
    }
#line 1865 "src/parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 384 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_print_type) = PRINT_CHAR_TYPE;
    }
#line 1873 "src/parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 387 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_print_type) = PRINT_HEX_TYPE;
    }
#line 1881 "src/parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 393 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_scan_type) = SCAN_DEC_TYPE;
    }
#line 1889 "src/parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 396 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_scan_type) = SCAN_CHAR_TYPE;
    }
#line 1897 "src/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 399 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_scan_type) = SCAN_FLOAT_TYPE;
    }
#line 1905 "src/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 405 "src/parser.y" /* yacc.c:1646  */
    {
        t_condition* cond = zero_allocate(t_condition);
        cond->condition = (yyvsp[-2].c_expression);
        cond->body = (yyvsp[0].c_statement);
        cond->else_body = NULL;  
        (yyval.c_condition) = cond;  
    }
#line 1917 "src/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 412 "src/parser.y" /* yacc.c:1646  */
    {   
        t_condition* cond = zero_allocate(t_condition);
        cond->condition = (yyvsp[-4].c_expression);
        cond->body = (yyvsp[-2].c_statement);
        cond->else_body = (yyvsp[0].c_statement);
        (yyval.c_condition) = cond;
    }
#line 1929 "src/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 422 "src/parser.y" /* yacc.c:1646  */
    {
        t_iteration* it = zero_allocate(t_iteration);
        it->type = WHILE_ITERATION;
        it->member._while = (yyvsp[0].c_while);
        (yyval.c_iteration) = it;
    }
#line 1940 "src/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 428 "src/parser.y" /* yacc.c:1646  */
    {
        t_iteration* it = zero_allocate(t_iteration);
        it->type = FOR_ITERATION;
        it->member._for = (yyvsp[0].c_for);
        (yyval.c_iteration) = it;
    }
#line 1951 "src/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 437 "src/parser.y" /* yacc.c:1646  */
    {
        t_while* w = zero_allocate(t_while);
        w->condition = (yyvsp[-2].c_expression);
        w->body = (yyvsp[0].c_statement);
        (yyval.c_while) = w;
    }
#line 1962 "src/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 446 "src/parser.y" /* yacc.c:1646  */
    {
        t_for* f = zero_allocate(t_for);
        f->initialization = (yyvsp[-6].c_expression);
        f->condition = (yyvsp[-4].c_expression);
        f->step = (yyvsp[-2].c_expression);
        f->body = (yyvsp[0].c_statement);
        (yyval.c_for) = f;
    }
#line 1975 "src/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 457 "src/parser.y" /* yacc.c:1646  */
    {
        t_return* ret = zero_allocate(t_return);
        ret->expression = (yyvsp[-1].c_expression);
        (yyval.c_return) = ret;
    }
#line 1985 "src/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 465 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 1993 "src/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 468 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_expression) = NULL;
    }
#line 2001 "src/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 474 "src/parser.y" /* yacc.c:1646  */
    {
        t_expression* exp = zero_allocate(t_expression);
        exp->assignment = (yyvsp[0].c_assignment);
        (yyval.c_expression) = exp;
    }
#line 2011 "src/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 482 "src/parser.y" /* yacc.c:1646  */
    {
        t_assignment* exp = zero_allocate(t_assignment);
        exp->identifier = (yyvsp[-2].string_val);
        exp->operator = (yyvsp[-1].c_assignment_operator);
        exp->and_expression = (yyvsp[0].c_and_expression);
        (yyval.c_assignment) = exp;
    }
#line 2023 "src/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 489 "src/parser.y" /* yacc.c:1646  */
    {
        t_assignment* exp = zero_allocate(t_assignment);
        exp->and_expression = (yyvsp[0].c_and_expression);
        (yyval.c_assignment) = exp;
    }
#line 2033 "src/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 497 "src/parser.y" /* yacc.c:1646  */
    {
        t_and_expression* exp = zero_allocate(t_and_expression);
        exp->left = (yyvsp[-2].c_and_expression);
        exp->right = (yyvsp[0].c_or_expression);
        (yyval.c_and_expression) = exp;
    }
#line 2044 "src/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 503 "src/parser.y" /* yacc.c:1646  */
    {
        t_and_expression* exp = zero_allocate(t_and_expression);
        exp->right = (yyvsp[0].c_or_expression);
        (yyval.c_and_expression) = exp;
    }
#line 2054 "src/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 511 "src/parser.y" /* yacc.c:1646  */
    {
        t_or_expression* exp = zero_allocate(t_or_expression);
        exp->left = (yyvsp[-2].c_or_expression);
        exp->right = (yyvsp[0].c_bw_and_expression);
        (yyval.c_or_expression) = exp;
    }
#line 2065 "src/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 517 "src/parser.y" /* yacc.c:1646  */
    {
        t_or_expression* exp = zero_allocate(t_or_expression);
        exp->right = (yyvsp[0].c_bw_and_expression);
        (yyval.c_or_expression) = exp;
    }
#line 2075 "src/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 525 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_and_expression* exp = zero_allocate(t_bw_and_expression);
        exp->left = (yyvsp[-2].c_bw_and_expression);
        exp->right = (yyvsp[0].c_bw_or_expression);
        (yyval.c_bw_and_expression) = exp;
    }
#line 2086 "src/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 531 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_and_expression* exp = zero_allocate(t_bw_and_expression);
        exp->right = (yyvsp[0].c_bw_or_expression);
        (yyval.c_bw_and_expression) = exp;
    }
#line 2096 "src/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 539 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_or_expression* exp = zero_allocate(t_bw_or_expression);
        exp->left = (yyvsp[-2].c_bw_or_expression);
        exp->right = (yyvsp[0].c_bw_xor_expression);
        (yyval.c_bw_or_expression) = exp;
    }
#line 2107 "src/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 545 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_or_expression* exp = zero_allocate(t_bw_or_expression);
        exp->right = (yyvsp[0].c_bw_xor_expression);
        (yyval.c_bw_or_expression) = exp;
    }
#line 2117 "src/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 553 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_xor_expression* exp = zero_allocate(t_bw_xor_expression);
        exp->left = (yyvsp[-2].c_bw_xor_expression);
        exp->right = (yyvsp[0].c_eq_expression);
        (yyval.c_bw_xor_expression) = exp;
    }
#line 2128 "src/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 559 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_xor_expression* exp = zero_allocate(t_bw_xor_expression);
        exp->right = (yyvsp[0].c_eq_expression);
        (yyval.c_bw_xor_expression) = exp;
    }
#line 2138 "src/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 567 "src/parser.y" /* yacc.c:1646  */
    {
        t_eq_expression* exp = zero_allocate(t_eq_expression);
        exp->type = EQ_EQ_EXPRESSION;
        exp->left = (yyvsp[-2].c_eq_expression);
        exp->right = (yyvsp[0].c_rel_expression);
        (yyval.c_eq_expression) = exp;
    }
#line 2150 "src/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 574 "src/parser.y" /* yacc.c:1646  */
    {
        t_eq_expression* exp = zero_allocate(t_eq_expression);
        exp->type = NOT_EQ_EXPRESSION;
        exp->left = (yyvsp[-2].c_eq_expression);
        exp->right = (yyvsp[0].c_rel_expression);
        (yyval.c_eq_expression) = exp;
    }
#line 2162 "src/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 581 "src/parser.y" /* yacc.c:1646  */
    {
        t_eq_expression* exp = zero_allocate(t_eq_expression);
        exp->right = (yyvsp[0].c_rel_expression);
        (yyval.c_eq_expression) = exp;
    }
#line 2172 "src/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 589 "src/parser.y" /* yacc.c:1646  */
    {
        t_rel_expression* exp = zero_allocate(t_rel_expression);
        exp->left = (yyvsp[-2].c_rel_expression);
        exp->type = (yyvsp[-1].c_rel_expression_type);
        exp->right = (yyvsp[0].c_shift_expression);
        (yyval.c_rel_expression) = exp;
    }
#line 2184 "src/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 596 "src/parser.y" /* yacc.c:1646  */
    {
        t_rel_expression* exp = zero_allocate(t_rel_expression);
        exp->right = (yyvsp[0].c_shift_expression);
        (yyval.c_rel_expression) = exp;
    }
#line 2194 "src/parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 604 "src/parser.y" /* yacc.c:1646  */
    {
        t_shift_expression* exp = zero_allocate(t_shift_expression);
        exp->left = (yyvsp[-2].c_shift_expression);
        exp->type = LEFT_SHIFT_EXPRESSION;
        exp->right = (yyvsp[0].c_set_rm_expression);
        (yyval.c_shift_expression) = exp;
    }
#line 2206 "src/parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 611 "src/parser.y" /* yacc.c:1646  */
    {
        t_shift_expression* exp = zero_allocate(t_shift_expression);
        exp->left = (yyvsp[-2].c_shift_expression);
        exp->type = RIGHT_SHIFT_EXPRESSION;
        exp->right = (yyvsp[0].c_set_rm_expression);
        (yyval.c_shift_expression) = exp;
    }
#line 2218 "src/parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 618 "src/parser.y" /* yacc.c:1646  */
    {
        t_shift_expression* exp = zero_allocate(t_shift_expression);
        exp->right = (yyvsp[0].c_set_rm_expression);
        (yyval.c_shift_expression) = exp;
    }
#line 2228 "src/parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 626 "src/parser.y" /* yacc.c:1646  */
    {
        t_set_rm_expression* exp = zero_allocate(t_set_rm_expression);
        exp->left = (yyvsp[-2].c_set_rm_expression);
        exp->right = (yyvsp[0].c_add_expression);
        (yyval.c_set_rm_expression) = exp;
    }
#line 2239 "src/parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 632 "src/parser.y" /* yacc.c:1646  */
    {
        t_set_rm_expression* exp = zero_allocate(t_set_rm_expression);
        exp->right = (yyvsp[0].c_add_expression);
        (yyval.c_set_rm_expression) = exp;
    }
#line 2249 "src/parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 640 "src/parser.y" /* yacc.c:1646  */
    {
        t_add_expression* exp = zero_allocate(t_add_expression);
        exp->left = (yyvsp[-2].c_add_expression);
        exp->type = ADD_PLUS;
        exp->right = (yyvsp[0].c_mult_expression);
        (yyval.c_add_expression) = exp;
    }
#line 2261 "src/parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 647 "src/parser.y" /* yacc.c:1646  */
    {
        t_add_expression* exp = zero_allocate(t_add_expression);
        exp->left = (yyvsp[-2].c_add_expression);
        exp->type = ADD_MINUS;
        exp->right = (yyvsp[0].c_mult_expression);
        (yyval.c_add_expression) = exp;
    }
#line 2273 "src/parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 654 "src/parser.y" /* yacc.c:1646  */
    {
        t_add_expression* exp = zero_allocate(t_add_expression);
        exp->right = (yyvsp[0].c_mult_expression);
        (yyval.c_add_expression) = exp;
    }
#line 2283 "src/parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 662 "src/parser.y" /* yacc.c:1646  */
    {
        t_mult_expression* exp = zero_allocate(t_mult_expression);
        exp->left = (yyvsp[-2].c_mult_expression);
        exp->type = (yyvsp[-1].c_mult_operator);
        exp->right = (yyvsp[0].c_cast_expression);
        (yyval.c_mult_expression) = exp;
    }
#line 2295 "src/parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 669 "src/parser.y" /* yacc.c:1646  */
    {
        t_mult_expression* exp = zero_allocate(t_mult_expression);
        exp->right = (yyvsp[0].c_cast_expression);
        (yyval.c_mult_expression) = exp;
    }
#line 2305 "src/parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 677 "src/parser.y" /* yacc.c:1646  */
    {
        t_cast_expression* exp = zero_allocate(t_cast_expression);
        exp->type = (yyvsp[-2].c_primitive_type);
        exp->left = (yyvsp[0].c_cast_expression);
        (yyval.c_cast_expression) = exp;
    }
#line 2316 "src/parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 683 "src/parser.y" /* yacc.c:1646  */
    {
        t_cast_expression* exp = zero_allocate(t_cast_expression);
        exp->right = (yyvsp[0].c_unary_expression);
        (yyval.c_cast_expression) = exp;
    }
#line 2326 "src/parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 691 "src/parser.y" /* yacc.c:1646  */
    {
        t_unary_expression* exp = zero_allocate(t_unary_expression);
        exp->type = (yyvsp[-1].c_unary_expression_type);
        exp->left = (yyvsp[0].c_unary_expression);
        (yyval.c_unary_expression) = exp;
    }
#line 2337 "src/parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 697 "src/parser.y" /* yacc.c:1646  */
    {
        t_unary_expression* exp = zero_allocate(t_unary_expression);
        exp->type = UNARY_SIZEOF;
        exp->left = (yyvsp[0].c_unary_expression);
        (yyval.c_unary_expression) = exp;
    }
#line 2348 "src/parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 703 "src/parser.y" /* yacc.c:1646  */
    {
        t_unary_expression* exp = zero_allocate(t_unary_expression);
        exp->right = (yyvsp[0].c_postfix_expression);
        (yyval.c_unary_expression) = exp;
    }
#line 2358 "src/parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 711 "src/parser.y" /* yacc.c:1646  */
    {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = ARRAY_ACCESS;
        exp->left = (yyvsp[-3].c_postfix_expression);
        exp->member.array_index = (yyvsp[-1].c_expression);
        (yyval.c_postfix_expression) = exp;
    }
#line 2370 "src/parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 718 "src/parser.y" /* yacc.c:1646  */
    {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = FUNCTION_CALL;
        exp->left = (yyvsp[-3].c_postfix_expression);
        exp->member.function_params = (yyvsp[-1].c_param_vals);
        (yyval.c_postfix_expression) = exp;
    }
#line 2382 "src/parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 725 "src/parser.y" /* yacc.c:1646  */
    {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->primary = (yyvsp[0].c_primary_expression);
        (yyval.c_postfix_expression) = exp;
    }
#line 2392 "src/parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 733 "src/parser.y" /* yacc.c:1646  */
    {
        t_param_vals* pv = zero_allocate(t_param_vals);
        pv->prev = (yyvsp[-2].c_param_vals);
        pv->cur = (yyvsp[0].c_expression);
        (yyval.c_param_vals) = pv;
    }
#line 2403 "src/parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 739 "src/parser.y" /* yacc.c:1646  */
    {
        t_param_vals* pv = zero_allocate(t_param_vals);
        pv->cur = (yyvsp[0].c_expression);
        (yyval.c_param_vals) = pv;
    }
#line 2413 "src/parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 744 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_param_vals) = NULL;
    }
#line 2421 "src/parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 750 "src/parser.y" /* yacc.c:1646  */
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = IDENTIFIER_PRIMARY_EXPRESSION;
        exp->member.identifier = (yyvsp[0].string_val);
        (yyval.c_primary_expression) = exp;
    }
#line 2432 "src/parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 756 "src/parser.y" /* yacc.c:1646  */
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = CONSTANT_PRIMARY_EXPRESSION;
        exp->member.constant = (yyvsp[0].c_constant);
        (yyval.c_primary_expression) = exp;
    }
#line 2443 "src/parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 762 "src/parser.y" /* yacc.c:1646  */
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = STRING_PRIMARY_EXPRESSION;
        exp->member.string = (yyvsp[0].string_val);
        (yyval.c_primary_expression) = exp;
    }
#line 2454 "src/parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 768 "src/parser.y" /* yacc.c:1646  */
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = NESTED_PRIMARY_EXPRESSION;
        exp->member.expression = (yyvsp[-1].c_expression);
        (yyval.c_primary_expression) = exp;
    }
#line 2465 "src/parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 777 "src/parser.y" /* yacc.c:1646  */
    {
        t_constant* c = zero_allocate(t_constant);
        c->type = INTEGER_CONSTANT;
        c->member.integer_val = (yyvsp[0].integer_val);
        (yyval.c_constant) = c;
    }
#line 2476 "src/parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 783 "src/parser.y" /* yacc.c:1646  */
    {
        t_constant* c = zero_allocate(t_constant);
        c->type = CHAR_CONSTANT;
        c->member.char_val = (yyvsp[0].char_val);
        (yyval.c_constant) = c;
    }
#line 2487 "src/parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 789 "src/parser.y" /* yacc.c:1646  */
    {
        t_constant* c = zero_allocate(t_constant);
        c->type = REAL_CONSTANT;
        c->member.float_val = (yyvsp[0].float_val);
        (yyval.c_constant) = c;
    }
#line 2498 "src/parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 798 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = EQUAL_OPERATOR; }
#line 2504 "src/parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 799 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = PLUS_EQUAL_OPERATOR; }
#line 2510 "src/parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 800 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = MINUS_EQUAL_OPERATOR; }
#line 2516 "src/parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 801 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = ASTERISK_EQUAL_OPERATOR; }
#line 2522 "src/parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 802 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = SLASH_EQUAL_OPERATOR; }
#line 2528 "src/parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 803 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = PERCENT_EQUAL_OPERATOR; }
#line 2534 "src/parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 807 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_unary_expression_type) = UNARY_PLUS; }
#line 2540 "src/parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 808 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_unary_expression_type) = UNARY_MINUS; }
#line 2546 "src/parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 809 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_unary_expression_type) = UNARY_EXCL; }
#line 2552 "src/parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 813 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = LESS_THAN; }
#line 2558 "src/parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 814 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = GREATER_THAN; }
#line 2564 "src/parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 815 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = LESS_THAN_OR_EQUAL; }
#line 2570 "src/parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 816 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = GREATER_THAN_OR_EQUAL; }
#line 2576 "src/parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 817 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = IS_IN; }
#line 2582 "src/parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 821 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_mult_operator) = ASTERISK_OPERATOR; }
#line 2588 "src/parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 822 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_mult_operator) = SLASH_OPERATOR; }
#line 2594 "src/parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 823 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_mult_operator) = PERCENT_OPERATOR; }
#line 2600 "src/parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 827 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = VOID_TYPE;
    }
#line 2608 "src/parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 830 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = BYTE_TYPE;
    }
#line 2616 "src/parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 833 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = BYTE_TYPE;
    }
#line 2624 "src/parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 836 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = BYTE_TYPE;
    }
#line 2632 "src/parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 839 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = SHORT_TYPE;
    }
#line 2640 "src/parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 842 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = INT_TYPE;
    }
#line 2648 "src/parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 845 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = LONG_TYPE;
    }
#line 2656 "src/parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 848 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = FLOAT_TYPE;
    }
#line 2664 "src/parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 851 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = DOUBLE_TYPE;
    }
#line 2672 "src/parser.c" /* yacc.c:1646  */
    break;


#line 2676 "src/parser.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 855 "src/parser.y" /* yacc.c:1906  */


void spaces(int n) {
    for (int i = 0; i < n; i++) printf(" ");
}

void print_ast(node root, node_type type, int cur_level) {
    node child[10];
    memset(child, 0, sizeof child);

    switch(type) {
        case NT_UNARY_EXPRESSION_TYPE:
            spaces(cur_level);
            printf("Unary operator\n");
            spaces(cur_level+1);
            switch(root.c_unary_expression_type) {
                case UNARY_PLUS: printf("+\n"); break;
                case UNARY_MINUS: printf("-\n"); break;
                case UNARY_EXCL: printf("!\n"); break;
                case UNARY_SIZEOF: printf("sizeof\n"); break;
            }
        break;

        case NT_REL_EXPRESSION_TYPE:
            spaces(cur_level);
            printf("Relational operator\n");
            spaces(cur_level+1);
            switch(root.c_rel_expression_type) {
                case LESS_THAN: printf("<\n"); break;
                case GREATER_THAN: printf(">\n"); break;
                case LESS_THAN_OR_EQUAL: printf("<=\n"); break;
                case GREATER_THAN_OR_EQUAL: printf(">=\n"); break;
                case IS_IN: printf("in\n"); break;
            }
        break;

        case NT_MULT_OPERATOR:
            spaces(cur_level);
            printf("Mult Operator\n");
            spaces(cur_level+1);
            switch(root.c_mult_operator) {
                case ASTERISK_OPERATOR:
                printf("*\n");
                break;
                case SLASH_OPERATOR:
                printf("/\n");
                break;
                case PERCENT_OPERATOR:
                printf("%%\n");
                break;
            }
        break;

        case NT_ASSIGNMENT_OPERATOR:
            spaces(cur_level);
            printf("Assignment Operator\n");
            spaces(cur_level+1);
            switch(root.c_assignment_operator) {
                case EQUAL_OPERATOR:
                printf("=\n");
                break;
                case PLUS_EQUAL_OPERATOR:
                printf("+=\n");
                break;
                case MINUS_EQUAL_OPERATOR:
                printf("-=\n");
                break;
                case ASTERISK_EQUAL_OPERATOR:
                printf("*=\n");
                break;
                case SLASH_EQUAL_OPERATOR:
                printf("/=\n");
                break;
                case PERCENT_EQUAL_OPERATOR:
                printf("%%=\n");
                break;
            }
        break;

        case NT_PRIMITIVE_TYPE:
            spaces(cur_level);
            printf("Type\n");
            spaces(cur_level+1);
            switch(root.c_primitive_type) {
                case BYTE_TYPE:
                printf("byte\n");
                break;
                case SHORT_TYPE:
                printf("short\n");
                break;
                case INT_TYPE:
                printf("int\n");
                break;
                case LONG_TYPE:
                printf("long\n");
                break;
                case FLOAT_TYPE:
                printf("float\n");
                break;
                case DOUBLE_TYPE:
                printf("double\n");
                break;
                case VOID_TYPE:
                printf("void\n");
                break;
            }
        break;

        case NT_PRINT_TYPE:
        break;

        case NT_SCAN_TYPE:
        break;

        case NT_PROGRAM:
            spaces(cur_level);
            printf("Program\n");
            child[0].c_declaration_list = root.c_program->declarations;
            print_ast(child[0], NT_DECLARATION_LIST, cur_level+1);
        break;

        case NT_DECLARATION_LIST:
            if (root.c_declaration_list->prev) {
                child[0].c_declaration_list = root.c_declaration_list->prev;
                print_ast(child[0], NT_DECLARATION_LIST, cur_level);
            } else {
                // print only at beginning of declaration list
                spaces(cur_level);
                printf("Declaration List\n");
            }

            if (root.c_declaration_list->cur) {
                child[1].c_declaration = root.c_declaration_list->cur;
                print_ast(child[1], NT_DECLARATION, cur_level+1);
            }
        break;

        case NT_DECLARATION:
            spaces(cur_level);
            printf("Declaration\n");
            if (root.c_declaration->type == VAR_DECLARATION) {
                child[0].c_variable = root.c_declaration->member.variable;
                print_ast(child[0], NT_VARIABLE, cur_level+1);
            } else if (root.c_declaration->type == FUN_DECLARATION) {
                child[0].c_function = root.c_declaration->member.function;
                print_ast(child[0], NT_FUNCTION, cur_level+1);
            } 
        break;

        case NT_VARIABLE:
            spaces(cur_level);
            printf("Variable");
            switch(root.c_variable->structure) {
                case ARRAY_TYPE: printf(" (array)"); break;
                case SET_TYPE: printf(" (set)"); break;
                case PRIMITIVE_TYPE: printf(" (primitive)"); break;
            }
            printf("\n");
            child[0].c_primitive_type = root.c_variable->type;
            print_ast(child[0], NT_PRIMITIVE_TYPE, cur_level+1);
            child[1].string_val = root.c_variable->identifier;
            print_ast(child[1], NT_IDENTIFIER, cur_level+1);
        break;

        case NT_FUNCTION:
            spaces(cur_level);
            printf("Function\n");
            child[0].c_primitive_type = root.c_function->return_type;
            print_ast(child[0], NT_PRIMITIVE_TYPE, cur_level+1);
            child[1].string_val = root.c_function->identifier;
            print_ast(child[1], NT_IDENTIFIER, cur_level+1);   
            child[2].c_function_params = root.c_function->params;
            print_ast(child[2], NT_FUNCTION_PARAMS, cur_level+1);
            child[3].c_scope = root.c_function->body;
            print_ast(child[3], NT_SCOPE, cur_level+1);
            printf("\n");
        break;

        case NT_FUNCTION_PARAM:
            spaces(cur_level);
            printf("Parameter");
            switch(root.c_function_param->structure) {
                case ARRAY_TYPE: printf(" (array)"); break;
                case SET_TYPE: printf(" (set)"); break;
                case PRIMITIVE_TYPE: printf(" (primitive)"); break;
            }
            printf("\n");
            child[0].c_primitive_type = root.c_function_param->type;
            print_ast(child[0], NT_PRIMITIVE_TYPE, cur_level+1);
            child[1].string_val = root.c_function_param->identifier;
            print_ast(child[1], NT_IDENTIFIER, cur_level+1); 
        break;

        case NT_FUNCTION_PARAMS:
            if (root.c_function_params == NULL) return;
            
            if (root.c_function_params->prev) {
                child[0].c_function_params = root.c_function_params->prev;
                print_ast(child[0], NT_FUNCTION_PARAMS, cur_level);
            } else {
                spaces(cur_level);
                printf("Parameters\n");
            }

            if (root.c_function_params->cur) {
                child[1].c_function_param = root.c_function_params->cur;
                print_ast(child[1], NT_FUNCTION_PARAM, cur_level+1);
            }
        break;

        case NT_SCOPE:
            spaces(cur_level);
            printf("Scope\n");
            child[0].c_statement_list = root.c_scope->statements;
            print_ast(child[0], NT_STATEMENT_LIST, cur_level+1);
        break;

        case NT_STATEMENT_LIST:
            if (root.c_statement_list == NULL) return;
            
            if (root.c_statement_list->prev) {
                child[0].c_statement_list = root.c_statement_list->prev;
                print_ast(child[0], NT_STATEMENT_LIST, cur_level);
            } else {
                spaces(cur_level);
                printf("Statements\n");
            }

            if (root.c_statement_list->cur) {
                child[1].c_statement = root.c_statement_list->cur;
                print_ast(child[1], NT_STATEMENT, cur_level+1);
            }
        break;

        case NT_STATEMENT:
            spaces(cur_level);
            printf("Statement\n");
            switch (root.c_statement->type) {
                case SCOPE_STATEMENT:
                    child[0].c_scope = root.c_statement->member.scope;
                    print_ast(child[0], NT_SCOPE, cur_level+1);
                break;

                case DECLARATION_STATEMENT:
                    child[0].c_declaration = root.c_statement->member.declaration;
                    print_ast(child[0], NT_DECLARATION, cur_level+1);
                break;

                case PRINT_STATEMENT:
                    child[0].c_print = root.c_statement->member.print;
                    print_ast(child[0], NT_PRINT, cur_level+1);
                break;

                case SCAN_STATEMENT:
                    child[0].c_scan = root.c_statement->member.scan;
                    print_ast(child[0], NT_SCAN, cur_level+1);
                break;

                case EXPRESSION_STATEMENT:
                    child[0].c_expression = root.c_statement->member.expression;
                    print_ast(child[0], NT_EXPRESSION, cur_level+1);
                break;

                case CONDITION_STATEMENT:
                    child[0].c_condition = root.c_statement->member.condition;
                    print_ast(child[0], NT_CONDITION, cur_level+1);
                break;

                case ITERATION_STATEMENT:
                    child[0].c_iteration = root.c_statement->member.iteration;
                    print_ast(child[0], NT_ITERATION, cur_level+1);
                break;

                case RETURN_STATEMENT:
                    child[0].c_return = root.c_statement->member._return;
                    print_ast(child[0], NT_RETURN, cur_level+1);
                break;

            }
        break;

        case NT_PRINT:
            spaces(cur_level);
            printf("Print\n");
            child[0].c_print_type = root.c_print->type;
            print_ast(child[0], NT_PRINT_TYPE, cur_level+1);
            child[1].c_expression = root.c_print->expression;
            print_ast(child[1], NT_EXPRESSION, cur_level+1);
        break;

        case NT_SCAN:
            spaces(cur_level);
            printf("Scan\n");
            child[0].c_scan_type = root.c_scan->type;
            print_ast(child[0], NT_SCAN_TYPE, cur_level+1);
            child[1].string_val = root.c_scan->destiny;
            print_ast(child[1], NT_IDENTIFIER, cur_level+1);
        break;

        case NT_RETURN:
            spaces(cur_level);
            printf("Return\n");
            if (root.c_return->expression) {
                child[0].c_expression = root.c_return->expression;
                print_ast(child[0], NT_EXPRESSION, cur_level+1);
            }
        break;

        case NT_EXPRESSION:
            if (root.c_expression == NULL) return;

            spaces(cur_level);
            printf("Expression\n");

            child[0].c_assignment = root.c_expression->assignment;
            print_ast(child[0], NT_ASSIGNMENT, cur_level+1);
        break;

        case NT_CONDITION:
            spaces(cur_level);
            printf("Condition\n");
            child[0].c_expression = root.c_condition->condition;
            print_ast(child[0], NT_EXPRESSION, cur_level+1);
            child[1].c_statement = root.c_condition->body;
            print_ast(child[1], NT_STATEMENT, cur_level+1);
            if (root.c_condition->else_body) {
                child[2].c_statement = root.c_condition->else_body;
                print_ast(child[2], NT_STATEMENT, cur_level+1);
            }
        break;

        case NT_ITERATION:
            spaces(cur_level);
            printf("Iteration\n");
            if (root.c_iteration->type == WHILE_ITERATION) {
                child[0].c_while = root.c_iteration->member._while;
                print_ast(child[0], NT_WHILE, cur_level+1);
            } else if (root.c_iteration->type == FOR_ITERATION) {
                child[0].c_for = root.c_iteration->member._for;
                print_ast(child[0], NT_FOR, cur_level+1);
            }
        break;

        case NT_WHILE:
            spaces(cur_level);
            printf("While\n");
            child[0].c_expression = root.c_while->condition;
            print_ast(child[0], NT_EXPRESSION, cur_level+1);
            child[1].c_statement = root.c_while->body;
            print_ast(child[1], NT_STATEMENT, cur_level+1);
        break;

        case NT_FOR:
            spaces(cur_level);
            printf("For\n");
            if (root.c_for->initialization) {
                child[0].c_expression = root.c_for->initialization;
                print_ast(child[0], NT_EXPRESSION, cur_level+1);
            }
            if (root.c_for->condition) {
                child[1].c_expression = root.c_for->condition;
                print_ast(child[1], NT_EXPRESSION, cur_level+1);
            }
            if (root.c_for->step) {
                child[2].c_expression = root.c_for->step;
                print_ast(child[2], NT_EXPRESSION, cur_level+1);
            }
            child[3].c_statement = root.c_for->body;
            print_ast(child[3], NT_STATEMENT, cur_level+1);
        break;

        case NT_ASSIGNMENT:
            spaces(cur_level);
            printf("Assignment\n");

            if (root.c_assignment->identifier) {
                child[0].string_val = root.c_assignment->identifier;
                print_ast(child[0], NT_IDENTIFIER, cur_level+1);
                child[1].c_assignment_operator = root.c_assignment->operator;
                print_ast(child[1], NT_ASSIGNMENT_OPERATOR, cur_level+1);
            }
            child[2].c_and_expression = root.c_assignment->and_expression;
            print_ast(child[2], NT_AND_EXPRESSION, cur_level+1);
        break;

        case NT_AND_EXPRESSION:
            spaces(cur_level);
            printf("And Expression\n");

            if (root.c_and_expression->left) {
                child[0].c_and_expression = root.c_and_expression->left;
                print_ast(child[0], NT_AND_EXPRESSION, cur_level+1);
                spaces(cur_level+1);
                printf("&&\n");
            }
            child[1].c_or_expression = root.c_and_expression->right;
            print_ast(child[1], NT_OR_EXPRESSION, cur_level+1);
        break;

        case NT_OR_EXPRESSION:
            spaces(cur_level);
            printf("Or Expression\n");

            if (root.c_or_expression->left) {
                child[0].c_or_expression = root.c_or_expression->left;
                print_ast(child[0], NT_OR_EXPRESSION, cur_level+1);
                spaces(cur_level+1);
                printf("||\n");
            }
            child[1].c_bw_and_expression = root.c_or_expression->right;
            print_ast(child[1], NT_BW_AND_EXPRESSION, cur_level+1);
        break;

        case NT_BW_AND_EXPRESSION:
            spaces(cur_level);
            printf("Bitwise And Expression\n");

            if (root.c_bw_and_expression->left) {
                child[0].c_bw_and_expression = root.c_bw_and_expression->left;
                print_ast(child[0], NT_BW_AND_EXPRESSION, cur_level+1);
                spaces(cur_level+1);
                printf("&\n");
            }
            child[1].c_bw_or_expression = root.c_bw_and_expression->right;
            print_ast(child[1], NT_BW_OR_EXPRESSION, cur_level+1);
        break;

        case NT_BW_OR_EXPRESSION:
            spaces(cur_level);
            printf("Bitwise Or Expression\n");

            if (root.c_bw_or_expression->left) {
                child[0].c_bw_or_expression = root.c_bw_or_expression->left;
                print_ast(child[0], NT_BW_OR_EXPRESSION, cur_level+1);
                spaces(cur_level+1);
                printf("&\n");
            }
            child[1].c_bw_xor_expression = root.c_bw_or_expression->right;
            print_ast(child[1], NT_BW_XOR_EXPRESSION, cur_level+1);
        break;

        case NT_BW_XOR_EXPRESSION:
            spaces(cur_level);
            printf("Bitwise Xor Expression\n");

            if (root.c_bw_xor_expression->left) {
                child[0].c_bw_xor_expression = root.c_bw_xor_expression->left;
                print_ast(child[0], NT_BW_XOR_EXPRESSION, cur_level+1);
                spaces(cur_level+1);
                printf("&\n");
            }
            child[1].c_eq_expression = root.c_bw_xor_expression->right;
            print_ast(child[1], NT_EQ_EXPRESSION, cur_level+1);
        break;

        case NT_EQ_EXPRESSION:
            spaces(cur_level);
            printf("Eq Expression\n");

            if (root.c_eq_expression->left) {
                child[0].c_eq_expression = root.c_eq_expression->left;
                print_ast(child[0], NT_EQ_EXPRESSION, cur_level+1);

                spaces(cur_level+1);
                if (root.c_eq_expression->type == EQ_EQ_EXPRESSION) {
                    printf("==\n");
                } else {
                    printf("!=\n");
                }
            }
            child[1].c_rel_expression = root.c_eq_expression->right;
            print_ast(child[1], NT_REL_EXPRESSION, cur_level+1);
        break;

        case NT_REL_EXPRESSION:
            spaces(cur_level);
            printf("Rel Expression\n");

            if (root.c_rel_expression->left) {
                child[0].c_rel_expression = root.c_rel_expression->left;
                print_ast(child[0], NT_REL_EXPRESSION, cur_level+1);

                child[0].c_rel_expression_type = root.c_rel_expression->type;
                print_ast(child[0], NT_REL_EXPRESSION_TYPE, cur_level+1);
            }
            child[1].c_shift_expression = root.c_rel_expression->right;
            print_ast(child[1], NT_SHIFT_EXPRESSION, cur_level+1);
        break;

        case NT_SHIFT_EXPRESSION:
            spaces(cur_level);
            printf("Shift Expression\n");

            if (root.c_shift_expression->left) {
                child[0].c_shift_expression = root.c_shift_expression->left;
                print_ast(child[0], NT_SHIFT_EXPRESSION, cur_level+1);

                spaces(cur_level+1);
                if (root.c_shift_expression->type == LEFT_SHIFT_EXPRESSION) {
                    printf("<<\n");
                } else {
                    printf(">>\n");
                }    
            }
            child[1].c_set_rm_expression = root.c_shift_expression->right;
            print_ast(child[1], NT_SET_RM_EXPRESSION, cur_level+1);
        break;

        case NT_SET_RM_EXPRESSION:
            spaces(cur_level);
            printf("Set Rm Expression\n");

            if (root.c_set_rm_expression->left) {
                child[0].c_set_rm_expression = root.c_set_rm_expression->left;
                print_ast(child[0], NT_SET_RM_EXPRESSION, cur_level+1);
                spaces(cur_level+1);
                printf("rm\n");
            }
            child[1].c_add_expression = root.c_set_rm_expression->right;
            print_ast(child[1], NT_ADD_EXPRESSION, cur_level+1);
        break;

        case NT_ADD_EXPRESSION:
            spaces(cur_level);
            printf("Add Expression\n");

            if (root.c_add_expression->left) {
                child[0].c_add_expression = root.c_add_expression->left;
                print_ast(child[0], NT_ADD_EXPRESSION, cur_level+1);

                spaces(cur_level+1);
                if (root.c_add_expression->type == ADD_PLUS) {
                    printf("+\n");
                } else {
                    printf("-\n");
                }    
            }
            child[1].c_mult_expression = root.c_add_expression->right;
            print_ast(child[1], NT_MULT_EXPRESSION, cur_level+1);
        break;

        case NT_MULT_EXPRESSION:
            spaces(cur_level);
            printf("Mult Expression\n");

            if (root.c_mult_expression->left) {
                child[0].c_mult_expression = root.c_mult_expression->left;
                print_ast(child[0], NT_MULT_EXPRESSION, cur_level+1);

                child[1].c_mult_operator = root.c_mult_expression->type;
                print_ast(child[1], NT_MULT_OPERATOR, cur_level+1);
            }
            child[2].c_cast_expression = root.c_mult_expression->right;
            print_ast(child[2], NT_CAST_EXPRESSION, cur_level+1);
        break;

        case NT_CAST_EXPRESSION:
            spaces(cur_level);
            printf("Cast Expression\n");

            if (root.c_cast_expression->left) {
                child[0].c_cast_expression = root.c_cast_expression->left;
                print_ast(child[0], NT_CAST_EXPRESSION, cur_level+1);

                child[1].c_primitive_type = root.c_cast_expression->type;
                print_ast(child[1], NT_PRIMITIVE_TYPE, cur_level+1);
            }
            child[2].c_unary_expression = root.c_cast_expression->right;
            print_ast(child[2], NT_UNARY_EXPRESSION, cur_level+1);
        break;

        case NT_UNARY_EXPRESSION:
            spaces(cur_level);
            printf("Unary Expression\n");

            if (root.c_unary_expression->left) {
                child[0].c_unary_expression = root.c_unary_expression->left;
                print_ast(child[0], NT_UNARY_EXPRESSION, cur_level+1);

                child[1].c_unary_expression_type = root.c_unary_expression->type;
                print_ast(child[1], NT_UNARY_EXPRESSION_TYPE, cur_level+1);
            }
            child[2].c_postfix_expression = root.c_unary_expression->right;
            print_ast(child[2], NT_POSTFIX_EXPRESSION, cur_level+1);
        break;

        case NT_POSTFIX_EXPRESSION:
            spaces(cur_level);
            printf("Postfix Expression\n");

            if (root.c_postfix_expression->left) {
                child[0].c_postfix_expression = root.c_postfix_expression->left;
                print_ast(child[0], NT_POSTFIX_EXPRESSION, cur_level+1);
                
                spaces(cur_level+1);
                if (root.c_postfix_expression->type == ARRAY_ACCESS) {
                    child[1].c_expression = root.c_postfix_expression->member.array_index;
                    print_ast(child[1], NT_EXPRESSION, cur_level+1);
                } else {
                    child[1].c_param_vals = root.c_postfix_expression->member.function_params;
                    print_ast(child[1], NT_PARAM_VALS, cur_level+1);
                }    
            }
            child[2].c_primary_expression = root.c_postfix_expression->primary;
            print_ast(child[2], NT_PRIMARY_EXPRESSION, cur_level+1);
        break;

        case NT_PRIMARY_EXPRESSION:
            spaces(cur_level);
            printf("Primary expression\n");

            switch(root.c_primary_expression->type) {
                case IDENTIFIER_PRIMARY_EXPRESSION:
                child[0].string_val = root.c_primary_expression->member.identifier;
                print_ast(child[0], NT_IDENTIFIER, cur_level+1);
                break;
                case CONSTANT_PRIMARY_EXPRESSION:
                child[0].c_constant = root.c_primary_expression->member.constant;
                print_ast(child[0], NT_CONSTANT, cur_level+1);
                break;
                case STRING_PRIMARY_EXPRESSION:
                child[0].string_val = root.c_primary_expression->member.string;
                print_ast(child[0], NT_STRING, cur_level+1);
                break;
                case NESTED_PRIMARY_EXPRESSION:
                child[0].c_expression = root.c_primary_expression->member.expression;
                print_ast(child[0], NT_EXPRESSION, cur_level+1);
                break;
            }
        break;

        case NT_CONSTANT:
            spaces(cur_level);
            printf("Constant\n");

            switch(root.c_constant->type) {
                case INTEGER_CONSTANT:
                    spaces(cur_level+1);
                    printf("Integer %lld\n", (long long)root.c_constant->member.integer_val);
                break;

                case CHAR_CONSTANT:
                    spaces(cur_level+1);
                    printf("Char %c\n", root.c_constant->member.char_val);
                break;

                case REAL_CONSTANT:
                    spaces(cur_level+1);
                    printf("Real %lf\n", root.c_constant->member.float_val);
                break;
            }
        break;

        case NT_PARAM_VALS:
            if (root.c_param_vals == NULL) return;

            if (root.c_param_vals->prev) {
                child[0].c_param_vals = root.c_param_vals->prev;
                print_ast(child[0], NT_PARAM_VALS, cur_level);
            } else {
                // print only at beginning of declaration list
                spaces(cur_level);
                printf("Parameter Values\n");
            }

            if (root.c_param_vals->cur) {
                child[1].c_expression = root.c_param_vals->cur;
                print_ast(child[1], NT_EXPRESSION, cur_level+1);
            }
        break;

        case NT_STRING:
            spaces(cur_level);
            printf("String %s\n", root.string_val);
        break;

        case NT_IDENTIFIER:
            spaces(cur_level);
            printf("Identifier %s\n", root.string_val);
        break;

        default:
            printf("SHOULD NOT HAPPEN!\n");
            exit(1);

    }
}

void free_ast(node root, node_type type) {
    node child[10];
    memset(child, 0, sizeof child);

    switch(type) {
         case NT_PROGRAM:
            child[0].c_declaration_list = root.c_program->declarations;
            free_ast(child[0], NT_DECLARATION_LIST);
            free(root.c_program);
        break;

        case NT_DECLARATION_LIST:
            if (root.c_declaration_list->cur) {
                child[1].c_declaration = root.c_declaration_list->cur;
                free_ast(child[1], NT_DECLARATION);
            }

            if (root.c_declaration_list->prev) {
                child[0].c_declaration_list = root.c_declaration_list->prev;
                free_ast(child[0], NT_DECLARATION_LIST);
            }

            free(root.c_declaration_list);
        break;

        case NT_DECLARATION:
            if (root.c_declaration->type == VAR_DECLARATION) {
                child[0].c_variable = root.c_declaration->member.variable;
                free_ast(child[0], NT_VARIABLE);
            } else if (root.c_declaration->type == FUN_DECLARATION) {
                child[0].c_function = root.c_declaration->member.function;
                free_ast(child[0], NT_FUNCTION);
            }

            free(root.c_declaration);
        break;

        case NT_VARIABLE:
            child[1].string_val = root.c_variable->identifier;
            free_ast(child[1], NT_IDENTIFIER);

            free(root.c_variable);
        break;

        case NT_FUNCTION:
            child[1].string_val = root.c_function->identifier;
            free_ast(child[1], NT_IDENTIFIER);   

            child[2].c_function_params = root.c_function->params;
            free_ast(child[2], NT_FUNCTION_PARAMS);

            child[3].c_scope = root.c_function->body;
            free_ast(child[3], NT_SCOPE);
            
            free(root.c_function);
        break;

        case NT_FUNCTION_PARAM:
            child[1].string_val = root.c_function_param->identifier;
            free_ast(child[1], NT_IDENTIFIER); 

            free(root.c_function_param);
        break;

        case NT_FUNCTION_PARAMS:
            if (root.c_function_params == NULL) return;

            if (root.c_function_params->cur) {
                child[1].c_function_param = root.c_function_params->cur;
                free_ast(child[1], NT_FUNCTION_PARAM);
            }
            
            if (root.c_function_params->prev) {
                child[0].c_function_params = root.c_function_params->prev;
                free_ast(child[0], NT_FUNCTION_PARAMS);
            }
            
            free(root.c_function_params);
        break;

        case NT_SCOPE:
            child[0].c_statement_list = root.c_scope->statements;
            free_ast(child[0], NT_STATEMENT_LIST);

            free(root.c_scope);
        break;

        case NT_STATEMENT_LIST:
            if (root.c_statement_list == NULL) return;

            if (root.c_statement_list->cur) {
                child[1].c_statement = root.c_statement_list->cur;
                free_ast(child[1], NT_STATEMENT);
            }
            
            if (root.c_statement_list->prev) {
                child[0].c_statement_list = root.c_statement_list->prev;
                free_ast(child[0], NT_STATEMENT_LIST);
            }

            free(root.c_statement_list);
        break;

        case NT_STATEMENT:
            switch (root.c_statement->type) {
                case SCOPE_STATEMENT:
                    child[0].c_scope = root.c_statement->member.scope;
                    free_ast(child[0], NT_SCOPE);
                break;

                case DECLARATION_STATEMENT:
                    child[0].c_declaration = root.c_statement->member.declaration;
                    free_ast(child[0], NT_DECLARATION);
                break;

                case PRINT_STATEMENT:
                    child[0].c_print = root.c_statement->member.print;
                    free_ast(child[0], NT_PRINT);
                break;

                case SCAN_STATEMENT:
                    child[0].c_scan = root.c_statement->member.scan;
                    free_ast(child[0], NT_SCAN);
                break;

                case EXPRESSION_STATEMENT:
                    child[0].c_expression = root.c_statement->member.expression;
                    free_ast(child[0], NT_EXPRESSION);
                break;

                case CONDITION_STATEMENT:
                    child[0].c_condition = root.c_statement->member.condition;
                    free_ast(child[0], NT_CONDITION);
                break;

                case ITERATION_STATEMENT:
                    child[0].c_iteration = root.c_statement->member.iteration;
                    free_ast(child[0], NT_ITERATION);
                break;

                case RETURN_STATEMENT:
                    child[0].c_return = root.c_statement->member._return;
                    free_ast(child[0], NT_RETURN);
                break;
            }

            free(root.c_statement);
        break;

        case NT_PRINT:
            child[1].c_expression = root.c_print->expression;
            free_ast(child[1], NT_EXPRESSION);

            free(root.c_print);
        break;

        case NT_SCAN:
            child[1].string_val = root.c_scan->destiny;
            free_ast(child[1], NT_IDENTIFIER);

            free(root.c_scan);
        break;

        case NT_RETURN:
            if (root.c_return->expression) {
                child[0].c_expression = root.c_return->expression;
                free_ast(child[0], NT_EXPRESSION);
            }

            free(root.c_return);
        break;

        case NT_EXPRESSION:
            if (root.c_expression == NULL) return;

            child[0].c_assignment = root.c_expression->assignment;
            free_ast(child[0], NT_ASSIGNMENT);

            free(root.c_expression);
        break;

        case NT_CONDITION:
            child[0].c_expression = root.c_condition->condition;
            free_ast(child[0], NT_EXPRESSION);

            child[1].c_statement = root.c_condition->body;
            free_ast(child[1], NT_STATEMENT);

            if (root.c_condition->else_body) {
                child[2].c_statement = root.c_condition->else_body;
                free_ast(child[2], NT_STATEMENT);
            }

            free(root.c_condition);
        break;

        case NT_ITERATION:
            if (root.c_iteration->type == WHILE_ITERATION) {
                child[0].c_while = root.c_iteration->member._while;
                free_ast(child[0], NT_WHILE);
            } else if (root.c_iteration->type == FOR_ITERATION) {
                child[0].c_for = root.c_iteration->member._for;
                free_ast(child[0], NT_FOR);
            }

            free(root.c_iteration);
        break;

        case NT_WHILE:
            child[0].c_expression = root.c_while->condition;
            free_ast(child[0], NT_EXPRESSION);
            child[1].c_statement = root.c_while->body;
            free_ast(child[1], NT_STATEMENT);

            free(root.c_while);
        break;

        case NT_FOR:
            if (root.c_for->initialization) {
                child[0].c_expression = root.c_for->initialization;
                free_ast(child[0], NT_EXPRESSION);
            }
            if (root.c_for->condition) {
                child[1].c_expression = root.c_for->condition;
                free_ast(child[1], NT_EXPRESSION);
            }
            if (root.c_for->step) {
                child[2].c_expression = root.c_for->step;
                free_ast(child[2], NT_EXPRESSION);
            }
            child[3].c_statement = root.c_for->body;
            free_ast(child[3], NT_STATEMENT);

            free(root.c_for);
        break;

        case NT_ASSIGNMENT:
            if (root.c_assignment->identifier) {
                child[0].string_val = root.c_assignment->identifier;
                free_ast(child[0], NT_IDENTIFIER);
            }

            child[2].c_and_expression = root.c_assignment->and_expression;
            free_ast(child[2], NT_AND_EXPRESSION);

            free(root.c_assignment);
        break;

        case NT_AND_EXPRESSION:
            if (root.c_and_expression->left) {
                child[0].c_and_expression = root.c_and_expression->left;
                free_ast(child[0], NT_AND_EXPRESSION);
            }
            child[1].c_or_expression = root.c_and_expression->right;
            free_ast(child[1], NT_OR_EXPRESSION);

            free(root.c_and_expression);
        break;

        case NT_OR_EXPRESSION:

            if (root.c_or_expression->left) {
                child[0].c_or_expression = root.c_or_expression->left;
                free_ast(child[0], NT_OR_EXPRESSION);
            }
            child[1].c_bw_and_expression = root.c_or_expression->right;
            free_ast(child[1], NT_BW_AND_EXPRESSION);
            
            free(root.c_or_expression);
        break;

        case NT_BW_AND_EXPRESSION:

            if (root.c_bw_and_expression->left) {
                child[0].c_bw_and_expression = root.c_bw_and_expression->left;
                free_ast(child[0], NT_BW_AND_EXPRESSION);
            }
            child[1].c_bw_or_expression = root.c_bw_and_expression->right;
            free_ast(child[1], NT_BW_OR_EXPRESSION);
            
            free(root.c_bw_and_expression);
        break;

        case NT_BW_OR_EXPRESSION:

            if (root.c_bw_or_expression->left) {
                child[0].c_bw_or_expression = root.c_bw_or_expression->left;
                free_ast(child[0], NT_BW_OR_EXPRESSION);
            }
            child[1].c_bw_xor_expression = root.c_bw_or_expression->right;
            free_ast(child[1], NT_BW_XOR_EXPRESSION);
            
            free(root.c_bw_or_expression);
        break;

        case NT_BW_XOR_EXPRESSION:

            if (root.c_bw_xor_expression->left) {
                child[0].c_bw_xor_expression = root.c_bw_xor_expression->left;
                free_ast(child[0], NT_BW_XOR_EXPRESSION);
            }
            child[1].c_eq_expression = root.c_bw_xor_expression->right;
            free_ast(child[1], NT_EQ_EXPRESSION);
            
            free(root.c_bw_xor_expression);
        break;

        case NT_EQ_EXPRESSION:

            if (root.c_eq_expression->left) {
                child[0].c_eq_expression = root.c_eq_expression->left;
                free_ast(child[0], NT_EQ_EXPRESSION);
            }
            child[1].c_rel_expression = root.c_eq_expression->right;
            free_ast(child[1], NT_REL_EXPRESSION);
            
            free(root.c_eq_expression);
        break;

        case NT_REL_EXPRESSION:

            if (root.c_rel_expression->left) {
                child[0].c_rel_expression = root.c_rel_expression->left;
                free_ast(child[0], NT_REL_EXPRESSION);
            }
            child[1].c_shift_expression = root.c_rel_expression->right;
            free_ast(child[1], NT_SHIFT_EXPRESSION);
            
            free(root.c_rel_expression);
        break;

        case NT_SHIFT_EXPRESSION:

            if (root.c_shift_expression->left) {
                child[0].c_shift_expression = root.c_shift_expression->left;
                free_ast(child[0], NT_SHIFT_EXPRESSION);
            }
            child[1].c_set_rm_expression = root.c_shift_expression->right;
            free_ast(child[1], NT_SET_RM_EXPRESSION);
            
            free(root.c_shift_expression);
        break;

        case NT_SET_RM_EXPRESSION:

            if (root.c_set_rm_expression->left) {
                child[0].c_set_rm_expression = root.c_set_rm_expression->left;
                free_ast(child[0], NT_SET_RM_EXPRESSION);
            }
            child[1].c_add_expression = root.c_set_rm_expression->right;
            free_ast(child[1], NT_ADD_EXPRESSION);
            
            free(root.c_set_rm_expression);
        break;

        case NT_ADD_EXPRESSION:

            if (root.c_add_expression->left) {
                child[0].c_add_expression = root.c_add_expression->left;
                free_ast(child[0], NT_ADD_EXPRESSION);
            }
            child[1].c_mult_expression = root.c_add_expression->right;
            free_ast(child[1], NT_MULT_EXPRESSION);
            
            free(root.c_add_expression);
        break;

        case NT_MULT_EXPRESSION:

            if (root.c_mult_expression->left) {
                child[0].c_mult_expression = root.c_mult_expression->left;
                free_ast(child[0], NT_MULT_EXPRESSION);
            }
            child[2].c_cast_expression = root.c_mult_expression->right;
            free_ast(child[2], NT_CAST_EXPRESSION);
            
            free(root.c_mult_expression);
        break;

        case NT_CAST_EXPRESSION:

            if (root.c_cast_expression->left) {
                child[0].c_cast_expression = root.c_cast_expression->left;
                free_ast(child[0], NT_CAST_EXPRESSION);
            }
            child[2].c_unary_expression = root.c_cast_expression->right;
            free_ast(child[2], NT_UNARY_EXPRESSION);
            
            free(root.c_cast_expression);
        break;

        case NT_UNARY_EXPRESSION:

            if (root.c_unary_expression->left) {
                child[0].c_unary_expression = root.c_unary_expression->left;
                free_ast(child[0], NT_UNARY_EXPRESSION);
            }
            child[2].c_postfix_expression = root.c_unary_expression->right;
            free_ast(child[2], NT_POSTFIX_EXPRESSION);
            
            free(root.c_unary_expression);
        break;

        case NT_POSTFIX_EXPRESSION:

            if (root.c_postfix_expression->left) {
                child[0].c_postfix_expression = root.c_postfix_expression->left;
                free_ast(child[0], NT_POSTFIX_EXPRESSION);
                
                if (root.c_postfix_expression->type == ARRAY_ACCESS) {
                    child[1].c_expression = root.c_postfix_expression->member.array_index;
                    free_ast(child[1], NT_EXPRESSION);
                } else {
                    child[1].c_param_vals = root.c_postfix_expression->member.function_params;
                    free_ast(child[1], NT_PARAM_VALS);
                }
            }
            child[2].c_primary_expression = root.c_postfix_expression->primary;
            free_ast(child[2], NT_PRIMARY_EXPRESSION);
            
            free(root.c_postfix_expression);
        break;

        case NT_PRIMARY_EXPRESSION:

            switch(root.c_primary_expression->type) {
                case IDENTIFIER_PRIMARY_EXPRESSION:
                child[0].string_val = root.c_primary_expression->member.identifier;
                free_ast(child[0], NT_IDENTIFIER);
                break;
                case CONSTANT_PRIMARY_EXPRESSION:
                child[0].c_constant = root.c_primary_expression->member.constant;
                free_ast(child[0], NT_CONSTANT);
                break;
                case STRING_PRIMARY_EXPRESSION:
                child[0].string_val = root.c_primary_expression->member.string;
                free_ast(child[0], NT_STRING);
                break;
                case NESTED_PRIMARY_EXPRESSION:
                child[0].c_expression = root.c_primary_expression->member.expression;
                free_ast(child[0], NT_EXPRESSION);
                break;
            }
            
            free(root.c_primary_expression);
        break;

        case NT_CONSTANT:
            free(root.c_constant);
        break;

        case NT_PARAM_VALS:
            if (root.c_param_vals == NULL) return;

            if (root.c_param_vals->cur) {
                child[1].c_expression = root.c_param_vals->cur;
                free_ast(child[1], NT_EXPRESSION);
            }

            if (root.c_param_vals->prev) {
                child[0].c_param_vals = root.c_param_vals->prev;
                free_ast(child[0], NT_PARAM_VALS);
            }
            
            free(root.c_param_vals);
        break;

        case NT_STRING:
            free(root.string_val);
        break;

        case NT_IDENTIFIER:
            free(root.string_val);
        break;

        default:
            printf("SHOULD NOT HAPPEN!\n");
            exit(1);

    }
}

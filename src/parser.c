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
#include <stdio.h>
#include <string.h>

#define zero_allocate(type) ((type*)calloc(1, sizeof(type)))

extern FILE* yyin;
extern int yylex();
extern uint32_t line;
extern uint32_t column;

void yyerror(const char *str) {    
    size_t sz = strlen(str) + 256;
    char* msg = malloc(sz);

    sprintf(msg, "%d:%d: %s\n", line, column, str);
}


#line 90 "src/parser.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
#line 45 "src/parser.y" /* yacc.c:355  */

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
    uint64_t integer_val;
    double float_val;
    char char_val;

#line 258 "src/parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 275 "src/parser.c" /* yacc.c:358  */

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
#define YYLAST   269

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

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
       0,   152,   152,   161,   167,   173,   179,   188,   195,   202,
     209,   219,   231,   237,   243,   250,   257,   264,   274,   282,
     288,   294,   300,   306,   312,   318,   324,   330,   336,   345,
     354,   363,   366,   369,   375,   378,   381,   387,   394,   404,
     410,   419,   428,   439,   447,   450,   456,   464,   471,   479,
     485,   493,   499,   507,   513,   521,   527,   535,   541,   549,
     556,   563,   571,   578,   586,   593,   600,   608,   614,   622,
     629,   636,   644,   651,   659,   665,   673,   679,   685,   693,
     700,   707,   715,   721,   726,   732,   738,   744,   750,   759,
     765,   771,   780,   781,   782,   783,   784,   785,   789,   790,
     791,   795,   796,   797,   798,   799,   803,   804,   805,   809,
     812,   815,   818,   821,   824,   827,   830,   833
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,    27,   127,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,    32,    17,    29,    -2,
    -111,  -111,    37,    52,    46,    -3,  -111,    53,  -111,    84,
     127,  -111,  -111,  -111,  -111,    96,    94,    49,   165,  -111,
    -111,  -111,  -111,  -111,    -1,  -111,  -111,  -111,    73,  -111,
    -111,  -111,  -111,  -111,  -111,    92,    97,   100,    81,  -111,
    -111,  -111,  -111,  -111,    81,   114,  -111,  -111,  -111,  -111,
    -111,    85,  -111,    86,    89,    95,    93,    98,    45,    -7,
      15,    90,    34,   -19,  -111,  -111,    54,  -111,  -111,    73,
     126,   125,    13,  -111,  -111,  -111,  -111,  -111,  -111,   224,
     122,   124,  -111,    81,  -111,    81,    81,    81,   119,  -111,
     121,   132,  -111,   224,   224,   224,   224,   224,   224,   224,
    -111,  -111,  -111,  -111,  -111,   224,   224,   224,   224,   224,
     224,  -111,  -111,  -111,   224,    81,    81,  -111,    20,  -111,
     147,  -111,    86,  -111,   224,   150,   156,   134,  -111,  -111,
    -111,    89,    95,    93,    98,    45,    -7,    -7,    15,    90,
      90,    34,   -19,   -19,  -111,   176,  -111,     4,  -111,  -111,
     159,   159,    81,  -111,  -111,    81,   128,  -111,   152,  -111,
     159,    81,  -111,   177,   159,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     3,     5,     6,     0,     0,     0,     0,
      13,     7,     0,     0,     0,     0,    10,     0,     9,     0,
       0,     8,    20,    11,    12,     0,     0,    14,    85,    87,
      89,    90,    91,    18,     0,   100,    98,    99,     0,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    45,    22,
      21,    19,    23,    24,     0,     0,    26,    27,    39,    40,
      28,     0,    46,    48,    50,    52,    54,    56,    58,    61,
      63,    66,    68,    71,    73,    75,    78,    81,    86,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,     0,
       0,     0,    85,     0,    77,     0,     0,    45,     0,    44,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,   106,   107,   108,     0,     0,    84,    76,     0,    17,
       0,    16,    47,    88,     0,     0,     0,     0,    43,    29,
      30,    49,    51,    53,    55,    57,    59,    60,    62,    64,
      65,    67,    69,    70,    72,     0,    83,     0,    15,    74,
       0,     0,    45,    79,    80,     0,    37,    41,     0,    82,
       0,    45,    38,     0,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,   191,  -111,  -111,  -111,   166,  -111,
    -102,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -106,   -44,  -111,   101,    83,    80,    87,   105,    82,   -23,
      76,   -18,    75,   -14,  -110,   -33,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,    11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    59,    15,    25,    34,    60,    36,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     108,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,   167,    87,    88,
      99,    89,   125,   134,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     100,   147,    38,    39,    23,    40,    41,    42,   120,   121,
      24,    29,    44,    16,   109,   104,   122,   123,   174,   140,
     110,   131,   132,   133,   164,   141,    18,     3,    19,    18,
      20,    19,    45,    30,   169,    17,   124,    46,    47,    22,
     175,    35,   126,   127,    48,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    21,   101,   137,    21,    91,   100,
      92,   145,   146,   109,    27,   135,   178,   136,   176,   177,
     118,   119,   129,   130,    26,   183,   102,    39,   182,    40,
      41,    42,   185,    28,    38,    39,   103,    40,    41,    42,
      31,   165,   166,    32,    44,   156,   157,    38,    39,    37,
      40,    41,    42,    32,    43,   105,    45,    44,   159,   160,
     106,    46,    47,   107,    45,   162,   163,   111,    48,    46,
      47,   113,   112,   114,   116,   115,    48,    45,   109,   138,
     117,   179,    46,    47,   128,   139,   143,   109,   144,    48,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    49,
      50,    51,    52,    53,    54,    55,   148,    56,   149,   168,
      57,    58,    38,    39,   170,    40,    41,    42,    32,   150,
     171,   172,    44,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    93,    94,    95,    96,    97,    98,   173,   181,
     180,   184,    45,    14,   152,    33,   151,    46,    47,   155,
     142,   158,   153,   161,    48,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    49,    50,    51,    52,    53,    54,
      55,   154,    56,     0,     0,    57,    58,   102,    39,     0,
      40,    41,    42,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,    46,    47,     0,     0,     0,     0,     0,    48
};

static const yytype_int16 yycheck[] =
{
      44,   107,     3,     4,     6,     6,     7,     8,    15,    16,
      12,    14,    13,     2,    58,    48,    23,    24,    14,     6,
      64,    40,    41,    42,   134,    12,     9,     0,    11,     9,
      13,    11,    33,    36,   144,     3,    43,    38,    39,    10,
      36,    30,    27,    28,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    37,    44,    89,    37,     9,   103,
      11,   105,   106,   107,    12,    11,   172,    13,   170,   171,
      25,    26,    38,    39,    37,   181,     3,     4,   180,     6,
       7,     8,   184,    37,     3,     4,    13,     6,     7,     8,
      37,   135,   136,     9,    13,   118,   119,     3,     4,     3,
       6,     7,     8,     9,    10,    13,    33,    13,   126,   127,
      13,    38,    39,    13,    33,   129,   130,     3,    45,    38,
      39,    35,    37,    34,    31,    30,    45,    33,   172,     3,
      32,   175,    38,    39,    44,    10,    14,   181,    14,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    37,    63,    37,    12,
      66,    67,     3,     4,    14,     6,     7,     8,     9,    37,
      14,    37,    13,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    17,    18,    19,    20,    21,    22,    12,    37,
      62,    14,    33,     2,   114,    29,   113,    38,    39,   117,
      99,   125,   115,   128,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   116,    63,    -1,    -1,    66,    67,     3,     4,    -1,
       6,     7,     8,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,    73,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    74,    75,    76,   115,     3,     9,    11,
      13,    37,    10,     6,    12,    77,    37,    12,    37,    14,
      36,    37,     9,    79,    78,   115,    80,     3,     3,     4,
       6,     7,     8,    10,    13,    33,    38,    39,    45,    55,
      56,    57,    58,    59,    60,    61,    63,    66,    67,    75,
      79,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   109,   110,   112,
     115,     9,    11,    17,    18,    19,    20,    21,    22,   111,
      92,   115,     3,    13,   106,    13,    13,    13,    91,    92,
      92,     3,    37,    35,    34,    30,    31,    32,    25,    26,
      15,    16,    23,    24,    43,   113,    27,    28,    44,    38,
      39,    40,    41,    42,   114,    11,    13,   106,     3,    10,
       6,    12,    94,    14,    14,    92,    92,    91,    37,    37,
      37,    95,    96,    97,    98,    99,   100,   100,   101,   102,
     102,   103,   104,   104,   105,    92,    92,   108,    12,   105,
      14,    14,    37,    12,    14,    36,    81,    81,    91,    92,
      62,    37,    81,    91,    14,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      75,    76,    77,    77,    78,    78,    78,    78,    79,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      83,    84,    84,    84,    85,    85,    85,    86,    86,    87,
      87,    88,    89,    90,    91,    91,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    99,
      99,    99,   100,   100,   101,   101,   101,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   106,   106,   106,   107,
     107,   107,   108,   108,   108,   109,   109,   109,   109,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   113,   113,   113,   113,   113,   114,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     3,     6,     5,
       5,     6,     3,     0,     2,     5,     4,     4,     3,     2,
       0,     1,     1,     1,     1,     2,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     5,     7,     1,
       1,     5,     9,     3,     1,     0,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     4,     1,     2,     2,     1,     4,
       4,     1,     3,     1,     0,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 152 "src/parser.y" /* yacc.c:1646  */
    {
        printf("OK!\n");
        t_program* program = zero_allocate(t_program);
        program->declarations = (yyvsp[0].c_declaration_list);
        (yyval.c_program) = program;
    }
#line 1528 "src/parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 161 "src/parser.y" /* yacc.c:1646  */
    {
        t_declaration_list* declaration_list = zero_allocate(t_declaration_list);
        declaration_list->prev = (yyvsp[-1].c_declaration_list);
        declaration_list->cur = (yyvsp[0].c_declaration);
        (yyval.c_declaration_list) = declaration_list;
    }
#line 1539 "src/parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 167 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_declaration_list) = NULL;
    }
#line 1547 "src/parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 173 "src/parser.y" /* yacc.c:1646  */
    {
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = VAR_DECLARATION;
        dec->member.variable = (yyvsp[0].c_variable);
        (yyval.c_declaration) = dec;
    }
#line 1558 "src/parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 179 "src/parser.y" /* yacc.c:1646  */
    {
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = FUN_DECLARATION;
        dec->member.function = (yyvsp[0].c_function);   
        (yyval.c_declaration) = dec;  
    }
#line 1569 "src/parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 188 "src/parser.y" /* yacc.c:1646  */
    {
        t_variable* var = zero_allocate(t_variable);
        var->type = (yyvsp[-2].c_primitive_type);
        var->structure = PRIMITIVE_TYPE;
        var->identifier = (yyvsp[-1].string_val);
        (yyval.c_variable) = var;
    }
#line 1581 "src/parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 195 "src/parser.y" /* yacc.c:1646  */
    {
        t_variable* var = zero_allocate(t_variable);
        var->type = (yyvsp[-5].c_primitive_type);
        var->structure = ARRAY_TYPE;
        var->identifier = (yyvsp[-4].string_val);
        (yyval.c_variable) = var;
    }
#line 1593 "src/parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 202 "src/parser.y" /* yacc.c:1646  */
    {
        t_variable* var = zero_allocate(t_variable);
        var->type = (yyvsp[-4].c_primitive_type);
        var->structure = ARRAY_TYPE;
        var->identifier = (yyvsp[-3].string_val);
        (yyval.c_variable) = var;
    }
#line 1605 "src/parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 209 "src/parser.y" /* yacc.c:1646  */
    {
        t_variable* var = zero_allocate(t_variable);
        var->type = (yyvsp[-4].c_primitive_type);
        var->structure = SET_TYPE;
        var->identifier = (yyvsp[-3].string_val);
        (yyval.c_variable) = var;
    }
#line 1617 "src/parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 219 "src/parser.y" /* yacc.c:1646  */
    {
        t_function* fun = zero_allocate(t_function);
        fun->return_type = (yyvsp[-5].c_primitive_type);
        fun->return_structure = PRIMITIVE_TYPE;
        fun->identifier = (yyvsp[-4].string_val);
        fun->params = (yyvsp[-2].c_function_params);
        fun->body = (yyvsp[0].c_scope);
        (yyval.c_function) = fun;
    }
#line 1631 "src/parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 231 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_params* fp = zero_allocate(t_function_params);
        fp->cur = (yyvsp[0].c_function_param);
        fp->prev = (yyvsp[-2].c_function_params);
        (yyval.c_function_params) = fp; 
    }
#line 1642 "src/parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 237 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_function_params) = NULL;
    }
#line 1650 "src/parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 243 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = (yyvsp[-1].c_primitive_type);
        var->structure = PRIMITIVE_TYPE;
        var->identifier = (yyvsp[0].string_val);
        (yyval.c_function_param) = var;
    }
#line 1662 "src/parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 250 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = (yyvsp[-4].c_primitive_type);
        var->structure = ARRAY_TYPE;
        var->identifier = (yyvsp[-3].string_val);
        (yyval.c_function_param) = var;
    }
#line 1674 "src/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 257 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = (yyvsp[-3].c_primitive_type);
        var->structure = ARRAY_TYPE;
        var->identifier = (yyvsp[-2].string_val);
        (yyval.c_function_param) = var;
    }
#line 1686 "src/parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 264 "src/parser.y" /* yacc.c:1646  */
    {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = (yyvsp[-3].c_primitive_type);
        var->structure = SET_TYPE;
        var->identifier = (yyvsp[-2].string_val);
        (yyval.c_function_param) = var;
    }
#line 1698 "src/parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 274 "src/parser.y" /* yacc.c:1646  */
    {
        t_scope* scope = zero_allocate(t_scope);
        scope->statements = (yyvsp[-1].c_statement_list);
        (yyval.c_scope) = scope;
    }
#line 1708 "src/parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 282 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement_list* fp = zero_allocate(t_statement_list);
        fp->cur = (yyvsp[0].c_statement);
        fp->prev = (yyvsp[-1].c_statement_list);
        (yyval.c_statement_list) = fp; 
    }
#line 1719 "src/parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 288 "src/parser.y" /* yacc.c:1646  */
    {
    (yyval.c_statement_list) = NULL;
}
#line 1727 "src/parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 294 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = SCOPE_STATEMENT;
        stmt->member.scope = (yyvsp[0].c_scope);
        (yyval.c_statement) = stmt;
    }
#line 1738 "src/parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 300 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = VAR_DECLARATION_STATEMENT;
        stmt->member.variable = (yyvsp[0].c_variable);
        (yyval.c_statement) = stmt;
    }
#line 1749 "src/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 306 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = PRINT_STATEMENT;
        stmt->member.print = (yyvsp[0].c_print);
        (yyval.c_statement) = stmt;
    }
#line 1760 "src/parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 312 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = SCAN_STATEMENT;
        stmt->member.scan = (yyvsp[0].c_scan);
        (yyval.c_statement) = stmt;
    }
#line 1771 "src/parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 318 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = EXPRESSION_STATEMENT;
        stmt->member.expression = (yyvsp[-1].c_expression);
        (yyval.c_statement) = stmt;
    }
#line 1782 "src/parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 324 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = CONDITION_STATEMENT;
        stmt->member.condition = (yyvsp[0].c_condition);
        (yyval.c_statement) = stmt;
    }
#line 1793 "src/parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 330 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = ITERATION_STATEMENT;
        stmt->member.iteration = (yyvsp[0].c_iteration);
        (yyval.c_statement) = stmt;
    }
#line 1804 "src/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 336 "src/parser.y" /* yacc.c:1646  */
    {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = RETURN_STATEMENT;
        stmt->member._return = (yyvsp[0].c_return);
        (yyval.c_statement) = stmt;
    }
#line 1815 "src/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 345 "src/parser.y" /* yacc.c:1646  */
    {
        t_print* print = zero_allocate(t_print);
        print->type = (yyvsp[-2].c_print_type);
        print->expression = (yyvsp[-1].c_expression);
        (yyval.c_print) = print;
    }
#line 1826 "src/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 354 "src/parser.y" /* yacc.c:1646  */
    {
        t_scan* scan = zero_allocate(t_scan);
        scan->type = (yyvsp[-2].c_scan_type);
        scan->destiny = (yyvsp[-1].string_val);
        (yyval.c_scan) = scan;
    }
#line 1837 "src/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 363 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_print_type) = PRINT_DEC_TYPE;
    }
#line 1845 "src/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 366 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_print_type) = PRINT_CHAR_TYPE;
    }
#line 1853 "src/parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 369 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_print_type) = PRINT_HEX_TYPE;
    }
#line 1861 "src/parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 375 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_scan_type) = SCAN_DEC_TYPE;
    }
#line 1869 "src/parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 378 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_scan_type) = SCAN_CHAR_TYPE;
    }
#line 1877 "src/parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 381 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_scan_type) = SCAN_FLOAT_TYPE;
    }
#line 1885 "src/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 387 "src/parser.y" /* yacc.c:1646  */
    {
        t_condition* cond = zero_allocate(t_condition);
        cond->condition = (yyvsp[-2].c_expression);
        cond->body = (yyvsp[0].c_statement);
        cond->else_body = NULL;  
        (yyval.c_condition) = cond;  
    }
#line 1897 "src/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 394 "src/parser.y" /* yacc.c:1646  */
    {   
        t_condition* cond = zero_allocate(t_condition);
        cond->condition = (yyvsp[-4].c_expression);
        cond->body = (yyvsp[-2].c_statement);
        cond->else_body = (yyvsp[0].c_statement);
        (yyval.c_condition) = cond;
    }
#line 1909 "src/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 404 "src/parser.y" /* yacc.c:1646  */
    {
        t_iteration* it = zero_allocate(t_iteration);
        it->type = WHILE_ITERATION;
        it->member._while = (yyvsp[0].c_while);
        (yyval.c_iteration) = it;
    }
#line 1920 "src/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 410 "src/parser.y" /* yacc.c:1646  */
    {
        t_iteration* it = zero_allocate(t_iteration);
        it->type = FOR_ITERATION;
        it->member._for = (yyvsp[0].c_for);
        (yyval.c_iteration) = it;
    }
#line 1931 "src/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 419 "src/parser.y" /* yacc.c:1646  */
    {
        t_while* w = zero_allocate(t_while);
        w->condition = (yyvsp[-2].c_expression);
        w->body = (yyvsp[0].c_statement);
        (yyval.c_while) = w;
    }
#line 1942 "src/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 428 "src/parser.y" /* yacc.c:1646  */
    {
        t_for* f = zero_allocate(t_for);
        f->initialization = (yyvsp[-6].c_expression);
        f->condition = (yyvsp[-4].c_expression);
        f->step = (yyvsp[-2].c_expression);
        f->body = (yyvsp[0].c_statement);
        (yyval.c_for) = f;
    }
#line 1955 "src/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 439 "src/parser.y" /* yacc.c:1646  */
    {
        t_return* ret = zero_allocate(t_return);
        ret->expression = (yyvsp[-1].c_expression);
        (yyval.c_return) = ret;
    }
#line 1965 "src/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 447 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_expression) = (yyvsp[0].c_expression);
    }
#line 1973 "src/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 450 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_expression) = NULL;
    }
#line 1981 "src/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 456 "src/parser.y" /* yacc.c:1646  */
    {
        t_expression* exp = zero_allocate(t_expression);
        exp->assignment = (yyvsp[0].c_assignment);
        (yyval.c_expression) = exp;
    }
#line 1991 "src/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 464 "src/parser.y" /* yacc.c:1646  */
    {
        t_assignment* exp = zero_allocate(t_assignment);
        exp->identifier = (yyvsp[-2].string_val);
        exp->operator = (yyvsp[-1].c_assignment_operator);
        exp->and_expression = (yyvsp[0].c_and_expression);
        (yyval.c_assignment) = exp;
    }
#line 2003 "src/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 471 "src/parser.y" /* yacc.c:1646  */
    {
        t_assignment* exp = zero_allocate(t_assignment);
        exp->and_expression = (yyvsp[0].c_and_expression);
        (yyval.c_assignment) = exp;
    }
#line 2013 "src/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 479 "src/parser.y" /* yacc.c:1646  */
    {
        t_and_expression* exp = zero_allocate(t_and_expression);
        exp->left = (yyvsp[-2].c_and_expression);
        exp->right = (yyvsp[0].c_or_expression);
        (yyval.c_and_expression) = exp;
    }
#line 2024 "src/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 485 "src/parser.y" /* yacc.c:1646  */
    {
        t_and_expression* exp = zero_allocate(t_and_expression);
        exp->right = (yyvsp[0].c_or_expression);
        (yyval.c_and_expression) = exp;
    }
#line 2034 "src/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 493 "src/parser.y" /* yacc.c:1646  */
    {
        t_or_expression* exp = zero_allocate(t_or_expression);
        exp->left = (yyvsp[-2].c_or_expression);
        exp->right = (yyvsp[0].c_bw_and_expression);
        (yyval.c_or_expression) = exp;
    }
#line 2045 "src/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 499 "src/parser.y" /* yacc.c:1646  */
    {
        t_or_expression* exp = zero_allocate(t_or_expression);
        exp->right = (yyvsp[0].c_bw_and_expression);
        (yyval.c_or_expression) = exp;
    }
#line 2055 "src/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 507 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_and_expression* exp = zero_allocate(t_bw_and_expression);
        exp->left = (yyvsp[-2].c_bw_and_expression);
        exp->right = (yyvsp[0].c_bw_or_expression);
        (yyval.c_bw_and_expression) = exp;
    }
#line 2066 "src/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 513 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_and_expression* exp = zero_allocate(t_bw_and_expression);
        exp->right = (yyvsp[0].c_bw_or_expression);
        (yyval.c_bw_and_expression) = exp;
    }
#line 2076 "src/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 521 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_or_expression* exp = zero_allocate(t_bw_or_expression);
        exp->left = (yyvsp[-2].c_bw_or_expression);
        exp->right = (yyvsp[0].c_bw_xor_expression);
        (yyval.c_bw_or_expression) = exp;
    }
#line 2087 "src/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 527 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_or_expression* exp = zero_allocate(t_bw_or_expression);
        exp->right = (yyvsp[0].c_bw_xor_expression);
        (yyval.c_bw_or_expression) = exp;
    }
#line 2097 "src/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 535 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_xor_expression* exp = zero_allocate(t_bw_xor_expression);
        exp->left = (yyvsp[-2].c_bw_xor_expression);
        exp->right = (yyvsp[0].c_eq_expression);
        (yyval.c_bw_xor_expression) = exp;
    }
#line 2108 "src/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 541 "src/parser.y" /* yacc.c:1646  */
    {
        t_bw_xor_expression* exp = zero_allocate(t_bw_xor_expression);
        exp->right = (yyvsp[0].c_eq_expression);
        (yyval.c_bw_xor_expression) = exp;
    }
#line 2118 "src/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 549 "src/parser.y" /* yacc.c:1646  */
    {
        t_eq_expression* exp = zero_allocate(t_eq_expression);
        exp->type = EQ_EQ_EXPRESSION;
        exp->left = (yyvsp[-2].c_eq_expression);
        exp->right = (yyvsp[0].c_rel_expression);
        (yyval.c_eq_expression) = exp;
    }
#line 2130 "src/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 556 "src/parser.y" /* yacc.c:1646  */
    {
        t_eq_expression* exp = zero_allocate(t_eq_expression);
        exp->type = NOT_EQ_EXPRESSION;
        exp->left = (yyvsp[-2].c_eq_expression);
        exp->right = (yyvsp[0].c_rel_expression);
        (yyval.c_eq_expression) = exp;
    }
#line 2142 "src/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 563 "src/parser.y" /* yacc.c:1646  */
    {
        t_eq_expression* exp = zero_allocate(t_eq_expression);
        exp->right = (yyvsp[0].c_rel_expression);
        (yyval.c_eq_expression) = exp;
    }
#line 2152 "src/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 571 "src/parser.y" /* yacc.c:1646  */
    {
        t_rel_expression* exp = zero_allocate(t_rel_expression);
        exp->left = (yyvsp[-2].c_rel_expression);
        exp->type = (yyvsp[-1].c_rel_expression_type);
        exp->right = (yyvsp[0].c_shift_expression);
        (yyval.c_rel_expression) = exp;
    }
#line 2164 "src/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 578 "src/parser.y" /* yacc.c:1646  */
    {
        t_rel_expression* exp = zero_allocate(t_rel_expression);
        exp->right = (yyvsp[0].c_shift_expression);
        (yyval.c_rel_expression) = exp;
    }
#line 2174 "src/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 586 "src/parser.y" /* yacc.c:1646  */
    {
        t_shift_expression* exp = zero_allocate(t_shift_expression);
        exp->left = (yyvsp[-2].c_shift_expression);
        exp->type = LEFT_SHIFT_EXPRESSION;
        exp->right = (yyvsp[0].c_set_rm_expression);
        (yyval.c_shift_expression) = exp;
    }
#line 2186 "src/parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 593 "src/parser.y" /* yacc.c:1646  */
    {
        t_shift_expression* exp = zero_allocate(t_shift_expression);
        exp->left = (yyvsp[-2].c_shift_expression);
        exp->type = RIGHT_SHIFT_EXPRESSION;
        exp->right = (yyvsp[0].c_set_rm_expression);
        (yyval.c_shift_expression) = exp;
    }
#line 2198 "src/parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 600 "src/parser.y" /* yacc.c:1646  */
    {
        t_shift_expression* exp = zero_allocate(t_shift_expression);
        exp->right = (yyvsp[0].c_set_rm_expression);
        (yyval.c_shift_expression) = exp;
    }
#line 2208 "src/parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 608 "src/parser.y" /* yacc.c:1646  */
    {
        t_set_rm_expression* exp = zero_allocate(t_set_rm_expression);
        exp->left = (yyvsp[-2].c_set_rm_expression);
        exp->right = (yyvsp[0].c_add_expression);
        (yyval.c_set_rm_expression) = exp;
    }
#line 2219 "src/parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 614 "src/parser.y" /* yacc.c:1646  */
    {
        t_set_rm_expression* exp = zero_allocate(t_set_rm_expression);
        exp->right = (yyvsp[0].c_add_expression);
        (yyval.c_set_rm_expression) = exp;
    }
#line 2229 "src/parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 622 "src/parser.y" /* yacc.c:1646  */
    {
        t_add_expression* exp = zero_allocate(t_add_expression);
        exp->left = (yyvsp[-2].c_add_expression);
        exp->type = ADD_PLUS;
        exp->right = (yyvsp[0].c_mult_expression);
        (yyval.c_add_expression) = exp;
    }
#line 2241 "src/parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 629 "src/parser.y" /* yacc.c:1646  */
    {
        t_add_expression* exp = zero_allocate(t_add_expression);
        exp->left = (yyvsp[-2].c_add_expression);
        exp->type = ADD_MINUS;
        exp->right = (yyvsp[0].c_mult_expression);
        (yyval.c_add_expression) = exp;
    }
#line 2253 "src/parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 636 "src/parser.y" /* yacc.c:1646  */
    {
        t_add_expression* exp = zero_allocate(t_add_expression);
        exp->right = (yyvsp[0].c_mult_expression);
        (yyval.c_add_expression) = exp;
    }
#line 2263 "src/parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 644 "src/parser.y" /* yacc.c:1646  */
    {
        t_mult_expression* exp = zero_allocate(t_mult_expression);
        exp->left = (yyvsp[-2].c_mult_expression);
        exp->type = (yyvsp[-1].c_mult_operator);
        exp->right = (yyvsp[0].c_cast_expression);
        (yyval.c_mult_expression) = exp;
    }
#line 2275 "src/parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 651 "src/parser.y" /* yacc.c:1646  */
    {
        t_mult_expression* exp = zero_allocate(t_mult_expression);
        exp->right = (yyvsp[0].c_cast_expression);
        (yyval.c_mult_expression) = exp;
    }
#line 2285 "src/parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 659 "src/parser.y" /* yacc.c:1646  */
    {
        t_cast_expression* exp = zero_allocate(t_cast_expression);
        exp->type = (yyvsp[-2].c_primitive_type);
        exp->left = (yyvsp[0].c_cast_expression);
        (yyval.c_cast_expression) = exp;
    }
#line 2296 "src/parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 665 "src/parser.y" /* yacc.c:1646  */
    {
        t_cast_expression* exp = zero_allocate(t_cast_expression);
        exp->right = (yyvsp[0].c_unary_expression);
        (yyval.c_cast_expression) = exp;
    }
#line 2306 "src/parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 673 "src/parser.y" /* yacc.c:1646  */
    {
        t_unary_expression* exp = zero_allocate(t_unary_expression);
        exp->type = (yyvsp[-1].c_unary_expression_type);
        exp->left = (yyvsp[0].c_unary_expression);
        (yyval.c_unary_expression) = exp;
    }
#line 2317 "src/parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 679 "src/parser.y" /* yacc.c:1646  */
    {
        t_unary_expression* exp = zero_allocate(t_unary_expression);
        exp->type = UNARY_SIZEOF;
        exp->left = (yyvsp[0].c_unary_expression);
        (yyval.c_unary_expression) = exp;
    }
#line 2328 "src/parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 685 "src/parser.y" /* yacc.c:1646  */
    {
        t_unary_expression* exp = zero_allocate(t_unary_expression);
        exp->right = (yyvsp[0].c_postfix_expression);
        (yyval.c_unary_expression) = exp;
    }
#line 2338 "src/parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 693 "src/parser.y" /* yacc.c:1646  */
    {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = ARRAY_ACCESS;
        exp->left = (yyvsp[-3].c_postfix_expression);
        exp->member.array_index = (yyvsp[-1].c_expression);
        (yyval.c_postfix_expression) = exp;
    }
#line 2350 "src/parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 700 "src/parser.y" /* yacc.c:1646  */
    {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = FUNCTION_CALL;
        exp->left = (yyvsp[-3].c_postfix_expression);
        exp->member.function_params = (yyvsp[-1].c_param_vals);
        (yyval.c_postfix_expression) = exp;
    }
#line 2362 "src/parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 707 "src/parser.y" /* yacc.c:1646  */
    {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->primary = (yyvsp[0].c_primary_expression);
        (yyval.c_postfix_expression) = exp;
    }
#line 2372 "src/parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 715 "src/parser.y" /* yacc.c:1646  */
    {
        t_param_vals* pv = zero_allocate(t_param_vals);
        pv->prev = (yyvsp[-2].c_param_vals);
        pv->cur = (yyvsp[0].c_expression);
        (yyval.c_param_vals) = pv;
    }
#line 2383 "src/parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 721 "src/parser.y" /* yacc.c:1646  */
    {
        t_param_vals* pv = zero_allocate(t_param_vals);
        pv->cur = (yyvsp[0].c_expression);
        (yyval.c_param_vals) = pv;
    }
#line 2393 "src/parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 726 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_param_vals) = NULL;
    }
#line 2401 "src/parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 732 "src/parser.y" /* yacc.c:1646  */
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = IDENTIFIER_PRIMARY_EXPRESSION;
        exp->member.identifier = (yyvsp[0].string_val);
        (yyval.c_primary_expression) = exp;
    }
#line 2412 "src/parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 738 "src/parser.y" /* yacc.c:1646  */
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = CONSTANT_PRIMARY_EXPRESSION;
        exp->member.constant = (yyvsp[0].c_constant);
        (yyval.c_primary_expression) = exp;
    }
#line 2423 "src/parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 744 "src/parser.y" /* yacc.c:1646  */
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = STRING_PRIMARY_EXPRESSION;
        exp->member.string = (yyvsp[0].string_val);
        (yyval.c_primary_expression) = exp;
    }
#line 2434 "src/parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 750 "src/parser.y" /* yacc.c:1646  */
    {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = NESTED_PRIMARY_EXPRESSION;
        exp->member.expression = (yyvsp[-1].c_expression);
        (yyval.c_primary_expression) = exp;
    }
#line 2445 "src/parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 759 "src/parser.y" /* yacc.c:1646  */
    {
        t_constant* c = zero_allocate(t_constant);
        c->type = INTEGER_CONSTANT;
        c->member.integer_val = (yyvsp[0].integer_val);
        (yyval.c_constant) = c;
    }
#line 2456 "src/parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 765 "src/parser.y" /* yacc.c:1646  */
    {
        t_constant* c = zero_allocate(t_constant);
        c->type = CHAR_CONSTANT;
        c->member.char_val = (yyvsp[0].char_val);
        (yyval.c_constant) = c;
    }
#line 2467 "src/parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 771 "src/parser.y" /* yacc.c:1646  */
    {
        t_constant* c = zero_allocate(t_constant);
        c->type = REAL_CONSTANT;
        c->member.float_val = (yyvsp[0].float_val);
        (yyval.c_constant) = c;
    }
#line 2478 "src/parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 780 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = EQUAL_OPERATOR; }
#line 2484 "src/parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 781 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = PLUS_EQUAL_OPERATOR; }
#line 2490 "src/parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 782 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = MINUS_EQUAL_OPERATOR; }
#line 2496 "src/parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 783 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = ASTERISK_EQUAL_OPERATOR; }
#line 2502 "src/parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 784 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = SLASH_EQUAL_OPERATOR; }
#line 2508 "src/parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 785 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_assignment_operator) = PERCENT_EQUAL_OPERATOR; }
#line 2514 "src/parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 789 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_unary_expression_type) = UNARY_PLUS; }
#line 2520 "src/parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 790 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_unary_expression_type) = UNARY_MINUS; }
#line 2526 "src/parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 791 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_unary_expression_type) + UNARY_EXCL; }
#line 2532 "src/parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 795 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = LESS_THAN; }
#line 2538 "src/parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 796 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = GREATER_THAN; }
#line 2544 "src/parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 797 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = LESS_THAN_OR_EQUAL; }
#line 2550 "src/parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 798 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = GREATER_THAN_OR_EQUAL; }
#line 2556 "src/parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 799 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_rel_expression_type) = IS_IN; }
#line 2562 "src/parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 803 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_mult_operator) = ASTERISK_OPERATOR; }
#line 2568 "src/parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 804 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_mult_operator) = SLASH_OPERATOR; }
#line 2574 "src/parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 805 "src/parser.y" /* yacc.c:1646  */
    { (yyval.c_mult_operator) = PERCENT_OPERATOR; }
#line 2580 "src/parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 809 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = VOID_TYPE;
    }
#line 2588 "src/parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 812 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = BYTE_TYPE;
    }
#line 2596 "src/parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 815 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = BYTE_TYPE;
    }
#line 2604 "src/parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 818 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = BYTE_TYPE;
    }
#line 2612 "src/parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 821 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = SHORT_TYPE;
    }
#line 2620 "src/parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 824 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = INT_TYPE;
    }
#line 2628 "src/parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 827 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = LONG_TYPE;
    }
#line 2636 "src/parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 830 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = FLOAT_TYPE;
    }
#line 2644 "src/parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 833 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.c_primitive_type) = DOUBLE_TYPE;
    }
#line 2652 "src/parser.c" /* yacc.c:1646  */
    break;


#line 2656 "src/parser.c" /* yacc.c:1646  */
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
#line 837 "src/parser.y" /* yacc.c:1906  */


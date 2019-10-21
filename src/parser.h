/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    LEFT_BRACE = 258,
    RIGHT_BRACE = 259,
    LEFT_BRACKET = 260,
    RIGHT_BRACKET = 261,
    LEFT_PAREN = 262,
    RIGHT_PAREN = 263,
    LEFT_ANGLE = 264,
    RIGHT_ANGLE = 265,
    EQUAL = 266,
    PLUS_EQUAL = 267,
    MINUS_EQUAL = 268,
    ASTERISK_EQUAL = 269,
    SLASH_EQUAL = 270,
    PERCENT_EQUAL = 271,
    LANGLE_EQUAL = 272,
    RANGLE_EQUAL = 273,
    EQUAL_EQUAL = 274,
    EXCL_EQUAL = 275,
    DOUBLE_LANGLE = 276,
    DOUBLE_RANGLE = 277,
    TILDE = 278,
    AND = 279,
    BAR = 280,
    CARET = 281,
    EXCL = 282,
    BAR_BAR = 283,
    AND_AND = 284,
    COMMA = 285,
    SEMICOLON = 286,
    PLUS = 287,
    MINUS = 288,
    ASTERISK = 289,
    SLASH = 290,
    PERCENT = 291,
    IN_RW = 292,
    RM_RW = 293,
    SIZEOF_RW = 294,
    VOID_RW = 295,
    BOOL_RW = 296,
    BYTE_RW = 297,
    CHAR_RW = 298,
    SHORT_RW = 299,
    INT_RW = 300,
    LONG_RW = 301,
    FLOAT_RW = 302,
    DOUBLE_RW = 303,
    PRINT_RW = 304,
    PRINTC_RW = 305,
    PRINTX_RW = 306,
    SCAN_RW = 307,
    SCANC_RW = 308,
    SCANF_RW = 309,
    IF_RW = 310,
    ELSE_RW = 311,
    WHILE_RW = 312,
    TRUE_RW = 313,
    FALSE_RW = 314,
    FOR_RW = 315,
    RETURN_RW = 316,
    UNDERSCORE = 317,
    STRING = 318,
    NEWLINE = 319,
    DIGIT = 320,
    LETTER = 321,
    CHAR = 322,
    INTEGER = 323,
    REAL = 324,
    IDENTIFIER = 325,
    REDUCE = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "src/parser.y" /* yacc.c:1909  */

    t_program* c_program;
    // t_declaration_list* c_declaration_list;

#line 131 "src/parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */

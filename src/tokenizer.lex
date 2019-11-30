/* Scanner for Afth */

%{

#include "token_types.h"
#include "my_string.h"
#include "lexical_error_handler.h"
#include "abstract_syntax_tree.h"
#include <stdio.h>

int fileno(FILE *stream);
uint32_t line = 1;
uint32_t column = 0;
%}

%option nounput
%option noinput

LEFT_BRACE      "{"
RIGHT_BRACE     "}"
LEFT_BRACKET    "["
RIGHT_BRACKET   "]"
LEFT_PAREN      "("
RIGHT_PAREN     ")"
LEFT_ANGLE      "<"
RIGHT_ANGLE     ">"

EQUAL           "="
PLUS_EQUAL      "+="
MINUS_EQUAL     "-="
ASTERISK_EQUAL  "*="
SLASH_EQUAL     "/="
PERCENT_EQUAL   "%="
LANGLE_EQUAL    "<="
RANGLE_EQUAL    ">="
EQUAL_EQUAL     "=="
EXCL_EQUAL      "!="
DOUBLE_LANGLE   "<<"
DOUBLE_RANGLE   ">>"

TILDE           "~"
AND             "&"
BAR             "|"
CARET           "^"
EXCL            "!"
BAR_BAR         "||"
AND_AND         "&&"
COMMA           ","
SEMICOLON       ";"
PLUS            "+"
MINUS           "-"
ASTERISK        "*"
SLASH           "/"
PERCENT         "%"

IN_RW           "in"
RM_RW           "rm"
SIZEOF_RW       "sizeof"
VOID_RW         "void"
BOOL_RW         "bool"
BYTE_RW         "byte"
CHAR_RW         "char"
SHORT_RW        "short"
INT_RW          "int"
LONG_RW         "long"
FLOAT_RW        "float"
DOUBLE_RW       "double"
PRINT_RW        "print"
PRINTC_RW       "printc"
PRINTX_RW       "printf"
SCAN_RW         "scan"
SCANC_RW        "scanc"
SCANF_RW        "scanf"
IF_RW           "if"
ELSE_RW         "else"
WHILE_RW        "while"
TRUE_RW         "true"
FALSE_RW        "false"
FOR_RW          "for"
RETURN_RW       "return"

UNDERSCORE      "_"
NEWLINE         \n
WHITESPACE      [\t ]+
DIGIT           [0-9]
STRING          \"[^"\\]*(\\.[^"\\]*)*\"
LETTER          [a-zA-Z]
CHAR            \'.\'
INTEGER         {DIGIT}+
REAL            {DIGIT}+"."{DIGIT}+
IDENTIFIER      {LETTER}({DIGIT}|{LETTER}|{UNDERSCORE})*

%x COMMENT
%x LINE_COMMENT

%%

"/*"                { column += yyleng; BEGIN(COMMENT); }
<COMMENT>"*/"       { column += yyleng; BEGIN(INITIAL); }
<COMMENT>{NEWLINE}  { column = 0; line++; }
<COMMENT>.          { column += yyleng; }

"//"                { column += yyleng; BEGIN(LINE_COMMENT); }
<LINE_COMMENT>{NEWLINE}  { column = 1; line++; BEGIN(INITIAL); }
<LINE_COMMENT>.          { column += yyleng; }

{LEFT_BRACE}        { column += yyleng; return LEFT_BRACE; }
{RIGHT_BRACE}       { column += yyleng; return RIGHT_BRACE; }
{LEFT_BRACKET}      { column += yyleng; return LEFT_BRACKET; }
{RIGHT_BRACKET}     { column += yyleng; return RIGHT_BRACKET; }
{LEFT_PAREN}        { column += yyleng; return LEFT_PAREN; }
{RIGHT_PAREN}       { column += yyleng; return RIGHT_PAREN; }
{LEFT_ANGLE}        { column += yyleng; return LEFT_ANGLE; }
{RIGHT_ANGLE}       { column += yyleng; return RIGHT_ANGLE; }

{EQUAL}             { column += yyleng; return EQUAL; }
{PLUS_EQUAL}        { column += yyleng; return PLUS_EQUAL; }
{MINUS_EQUAL}       { column += yyleng; return MINUS_EQUAL; }
{ASTERISK_EQUAL}    { column += yyleng; return ASTERISK_EQUAL; }
{SLASH_EQUAL}       { column += yyleng; return SLASH_EQUAL; }
{PERCENT_EQUAL}     { column += yyleng; return PERCENT_EQUAL; }
{LANGLE_EQUAL}      { column += yyleng; return LANGLE_EQUAL; }
{RANGLE_EQUAL}      { column += yyleng; return RANGLE_EQUAL; }
{EQUAL_EQUAL}       { column += yyleng; return EQUAL_EQUAL; }
{EXCL_EQUAL}        { column += yyleng; return EXCL_EQUAL; }
{DOUBLE_LANGLE}     { column += yyleng; return DOUBLE_LANGLE; }
{DOUBLE_RANGLE}     { column += yyleng; return DOUBLE_RANGLE; }

{TILDE}             { column += yyleng; return TILDE; }
{AND}               { column += yyleng; return AND; }
{BAR}               { column += yyleng; return BAR; }
{CARET}             { column += yyleng; return CARET; }
{EXCL}              { column += yyleng; return EXCL; }
{BAR_BAR}           { column += yyleng; return BAR_BAR; }
{AND_AND}           { column += yyleng; return AND_AND; }
{COMMA}             { column += yyleng; return COMMA; }
{SEMICOLON}         { column += yyleng; return SEMICOLON; }
{PLUS}              { column += yyleng; return PLUS; }
{MINUS}             { column += yyleng; return MINUS; }
{ASTERISK}          { column += yyleng; return ASTERISK; }
{SLASH}             { column += yyleng; return SLASH; }
{PERCENT}           { column += yyleng; return PERCENT; }

{IN_RW}             { column += yyleng; return IN_RW; }
{RM_RW}             { column += yyleng; return RM_RW; }
{SIZEOF_RW}         { column += yyleng; return SIZEOF_RW; }
{VOID_RW}           { column += yyleng; return VOID_RW; }
{BOOL_RW}           { column += yyleng; return BOOL_RW; }
{BYTE_RW}           { column += yyleng; return BYTE_RW; }
{CHAR_RW}           { column += yyleng; return CHAR_RW; }
{SHORT_RW}          { column += yyleng; return SHORT_RW; }
{INT_RW}            { column += yyleng; return INT_RW; }
{LONG_RW}           { column += yyleng; return LONG_RW; }
{FLOAT_RW}          { column += yyleng; return FLOAT_RW; }
{DOUBLE_RW}         { column += yyleng; return DOUBLE_RW; }
{PRINT_RW}          { column += yyleng; return PRINT_RW; }
{PRINTC_RW}         { column += yyleng; return PRINTC_RW; }
{PRINTX_RW}         { column += yyleng; return PRINTX_RW; }
{SCAN_RW}           { column += yyleng; return SCAN_RW; }
{SCANC_RW}          { column += yyleng; return SCANC_RW; }
{SCANF_RW}          { column += yyleng; return SCANF_RW; }
{IF_RW}             { column += yyleng; return IF_RW; }
{ELSE_RW}           { column += yyleng; return ELSE_RW; }
{WHILE_RW}          { column += yyleng; return WHILE_RW; }
{FOR_RW}            { column += yyleng; return FOR_RW; }
{RETURN_RW}         { column += yyleng; return RETURN_RW; }

{INTEGER}           { column += yyleng; yylval.integer_val = atoi(yytext); return INTEGER; }
{REAL}              { column += yyleng; yylval.float_val = atof(yytext); return REAL; }
{IDENTIFIER}        { column += yyleng; yylval.string_val = duplicate(yytext); return IDENTIFIER; }
{STRING}            { column += yyleng; yylval.string_val = duplicate(yytext); return STRING; }
{CHAR}              { column += yyleng; yylval.char_val = *yytext; return CHAR; }
{WHITESPACE}        { column += yyleng; BEGIN(INITIAL); }
{NEWLINE}           { column = 0; line++; BEGIN(INITIAL); }
.                   { column += yyleng; add_error(*yytext, line, column); }

%%

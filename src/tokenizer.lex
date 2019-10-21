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

{LEFT_BRACE}        { return LEFT_BRACE; }
{RIGHT_BRACE}       { return RIGHT_BRACE; }
{LEFT_BRACKET}      { return LEFT_BRACKET; }
{RIGHT_BRACKET}     { return RIGHT_BRACKET; }
{LEFT_PAREN}        { return LEFT_PAREN; }
{RIGHT_PAREN}       { return RIGHT_PAREN; }
{LEFT_ANGLE}        { return LEFT_ANGLE; }
{RIGHT_ANGLE}       { return RIGHT_ANGLE; }

{EQUAL}             { return EQUAL; }
{PLUS_EQUAL}        { return PLUS_EQUAL; }
{MINUS_EQUAL}       { return MINUS_EQUAL; }
{ASTERISK_EQUAL}    { return ASTERISK_EQUAL; }
{SLASH_EQUAL}       { return SLASH_EQUAL; }
{PERCENT_EQUAL}     { return PERCENT_EQUAL; }
{LANGLE_EQUAL}      { return LANGLE_EQUAL; }
{RANGLE_EQUAL}      { return RANGLE_EQUAL; }
{EQUAL_EQUAL}       { return EQUAL_EQUAL; }
{EXCL_EQUAL}        { return EXCL_EQUAL; }
{DOUBLE_LANGLE}     { return DOUBLE_LANGLE; }
{DOUBLE_RANGLE}     { return DOUBLE_RANGLE; }

{TILDE}             { return TILDE; }
{AND}               { return AND; }
{BAR}               { return BAR; }
{CARET}             { return CARET; }
{EXCL}              { return EXCL; }
{BAR_BAR}           { return BAR_BAR; }
{AND_AND}           { return AND_AND; }
{COMMA}             { return COMMA; }
{SEMICOLON}         { return SEMICOLON; }
{PLUS}              { return PLUS; }
{MINUS}             { return MINUS; }
{ASTERISK}          { return ASTERISK; }
{SLASH}             { return SLASH; }
{PERCENT}           { return PERCENT; }

{IN_RW}             { return IN_RW; }
{RM_RW}             { return RM_RW; }
{SIZEOF_RW}         { return SIZEOF_RW; }
{VOID_RW}           { return VOID_RW; }
{BOOL_RW}           { return BOOL_RW; }
{BYTE_RW}           { return BYTE_RW; }
{CHAR_RW}           { return CHAR_RW; }
{SHORT_RW}          { return SHORT_RW; }
{INT_RW}            { return INT_RW; }
{LONG_RW}           { return LONG_RW; }
{FLOAT_RW}          { return FLOAT_RW; }
{DOUBLE_RW}         { return DOUBLE_RW; }
{PRINT_RW}          { return PRINT_RW; }
{PRINTC_RW}         { return PRINTC_RW; }
{PRINTX_RW}         { return PRINTX_RW; }
{SCAN_RW}           { return SCAN_RW; }
{SCANC_RW}          { return SCANC_RW; }
{SCANF_RW}          { return SCANF_RW; }
{IF_RW}             { return IF_RW; }
{ELSE_RW}           { return ELSE_RW; }
{WHILE_RW}          { return WHILE_RW; }
{FOR_RW}            { return FOR_RW; }
{RETURN_RW}         { return RETURN_RW; }

{INTEGER}           { yylval.integer_val = atoi(yytext); return INTEGER; }
{REAL}              { yylval.float_val = atof(yytext); return REAL; }
{IDENTIFIER}        { yylval.string_val = duplicate(yytext); return IDENTIFIER; }
{STRING}            { yylval.string_val = duplicate(yytext); return STRING; }
{CHAR}              { yylval.char_val = *yytext; return CHAR; }
{WHITESPACE}        { BEGIN(INITIAL); }
{NEWLINE}           { column = 0; line++; BEGIN(INITIAL); }
.                   { printf("error?\n"); }

%%

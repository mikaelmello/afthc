/* Scanner for Afth */

%{

#include "token_types.h"
#include "my_string.h"
#include "lexical_error_handler.h"

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

{LEFT_BRACE}        { return T_LEFT_BRACE; }
{RIGHT_BRACE}       { return T_RIGHT_BRACE; }
{LEFT_BRACKET}      { return T_LEFT_BRACKET; }
{RIGHT_BRACKET}     { return T_RIGHT_BRACKET; }
{LEFT_PAREN}        { return T_LEFT_PAREN; }
{RIGHT_PAREN}       { return T_RIGHT_PAREN; }
{LEFT_ANGLE}        { return T_LEFT_ANGLE; }
{RIGHT_ANGLE}       { return T_RIGHT_ANGLE; }

{EQUAL}             { return T_EQUAL; }
{PLUS_EQUAL}        { return T_PLUS_EQUAL; }
{MINUS_EQUAL}       { return T_MINUS_EQUAL; }
{ASTERISK_EQUAL}    { return T_ASTERISK_EQUAL; }
{SLASH_EQUAL}       { return T_SLASH_EQUAL; }
{PERCENT_EQUAL}     { return T_PERCENT_EQUAL; }
{LANGLE_EQUAL}      { return T_LANGLE_EQUAL; }
{RANGLE_EQUAL}      { return T_RANGLE_EQUAL; }
{EQUAL_EQUAL}       { return T_EQUAL_EQUAL; }
{EXCL_EQUAL}        { return T_EXCL_EQUAL; }
{DOUBLE_LANGLE}     { return T_DOUBLE_LANGLE; }
{DOUBLE_RANGLE}     { return T_DOUBLE_RANGLE; }

{TILDE}             { return T_TILDE; }
{AND}               { return T_AND; }
{BAR}               { return T_BAR; }
{CARET}             { return T_CARET; }
{EXCL}              { return T_EXCL; }
{BAR_BAR}           { return T_BAR_BAR; }
{AND_AND}           { return T_AND_AND; }
{COMMA}             { return T_COMMA; }
{SEMICOLON}         { return T_SEMICOLON; }
{PLUS}              { return T_PLUS; }
{MINUS}             { return T_MINUS; }
{ASTERISK}          { return T_ASTERISK; }
{SLASH}             { return T_SLASH; }
{PERCENT}           { return T_PERCENT; }

{IN_RW}             { return T_IN_RW; }
{RM_RW}             { return T_RM_RW; }
{SIZEOF_RW}         { return T_SIZEOF_RW; }
{VOID_RW}           { return T_VOID_RW; }
{BOOL_RW}           { return T_BOOL_RW; }
{BYTE_RW}           { return T_BYTE_RW; }
{CHAR_RW}           { return T_CHAR_RW; }
{SHORT_RW}          { return T_SHORT_RW; }
{INT_RW}            { return T_INT_RW; }
{LONG_RW}           { return T_LONG_RW; }
{FLOAT_RW}          { return T_FLOAT_RW; }
{DOUBLE_RW}         { return T_DOUBLE_RW; }
{PRINT_RW}          { return T_PRINT_RW; }
{PRINTC_RW}         { return T_PRINTC_RW; }
{PRINTX_RW}         { return T_PRINTX_RW; }
{SCAN_RW}           { return T_SCAN_RW; }
{SCANC_RW}          { return T_SCANC_RW; }
{SCANF_RW}          { return T_SCANF_RW; }
{IF_RW}             { return T_IF_RW; }
{ELSE_RW}           { return T_ELSE_RW; }
{WHILE_RW}          { return T_WHILE_RW; }
{FOR_RW}            { return T_FOR_RW; }
{RETURN_RW}         { return T_RETURN_RW; }

{INTEGER}           { return T_INTEGER; }
{REAL}              { return T_REAL; }
{IDENTIFIER}        { return T_IDENTIFIER; }
{STRING}            { return T_STRING; }
{CHAR}              { return T_CHAR; }
{WHITESPACE}        { return T_WHITESPACE; }
{NEWLINE}           { column = 0; line++; return T_WHITESPACE; }
.                   { return T_ERROR; }

%%

/* Scanner for Afth */

%{
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
BOOL_RW         "bool"
BYTE_RW         "byte"
CHAR_RW         "char"
SHORT_RW        "short"
INT_RW          "int"
LONG_RW         "long"
FLOAT_RW        "float"
DOUBLE_RW       "double"
IF_RW           "if"
ELSE_RW         "else"
WHILE_RW        "while"
FOR_RW          "for"
RETURN_RW       "return"

UNDERSCORE      "_"
NEWLINE         \n
WHITESPACE      [\t ]
DIGIT           [0-9]
STRING          \"[^"\\]*(\\.[^"\\]*)*\"
LETTER          [a-zA-Z]
INTEGER         {DIGIT}+
REAL            {DIGIT}+"."{DIGIT}+
ID              {LETTER}({DIGIT}|{LETTER}|{UNDERSCORE})*

%%

%%

int main(int argc, char* argv[]) {
    argc -= 1;
    argv++;

    if (argc > 0) {
        yyin = fopen( argv[0], "r" );
    } else {
        yyin = stdin;
    }
    yylex();
}

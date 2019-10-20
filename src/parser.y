%{

#include "my_string.h"
#include "lexical_error_handler.h"
#include <stdio.h>

extern FILE* yyin;

int yyerror() {
    
}

%}

%token LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET
%token LEFT_PAREN RIGHT_PAREN LEFT_ANGLE RIGHT_ANGLE EQUAL
%token PLUS_EQUAL MINUS_EQUAL ASTERISK_EQUAL SLASH_EQUAL
%token PERCENT_EQUAL LANGLE_EQUAL RANGLE_EQUAL EQUAL_EQUAL
%token EXCL_EQUAL DOUBLE_LANGLE DOUBLE_RANGLE TILDE AND BAR
%token CARET EXCL BAR_BAR AND_AND COMMA SEMICOLON PLUS MINUS
%token ASTERISK SLASH PERCENT IN_RW RM_RW SIZEOF_RW VOID_RW
%token BOOL_RW BYTE_RW CHAR_RW SHORT_RW INT_RW LONG_RW
%token FLOAT_RW DOUBLE_RW PRINT_RW PRINTC_RW PRINTX_RW SCAN_RW
%token SCANC_RW SCANF_RW IF_RW ELSE_RW WHILE_RW TRUE_RW
%token FALSE_RW FOR_RW RETURN_RW UNDERSCORE WHITESPACE STRING
%token NEWLINE DIGIT LETTER CHAR INTEGER REAL IDENTIFIER

%nonassoc REDUCE
%nonassoc ELSE_RW
%%

library:
    declaration-list

declaration-list:
    declaration-list declaration
|   %empty

declaration: var-declaration
|   fun-declaration

var-declaration:
    type IDENTIFIER var-structure SEMICOLON

var-structure:
    LEFT_BRACKET INTEGER RIGHT_BRACKET
|   LEFT_BRACKET RIGHT_BRACKET
|   LEFT_BRACE RIGHT_BRACE
|   %empty

fun-declaration:
    type IDENTIFIER LEFT_PAREN param-decs RIGHT_PAREN scope

param-decs:
    param-decs COMMA param-dec
|   %empty

param-dec:
    type IDENTIFIER var-structure

scope:
    LEFT_BRACE statement-list RIGHT_BRACE

statement-list:
    statement-list statement
|   %empty

statement:  
    scope
|   var-declaration
|   assignment
|   print
|   scan
|   expression SEMICOLON
|   condition
|   iteration
|   return

print:
    print-words expression SEMICOLON

scan:
    scan-words IDENTIFIER SEMICOLON

print-words:
    PRINT_RW | PRINTC_RW | PRINTX_RW

scan-words:
    SCAN_RW | SCANC_RW | SCANF_RW

condition:
    IF_RW LEFT_PAREN expression RIGHT_PAREN statement REDUCE
|   IF_RW LEFT_PAREN expression RIGHT_PAREN statement ELSE_RW statement

iteration:
    WHILE_RW LEFT_PAREN expression RIGHT_PAREN statement
|   FOR_RW LEFT_PAREN optional-expression SEMICOLON optional-expression SEMICOLON optional-expression RIGHT_PAREN statement

return:
    RETURN_RW optional-expression SEMICOLON

assignment:
    IDENTIFIER assignment-op expression SEMICOLON

optional-expression:
    expression
|   %empty

expression:
    and-expression

and-expression:
    and-expression AND_AND or-expression
|   or-expression

or-expression:
    or-expression BAR_BAR bw-or-expression
|   bw-or-expression

bw-or-expression:
    bw-or-expression BAR bw-xor-expression
|   bw-xor-expression

bw-xor-expression:
    bw-xor-expression CARET bw-and-expression
|   bw-and-expression

bw-and-expression:
    bw-and-expression AND eq-expression
|   eq-expression

eq-expression:
    eq-expression EQUAL_EQUAL rel-expression
|   eq-expression EXCL_EQUAL rel-expression
|   rel-expression

rel-expression:
    rel-expression rel-op shift-expression
|   shift-expression

shift-expression:
    shift-expression DOUBLE_LANGLE set-rm-expression
|   shift-expression DOUBLE_RANGLE set-rm-expression
|   set-rm-expression

set-rm-expression:
    set-rm-expression RM_RW add-expression
|   add-expression

add-expression:
    add-expression PLUS mult-expression
|   add-expression MINUS mult-expression
|   mult-expression

mult-expression:
    mult-expression mul-op cast-expression
|   cast-expression

cast-expression:
    LEFT_PAREN type RIGHT_PAREN cast-expression
|   unary-expression

unary-expression:
    unary-op cast-expression
|   SIZEOF_RW cast-expression
|   postfix-expression

postfix-expression:
    postfix-expression LEFT_BRACKET expression RIGHT_BRACKET
|   postfix-expression LEFT_PAREN param-vals RIGHT_PAREN
|   primary-expression

param-vals:
    param-vals COMMA expression
|   %empty

primary-expression:
    IDENTIFIER
|   constant
|   STRING
|   LEFT_PAREN expression RIGHT_PAREN

constant:
    INTEGER | CHAR | REAL

assignment-op:
    EQUAL | PLUS_EQUAL | MINUS_EQUAL | ASTERISK_EQUAL | SLASH_EQUAL | PERCENT_EQUAL

unary-op:
    PLUS | MINUS | EXCL

rel-op:
    LEFT_ANGLE | RIGHT_ANGLE | LANGLE_EQUAL | RANGLE_EQUAL | IN_RW

mul-op:
    ASTERISK | SLASH | PERCENT

type: VOID_RW | BOOL_RW | BYTE_RW | CHAR_RW | SHORT_RW | INT_RW | LONG_RW | FLOAT_RW | DOUBLE_RW

%%

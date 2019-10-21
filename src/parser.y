%{

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

%}

%token <string_val> IDENTIFIER STRING
%token <integer_val> DIGIT INTEGER
%token <char_val> CHAR
%token <float_val> REAL
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
%token FALSE_RW FOR_RW RETURN_RW UNDERSCORE
%token NEWLINE

%nonassoc REDUCE
%nonassoc ELSE_RW

%union {
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
}

%type <c_program> program;
%type <c_declaration_list> declaration-list;
%type <c_declaration> declaration;
%type <c_variable> var-declaration;
%type <c_function> fun-declaration;
%type <c_function_params> param-decs;
%type <c_function_param> param-dec;
%type <c_scope> scope;
%type <c_primitive_type> type;
%type <c_statement_list> statement-list;
%type <c_statement> statement;
%type <c_print> print;
%type <c_print_type> print-type;
%type <c_scan> scan;
%type <c_scan_type> scan-type;
%type <c_return> return;
%type <c_expression> expression;
%type <c_expression> optional-expression;
%type <c_condition> condition;
%type <c_iteration> iteration;
%type <c_while> while-iteration;
%type <c_for> for-iteration;
%type <c_assignment> assignment;
%type <c_and_expression> and-expression;
%type <c_or_expression> or-expression;
%type <c_bw_or_expression> bw-or-expression;
%type <c_bw_xor_expression> bw-xor-expression;
%type <c_bw_and_expression> bw-and-expression;
%type <c_eq_expression> eq-expression;
%type <c_rel_expression> rel-expression;
%type <c_shift_expression> shift-expression;
%type <c_set_rm_expression> set-rm-expression;
%type <c_add_expression> add-expression;
%type <c_mult_expression> mult-expression;
%type <c_cast_expression> cast-expression;
%type <c_unary_expression> unary-expression;
%type <c_postfix_expression> postfix-expression;
%type <c_primary_expression> primary-expression;
%type <c_constant> constant;
%type <c_param_vals> param-vals;
%type <c_assignment_operator> assignment-op;
%type <c_rel_expression_type> rel-op;
%type <c_mult_operator> mul-op;
%type <c_unary_expression_type> unary-op;

%start program

%%

program:
    declaration-list {
        printf("OK!\n");
        t_program* program = zero_allocate(t_program);
        program->declarations = $1;
        $$ = program;
    }
;

declaration-list:
    declaration-list declaration {
        t_declaration_list* declaration_list = zero_allocate(t_declaration_list);
        declaration_list->prev = $1;
        declaration_list->cur = $2;
        $$ = declaration_list;
    }
|   %empty {
        $$ = NULL;
    }
;

declaration:
    var-declaration {
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = VAR_DECLARATION;
        dec->member.variable = $1;
        $$ = dec;
    }
|   fun-declaration {
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = FUN_DECLARATION;
        dec->member.function = $1;   
        $$ = dec;  
    }
;

var-declaration:
    type IDENTIFIER SEMICOLON {
        t_variable* var = zero_allocate(t_variable);
        var->type = $1;
        var->structure = PRIMITIVE_TYPE;
        var->identifier = $2;
        $$ = var;
    }
|   type IDENTIFIER LEFT_BRACKET INTEGER RIGHT_BRACKET SEMICOLON {
        t_variable* var = zero_allocate(t_variable);
        var->type = $1;
        var->structure = ARRAY_TYPE;
        var->identifier = $2;
        $$ = var;
    }
|   type IDENTIFIER LEFT_BRACKET RIGHT_BRACKET SEMICOLON {
        t_variable* var = zero_allocate(t_variable);
        var->type = $1;
        var->structure = ARRAY_TYPE;
        var->identifier = $2;
        $$ = var;
    }
|   type IDENTIFIER LEFT_BRACE RIGHT_BRACE SEMICOLON {
        t_variable* var = zero_allocate(t_variable);
        var->type = $1;
        var->structure = SET_TYPE;
        var->identifier = $2;
        $$ = var;
    }
;

fun-declaration:
    type IDENTIFIER LEFT_PAREN param-decs RIGHT_PAREN scope {
        t_function* fun = zero_allocate(t_function);
        fun->return_type = $1;
        fun->return_structure = PRIMITIVE_TYPE;
        fun->identifier = $2;
        fun->params = $4;
        fun->body = $6;
        $$ = fun;
    }
;

param-decs:
    param-decs COMMA param-dec {
        t_function_params* fp = zero_allocate(t_function_params);
        fp->cur = $3;
        fp->prev = $1;
        $$ = fp; 
    }
|   %empty {
        $$ = NULL;
    }
;

param-dec:
    type IDENTIFIER {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = $1;
        var->structure = PRIMITIVE_TYPE;
        var->identifier = $2;
        $$ = var;
    }
|   type IDENTIFIER LEFT_BRACKET INTEGER RIGHT_BRACKET {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = $1;
        var->structure = ARRAY_TYPE;
        var->identifier = $2;
        $$ = var;
    }
|   type IDENTIFIER LEFT_BRACKET RIGHT_BRACKET {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = $1;
        var->structure = ARRAY_TYPE;
        var->identifier = $2;
        $$ = var;
    }
|   type IDENTIFIER LEFT_BRACE RIGHT_BRACE {
        t_function_param* var = zero_allocate(t_function_param);
        var->type = $1;
        var->structure = SET_TYPE;
        var->identifier = $2;
        $$ = var;
    }
;

scope:
    LEFT_BRACE statement-list RIGHT_BRACE {
        t_scope* scope = zero_allocate(t_scope);
        scope->statements = $2;
        $$ = scope;
    }
;

statement-list:
    statement-list statement {
        t_statement_list* fp = zero_allocate(t_statement_list);
        fp->cur = $2;
        fp->prev = $1;
        $$ = fp; 
    }
|   %empty {
    $$ = NULL;
}
;

statement:  
    scope {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = SCOPE_STATEMENT;
        stmt->member.scope = $1;
        $$ = stmt;
    }
|   var-declaration {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = VAR_DECLARATION_STATEMENT;
        stmt->member.variable = $1;
        $$ = stmt;
    }
|   print {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = PRINT_STATEMENT;
        stmt->member.print = $1;
        $$ = stmt;
    }
|   scan {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = SCAN_STATEMENT;
        stmt->member.scan = $1;
        $$ = stmt;
    }
|   expression SEMICOLON {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = EXPRESSION_STATEMENT;
        stmt->member.expression = $1;
        $$ = stmt;
    }
|   condition {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = CONDITION_STATEMENT;
        stmt->member.condition = $1;
        $$ = stmt;
    }
|   iteration {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = ITERATION_STATEMENT;
        stmt->member.iteration = $1;
        $$ = stmt;
    }
|   return {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = RETURN_STATEMENT;
        stmt->member._return = $1;
        $$ = stmt;
    }
;

print:
    print-type expression SEMICOLON {
        t_print* print = zero_allocate(t_print);
        print->type = $1;
        print->expression = $2;
        $$ = print;
    }
;

scan:
    scan-type IDENTIFIER SEMICOLON {
        t_scan* scan = zero_allocate(t_scan);
        scan->type = $1;
        scan->destiny = $2;
        $$ = scan;
    }
;

print-type:
    PRINT_RW {
        $$ = PRINT_DEC_TYPE;
    }
|   PRINTC_RW {
        $$ = PRINT_CHAR_TYPE;
    }
|   PRINTX_RW {
        $$ = PRINT_HEX_TYPE;
    }
;

scan-type:
    SCAN_RW {
        $$ = SCAN_DEC_TYPE;
    }
|   SCANC_RW {
        $$ = SCAN_CHAR_TYPE;
    }
|   SCANF_RW {
        $$ = SCAN_FLOAT_TYPE;
    }
;

condition:
    IF_RW LEFT_PAREN expression RIGHT_PAREN statement %prec REDUCE {
        t_condition* cond = zero_allocate(t_condition);
        cond->condition = $3;
        cond->body = $5;
        cond->else_body = NULL;  
        $$ = cond;  
    }
|   IF_RW LEFT_PAREN expression RIGHT_PAREN statement ELSE_RW statement {   
        t_condition* cond = zero_allocate(t_condition);
        cond->condition = $3;
        cond->body = $5;
        cond->else_body = $7;
        $$ = cond;
    }
;

iteration:
    while-iteration {
        t_iteration* it = zero_allocate(t_iteration);
        it->type = WHILE_ITERATION;
        it->member._while = $1;
        $$ = it;
    }
|   for-iteration {
        t_iteration* it = zero_allocate(t_iteration);
        it->type = FOR_ITERATION;
        it->member._for = $1;
        $$ = it;
    }
;

while-iteration:
    WHILE_RW LEFT_PAREN expression RIGHT_PAREN statement {
        t_while* w = zero_allocate(t_while);
        w->condition = $3;
        w->body = $5;
        $$ = w;
    }
;

for-iteration:
    FOR_RW LEFT_PAREN optional-expression SEMICOLON optional-expression SEMICOLON optional-expression RIGHT_PAREN statement {
        t_for* f = zero_allocate(t_for);
        f->initialization = $3;
        f->condition = $5;
        f->step = $7;
        f->body = $9;
        $$ = f;
    }
;

return:
    RETURN_RW optional-expression SEMICOLON {
        t_return* ret = zero_allocate(t_return);
        ret->expression = $2;
        $$ = ret;
    }
;

optional-expression:
    expression {
        $$ = $1;
    }
|   %empty {
        $$ = NULL;
    }
;

expression:
    assignment {
        t_expression* exp = zero_allocate(t_expression);
        exp->assignment = $1;
        $$ = exp;
    }
;

assignment:
    IDENTIFIER assignment-op and-expression {
        t_assignment* exp = zero_allocate(t_assignment);
        exp->identifier = $1;
        exp->operator = $2;
        exp->and_expression = $3;
        $$ = exp;
    }
|   and-expression {
        t_assignment* exp = zero_allocate(t_assignment);
        exp->and_expression = $1;
        $$ = exp;
    }
;

and-expression:
    and-expression AND_AND or-expression {
        t_and_expression* exp = zero_allocate(t_and_expression);
        exp->left = $1;
        exp->right = $3;
        $$ = exp;
    }
|   or-expression {
        t_and_expression* exp = zero_allocate(t_and_expression);
        exp->right = $1;
        $$ = exp;
    }
;

or-expression:
    or-expression BAR_BAR bw-and-expression {
        t_or_expression* exp = zero_allocate(t_or_expression);
        exp->left = $1;
        exp->right = $3;
        $$ = exp;
    }
|   bw-and-expression {
        t_or_expression* exp = zero_allocate(t_or_expression);
        exp->right = $1;
        $$ = exp;
    }
;

bw-and-expression:
    bw-and-expression AND bw-or-expression {
        t_bw_and_expression* exp = zero_allocate(t_bw_and_expression);
        exp->left = $1;
        exp->right = $3;
        $$ = exp;
    }
|   bw-or-expression {
        t_bw_and_expression* exp = zero_allocate(t_bw_and_expression);
        exp->right = $1;
        $$ = exp;
    }
;

bw-or-expression:
    bw-or-expression BAR bw-xor-expression {
        t_bw_or_expression* exp = zero_allocate(t_bw_or_expression);
        exp->left = $1;
        exp->right = $3;
        $$ = exp;
    }
|   bw-xor-expression {
        t_bw_or_expression* exp = zero_allocate(t_bw_or_expression);
        exp->right = $1;
        $$ = exp;
    }
;

bw-xor-expression:
    bw-xor-expression CARET eq-expression {
        t_bw_xor_expression* exp = zero_allocate(t_bw_xor_expression);
        exp->left = $1;
        exp->right = $3;
        $$ = exp;
    }
|   eq-expression {
        t_bw_xor_expression* exp = zero_allocate(t_bw_xor_expression);
        exp->right = $1;
        $$ = exp;
    }
;

eq-expression:
    eq-expression EQUAL_EQUAL rel-expression {
        t_eq_expression* exp = zero_allocate(t_eq_expression);
        exp->type = EQ_EQ_EXPRESSION;
        exp->left = $1;
        exp->right = $3;
        $$ = exp;
    }
|   eq-expression EXCL_EQUAL rel-expression {
        t_eq_expression* exp = zero_allocate(t_eq_expression);
        exp->type = NOT_EQ_EXPRESSION;
        exp->left = $1;
        exp->right = $3;
        $$ = exp;
    }
|   rel-expression {
        t_eq_expression* exp = zero_allocate(t_eq_expression);
        exp->right = $1;
        $$ = exp;
    }
;

rel-expression:
    rel-expression rel-op shift-expression {
        t_rel_expression* exp = zero_allocate(t_rel_expression);
        exp->left = $1;
        exp->type = $2;
        exp->right = $3;
        $$ = exp;
    }
|   shift-expression {
        t_rel_expression* exp = zero_allocate(t_rel_expression);
        exp->right = $1;
        $$ = exp;
    }
;

shift-expression:
    shift-expression DOUBLE_LANGLE set-rm-expression {
        t_shift_expression* exp = zero_allocate(t_shift_expression);
        exp->left = $1;
        exp->type = LEFT_SHIFT_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   shift-expression DOUBLE_RANGLE set-rm-expression {
        t_shift_expression* exp = zero_allocate(t_shift_expression);
        exp->left = $1;
        exp->type = RIGHT_SHIFT_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   set-rm-expression {
        t_shift_expression* exp = zero_allocate(t_shift_expression);
        exp->right = $1;
        $$ = exp;
    }
;

set-rm-expression:
    set-rm-expression RM_RW add-expression {
        t_set_rm_expression* exp = zero_allocate(t_set_rm_expression);
        exp->left = $1;
        exp->right = $3;
        $$ = exp;
    }
|   add-expression  {
        t_set_rm_expression* exp = zero_allocate(t_set_rm_expression);
        exp->right = $1;
        $$ = exp;
    }
;

add-expression:
    add-expression PLUS mult-expression {
        t_add_expression* exp = zero_allocate(t_add_expression);
        exp->left = $1;
        exp->type = ADD_PLUS;
        exp->right = $3;
        $$ = exp;
    }
|   add-expression MINUS mult-expression {
        t_add_expression* exp = zero_allocate(t_add_expression);
        exp->left = $1;
        exp->type = ADD_MINUS;
        exp->right = $3;
        $$ = exp;
    }
|   mult-expression {
        t_add_expression* exp = zero_allocate(t_add_expression);
        exp->right = $1;
        $$ = exp;
    }
;

mult-expression:
    mult-expression mul-op cast-expression {
        t_mult_expression* exp = zero_allocate(t_mult_expression);
        exp->left = $1;
        exp->type = $2;
        exp->right = $3;
        $$ = exp;
    }
|   cast-expression {
        t_mult_expression* exp = zero_allocate(t_mult_expression);
        exp->right = $1;
        $$ = exp;
    }
;

cast-expression:
    LEFT_PAREN type RIGHT_PAREN cast-expression {
        t_cast_expression* exp = zero_allocate(t_cast_expression);
        exp->type = $2;
        exp->left = $4;
        $$ = exp;
    }
|   unary-expression {
        t_cast_expression* exp = zero_allocate(t_cast_expression);
        exp->right = $1;
        $$ = exp;
    }
;

unary-expression:
    unary-op unary-expression {
        t_unary_expression* exp = zero_allocate(t_unary_expression);
        exp->type = $1;
        exp->left = $2;
        $$ = exp;
    }
|   SIZEOF_RW unary-expression {
        t_unary_expression* exp = zero_allocate(t_unary_expression);
        exp->type = UNARY_SIZEOF;
        exp->left = $2;
        $$ = exp;
    }
|   postfix-expression {
        t_unary_expression* exp = zero_allocate(t_unary_expression);
        exp->right = $1;
        $$ = exp;
    }
;

postfix-expression:
    postfix-expression LEFT_BRACKET expression RIGHT_BRACKET {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = ARRAY_ACCESS;
        exp->left = $1;
        exp->member.array_index = $3;
        $$ = exp;
    }
|   postfix-expression LEFT_PAREN param-vals RIGHT_PAREN {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = FUNCTION_CALL;
        exp->left = $1;
        exp->member.function_params = $3;
        $$ = exp;
    }
|   primary-expression {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->primary = $1;
        $$ = exp;
    }
;

param-vals:
    param-vals COMMA expression {
        t_param_vals* pv = zero_allocate(t_param_vals);
        pv->prev = $1;
        pv->cur = $3;
        $$ = pv;
    }
|   expression {
        t_param_vals* pv = zero_allocate(t_param_vals);
        pv->cur = $1;
        $$ = pv;
    }
|   %empty {
        $$ = NULL;
    }
;

primary-expression:
    IDENTIFIER {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = IDENTIFIER_PRIMARY_EXPRESSION;
        exp->member.identifier = $1;
        $$ = exp;
    }
|   constant {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = CONSTANT_PRIMARY_EXPRESSION;
        exp->member.constant = $1;
        $$ = exp;
    }
|   STRING {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = STRING_PRIMARY_EXPRESSION;
        exp->member.string = $1;
        $$ = exp;
    }
|   LEFT_PAREN expression RIGHT_PAREN {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = NESTED_PRIMARY_EXPRESSION;
        exp->member.expression = $2;
        $$ = exp;
    }
;

constant:
    INTEGER {
        t_constant* c = zero_allocate(t_constant);
        c->type = INTEGER_CONSTANT;
        c->member.integer_val = $1;
        $$ = c;
    }
|   CHAR {
        t_constant* c = zero_allocate(t_constant);
        c->type = CHAR_CONSTANT;
        c->member.char_val = $1;
        $$ = c;
    }
|   REAL {
        t_constant* c = zero_allocate(t_constant);
        c->type = REAL_CONSTANT;
        c->member.float_val = $1;
        $$ = c;
    }
;

assignment-op:
    EQUAL { $$ = EQUAL_OPERATOR; }
|   PLUS_EQUAL { $$ = PLUS_EQUAL_OPERATOR; }
|   MINUS_EQUAL { $$ = MINUS_EQUAL_OPERATOR; }
|   ASTERISK_EQUAL { $$ = ASTERISK_EQUAL_OPERATOR; }
|   SLASH_EQUAL { $$ = SLASH_EQUAL_OPERATOR; }
|   PERCENT_EQUAL { $$ = PERCENT_EQUAL_OPERATOR; }
;

unary-op:
    PLUS { $$ = UNARY_PLUS; }
|   MINUS { $$ = UNARY_MINUS; }
|   EXCL { $$ + UNARY_EXCL; }
;

rel-op:
    LEFT_ANGLE { $$ = LESS_THAN; }
|   RIGHT_ANGLE { $$ = GREATER_THAN; }
|   LANGLE_EQUAL { $$ = LESS_THAN_OR_EQUAL; }
|   RANGLE_EQUAL { $$ = GREATER_THAN_OR_EQUAL; }
|   IN_RW { $$ = IS_IN; }
;

mul-op:
    ASTERISK { $$ = ASTERISK_OPERATOR; }
|   SLASH { $$ = SLASH_OPERATOR; }
|   PERCENT { $$ = PERCENT_OPERATOR; }
;

type:
    VOID_RW {
        $$ = VOID_TYPE;
    }
|   BOOL_RW {
        $$ = BYTE_TYPE;
    }
|   BYTE_RW {
        $$ = BYTE_TYPE;
    }
|   CHAR_RW {
        $$ = BYTE_TYPE;
    }
|   SHORT_RW {
        $$ = SHORT_TYPE;
    }
|   INT_RW {
        $$ = INT_TYPE;
    }
|   LONG_RW {
        $$ = LONG_TYPE;
    }
|   FLOAT_RW {
        $$ = FLOAT_TYPE;
    }
|   DOUBLE_RW {
        $$ = DOUBLE_TYPE;
    }

%%

%{

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

%}

%define parse.error verbose
%define parse.lac none

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
    int64_t integer_val;
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
        t_program* program = zero_allocate(t_program);
        program->declarations = $1;
        ast_root.c_program = program;
        print_ast(ast_root, NT_PROGRAM, 0);
        print_symbol_table_list(sym_table);
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
        append_symbol_table_node(sym_table, dec);
        $$ = dec;
    }
|   fun-declaration {
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = FUN_DECLARATION;
        dec->member.function = $1;  
        append_symbol_table_node(sym_table, dec); 
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
|   param-dec {
        t_function_params* fp = zero_allocate(t_function_params);
        fp->cur = $1;
        fp->prev = NULL;
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
|   declaration {
        t_statement* stmt = zero_allocate(t_statement);
        stmt->type = DECLARATION_STATEMENT;
        stmt->member.declaration = $1;
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
|   EXCL { $$ = UNARY_EXCL; }
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

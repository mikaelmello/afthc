%{

#include "symbol_table.h"
#include "abstract_syntax_tree.h"
#include "my_string.h"
#include "lexical_error_handler.h"
#include <stdio.h>
#include <assert.h>
#include "scope.h"
#include <string.h>

#define zero_allocate(type) ((type*)calloc(1, sizeof(type)))

extern FILE* yyin;
extern int yylex();
extern uint32_t line;
extern uint32_t column;
extern scope_error_t LAST_ERROR;
scope_t* root_scope;
scope_t* current_scope;
node ast_root;

void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

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
    t_expression_type c_expression_type;
    t_constant_type c_constant_type;
    t_assignment_operator c_assignment_operator;
    t_primitive_type c_primitive_type;
    t_print_type c_print_type;
    t_scan_type c_scan_type;
    t_program* c_program;
    t_declaration_list* c_declaration_list;
    t_declaration* c_declaration;
    t_variable* c_variable;
    t_function* c_function;
    t_function_params* c_function_params;
    t_brace_enclosed_scope* c_brace_enclosed_scope;
    t_statement_list* c_statement_list;
    t_statement* c_statement;
    t_print* c_print;
    t_scan* c_scan;
    t_return* c_return;
    t_expression* c_expression;
    t_condition* c_condition;
    t_iteration* c_iteration;
    t_assignment* c_assignment;
    t_postfix_expression* c_postfix_expression;
    t_primary_expression* c_primary_expression;
    t_cast_expression* c_cast_expression;
    st_element_t* c_st_element;
    t_constant* c_constant;
    t_param_vals* c_param_vals;
    char* string_val;
    int64_t integer_val;
    double float_val;
    char char_val;
}

%type <c_program> program;
%type <c_declaration_list> declaration-list;
%type <c_st_element> declaration;
%type <c_st_element> var-declaration;
%type <c_st_element> fun-declaration;
%type <c_function_params> param-decs;
%type <c_brace_enclosed_scope> scope;
%type <c_primitive_type> type;
%type <c_statement_list> statement-list;
%type <c_statement> statement;
%type <c_print> print;
%type <c_print_type> print-type;
%type <c_scan> scan;
%type <c_scan_type> scan-type;
%type <c_return> return;
%type <c_expression> optional-expression;
%type <c_condition> condition;
%type <c_iteration> iteration;
%type <c_assignment> assignment;
%type <c_expression> expression;
%type <c_expression> and-expression;
%type <c_expression> or-expression;
%type <c_expression> bw-or-expression;
%type <c_expression> bw-xor-expression;
%type <c_expression> bw-and-expression;
%type <c_expression> eq-expression;
%type <c_expression> rel-expression;
%type <c_expression> shift-expression;
%type <c_expression> set-rm-expression;
%type <c_expression> add-expression;
%type <c_expression> mult-expression;
%type <c_st_element> identifier;
%type <c_cast_expression> cast-expression;
%type <c_expression> unary-expression;
%type <c_postfix_expression> postfix-expression;
%type <c_primary_expression> primary-expression;
%type <c_constant> constant;
%type <c_param_vals> param-vals;
%type <c_assignment_operator> assignment-op;
%type <c_expression_type> rel-op;
%type <c_expression_type> mul-op;
%type <c_expression_type> unary-op;

%start program

%%

program:
    declaration-list {
        t_program* program = zero_allocate(t_program);
        program->declaration_list = $1;
        print_program(program, 0);
        $$ = program;

        scope_destroy(current_scope);
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
    var-declaration SEMICOLON {
        $$ = $1;
    }
|   fun-declaration {
        $$ = $1;
    }
;

var-declaration:
    type IDENTIFIER {
        t_variable* var = zero_allocate(t_variable);
        var->type_info.primitive_type = $1;
        var->type_info.data_structure = PRIMITIVE;
        var->identifier = $2;
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = VAR_DECLARATION;
        dec->member.variable = var;
        scope_element_t* add = scope_add(current_scope, dec);
        if (LAST_ERROR == EXISTING_DECLARATION) {
            LAST_ERROR = 0;
            printf("Multiple declaration of identifier %s\n", $2);
        }
        $$ = add;
    }
|   type IDENTIFIER LEFT_BRACKET INTEGER RIGHT_BRACKET {
        t_variable* var = zero_allocate(t_variable);
        var->type_info.primitive_type = $1;
        var->type_info.data_structure = ARRAY;
        var->identifier = $2;
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = VAR_DECLARATION;
        dec->member.variable = var;
        scope_element_t* add = scope_add(current_scope, dec);
        if (LAST_ERROR == EXISTING_DECLARATION) {
            LAST_ERROR = 0;
            printf("Multiple declaration of identifier %s\n", $2);
        }
        $$ = add;
    }
|   type IDENTIFIER LEFT_BRACE RIGHT_BRACE {
        t_variable* var = zero_allocate(t_variable);
        var->type_info.primitive_type = $1;
        var->type_info.data_structure = SET;
        var->identifier = $2;
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = VAR_DECLARATION;
        dec->member.variable = var;
        scope_element_t* add = scope_add(current_scope, dec);
        if (LAST_ERROR == EXISTING_DECLARATION) {
            LAST_ERROR = 0;
            printf("Multiple declaration of identifier %s\n", $2);
        }
        $$ = add;
    }
;

fun-declaration:
    type IDENTIFIER LEFT_PAREN {
        t_function* fun = zero_allocate(t_function);
        fun->type_info.primitive_type = $1;
        fun->type_info.data_structure = FUNCTION;
        fun->identifier = $2;
        fun->params = NULL;
        fun->body = NULL;
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = FUN_DECLARATION;
        dec->member.function = fun;
        scope_add(current_scope, dec);
        current_scope = scope_create(current_scope);
    } param-decs RIGHT_PAREN {
        st_element_t* fun = scope_find(current_scope, $2);
        if (fun == NULL) {
            printf("Should not happen, fun is null!\n");
            exit(55);
        }
        fun->declaration->member.function->params = $5;
    } scope {
        st_element_t* fun = scope_find(current_scope, $2);
        if (fun == NULL) {
            printf("Should not happen, fun is null!\n");
            exit(55);
        }
        fun->declaration->member.function->body = $8;
        $$ = fun;
        current_scope = scope_destroy(current_scope);
    }
|   type IDENTIFIER LEFT_PAREN {
        t_function* fun = zero_allocate(t_function);
        fun->type_info.primitive_type = $1;
        fun->type_info.data_structure = FUNCTION;
        fun->identifier = $2;
        fun->params = NULL;
        
        t_declaration* dec = zero_allocate(t_declaration);
        dec->type = FUN_DECLARATION;
        dec->member.function = fun;
        scope_add(current_scope, dec);
        current_scope = scope_create(current_scope);
    } RIGHT_PAREN scope {
        st_element_t* fun = scope_find(current_scope, $2);
        if (fun == NULL) {
            printf("Should not happen, fun is null!\n");
            exit(55);
        }
        fun->declaration->member.function->body = $6;
        $$ = fun;
        current_scope = scope_destroy(current_scope);
    }
;

param-decs:
    param-decs COMMA var-declaration {
        t_function_params* fp = zero_allocate(t_function_params);
        assert($3->declaration->type == VAR_DECLARATION);
        fp->cur = $3;
        fp->prev = $1;
        $$ = fp; 
    }
|   var-declaration {
        t_function_params* fp = zero_allocate(t_function_params);
        assert($1->declaration->type == VAR_DECLARATION);
        fp->cur = $1;
        fp->prev = NULL;
        $$ = fp; 
    }
;

scope:
    LEFT_BRACE statement-list RIGHT_BRACE {
        t_brace_enclosed_scope* scope = zero_allocate(t_brace_enclosed_scope);
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
        stmt->type = BRACE_ENCLOSED_SCOPE_STATEMENT;
        stmt->member.scope = $1;
        $$ = stmt;
    }
|   var-declaration SEMICOLON {
        t_statement* stmt = zero_allocate(t_statement);
        assert($1->declaration->type == VAR_DECLARATION);
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

        assert($2 != NULL);
        assert($2->type_info.data_structure == PRIMITIVE);

        if ($1 == PRINT_CHAR_TYPE) {
            assert(is_type_equivalent(
                LONG_TYPE, 
                $2->type_info.primitive_type
                )
            );
        }
    }
;

scan:
    scan-type identifier SEMICOLON {
        t_scan* scan = zero_allocate(t_scan);
        scan->type = $1;

        assert($2 != NULL);
        assert($2->declaration != NULL);
        assert($2->declaration->type == VAR_DECLARATION);
        assert($2->declaration->member.variable->type_info.data_structure == PRIMITIVE);

        if ($1 == SCAN_DEC_TYPE || $1 == SCAN_CHAR_TYPE) {
            assert(is_type_equivalent(
                LONG_TYPE, 
                $2->declaration->member.variable->type_info.primitive_type
                )
            );
        } else {
            assert(is_type_equivalent(
                FLOAT_TYPE, 
                $2->declaration->member.variable->type_info.primitive_type
                )
            );
        }
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
        assert($3 != NULL);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent(
            LONG_TYPE, 
            $3->type_info.primitive_type
            )
        );
        
        t_condition* cond = zero_allocate(t_condition);
        cond->condition = $3;
        cond->body = $5;
        cond->else_body = NULL;

        $$ = cond;  
    }
|   IF_RW LEFT_PAREN expression RIGHT_PAREN statement ELSE_RW statement {   
        assert($3 != NULL);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent(
            LONG_TYPE, 
            $3->type_info.primitive_type
            )
        );

        t_condition* cond = zero_allocate(t_condition);
        cond->condition = $3;
        cond->body = $5;
        cond->else_body = $7;

        $$ = cond;
    }
;

iteration:
    WHILE_RW LEFT_PAREN expression RIGHT_PAREN statement {
        assert($3 != NULL);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent(
            LONG_TYPE, 
            $3->type_info.primitive_type
            )
        );

        t_iteration* w = zero_allocate(t_iteration);
        w->initialization = NULL;
        w->condition = $3;
        w->step = NULL;
        w->body = $5;
        $$ = w;
    }
|   FOR_RW LEFT_PAREN optional-expression SEMICOLON optional-expression SEMICOLON optional-expression RIGHT_PAREN statement {
        

        if ($3 != NULL) {
            assert($3->type_info.data_structure == PRIMITIVE);
            assert(is_type_equivalent(
                LONG_TYPE, 
                $3->type_info.primitive_type
                )
            );
        }
        if ($5 != NULL) {
            assert($5->type_info.data_structure == PRIMITIVE);
            assert(is_type_equivalent(
                LONG_TYPE, 
                $5->type_info.primitive_type
                )
            );
        }
        if ($7 != NULL) {
            assert($7->type_info.data_structure == PRIMITIVE);
            assert(is_type_equivalent(
                LONG_TYPE, 
                $7->type_info.primitive_type
                )
            );
        }
        
        t_iteration* f = zero_allocate(t_iteration);
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

assignment:
    identifier assignment-op expression {
        t_type_info info = get_type_info($1);
        assert(info.data_structure == PRIMITIVE);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert($3->type_info.primitive_type != VOID_TYPE && $3->type_info.primitive_type != STRING_TYPE);
        assert(is_type_equivalent($3->type_info.primitive_type, info.primitive_type));
        t_assignment* exp = zero_allocate(t_assignment);
        exp->identifier = $1;
        exp->operator = $2;
        exp->expression = $3;
        exp->type_info = info;
        $$ = exp;
    }
;

expression:
    assignment {
        t_expression* exp = zero_allocate(t_expression);
        exp->type = ASSIGNMENT_EXPRESSION;
        exp->assignment = $1;
        exp->type_info = $1->type_info;
        $$ = exp;
    }
|   and-expression {
        $$ = $1;
    }
;

and-expression:
    and-expression AND_AND or-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($1->type_info.primitive_type, LONG_TYPE));
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($3->type_info.primitive_type, LONG_TYPE));

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = $1->type_info;
        exp->left = $1;
        exp->type = AND_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   or-expression {
        $$ = $1;
    }
;

or-expression:
    or-expression BAR_BAR bw-and-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($1->type_info.primitive_type, LONG_TYPE));
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($3->type_info.primitive_type, LONG_TYPE));

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = $1->type_info;
        exp->left = $1;
        exp->type = OR_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   bw-and-expression {
        $$ = $1;
    }
;

bw-and-expression:
    bw-and-expression AND bw-or-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($1->type_info.primitive_type, LONG_TYPE));
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($3->type_info.primitive_type, LONG_TYPE));

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = $1->type_info;
        exp->left = $1;
        exp->type = BW_AND_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   bw-or-expression {
        $$ = $1;
    }
;

bw-or-expression:
    bw-or-expression BAR bw-xor-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($1->type_info.primitive_type, LONG_TYPE));
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($3->type_info.primitive_type, LONG_TYPE));

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = $1->type_info;
        exp->left = $1;
        exp->type = BW_OR_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   bw-xor-expression {
        $$ = $1;
    }
;

bw-xor-expression:
    bw-xor-expression CARET eq-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($1->type_info.primitive_type, LONG_TYPE));
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($3->type_info.primitive_type, LONG_TYPE));

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = $1->type_info;
        exp->left = $1;
        exp->type = BW_XOR_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   eq-expression {
        $$ = $1;
    }
;

eq-expression:
    eq-expression EQUAL_EQUAL rel-expression {
        t_type_info info;
        info.primitive_type = LONG_TYPE;
        info.data_structure = PRIMITIVE;
        assert($1->type_info.data_structure == PRIMITIVE);
        assert($1->type_info.primitive_type != VOID_TYPE && 
            $1->type_info.primitive_type != STRING_TYPE);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert($3->type_info.primitive_type != VOID_TYPE && 
            $3->type_info.primitive_type != STRING_TYPE);

        t_expression* exp = zero_allocate(t_expression);
        exp->type = EQ_EQ_EXPRESSION;
        exp->left = $1;
        exp->right = $3;
        exp->type_info = info;
        $$ = exp;
    }
|   eq-expression EXCL_EQUAL rel-expression {
        t_type_info info;
        info.primitive_type = LONG_TYPE;
        info.data_structure = PRIMITIVE;
        assert($1->type_info.data_structure == PRIMITIVE);
        assert($1->type_info.primitive_type != VOID_TYPE && 
            $1->type_info.primitive_type != STRING_TYPE);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert($3->type_info.primitive_type != VOID_TYPE && 
            $3->type_info.primitive_type != STRING_TYPE);
            
        t_expression* exp = zero_allocate(t_expression);
        exp->type = NOT_EQ_EXPRESSION;
        exp->left = $1;
        exp->right = $3;
        exp->type_info = info;
        $$ = exp;
    }
|   rel-expression {
        $$ = $1;
    }
;

rel-expression:
    rel-expression rel-op shift-expression {
        t_type_info info;
        info.primitive_type = LONG_TYPE;
        info.data_structure = PRIMITIVE;

        if ($2 == IS_IN) {
            assert($1->type_info.data_structure == SET);
            assert($1->type_info.primitive_type != VOID_TYPE && 
                $1->type_info.primitive_type != STRING_TYPE);
            assert($3->type_info.data_structure == PRIMITIVE);
            assert(is_type_equivalent($1->type_info.primitive_type, $3->type_info.primitive_type));
        } else {
            assert($1->type_info.data_structure == PRIMITIVE);
            assert($1->type_info.primitive_type != VOID_TYPE && 
                $1->type_info.primitive_type != STRING_TYPE);
            assert($3->type_info.data_structure == PRIMITIVE);
            assert($3->type_info.primitive_type != VOID_TYPE && 
                $3->type_info.primitive_type != STRING_TYPE);
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->left = $1;
        exp->type = $2;
        exp->right = $3;
        exp->type_info = info;
        $$ = exp;
    }
|   shift-expression {
        $$ = $1;
    }
;

shift-expression:
    shift-expression DOUBLE_LANGLE set-rm-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($1->type_info.primitive_type, LONG_TYPE));
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($3->type_info.primitive_type, LONG_TYPE));

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = $1->type_info;
        exp->left = $1;
        exp->type = LEFT_SHIFT_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   shift-expression DOUBLE_RANGLE set-rm-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($1->type_info.primitive_type, LONG_TYPE));
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($3->type_info.primitive_type, LONG_TYPE));

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = $1->type_info;
        exp->left = $1;
        exp->type = RIGHT_SHIFT_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   set-rm-expression {
        $$ = $1;
    }
;

set-rm-expression:
    set-rm-expression RM_RW add-expression {
        assert($1->type_info.data_structure == SET);
        assert($1->type_info.primitive_type != VOID_TYPE && 
            $1->type_info.primitive_type != STRING_TYPE);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(is_type_equivalent($1->type_info.primitive_type, $3->type_info.primitive_type));

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = $1->type_info;
        exp->left = $1;
        exp->type = RM_EXPRESSION;
        exp->right = $3;
        $$ = exp;
    }
|   add-expression  {
        $$ = $1;
    }
;

add-expression:
    add-expression PLUS mult-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert($1->type_info.primitive_type != VOID_TYPE && 
            $1->type_info.primitive_type != STRING_TYPE);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert($3->type_info.primitive_type != VOID_TYPE && 
            $3->type_info.primitive_type != STRING_TYPE);

        t_type_info info;
        info.data_structure = PRIMITIVE;
        if (is_type_equivalent($1->type_info.primitive_type, DOUBLE_TYPE) ||
            is_type_equivalent($3->type_info.primitive_type, DOUBLE_TYPE)) {
            info.primitive_type = DOUBLE_TYPE;
        } else {
            info.primitive_type = LONG_TYPE;
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = info;
        exp->left = $1;
        exp->type = ADD_PLUS;
        exp->right = $3;
        $$ = exp;
    }
|   add-expression MINUS mult-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert($1->type_info.primitive_type != VOID_TYPE && 
            $1->type_info.primitive_type != STRING_TYPE);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert($3->type_info.primitive_type != VOID_TYPE && 
            $3->type_info.primitive_type != STRING_TYPE);

        t_type_info info;
        info.data_structure = PRIMITIVE;
        if (is_type_equivalent($1->type_info.primitive_type, DOUBLE_TYPE) ||
            is_type_equivalent($3->type_info.primitive_type, DOUBLE_TYPE)) {
            info.primitive_type = DOUBLE_TYPE;
        } else {
            info.primitive_type = LONG_TYPE;
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = info;
        exp->left = $1;
        exp->type = ADD_MINUS;
        exp->right = $3;
        $$ = exp;
    }
|   mult-expression {
        $$ = $1;
    }
;

mult-expression:
    mult-expression mul-op unary-expression {
        assert($1->type_info.data_structure == PRIMITIVE);
        assert($1->type_info.primitive_type != VOID_TYPE && 
            $1->type_info.primitive_type != STRING_TYPE);
        assert($3->type_info.data_structure == PRIMITIVE);
        assert($3->type_info.primitive_type != VOID_TYPE && 
            $3->type_info.primitive_type != STRING_TYPE);

        t_type_info info;
        info.data_structure = PRIMITIVE;
        if (is_type_equivalent($1->type_info.primitive_type, DOUBLE_TYPE) ||
            is_type_equivalent($3->type_info.primitive_type, DOUBLE_TYPE)) {
            info.primitive_type = DOUBLE_TYPE;
        } else {
            info.primitive_type = LONG_TYPE;
        }
        
        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = info;
        exp->left = $1;
        exp->type = $2;
        exp->right = $3;
        $$ = exp;
    }
|   unary-expression {
        $$ = $1;
    }
;

unary-expression:
    unary-op unary-expression {
        t_type_info info;
        if ($1 == UNARY_PLUS || $1 == UNARY_MINUS || $1 == UNARY_EXCL) {
            assert($2->type_info.data_structure == PRIMITIVE);
            assert($2->type_info.primitive_type != VOID_TYPE && 
                $2->type_info.primitive_type != STRING_TYPE);

            if ($1 == UNARY_EXCL) {
                assert(is_type_equivalent($2->type_info.primitive_type, LONG_TYPE) == 1);
            }

            info = $2->type_info;
        } else {
            info.data_structure = PRIMITIVE;
            info.primitive_type = LONG_TYPE;
        }

        t_expression* exp = zero_allocate(t_expression);
        exp->type_info = info;
        exp->type = $1;
        exp->right = $2;
        $$ = exp;
    }
|   cast-expression {
        t_expression* exp = zero_allocate(t_expression);
        exp->type = $1->type;
        exp->value = $1;
        exp->type_info = $1->type_info;
        printf("%d\n", exp->type_info.primitive_type);
        $$ = exp;
    }
;

cast-expression:
    LEFT_PAREN type RIGHT_PAREN LEFT_PAREN expression RIGHT_PAREN {
        assert($5->type_info.data_structure == PRIMITIVE);
        assert($5->type_info.primitive_type != VOID_TYPE && 
               $5->type_info.primitive_type != STRING_TYPE);

        t_cast_expression* exp = zero_allocate(t_cast_expression);

        exp->cast_type = $2;
        exp->right = $5;
        exp->type = CAST_EXPRESSION;
        exp->type_info.primitive_type = $2;
        exp->type_info.data_structure = PRIMITIVE;
        $$ = exp;
    }
|   postfix-expression {
        t_cast_expression* exp = zero_allocate(t_cast_expression);
        exp->left = $1;
        exp->type = $1->type;
        exp->type_info = $1->type_info;
        $$ = exp;
    }
;

postfix-expression:
    identifier LEFT_BRACKET expression RIGHT_BRACKET {
        assert($3->type_info.data_structure == PRIMITIVE);
        assert(
            is_type_equivalent(
                $3->type_info.primitive_type, 
                LONG_TYPE)
            == 1
        );

        assert(is_structure_equivalent($1->declaration, ARRAY) == 1);

        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = ARRAY_ACCESS;
        exp->left = $1;
        exp->member.array_index = $3;

        exp->type_info.primitive_type = get_type_info($1).primitive_type;
        exp->type_info.data_structure = PRIMITIVE;
        $$ = exp;
    }
|   identifier LEFT_PAREN param-vals RIGHT_PAREN {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->type = FUNCTION_CALL;
        exp->left = $1;
        exp->member.function_params = $3;
        
        // TODO: assert param-vals

        assert(is_structure_equivalent($1->declaration, FUNCTION) == 1);

        exp->type_info.primitive_type = get_type_info($1).primitive_type;
        exp->type_info.data_structure = PRIMITIVE;
        $$ = exp;
    }
|   primary-expression {
        t_postfix_expression* exp = zero_allocate(t_postfix_expression);
        exp->primary = $1;
        exp->type = $1->type;
        exp->type_info = $1->type_info;
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

identifier:
    IDENTIFIER {
        st_element_t* element = scope_find(current_scope, $1);
        if (element == NULL) {
            printf("Identifier %s not previously declared\n", $1);
        }
        $$ = element;
    }

primary-expression:
    identifier {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = IDENTIFIER_PRIMARY_EXPRESSION;
        exp->member.identifier = $1;

        if ($1 != NULL) {
            exp->type_info = get_type_info($1);
        } else {
            exp->type_info.primitive_type = LONG_TYPE;
            exp->type_info.data_structure = PRIMITIVE;
        }
        $$ = exp;
    }
|   constant {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        printf("opa constante\n");
        exp->type = CONSTANT_PRIMARY_EXPRESSION;
        exp->member.constant = $1;
        exp->type_info = $1->type_info;
        $$ = exp;
    }
|   STRING {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = STRING_PRIMARY_EXPRESSION;
        exp->member.string = $1;
        exp->type_info.primitive_type = STRING_TYPE;
        exp->type_info.data_structure = PRIMITIVE;
        $$ = exp;
    }
|   LEFT_PAREN expression RIGHT_PAREN {
        t_primary_expression* exp = zero_allocate(t_primary_expression);
        exp->type = NESTED_PRIMARY_EXPRESSION;
        exp->member.expression = $2;
        exp->type_info = $2->type_info;
        $$ = exp;
    }
;

constant:
    INTEGER {
        t_constant* c = zero_allocate(t_constant);
        c->type_info.primitive_type = LONG_TYPE;
        c->type_info.data_structure = PRIMITIVE;
        c->member.integer_val = $1;
    printf("uai %d\n", $1);
        $$ = c;
    }
|   CHAR {
        t_constant* c = zero_allocate(t_constant);
        c->type_info.primitive_type = CHAR_TYPE;
        c->type_info.data_structure = PRIMITIVE;
        c->member.char_val = $1;
        $$ = c;
    }
|   REAL {
        t_constant* c = zero_allocate(t_constant);
        c->type_info.primitive_type = DOUBLE_TYPE;
        c->type_info.data_structure = PRIMITIVE;
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
|   SIZEOF_RW { $$ = UNARY_SIZEOF; }
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

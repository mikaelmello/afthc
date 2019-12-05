#ifndef ABSTRACT_SYNTAX_TREE_H
#define ABSTRACT_SYNTAX_TREE_H

#include <stdint.h>
#include "tac.h"

typedef struct st_element_t st_element_t;
typedef struct tac_operand_t tac_operand_t;
typedef struct t_program t_program;
typedef struct t_declaration_list t_declaration_list;
typedef struct t_declaration t_declaration;
typedef struct t_function t_function;
typedef struct t_function_params t_function_params;
typedef struct t_set t_set;
typedef struct t_variable t_variable;
typedef struct t_brace_enclosed_scope t_brace_enclosed_scope;
typedef struct t_statement_list t_statement_list;
typedef struct t_statement t_statement;
typedef struct t_print t_print;
typedef struct t_scan t_scan;
typedef struct t_return t_return;
typedef struct t_condition t_condition;
typedef struct t_iteration t_iteration;
typedef struct t_type_info t_type_info;
typedef struct t_expression t_expression;
typedef struct t_assignment t_assignment;
typedef struct t_cast_expression t_cast_expression;
typedef struct t_postfix_expression t_postfix_expression;
typedef struct t_primary_expression t_primary_expression;
typedef struct t_identifier t_identifier;
typedef struct t_constant t_constant;
typedef struct t_param_vals t_param_vals;
typedef enum t_expression_type t_expression_type;
typedef enum t_primary_expression_type t_primary_expression_type;
typedef enum t_constant_type t_constant_type;
typedef enum t_postfix_expression_type t_postfix_expression_type;
typedef enum t_assignment_operator t_assignment_operator;
typedef enum t_scan_type t_scan_type;
typedef enum t_print_type t_print_type;
typedef enum t_statement_type t_statement_type;
typedef enum t_declaration_type t_declaration_type;
typedef enum t_primitive_type t_primitive_type;
typedef enum t_structure_type t_structure_type;

enum t_expression_type {
  AND_EXPRESSION = 1,
  OR_EXPRESSION,
  BW_AND_EXPRESSION,
  BW_OR_EXPRESSION,
  BW_XOR_EXPRESSION,
  NOT_EQ_EXPRESSION,
  EQ_EQ_EXPRESSION,
  LESS_THAN,
  GREATER_THAN,
  LESS_THAN_OR_EQUAL,
  GREATER_THAN_OR_EQUAL,
  CAST_EXPRESSION,
  IS_IN,
  LEFT_SHIFT_EXPRESSION,
  ASSIGNMENT_EXPRESSION,
  RIGHT_SHIFT_EXPRESSION,
  RM_EXPRESSION,
  UNARY_PLUS,
  UNARY_MINUS,
  UNARY_EXCL,
  UNARY_SIZEOF,
  ADD_PLUS,
  ADD_MINUS,
  ASTERISK_OPERATOR,
  SLASH_OPERATOR,
  PERCENT_OPERATOR,
  ARRAY_ACCESS,
  FUNCTION_CALL,
  IDENTIFIER_PRIMARY_EXPRESSION,
  CONSTANT_PRIMARY_EXPRESSION,
  STRING_PRIMARY_EXPRESSION,
  NESTED_PRIMARY_EXPRESSION,
};

enum t_primitive_type {
  BYTE_TYPE,
  CHAR_TYPE,
  SHORT_TYPE,
  INT_TYPE,
  LONG_TYPE,
  FLOAT_TYPE,
  DOUBLE_TYPE,
  VOID_TYPE,
  STRING_TYPE,
};

enum t_structure_type {
  PRIMITIVE,
  ARRAY,
  SET,
  FUNCTION,
};

struct t_type_info {
  t_primitive_type primitive_type;
  t_structure_type data_structure;
};

enum t_constant_type {
  INTEGER_CONSTANT,
  CHAR_CONSTANT,
  REAL_CONSTANT,
};

struct t_constant {
  t_type_info type_info;
  tac_operand_t* operand;

  union {
    char* string_val;
    int64_t integer_val;
    double float_val;
    char char_val;
  } member;
};

struct t_primary_expression {
  t_expression_type type;
  t_type_info type_info;
  tac_operand_t* operand;

  union {
    t_assignment* assignment;
    st_element_t* identifier;
    t_constant* constant;
    char* string;
    t_expression* expression;
  } member;
};

struct t_param_vals {
  int size;
  t_expression* cur;
  t_param_vals* prev;
};

struct t_postfix_expression {
  t_expression_type type;
  t_type_info type_info;
  tac_operand_t* operand;

  union {
    t_expression* array_index;
    t_param_vals* function_params;
  } member;

  st_element_t* left;
  t_primary_expression* primary;
};

enum t_assignment_operator {
  EQUAL_OPERATOR,
  PLUS_EQUAL_OPERATOR,
  MINUS_EQUAL_OPERATOR,
  ASTERISK_EQUAL_OPERATOR,
  SLASH_EQUAL_OPERATOR,
  PERCENT_EQUAL_OPERATOR,
};

struct t_assignment {
  tac_operand_t* operand;
  st_element_t* identifier;
  t_type_info type_info;
  t_assignment_operator operator;
  t_expression* expression;
};

struct t_expression {
  tac_operand_t* operand;
  t_expression_type type;
  t_type_info type_info;
  t_expression* left;
  t_expression* right;

  t_cast_expression* value;

  t_assignment* assignment;
};

struct t_cast_expression {
  tac_operand_t* operand;
  t_expression_type type;
  t_type_info type_info;
  t_primitive_type cast_type;
  t_expression* right;
  t_postfix_expression* left;
};

struct t_iteration {
  t_expression* initialization;
  t_expression* condition;
  t_expression* step;

  t_statement* body;
};

struct t_condition {
  t_expression* condition;
  int if_id;

  t_statement* body;
  t_statement* else_body;
};

struct t_return {
  t_expression* expression;
};

enum t_print_type {
  PRINT_CHAR_TYPE,
  PRINT_DEC_TYPE,
  PRINT_HEX_TYPE,
};

struct t_print {
  t_print_type type;
  t_expression* expression;
};

enum t_scan_type {
  SCAN_CHAR_TYPE,
  SCAN_DEC_TYPE,
  SCAN_FLOAT_TYPE,
};

struct t_scan {
  t_scan_type type;
  st_element_t* destiny;
};

enum t_statement_type {
  BRACE_ENCLOSED_SCOPE_STATEMENT,
  VAR_DECLARATION_STATEMENT,
  PRINT_STATEMENT,
  SCAN_STATEMENT,
  EXPRESSION_STATEMENT,
  CONDITION_STATEMENT,
  ITERATION_STATEMENT,
  RETURN_STATEMENT,
};

struct t_statement {
  t_statement_type type;

  union {
    t_brace_enclosed_scope* scope;
    st_element_t* variable;
    t_print* print;
    t_scan* scan;
    t_return* _return;
    t_expression* expression;
    t_condition* condition;
    t_iteration* iteration;
  } member;
};

struct t_brace_enclosed_scope {
  t_statement_list* statements;
};

struct t_statement_list {
  t_statement* cur;
  t_statement_list* prev;
};

enum t_declaration_type {
  VAR_DECLARATION,
  FUN_DECLARATION,
};

struct t_program {
  t_declaration_list* declaration_list;
};

struct t_declaration_list {
  t_declaration_list* prev;
  st_element_t* cur;
};

char* declaration_get_label(t_declaration* declaration);

struct t_declaration {
  t_declaration_type type;

  union {
    t_variable* variable;
    t_function* function;
  } member;
};

struct t_set {};

struct t_function {
  t_type_info type_info;
  char* identifier;
  t_function_params* params;
  t_brace_enclosed_scope* body;
};

struct t_function_params {
  int size;
  st_element_t* cur;
  t_function_params* prev;
};

struct t_function_param {
  t_primitive_type type;
  t_structure_type structure;
  char* identifier;
};

struct t_variable {
  t_type_info type_info;
  int size;
  int addr;
  char* identifier;
};

struct st_element_t {
  int addr;
  t_declaration* declaration;
  st_element_t* next;
};

int is_structure_equivalent(t_declaration* dec, t_structure_type type);
int is_type_equivalent(t_primitive_type type1, t_primitive_type type2);
t_type_info get_type_info(st_element_t* dec);
void spaces(int n);
void print_data_structure(t_structure_type structure, int cur_level);
void print_primitive_type(t_primitive_type type, int cur_level);
void print_fun_params(t_function_params* params, int cur_level);
void print_brace_enclosed_scope(t_brace_enclosed_scope* scope, int cur_level);
void print_statement_list(t_statement_list* list, int cur_level);
void print_statement(t_statement* statement, int cur_level);
void print_expression_type(t_expression_type type, int cur_level);
void print_array_access(t_postfix_expression* expression, int cur_level);
void print_function_call_params(t_param_vals* params, int cur_level);
void print_function_call(t_postfix_expression* expression, int cur_level);
void print_constant(t_constant* constant, int cur_level);
void print_primary_expression(t_primary_expression* expression, int cur_level);
void print_postfix_expression(t_postfix_expression* expression, int cur_level);
void print_cast_expression(t_cast_expression* cast, int cur_level);
void print_expression(t_expression* expression, int cur_level);
void print_condition(t_condition* condition, int cur_level);
void print_iteration(t_iteration* it, int cur_level);
void print_return(t_return* ret, int cur_level);
void print_print_type(t_print_type type, int cur_level);
void print_print(t_print* print, int cur_level);
void print_scan_type(t_scan_type type, int cur_level);
void print_scan(t_scan* scan, int cur_level);
void print_st_element(st_element_t* element, int cur_level, int print_fun_body);
void print_declaration(st_element_t* declaration, int cur_level);
void print_declaration_list(t_declaration_list* list, int cur_level);
void print_program(t_program* program, int cur_level);

void free_fun_params(t_function_params* params);
void free_brace_enclosed_scope(t_brace_enclosed_scope* scope);
void free_statement_list(t_statement_list* list);
void free_statement(t_statement* statement);
void free_array_access(t_postfix_expression* expression);
void free_function_call_params(t_param_vals* params);
void free_function_call(t_postfix_expression* expression);
void free_constant(t_constant* constant);
void free_primary_expression(t_primary_expression* expression);
void free_postfix_expression(t_postfix_expression* expression);
void free_cast_expression(t_cast_expression* cast);
void free_expression(t_expression* expression);
void free_condition(t_condition* condition);
void free_iteration(t_iteration* it);
void free_return(t_return* ret);
void free_print(t_print* print);
void free_scan(t_scan* scan);
void free_declaration(t_declaration* declaration);
void free_declaration_list(t_declaration_list* list);
void free_program(t_program* program);

#endif

#ifndef ABSTRACT_SYNTAX_TREE_H
#define ABSTRACT_SYNTAX_TREE_H

#include <stdint.h>

typedef struct t_program t_program;
typedef struct t_declaration_list t_declaration_list;
typedef struct t_declaration t_declaration;
typedef struct t_function t_function;
typedef struct t_function_param t_function_param;
typedef struct t_function_params t_function_params;
typedef struct t_set t_set;
typedef struct t_variable t_variable;
typedef struct t_scope t_scope;
typedef struct t_statement_list t_statement_list;
typedef struct t_statement t_statement;
typedef struct t_print t_print;
typedef struct t_scan t_scan;
typedef struct t_return t_return;
typedef struct t_expression t_expression;
typedef struct t_condition t_condition;
typedef struct t_iteration t_iteration;
typedef struct t_while t_while;
typedef struct t_for t_for;
typedef struct t_expression t_expression;
typedef struct t_assignment t_assignment;
typedef struct t_and_expression t_and_expression;
typedef struct t_or_expression t_or_expression;
typedef struct t_bw_or_expression t_bw_or_expression;
typedef struct t_bw_xor_expression t_bw_xor_expression;
typedef struct t_bw_and_expression t_bw_and_expression;
typedef struct t_eq_expression t_eq_expression;
typedef struct t_rel_expression t_rel_expression;
typedef struct t_shift_expression t_shift_expression;
typedef struct t_set_rm_expression t_set_rm_expression;
typedef struct t_add_expression t_add_expression;
typedef struct t_mult_expression t_mult_expression;
typedef struct t_cast_expression t_cast_expression;
typedef struct t_unary_expression t_unary_expression;
typedef struct t_postfix_expression t_postfix_expression;
typedef struct t_primary_expression t_primary_expression;
typedef struct t_constant t_constant;
typedef struct t_param_vals t_param_vals;
typedef enum t_primary_expression_type t_primary_expression_type;
typedef enum t_constant_type t_constant_type;
typedef enum t_postfix_expression_type t_postfix_expression_type;
typedef enum t_unary_expression_type t_unary_expression_type;
typedef enum t_add_expression_type t_add_expression_type;
typedef enum t_eq_expression_type t_eq_expression_type;
typedef enum t_shift_expression_type t_shift_expression_type;
typedef enum t_mult_operator t_mult_operator;
typedef enum t_assignment_operator t_assignment_operator;
typedef enum t_iteration_type t_iteration_type;
typedef enum t_scan_type t_scan_type;
typedef enum t_print_type t_print_type;
typedef enum t_statement_type t_statement_type;
typedef enum t_declaration_type t_declaration_type;
typedef enum t_primitive_type t_primitive_type;
typedef enum t_structure_type t_structure_type;
typedef enum t_rel_expression_type t_rel_expression_type;

typedef enum node_type {
  NT_PRIMARY_EXPRESSION_TYPE,
  NT_CONSTANT_TYPE,
  NT_POSTFIX_EXPRESSION_TYPE,
  NT_UNARY_EXPRESSION_TYPE,
  NT_ADD_EXPRESSION_TYPE,
  NT_EQ_EXPRESSION_TYPE,
  NT_SHIFT_EXPRESSION_TYPE,
  NT_REL_EXPRESSION_TYPE,
  NT_MULT_OPERATOR,
  NT_ASSIGNMENT_OPERATOR,
  NT_ITERATION_TYPE,
  NT_PRIMITIVE_TYPE,
  NT_PRINT_TYPE,
  NT_SCAN_TYPE,
  NT_PROGRAM,
  NT_DECLARATION_LIST,
  NT_DECLARATION,
  NT_VARIABLE,
  NT_FUNCTION,
  NT_FUNCTION_PARAM,
  NT_FUNCTION_PARAMS,
  NT_SCOPE,
  NT_STATEMENT_LIST,
  NT_STATEMENT,
  NT_PRINT,
  NT_SCAN,
  NT_RETURN,
  NT_EXPRESSION,
  NT_CONDITION,
  NT_ITERATION,
  NT_WHILE,
  NT_FOR,
  NT_ASSIGNMENT,
  NT_AND_EXPRESSION,
  NT_OR_EXPRESSION,
  NT_BW_OR_EXPRESSION,
  NT_BW_XOR_EXPRESSION,
  NT_BW_AND_EXPRESSION,
  NT_EQ_EXPRESSION,
  NT_REL_EXPRESSION,
  NT_SHIFT_EXPRESSION,
  NT_SET_RM_EXPRESSION,
  NT_ADD_EXPRESSION,
  NT_MULT_EXPRESSION,
  NT_CAST_EXPRESSION,
  NT_UNARY_EXPRESSION,
  NT_POSTFIX_EXPRESSION,
  NT_PRIMARY_EXPRESSION,
  NT_CONSTANT,
  NT_PARAM_VALS,
  NT_STRING,
  NT_INTEGER,
  NT_DOUBLE,
  NT_CHAR,
  NT_IDENTIFIER,
} node_type;

enum t_rel_expression_type {
  LESS_THAN,
  GREATER_THAN,
  LESS_THAN_OR_EQUAL,
  GREATER_THAN_OR_EQUAL,
  IS_IN,
};

enum t_primitive_type {
  BYTE_TYPE,
  SHORT_TYPE,
  INT_TYPE,
  LONG_TYPE,
  FLOAT_TYPE,
  DOUBLE_TYPE,
  VOID_TYPE,
};

enum t_primary_expression_type {
  IDENTIFIER_PRIMARY_EXPRESSION,
  CONSTANT_PRIMARY_EXPRESSION,
  STRING_PRIMARY_EXPRESSION,
  NESTED_PRIMARY_EXPRESSION,
};

enum t_constant_type {
  INTEGER_CONSTANT,
  CHAR_CONSTANT,
  REAL_CONSTANT,
};

struct t_constant {
  t_constant_type type;

  union {
    char* string_val;
    int64_t integer_val;
    double float_val;
    char char_val;
  } member;
};

struct t_primary_expression {
  t_primary_expression_type type;

  union {
    char* identifier;
    t_constant* constant;
    char* string;
    t_expression* expression;
  } member;
};

struct t_param_vals {
  t_expression* cur;
  t_param_vals* prev;
};

enum t_postfix_expression_type { ARRAY_ACCESS, FUNCTION_CALL };

enum t_unary_expression_type {
  UNARY_PLUS,
  UNARY_MINUS,
  UNARY_EXCL,
  UNARY_SIZEOF
};

enum t_add_expression_type {
  ADD_PLUS,
  ADD_MINUS,
};

enum t_eq_expression_type {
  EQ_EQ_EXPRESSION,
  NOT_EQ_EXPRESSION,
};

enum t_shift_expression_type {
  LEFT_SHIFT_EXPRESSION,
  RIGHT_SHIFT_EXPRESSION,
};

struct t_postfix_expression {
  t_postfix_expression_type type;

  union {
    t_expression* array_index;
    t_param_vals* function_params;
  } member;

  t_postfix_expression* left;
  t_primary_expression* primary;
};

struct t_unary_expression {
  t_unary_expression_type type;

  t_unary_expression* left;
  t_postfix_expression* right;
};

struct t_cast_expression {
  t_primitive_type type;

  t_cast_expression* left;
  t_unary_expression* right;
};

enum t_mult_operator {
  ASTERISK_OPERATOR,
  SLASH_OPERATOR,
  PERCENT_OPERATOR,
};

struct t_mult_expression {
  t_mult_operator type;

  t_mult_expression* left;
  t_cast_expression* right;
};

struct t_add_expression {
  t_add_expression_type type;

  t_add_expression* left;
  t_mult_expression* right;
};

struct t_set_rm_expression {
  t_set_rm_expression* left;
  t_add_expression* right;
};

struct t_shift_expression {
  t_shift_expression_type type;
  t_shift_expression* left;
  t_set_rm_expression* right;
};

struct t_rel_expression {
  t_rel_expression_type type;

  t_rel_expression* left;
  t_shift_expression* right;
};

struct t_eq_expression {
  t_eq_expression_type type;

  t_eq_expression* left;
  t_rel_expression* right;
};

struct t_bw_xor_expression {
  t_bw_xor_expression* left;
  t_eq_expression* right;
};

struct t_bw_and_expression {
  t_bw_and_expression* left;
  t_bw_or_expression* right;
};

struct t_bw_or_expression {
  t_bw_or_expression* left;
  t_bw_xor_expression* right;
};

struct t_or_expression {
  t_or_expression* left;
  t_bw_and_expression* right;
};

struct t_and_expression {
  t_and_expression* left;
  t_or_expression* right;
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
  char* identifier;
  t_assignment_operator operator;
  t_and_expression* and_expression;
};

struct t_expression {
  t_assignment* assignment;
};

enum t_iteration_type {
  FOR_ITERATION,
  WHILE_ITERATION,
};

struct t_while {
  t_expression* condition;

  t_statement* body;
};

struct t_for {
  t_expression* initialization;
  t_expression* condition;
  t_expression* step;

  t_statement* body;
};

struct t_iteration {
  t_iteration_type type;

  union {
    t_while* _while;
    t_for* _for;
  } member;
};

struct t_condition {
  t_expression* condition;

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
  char* destiny;
};

enum t_statement_type {
  SCOPE_STATEMENT,
  DECLARATION_STATEMENT,
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
    t_scope* scope;
    t_declaration* declaration;
    t_print* print;
    t_scan* scan;
    t_return* _return;
    t_expression* expression;
    t_condition* condition;
    t_iteration* iteration;
  } member;
};

struct t_scope {
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

enum t_structure_type {
  PRIMITIVE_TYPE,
  ARRAY_TYPE,
  SET_TYPE,
};

struct t_program {
  t_declaration_list* declarations;
};

struct t_declaration_list {
  t_declaration_list* prev;
  t_declaration* cur;
};

struct t_declaration {
  t_declaration_type type;

  union {
    t_variable* variable;
    t_function* function;
  } member;
};

struct t_set {};

struct t_function {
  t_primitive_type return_type;
  t_structure_type return_structure;
  char* identifier;
  t_function_params* params;
  t_scope* body;

  union {
    int8_t (*byte_function)();
    int16_t (*short_function)();
    int32_t (*int_function)();
    int64_t (*long_function)();

    int8_t* (*array_byte_function)();
    int16_t* (*array_short_function)();
    int32_t* (*array_int_function)();
    int64_t* (*array_long_function)();

    t_set* (*set_function)();

    float (*float_function)();
    double (*double_function)();
  } member;
};

struct t_function_params {
  t_function_param* cur;
  t_function_params* prev;
};

struct t_function_param {
  t_primitive_type type;
  t_structure_type structure;
  char* identifier;
};

struct t_variable {
  t_primitive_type type;
  t_structure_type structure;
  char* identifier;

  union {
    int8_t byte_val;
    int16_t short_val;
    int32_t int_val;
    int64_t long_val;

    int8_t* array_byte_val;
    int16_t* array_short_val;
    int32_t* array_int_val;
    int64_t* array_long_val;

    t_set* set_val;

    float float_val;
    double double_val;
  } member;
};

typedef union node {
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
} node;

#endif

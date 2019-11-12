#ifndef ABSTRACT_SYNTAX_TREE_H
#define ABSTRACT_SYNTAX_TREE_H

#include <stdint.h>

typedef struct t_program t_program;
typedef struct t_declaration_list t_declaration_list;
typedef struct t_declaration t_declaration;
typedef struct t_function t_function;
typedef struct t_function_params t_function_params;
typedef struct t_set t_set;
typedef struct t_variable t_variable;
typedef struct t_scope t_scope;
typedef struct t_statement_list t_statement_list;
typedef struct t_statement t_statement;
typedef struct t_print t_print;
typedef struct t_scan t_scan;
typedef struct t_return t_return;
typedef struct t_condition t_condition;
typedef struct t_iteration t_iteration;
typedef struct t_expression t_expression;
typedef struct t_assignment t_assignment;
typedef struct t_cast_expression t_cast_expression;
typedef struct t_postfix_expression t_postfix_expression;
typedef struct t_primary_expression t_primary_expression;
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

typedef enum node_type {
  NT_PRIMARY_EXPRESSION_TYPE,
  NT_CONSTANT_TYPE,
  NT_POSTFIX_EXPRESSION_TYPE,
  NT_ASSIGNMENT_OPERATOR,
  NT_PRIMITIVE_TYPE,
  NT_PRINT_TYPE,
  NT_SCAN_TYPE,
  NT_PROGRAM,
  NT_DECLARATION_LIST,
  NT_DECLARATION,
  NT_VARIABLE,
  NT_FUNCTION,
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
  NT_ASSIGNMENT,
  NT_CAST_EXPRESSION,
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
    t_assignment* assignment;
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

struct t_postfix_expression {
  t_postfix_expression_type type;

  union {
    t_expression* array_index;
    t_param_vals* function_params;
  } member;

  t_postfix_expression* left;
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
  char* identifier;
  t_assignment_operator operator;
  t_expression* expression;
};

enum t_expression_type {
  AND_EXPRESSION,
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
};

struct t_expression {
  t_expression_type type;
  t_expression* left;
  t_expression* right;

  t_cast_expression* value;

  t_assignment* assignment;
};

struct t_cast_expression {
  int cast;
  t_primitive_type cast_type;
  t_postfix_expression* right;
};

struct t_iteration {
  t_expression* initialization;
  t_expression* condition;
  t_expression* step;

  t_statement* body;
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
    t_scope* scope;
    t_variable* variable;
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
  t_declaration_list* declaration_list;
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
  t_variable* cur;
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
  t_scope* c_scope;
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
  t_constant* c_constant;
  t_param_vals* c_param_vals;
  t_expression_type c_expression_type;
  char* string_val;
  int64_t integer_val;
  double float_val;
  char char_val;
} node;

#endif

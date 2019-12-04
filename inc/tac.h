#ifndef TAC_H
#define TAC_H

#include "abstract_syntax_tree.h"

typedef char* tac_symbol_t;
typedef struct tac_line_t tac_line_t;
typedef struct tac_operand_t tac_operand_t;
typedef struct tac_program_t tac_program_t;
typedef struct tac_table_t tac_table_t;
typedef struct tac_code_t tac_code_t;
typedef struct tac_label_t tac_label_t;
typedef enum tac_instr_t tac_instr_t;
typedef enum tac_operand_type_t tac_operand_type_t;

tac_program_t* tac_program_create();
void tac_program_initialize(tac_program_t* program);
void tac_program_clean(tac_program_t* program);
void tac_program_print(tac_program_t* program);
int tac_program_add_label(tac_program_t* program, char* name);
int tac_program_add_line(tac_program_t* program, tac_instr_t instr,
                         tac_operand_t* operands[3]);
tac_label_t* tac_program_get_label(tac_program_t* program, int label_id);

void tac_program_if_start_label(tac_program_t* program);
void tac_program_if_end_label(tac_program_t* program);

void tac_table_initialize(tac_table_t* table);
void tac_table_clean(tac_table_t* table);
void tac_table_print(tac_table_t* table);

void tac_code_initialize(tac_code_t* code);
void tac_code_clean(tac_code_t* code);
void tac_code_print(tac_code_t* code);

void tac_label_free_members(tac_label_t* label);
void tac_label_print(tac_label_t* print);

void tac_line_print(tac_line_t* line);
void tac_line_free_members(tac_line_t* line);

tac_operand_t* tac_operand_stack_at(int idx);
tac_operand_t* tac_operand_int_constant(int value);
tac_operand_t* tac_operand_char_constant(char value);
tac_operand_t* tac_operand_float_constant(double value);
tac_operand_t* tac_operand_temp(int id);
tac_operand_t* tac_operand_access(tac_operand_t* op);
tac_operand_t* tac_operand_dup(tac_operand_t* op);
void tac_operand_free(tac_operand_t* operand);
void tac_operand_print(tac_operand_t* operand);

struct tac_table_t {};

struct tac_code_t {
  int line_count;
  int line_capacity;
  tac_line_t* lines;

  int label_count;
  int label_capacity;
  tac_label_t* labels;
};

struct tac_program_t {
  tac_table_t table;
  tac_code_t code;
  int stack_head;
};

void gen_condition();

enum tac_instr_t {
  // logic/arithmetic
  ADD_INSTR,
  SUB_INSTR,
  MUL_INSTR,
  DIV_INSTR,
  AND_INSTR,
  OR_INSTR,
  MINUS_INSTR,
  NOT_INSTR,
  BAND_INSTR,
  BOR_INSTR,
  BXOR_INSTR,
  SHL_INSTR,
  SHR_INSTR,
  BNOT_INSTR,
  MOD_INSTR,
  // relational
  SEQ_INSTR,
  SLT_INSTR,
  SLEQ_INSTR,
  // type conversion
  CHTOINT_INSTR,
  CHTOFL_INSTR,
  INTTOFL_INSTR,
  INTTOCH_INSTR,
  FLTOCH_INSTR,
  FLTOINT_INSTR,
  // attr
  MOV_INSTR,
  // flow control
  BRZ_INSTR,
  BRNZ_INSTR,
  JUMP_INSTR,
  // stack
  PUSH_INSTR,
  POP_INSTR,
  // functions
  PARAM_INSTR,
  CALL_INSTR,
  RETURN_INSTR,
  // sys calls
  PRINT_INSTR,
  PRINTLN_INSTR,
  SCANC_INSTR,
  SCANI_INSTR,
  SCANF_INSTR,
  MEMA_INSTR,
  MEMF_INSTR,
  RAND_INSTR,
};

enum tac_operand_type_t {
  FUN_PARAM,
  TEMP_VAR,
  LABEL,
  INT_CONSTANT,
  CCHAR_CONSTANT,
  FLOAT_CONSTANT,
  STACK,
  ACCESS,
};

struct tac_label_t {
  char* name;
  int position;
  int id;
};

struct tac_line_t {
  tac_instr_t instruction;
  tac_operand_t* operands[3];
};

struct tac_operand_t {
  tac_operand_type_t type;

  union {
    int fun_param;
    int temp_var;
    tac_label_t* label;
    tac_operand_t* access;
    int int_constant;
    char char_constant;
    double float_constant;
  } value;
};

#endif

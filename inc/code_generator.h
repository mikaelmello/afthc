#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

int condition_counter;
int iteration_counter;

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
void tac_program_free(tac_program_t* program);
void tac_program_add_label(tac_program_t* program, char* name);
void tac_program_print(tac_program_t* program);

tac_table_t* tac_table_create();
void tac_table_free(tac_table_t* table);
void tac_table_print(tac_table_t* table);

tac_code_t* tac_code_create();
void tac_code_free(tac_code_t* code);
void tac_code_print(tac_code_t* code);

void tac_line_print(tac_line_t* line);

struct tac_program_t {
  tac_table_t* table;
  tac_code_t* code;
};

struct tac_table_t {};

struct tac_code_t {
  int line_count;
  int line_capacity;
  tac_line_t* lines;

  int label_count;
  int label_capacity;
  tac_label_t* labels;
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
  SYMBOL,
  CONSTANT,
};

struct tac_label_t {
  char* name;
  int position;
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
    tac_label_t label;
    tac_symbol_t symbol;
  } value;
};

#endif

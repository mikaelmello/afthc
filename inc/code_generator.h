#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

typedef struct taddr_line_t taddr_line_t;
typedef enum taddr_instr_t taddr_instr_t;

enum taddr_instr_t {
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

struct taddr_line_t {};

#endif

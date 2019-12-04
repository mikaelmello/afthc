#include "code_generator.h"
#include <memory.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "abstract_syntax_tree.h"
#include "my_string.h"
#include "tac.h"

extern tac_program_t tac_program;

int gen_fun_label(char* name) {
  return tac_program_add_label(&tac_program, name);
}
int get_stack_head() { return tac_program.stack_head; }

void gen_return(t_expression* expression) {
  tac_operand_t* operands[3] =
      /* get operand from expression */ {NULL, NULL, NULL};

  tac_program_add_line(&tac_program, RETURN_INSTR, operands);
}

int gen_push(int value) {
  tac_operand_t* operands[3] = {
      tac_operand_constant(value),
      NULL,
      NULL,
  };

  int addr = tac_program.stack_head;
  tac_program_add_line(&tac_program, PUSH_INSTR, operands);
  tac_program.stack_head++;
  return addr;
}

int gen_pop() {
  tac_operand_t* operands[3] = {
      tac_operand_temp(1023),
      NULL,
      NULL,
  };

  tac_program_add_line(&tac_program, POP_INSTR, operands);
  tac_program.stack_head--;
  return tac_program.stack_head;
}

int gen_primitive_declaration() { return gen_push(0); }

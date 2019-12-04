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

void gen_return(t_expression* expression) {
  tac_operand_t* operands[3] =
      /* get operand from expression */ {NULL, NULL, NULL};

  tac_program_add_line(&tac_program, RETURN_INSTR, operands);
}

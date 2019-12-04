#include "code_generator.h"
#include <memory.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "abstract_syntax_tree.h"
#include "my_string.h"
#include "tac.h"

extern tac_program_t tac_program;

int temp = 0;

int new_temp() {
  int old = temp;
  temp = (temp + 1) % 1024;
  return old;
}

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

void gen_assignment(t_assignment* assignment) {
  int varpos = assignment->identifier->declaration->member.variable->addr;

  if (assignment->operator== EQUAL_OPERATOR) {
    tac_operand_t* operands[3] = {
        tac_operand_stack_at(varpos),
        tac_operand_temp(assignment->expression->addr),
        NULL,
    };
    tac_program_add_line(&tac_program, MOV_INSTR, operands);
    return;
  }

  tac_operand_t* operands[3] = {
      tac_operand_stack_at(varpos),
      tac_operand_stack_at(varpos),
      tac_operand_temp(assignment->expression->addr),
  };

  switch (assignment->operator) {
    case PLUS_EQUAL_OPERATOR:
      tac_program_add_line(&tac_program, ADD_INSTR, operands);
      break;
    case MINUS_EQUAL_OPERATOR:
      tac_program_add_line(&tac_program, MINUS_INSTR, operands);
      break;
    case ASTERISK_EQUAL_OPERATOR:
      tac_program_add_line(&tac_program, MUL_INSTR, operands);
      break;
    case SLASH_EQUAL_OPERATOR:
      tac_program_add_line(&tac_program, DIV_INSTR, operands);
      break;
    case PERCENT_EQUAL_OPERATOR:
      tac_program_add_line(&tac_program, MOD_INSTR, operands);
      break;
    default:
      break;
  }
}

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

tac_operand_t* new_temp() {
  int old = temp;
  temp = (temp + 1) % 1024;
  return tac_operand_temp(old);
}

int gen_fun_label(char* name) {
  return tac_program_add_label(&tac_program, name);
}

int reset_stack_head() {
  temp = 0;
  return tac_program.stack_head = 0;
}
int get_stack_head() { return tac_program.stack_head; }

void gen_return(t_function* fun, t_return* ret) {
  int jumpra = 1;
  if (strcmp("main", fun->identifier) == 0) {
    jumpra = 0;
  }

  if (jumpra == 1) {
    tac_operand_t* operands[3] = {
        (ret == NULL || ret->expression == NULL ? NULL
                                                : ret->expression->operand),
        NULL, NULL};

    if (fun->type_info.primitive_type != VOID_TYPE && operands[0] == NULL) {
      operands[0] = tac_operand_int_constant(0);
    }
    tac_program_add_line(&tac_program, RETURN_INSTR, operands);
  }
}

int gen_push(int value) {
  tac_operand_t* operands[3] = {
      tac_operand_int_constant(value),
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

tac_operand_t* gen_mema(int size) {
  tac_operand_t* newt = new_temp();
  tac_operand_t* operands[3] = {
      tac_operand_dup(newt),
      tac_operand_int_constant(size),
      NULL,
  };

  tac_program_add_line(&tac_program, MEMA_INSTR, operands);
  return newt;
}

int gen_array_declaration(int size) {
  tac_operand_t* mema = gen_mema(size);
  tac_operand_t* operands[3] = {
      mema,
      NULL,
      NULL,
  };

  int addr = tac_program.stack_head;
  tac_program_add_line(&tac_program, PUSH_INSTR, operands);
  tac_program.stack_head++;
  return addr;
}

// int gen_set_declaration() {
//   tac_operand_t* mema = gen_mema(size);
//   tac_operand_t* operands[3] = {
//       mema,
//       NULL,
//       NULL,
//   };

//   int addr = tac_program.stack_head;
//   tac_program_add_line(&tac_program, PUSH_INSTR, operands);
//   tac_program.stack_head++;
//   return addr;
// }

tac_operand_t* gen_assignment(t_assignment* assignment) {
  if (assignment == NULL || assignment->identifier == NULL) return NULL;
  int varpos = assignment->identifier->declaration->member.variable->addr;

  if (assignment->operator== EQUAL_OPERATOR) {
    tac_operand_t* operands[3] = {
        tac_operand_stack_at(varpos),
        assignment->expression->operand,
        NULL,
    };
    tac_program_add_line(&tac_program, MOV_INSTR, operands);
    return tac_operand_stack_at(varpos);
  }

  tac_operand_t* operands[3] = {
      tac_operand_stack_at(varpos),
      tac_operand_stack_at(varpos),
      assignment->expression->operand,
  };

  switch (assignment->operator) {
    case PLUS_EQUAL_OPERATOR:
      tac_program_add_line(&tac_program, ADD_INSTR, operands);
      break;
    case MINUS_EQUAL_OPERATOR:
      tac_program_add_line(&tac_program, SUB_INSTR, operands);
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

  return tac_operand_stack_at(varpos);
}

tac_operand_t* gen_cast(t_cast_expression* exp) {
  if (exp->right->type_info.primitive_type == exp->cast_type)
    return exp->operand;

  tac_instr_t instr;
  if (exp->cast_type == CHAR_TYPE) {
    if (exp->right->type_info.primitive_type == LONG_TYPE) {
      instr = INTTOCH_INSTR;
    } else {
      instr = FLTOCH_INSTR;
    }
  } else if (exp->cast_type == LONG_TYPE) {
    if (exp->right->type_info.primitive_type == DOUBLE_TYPE) {
      instr = FLTOINT_INSTR;
    } else {
      instr = CHTOINT_INSTR;
    }
  } else if (exp->cast_type == DOUBLE_TYPE) {
    if (exp->right->type_info.primitive_type == LONG_TYPE) {
      instr = INTTOFL_INSTR;
    } else {
      instr = CHTOFL_INSTR;
    }
  }

  tac_operand_t* operands[3] = {
      exp->right->operand,
      tac_operand_dup(exp->right->operand),
      NULL,
  };
  tac_program_add_line(&tac_program, instr, operands);

  return tac_operand_dup(exp->right->operand);
}

tac_operand_t* gen_unary(t_expression* exp) {
  if (exp->type == UNARY_PLUS) return exp->right->operand;

  tac_instr_t instr;
  if (exp->type == UNARY_MINUS)
    instr = MINUS_INSTR;
  else
    instr = NOT_INSTR;

  tac_operand_t* operands[3] = {
      exp->right->operand,
      tac_operand_dup(exp->right->operand),
      NULL,
  };
  tac_program_add_line(&tac_program, instr, operands);

  return tac_operand_dup(exp->right->operand);
}

tac_operand_t* gen_mult(t_expression* exp) {
  if (exp->type_info.primitive_type == DOUBLE_TYPE) {
    if (exp->left->type_info.primitive_type != DOUBLE_TYPE) {
      tac_operand_t* operands[3] = {
          exp->left->operand,
          tac_operand_dup(exp->left->operand),
          NULL,
      };
      tac_program_add_line(&tac_program, INTTOFL_INSTR, operands);
      exp->left->operand = tac_operand_dup(exp->left->operand);
    } else if (exp->right->type_info.primitive_type != DOUBLE_TYPE) {
      tac_operand_t* operands[3] = {
          exp->right->operand,
          tac_operand_dup(exp->right->operand),
          NULL,
      };
      tac_program_add_line(&tac_program, INTTOFL_INSTR, operands);
      exp->right->operand = tac_operand_dup(exp->right->operand);
    }
  }

  tac_operand_t* newt = new_temp();
  tac_operand_t* operands[3] = {
      tac_operand_dup(newt),
      exp->left->operand,
      exp->right->operand,
  };

  tac_instr_t instr;
  if (exp->type == ASTERISK_OPERATOR)
    instr = MUL_INSTR;
  else if (exp->type == SLASH_OPERATOR)
    instr = DIV_INSTR;
  else
    instr = MOD_INSTR;
  tac_program_add_line(&tac_program, instr, operands);
  return newt;
}

tac_operand_t* gen_add(t_expression* exp) {
  if (exp->type_info.primitive_type == DOUBLE_TYPE) {
    if (exp->left->type_info.primitive_type != DOUBLE_TYPE) {
      tac_operand_t* operands[3] = {
          exp->left->operand,
          tac_operand_dup(exp->left->operand),
          NULL,
      };
      tac_program_add_line(&tac_program, INTTOFL_INSTR, operands);
      exp->left->operand = tac_operand_dup(exp->left->operand);
    } else if (exp->right->type_info.primitive_type != DOUBLE_TYPE) {
      tac_operand_t* operands[3] = {
          exp->right->operand,
          tac_operand_dup(exp->right->operand),
          NULL,
      };
      tac_program_add_line(&tac_program, INTTOFL_INSTR, operands);
      exp->right->operand = tac_operand_dup(exp->right->operand);
    }
  }

  tac_operand_t* newt = new_temp();
  tac_operand_t* operands[3] = {
      tac_operand_dup(newt),
      exp->left->operand,
      exp->right->operand,
  };

  tac_instr_t instr;
  if (exp->type == ADD_PLUS)
    instr = ADD_INSTR;
  else
    instr = SUB_INSTR;
  tac_program_add_line(&tac_program, instr, operands);
  return newt;
}

tac_operand_t* gen_shift(t_expression* exp) {
  tac_operand_t* newt = new_temp();
  tac_operand_t* operands[3] = {
      tac_operand_dup(newt),
      exp->left->operand,
      exp->right->operand,
  };

  tac_instr_t instr;
  if (exp->type == RIGHT_SHIFT_EXPRESSION)
    instr = SHR_INSTR;
  else
    instr = SHL_INSTR;
  tac_program_add_line(&tac_program, instr, operands);
  return newt;
}

tac_operand_t* gen_rel(t_expression* exp) {
  tac_operand_t* newt = new_temp();
  tac_operand_t* operands[3] = {
      tac_operand_dup(newt),
      exp->left->operand,
      exp->right->operand,
  };

  tac_instr_t instr;
  if (exp->type == LESS_THAN) {
    instr = SLT_INSTR;
  } else if (exp->type == GREATER_THAN) {
    tac_operand_t* temp = operands[1];
    operands[1] = operands[2];
    operands[2] = temp;
    instr = SLT_INSTR;
  } else if (exp->type == LESS_THAN_OR_EQUAL) {
    instr = SLEQ_INSTR;
  } else if (exp->type == GREATER_THAN_OR_EQUAL) {
    tac_operand_t* temp = operands[1];
    operands[1] = operands[2];
    operands[2] = temp;
    instr = SLEQ_INSTR;
  } else if (exp->type == EQ_EQ_EXPRESSION || exp->type == NOT_EQ_EXPRESSION) {
    instr = SEQ_INSTR;
  }

  tac_program_add_line(&tac_program, instr, operands);

  if (exp->type == NOT_EQ_EXPRESSION) {
    tac_operand_t* operands2[3] = {tac_operand_dup(newt), tac_operand_dup(newt),
                                   NULL};
    tac_program_add_line(&tac_program, NOT_INSTR, operands2);
  }

  return newt;
}

tac_operand_t* gen_bw(t_expression* exp) {
  tac_operand_t* newt = new_temp();
  tac_operand_t* operands[3] = {
      tac_operand_dup(newt),
      exp->left->operand,
      exp->right->operand,
  };

  tac_instr_t instr;
  if (exp->type == BW_XOR_EXPRESSION) {
    instr = BXOR_INSTR;
  } else if (exp->type == BW_OR_EXPRESSION) {
    instr = BOR_INSTR;
  } else if (exp->type == BW_AND_EXPRESSION) {
    instr = BAND_INSTR;
  }

  tac_program_add_line(&tac_program, instr, operands);

  return newt;
}

tac_operand_t* gen_logical(t_expression* exp) {
  tac_operand_t* newt = new_temp();
  tac_operand_t* operands[3] = {
      tac_operand_dup(newt),
      exp->left->operand,
      exp->right->operand,
  };

  tac_instr_t instr;
  if (exp->type == AND_EXPRESSION) {
    instr = AND_INSTR;
  } else if (exp->type == OR_EXPRESSION) {
    instr = OR_INSTR;
  }

  tac_program_add_line(&tac_program, instr, operands);

  return newt;
}

tac_operand_t* gen_array_access(t_postfix_expression* exp) {
  tac_operand_t* newt = new_temp();
  tac_operand_t* addr_pos =
      tac_operand_stack_at(exp->left->declaration->member.variable->addr);

  tac_operand_t* operands[3];
  operands[0] = tac_operand_dup(newt);
  operands[1] = tac_operand_access(tac_operand_dup(addr_pos),
                                   exp->member.array_index->operand);
  operands[2] = NULL;

  // newt now points to our element
  tac_program_add_line(&tac_program, MOV_INSTR, operands);
  return newt;
}

void gen_print(t_print* p) {
  tac_operand_t* operands[3] = {p->expression->operand, NULL, NULL};

  // newt now points to our element
  tac_program_add_line(&tac_program, PRINTLN_INSTR, operands);
}

void gen_scan(t_scan* s) {
  tac_operand_t* addr_pos =
      tac_operand_stack_at(s->destiny->declaration->member.variable->addr);
  tac_operand_t* operands[3] = {addr_pos, NULL, NULL};

  tac_instr_t instr;
  if (s->type == SCAN_DEC_TYPE) {
    instr = SCANI_INSTR;
  } else if (s->type == SCAN_CHAR_TYPE) {
    instr = SCANC_INSTR;
  } else {
    instr = SCANF_INSTR;
  }

  // newt now points to our element
  tac_program_add_line(&tac_program, instr, operands);
}

void gen_pop_array(t_variable* var) {
  tac_operand_t* addr_pos = tac_operand_stack_at(var->addr);
  gen_memf(addr_pos);

  gen_pop();
}

void gen_param_push(t_param_vals* param) {
  if (param == NULL) return;

  gen_param_push(param->prev);

  tac_operand_t* operands[3] = {
      param->cur->operand,
      NULL,
      NULL,
  };

  tac_program_add_line(&tac_program, PUSH_INSTR, operands);
}

void gen_memf(tac_operand_t* operand) {
  tac_operand_t* operands[3] = {operand, NULL, NULL};
  tac_program_add_line(&tac_program, MEMF_INSTR, operands);
}

tac_operand_t* gen_fun_call(t_function* fun, t_param_vals* params) {
  gen_param_push(params);

  tac_label_t* fun_label =
      tac_program_get_label_name(&tac_program, fun->identifier);
  tac_operand_t* operands[3] = {
      tac_operand_label(fun_label),
      tac_operand_int_constant(params->size),
      NULL,
  };

  tac_program_add_line(&tac_program, CALL_INSTR, operands);

  tac_operand_t* newt = new_temp();
  operands[0] = tac_operand_dup(newt);
  operands[1] = NULL;
  tac_program_add_line(&tac_program, POP_INSTR, operands);
  return newt;
}

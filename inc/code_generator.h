#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "abstract_syntax_tree.h"

int get_stack_head();

int gen_fun_label(char* name);
void gen_return(t_return* ret);
int gen_push(int value);
int gen_pop();
int gen_primitive_declaration();
int gen_array_declaration(int size);

tac_operand_t* gen_mult(t_expression* exp);
tac_operand_t* gen_add(t_expression* exp);
tac_operand_t* gen_unary(t_expression* exp);
tac_operand_t* gen_shift(t_expression* exp);
tac_operand_t* gen_rel(t_expression* exp);
tac_operand_t* gen_bw(t_expression* exp);
tac_operand_t* gen_logical(t_expression* exp);
tac_operand_t* gen_cast(t_cast_expression* exp);
tac_operand_t* gen_assignment(t_assignment* assignment);
tac_operand_t* gen_array_access(t_postfix_expression* exp);
tac_operand_t* gen_mema(int size);

#endif

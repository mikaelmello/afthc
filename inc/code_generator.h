#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "abstract_syntax_tree.h"

int reset_stack_head();
int get_stack_head();

int gen_fun_label(char* name);
int gen_push(int value);
int gen_pop();
int gen_primitive_declaration();
int gen_array_declaration(int size);
int gen_set_declaration();
void gen_print(t_print* p);
void gen_scan(t_scan* s);

void gen_return(t_function* fun, t_return* ret);
tac_operand_t* gen_mult(t_expression* exp);
tac_operand_t* gen_add(t_expression* exp);
tac_operand_t* gen_unary(t_expression* exp);
void gen_condition(t_condition* exp);
void gen_if_midlabel(t_condition* exp);
void gen_if_endlabel(t_condition* exp);
tac_operand_t* gen_shift(t_expression* exp, int is_set);
tac_operand_t* gen_rel(t_expression* exp);
tac_operand_t* gen_bw(t_expression* exp);
tac_operand_t* gen_rm(t_expression* exp);
tac_operand_t* gen_logical(t_expression* exp);
tac_operand_t* gen_fun_call(t_function* fun, t_param_vals* params);
tac_operand_t* gen_cast(t_cast_expression* exp);
tac_operand_t* gen_assignment(t_assignment* assignment);
tac_operand_t* gen_array_access(t_postfix_expression* exp);
tac_operand_t* gen_mema(int size);

void gen_pop_array(t_variable* var);
void gen_memf(tac_operand_t* operand);

#endif

#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "abstract_syntax_tree.h"

int get_stack_head();

int gen_fun_label(char* name);
void gen_return(t_return* ret);
int gen_push(int value);
int gen_pop();
int gen_primitive_declaration();
void gen_assignment(t_assignment* assignment);

#endif

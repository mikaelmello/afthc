#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "abstract_syntax_tree.h"

int get_stack_head();

int gen_fun_label(char* name);
void gen_return(t_expression* expression);
int gen_push(int value);
int gen_pop();
int gen_primitive_declaration();

#endif

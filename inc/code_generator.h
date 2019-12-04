#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "abstract_syntax_tree.h"

int gen_fun_label(char* name);
void gen_return(t_expression* expression);
void gen_stack_set(int position);

#endif

#include "abstract_syntax_tree.h"
#include <stdlib.h>

t_program* create_program() {
  t_program* program = (t_program*)malloc(sizeof(t_program));
  program->declarations = NULL;
  return program;
}

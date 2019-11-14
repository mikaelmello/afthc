#include "abstract_syntax_tree.h"
#include <stdio.h>
#include <stdlib.h>

char* declaration_get_label(t_declaration* declaration) {
  if (declaration->type == VAR_DECLARATION) {
    t_variable* var = declaration->member.variable;
    return var->identifier;
  } else if (declaration->type == FUN_DECLARATION) {
    t_function* fun = declaration->member.function;
    return fun->identifier;
  } else {
    printf("Unknown type, figure it out!");
    exit(945);
  }
}

int is_type_equivalent(t_primitive_type type1, t_primitive_type type2) {
  if ((type1 == BYTE_TYPE || type1 == CHAR_TYPE || type1 == SHORT_TYPE ||
       type1 == INT_TYPE || type1 == LONG_TYPE) &&
      (type2 == BYTE_TYPE || type2 == CHAR_TYPE || type2 == SHORT_TYPE ||
       type2 == INT_TYPE || type2 == LONG_TYPE)) {
    return 1;
  }
  if ((type1 == FLOAT_TYPE || type1 == DOUBLE_TYPE) &&
      (type2 == FLOAT_TYPE || type2 == DOUBLE_TYPE)) {
    return 1;
  }

  if (type1 == type2) return 1;

  return 0;
}

int is_structure_equivalent(t_declaration* dec, t_structure_type type) {
  if (dec->type == VAR_DECLARATION) {
    if (dec->member.variable->type_info.data_structure == type) {
      return 1;
    }
  } else if (dec->type == FUN_DECLARATION) {
    if (dec->member.function->type_info.data_structure == type) {
      return 1;
    }
  } else {
    printf("Unknown type, figure it out!");
    exit(945);
  }
  return 0;
}

t_type_info get_type_info(st_element_t* dec) {
  if (dec->declaration->type == VAR_DECLARATION) {
    return dec->declaration->member.variable->type_info;
  } else if (dec->declaration->type == FUN_DECLARATION) {
    return dec->declaration->member.function->type_info;
  } else {
    printf("Unknown type, figure it out!");
    exit(945);
  }
}

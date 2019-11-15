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

void spaces(int n) {
  for (int i = 0; i < n; i++) printf(" ");
}

void print_data_structure(t_structure_type structure, int cur_level) {
  if (structure == PRIMITIVE) return;

  spaces(cur_level);
  switch (structure) {
    case ARRAY:
      printf("Structure: Array\n");
      break;
    case SET:
      printf("Structure: Set\n");
      break;
    case FUNCTION:
      printf("Function\n");
      break;
    case PRIMITIVE:
      printf("Primitive\n");
      break;
  }
}

void print_primitive_type(t_primitive_type type, int cur_level) {
  spaces(cur_level);
  printf("Primitive type: ");
  switch (type) {
    case BYTE_TYPE:
      printf("Byte\n");
      break;
    case CHAR_TYPE:
      printf("Char\n");
      break;
    case SHORT_TYPE:
      printf("Short\n");
      break;
    case INT_TYPE:
      printf("Int\n");
      break;
    case LONG_TYPE:
      printf("Long\n");
      break;
    case FLOAT_TYPE:
      printf("Float\n");
      break;
    case DOUBLE_TYPE:
      printf("Double\n");
      break;
    case VOID_TYPE:
      printf("Void\n");
      break;
    case STRING_TYPE:
      printf("String Literal\n");
      break;
  }
}

void print_fun_params(t_function_params* params, int cur_level) {
  if (params == NULL) return;

  if (params->prev != NULL) {
    print_fun_params(params->prev, cur_level);
  } else {
    spaces(cur_level);
    printf("Function parameters\n");
  }

  if (params->cur) {
    print_declaration(params->cur, cur_level + 1);
  }
}

void print_brace_enclosed_scope(t_brace_enclosed_scope* scope, int cur_level) {
  if (scope == NULL) return;

  spaces(cur_level);
  printf("Brace Enclosed Scope {}\n");
  print_statement_list(scope->statements, cur_level + 1);
}

void print_statement_list(t_statement_list* list, int cur_level) {
  if (list == NULL) return;

  if (list->prev != NULL) {
    print_statement_list(list->prev, cur_level);
  }

  if (list->cur != NULL) {
    print_statement(list->cur, cur_level);
  }
}

void print_statement(t_statement* statement, int cur_level) {
  if (statement == NULL) return;

  spaces(cur_level);
  printf("Statement\n");

  switch (statement->type) {
    case BRACE_ENCLOSED_SCOPE_STATEMENT:
      print_brace_enclosed_scope(statement->member.scope, cur_level + 1);
      break;
    case VAR_DECLARATION_STATEMENT:
      print_declaration(statement->member.variable, cur_level + 1);
      break;
    case PRINT_STATEMENT:
      print_print(statement->member.print, cur_level + 1);
      break;
    case SCAN_STATEMENT:
      print_scan(statement->member.scan, cur_level + 1);
      break;
    case EXPRESSION_STATEMENT:
      print_expression(statement->member.expression, cur_level + 1);
      break;
    case CONDITION_STATEMENT:
      print_condition(statement->member.condition, cur_level + 1);
      break;
    case ITERATION_STATEMENT:
      print_iteration(statement->member.iteration, cur_level + 1);
      break;
    case RETURN_STATEMENT:
      print_return(statement->member._return, cur_level + 1);
      break;
  }
}

void print_expression_type(t_expression_type type, int cur_level) {
  spaces(cur_level);
  printf("Type: ");
  switch (type) {
    case AND_EXPRESSION:
      printf("And\n");
      break;
    case OR_EXPRESSION:
      printf("Or\n");
      break;
    case BW_AND_EXPRESSION:
      printf("Bitwise And\n");
      break;
    case BW_OR_EXPRESSION:
      printf("Bitwise Or\n");
      break;
    case BW_XOR_EXPRESSION:
      printf("Bitwise Xor\n");
      break;
    case NOT_EQ_EXPRESSION:
      printf("Not equal\n");
      break;
    case EQ_EQ_EXPRESSION:
      printf("Equal\n");
      break;
    case LESS_THAN:
      printf("Less than\n");
      break;
    case GREATER_THAN:
      printf("Greater than\n");
      break;
    case LESS_THAN_OR_EQUAL:
      printf("Less than or equal\n");
      break;
    case GREATER_THAN_OR_EQUAL:
      printf("Greater than or equal\n");
      break;
    case CAST_EXPRESSION:
      printf("Cast\n");
      break;
    case IS_IN:
      printf("Is in\n");
      break;
    case LEFT_SHIFT_EXPRESSION:
      printf("Left Shift\n");
      break;
    case ASSIGNMENT_EXPRESSION:
      printf("Assignment\n");
      break;
    case RIGHT_SHIFT_EXPRESSION:
      printf("Right Shift\n");
      break;
    case RM_EXPRESSION:
      printf("Remove\n");
      break;
    case UNARY_PLUS:
      printf("Unary plus\n");
      break;
    case UNARY_MINUS:
      printf("Unary minus\n");
      break;
    case UNARY_EXCL:
      printf("Unary not\n");
      break;
    case UNARY_SIZEOF:
      printf("Unary sizeof\n");
      break;
    case ADD_PLUS:
      printf("Add\n");
      break;
    case ADD_MINUS:
      printf("Subtract\n");
      break;
    case ASTERISK_OPERATOR:
      printf("Multiply\n");
      break;
    case SLASH_OPERATOR:
      printf("Divide\n");
      break;
    case PERCENT_OPERATOR:
      printf("Modulo\n");
      break;
    case ARRAY_ACCESS:
      printf("Array access\n");
      break;
    case FUNCTION_CALL:
      printf("Function call\n");
      break;
    case IDENTIFIER_PRIMARY_EXPRESSION:
      printf("Identifier\n");
      break;
    case CONSTANT_PRIMARY_EXPRESSION:
      printf("Constant\n");
      break;
    case STRING_PRIMARY_EXPRESSION:
      printf("String literal\n");
      break;
    case NESTED_PRIMARY_EXPRESSION:
      printf("Nested primary expression\n");
      break;
  }
}

void print_array_access(t_postfix_expression* expression, int cur_level) {
  if (expression == NULL) return;

  spaces(cur_level);
  printf("Array:\n");
  print_st_element(expression->left, cur_level + 1, 0);
  spaces(cur_level);
  printf("Index expression:\n");
  print_expression(expression->member.array_index, cur_level + 1);
}

void print_function_call_params(t_param_vals* params, int cur_level) {
  if (params == NULL) return;

  if (params->prev != NULL) {
    print_function_call_params(params->prev, cur_level);
  } else {
    spaces(cur_level);
    printf("Parameters\n");
  }

  if (params->cur) {
    print_expression(params->cur, cur_level + 1);
  }
}

void print_function_call(t_postfix_expression* expression, int cur_level) {
  if (expression == NULL) return;

  print_st_element(expression->left, cur_level, 0);
  print_function_call_params(expression->member.function_params, cur_level);
}

void print_constant(t_constant* constant, int cur_level) {
  if (constant == NULL) return;

  spaces(cur_level);
  switch (constant->type_info.primitive_type) {
    case LONG_TYPE:
      printf("Integer: %ld\n", constant->member.integer_val);
      break;
    case CHAR_TYPE:
      printf("Char: %c\n", constant->member.char_val);
      break;
    case DOUBLE_TYPE:
      printf("Real: %lf\n", constant->member.float_val);
      break;
    case BYTE_TYPE:
    case SHORT_TYPE:
    case INT_TYPE:
    case FLOAT_TYPE:
    case VOID_TYPE:
    case STRING_TYPE:
      printf("Should not appear!\n");
      break;
  }
}

void print_primary_expression(t_primary_expression* expression, int cur_level) {
  if (expression == NULL) return;

  spaces(cur_level);
  switch (expression->type) {
    case IDENTIFIER_PRIMARY_EXPRESSION:
      print_st_element(expression->member.identifier, cur_level + 1, 0);
      break;
    case CONSTANT_PRIMARY_EXPRESSION:
      print_constant(expression->member.constant, cur_level + 1);
      break;
    case STRING_PRIMARY_EXPRESSION:
      spaces(cur_level + 1);
      printf("%s\n", expression->member.string);
      break;
    case NESTED_PRIMARY_EXPRESSION:
      print_expression(expression->member.expression, cur_level + 1);
      break;
    default:
      printf("SHOOOULD NOT HAPPEN!\n");
      exit(99);
  }
}

void print_postfix_expression(t_postfix_expression* expression, int cur_level) {
  if (expression == NULL) return;

  if (expression->primary) {
    print_primary_expression(expression->primary, cur_level);
    return;
  }

  switch (expression->type) {
    case ARRAY_ACCESS:
      print_array_access(expression, cur_level);
      break;
    case FUNCTION_CALL:
      print_function_call(expression, cur_level);
      break;
    default:
      printf("SHOULD NOT HAPPEN\n");
      exit(5);
  }
}

void print_cast_expression(t_cast_expression* cast, int cur_level) {
  if (cast == NULL) return;

  if (cast->type == CAST_EXPRESSION) {
    spaces(cur_level);
    printf("Cast:\n");
    print_primitive_type(cast->cast_type, cur_level + 1);
    print_expression(cast->right, cur_level + 1);
    return;
  }

  print_postfix_expression(cast->left, cur_level);
}

void print_assignment_operator(t_assignment_operator operator, int cur_level) {
  spaces(cur_level);
  switch (operator) {
    case EQUAL_OPERATOR:
      printf("=\n");
      break;
    case PLUS_EQUAL_OPERATOR:
      printf("+=\n");
      break;
    case MINUS_EQUAL_OPERATOR:
      printf("-=\n");
      break;
    case ASTERISK_EQUAL_OPERATOR:
      printf("*=\n");
      break;
    case SLASH_EQUAL_OPERATOR:
      printf("/=\n");
      break;
    case PERCENT_EQUAL_OPERATOR:
      printf("%%=\n");
      break;
  }
}

void print_assignment(t_assignment* assignment, int cur_level) {
  if (assignment == NULL) return;

  spaces(cur_level);
  printf("Operator\n");
  print_assignment_operator(assignment->operator, cur_level + 1);
  spaces(cur_level);
  printf("Identifier:\n");
  print_st_element(assignment->identifier, cur_level + 1, 0);
  print_expression(assignment->expression, cur_level);
}

void print_expression(t_expression* expression, int cur_level) {
  if (expression == NULL) return;

  spaces(cur_level);
  printf("Expression\n");
  print_primitive_type(expression->type_info.primitive_type, cur_level + 1);
  print_data_structure(expression->type_info.data_structure, cur_level + 1);
  print_expression_type(expression->type, cur_level + 1);

  switch (expression->type) {
    case ARRAY_ACCESS:
    case FUNCTION_CALL:
    case IDENTIFIER_PRIMARY_EXPRESSION:
    case CONSTANT_PRIMARY_EXPRESSION:
    case STRING_PRIMARY_EXPRESSION:
    case NESTED_PRIMARY_EXPRESSION:
    case CAST_EXPRESSION:
      print_cast_expression(expression->value, cur_level + 1);
      break;
    case ASSIGNMENT_EXPRESSION:
      print_assignment(expression->assignment, cur_level + 1);
      break;
    default:
      spaces(cur_level + 1);
      printf("Left side\n");
      print_expression(expression->left, cur_level + 2);
      spaces(cur_level + 1);
      printf("Right side\n");
      print_expression(expression->right, cur_level + 2);
  }
}

void print_condition(t_condition* condition, int cur_level) {
  if (condition == NULL) return;

  spaces(cur_level);
  printf("Condition\n");
  print_expression(condition->condition, cur_level + 1);

  spaces(cur_level + 1);
  printf("Body\n");
  print_statement(condition->body, cur_level + 2);

  if (condition->else_body) {
    spaces(cur_level + 1);
    printf("Else Body\n");
    print_statement(condition->else_body, cur_level + 2);
  }
}

void print_iteration(t_iteration* it, int cur_level) {
  if (it == NULL) return;

  spaces(cur_level);
  printf("Iteration\n");

  if (it->initialization) {
    spaces(cur_level + 1);
    printf("Initialization\n");
    print_expression(it->initialization, cur_level + 2);
  }
  if (it->condition) {
    spaces(cur_level + 1);
    printf("Condition\n");
    print_expression(it->condition, cur_level + 2);
  }
  if (it->step) {
    spaces(cur_level + 1);
    printf("Step\n");
    print_expression(it->step, cur_level + 2);
  }

  spaces(cur_level + 1);
  printf("Body\n");
  print_statement(it->body, cur_level + 2);
}

void print_return(t_return* ret, int cur_level) {
  if (ret == NULL) return;

  spaces(cur_level);
  printf("Return statement\n");
  print_expression(ret->expression, cur_level + 1);
}

void print_print_type(t_print_type type, int cur_level) {
  spaces(cur_level);
  printf("Type: ");
  switch (type) {
    case PRINT_CHAR_TYPE:
      printf("Character\n");
      break;
    case PRINT_DEC_TYPE:
      printf("Decimal number\n");
      break;
    case PRINT_HEX_TYPE:
      printf("Hexadecimal number\n");
  }
}

void print_print(t_print* print, int cur_level) {
  if (print == NULL) return;

  spaces(cur_level);
  printf("Print\n");
  print_print_type(print->type, cur_level + 1);
  print_expression(print->expression, cur_level + 1);
}

void print_scan_type(t_scan_type type, int cur_level) {
  spaces(cur_level);
  printf("Type: ");
  switch (type) {
    case SCAN_CHAR_TYPE:
      printf("Character\n");
      break;
    case SCAN_DEC_TYPE:
      printf("Decimal number\n");
      break;
    case SCAN_FLOAT_TYPE:
      printf("Real number\n");
  }
}

void print_scan(t_scan* scan, int cur_level) {
  if (scan == NULL) return;

  spaces(cur_level);
  printf("Print\n");
  print_scan_type(scan->type, cur_level + 1);
  spaces(cur_level + 1);
  printf("Variable to scan:");
  print_st_element(scan->destiny, cur_level + 2, 0);
}

void print_st_element(st_element_t* element, int cur_level,
                      int print_fun_body) {
  if (element == NULL) return;

  t_type_info i = get_type_info(element);
  print_data_structure(i.data_structure, cur_level);
  print_primitive_type(i.primitive_type, cur_level);

  char* label = declaration_get_label(element->declaration);
  spaces(cur_level);
  printf("Label: %s\n", label);

  if (element->declaration->type == FUN_DECLARATION) {
    print_fun_params(element->declaration->member.function->params, cur_level);

    if (print_fun_body) {
      print_brace_enclosed_scope(element->declaration->member.function->body,
                                 cur_level);
    }
  }
}

void print_declaration(st_element_t* declaration, int cur_level) {
  if (declaration == NULL) return;

  spaces(cur_level);
  printf("Declaration\n");
  print_st_element(declaration, cur_level + 1, 1);
}

void print_declaration_list(t_declaration_list* list, int cur_level) {
  if (list == NULL) return;
  if (list->prev != NULL) {
    print_declaration_list(list->prev, cur_level);
  }

  if (list->cur != NULL) {
    print_declaration(list->cur, cur_level);
  }
}

void print_program(t_program* program, int cur_level) {
  if (program == NULL) return;

  spaces(cur_level);
  printf("Program\n");
  print_declaration_list(program->declaration_list, cur_level + 1);
}

void free_fun_params(t_function_params* params) {
  if (params == NULL) return;

  if (params->prev != NULL) {
    free_fun_params(params->prev);
  }

  free_declaration(params->cur);
  free(params);
}

void free_brace_enclosed_scope(t_brace_enclosed_scope* scope) {
  if (scope == NULL) return;
  free_statement_list(scope->statements);
  free(scope);
}

void free_statement_list(t_statement_list* list) {
  if (list == NULL) return;

  if (list->prev != NULL) {
    free_statement_list(list->prev);
  }

  free_statement(list->cur);
  free(list);
}

void free_statement(t_statement* statement) {
  if (statement == NULL) return;

  switch (statement->type) {
    case BRACE_ENCLOSED_SCOPE_STATEMENT:
      free_brace_enclosed_scope(statement->member.scope);
      break;
    case VAR_DECLARATION_STATEMENT:
      free_declaration(statement->member.variable);
      break;
    case PRINT_STATEMENT:
      free_print(statement->member.print);
      break;
    case SCAN_STATEMENT:
      free_scan(statement->member.scan);
      break;
    case EXPRESSION_STATEMENT:
      free_expression(statement->member.expression);
      break;
    case CONDITION_STATEMENT:
      free_condition(statement->member.condition);
      break;
    case ITERATION_STATEMENT:
      free_iteration(statement->member.iteration);
      break;
    case RETURN_STATEMENT:
      free_return(statement->member._return);
      break;
  }

  free(statement);
}

void free_function_call_params(t_param_vals* params) {
  if (params == NULL) return;

  if (params->prev != NULL) {
    free_function_call_params(params->prev);
  }

  free_expression(params->cur);
  free(params);
}

void free_array_access(t_postfix_expression* expression) {
  if (expression == NULL) return;

  free_declaration(expression->left);
  free_expression(expression->member.array_index);
}

void free_function_call(t_postfix_expression* expression) {
  if (expression == NULL) return;

  free_declaration(expression->left);
  free_function_call_params(expression->member.function_params);
}

void free_constant(t_constant* constant) {
  if (constant == NULL) return;

  switch (constant->type_info.primitive_type) {
    case LONG_TYPE:
    case CHAR_TYPE:
    case DOUBLE_TYPE:
      break;
    case BYTE_TYPE:
    case SHORT_TYPE:
    case INT_TYPE:
    case FLOAT_TYPE:
    case VOID_TYPE:
    case STRING_TYPE:
      printf("Should not appear!\n");
      break;
  }

  free(constant);
}

void free_primary_expression(t_primary_expression* expression) {
  if (expression == NULL) return;

  switch (expression->type) {
    case IDENTIFIER_PRIMARY_EXPRESSION:
      free_declaration(expression->member.identifier);
      break;
    case CONSTANT_PRIMARY_EXPRESSION:
      free_constant(expression->member.constant);
      break;
    case STRING_PRIMARY_EXPRESSION:
      free(expression->member.string);
      break;
    case NESTED_PRIMARY_EXPRESSION:
      free_expression(expression->member.expression);
      break;
    default:
      printf("SHOOOULD NOT HAPPEN!\n");
      exit(99);
  }
  free(expression);
}

void free_postfix_expression(t_postfix_expression* expression) {
  if (expression == NULL) return;

  if (expression->primary) {
    free_primary_expression(expression->primary);
    free(expression);
    return;
  }

  switch (expression->type) {
    case ARRAY_ACCESS:
      free_array_access(expression);
      break;
    case FUNCTION_CALL:
      free_function_call(expression);
      break;
    default:
      printf("SHOULD NOT HAPPEN\n");
      exit(5);
  }
  free(expression);
}

void free_cast_expression(t_cast_expression* cast) {
  if (cast == NULL) return;

  if (cast->type == CAST_EXPRESSION) {
    free_expression(cast->right);
    free(cast);
    return;
  }

  free_postfix_expression(cast->left);
  free(cast);
}

void free_assignment(t_assignment* assignment) {
  if (assignment == NULL) return;

  free_declaration(assignment->identifier);
  free_expression(assignment->expression);
  free(assignment);
}

void free_expression(t_expression* expression) {
  if (expression == NULL) return;

  switch (expression->type) {
    case ARRAY_ACCESS:
    case FUNCTION_CALL:
    case IDENTIFIER_PRIMARY_EXPRESSION:
    case CONSTANT_PRIMARY_EXPRESSION:
    case STRING_PRIMARY_EXPRESSION:
    case NESTED_PRIMARY_EXPRESSION:
    case CAST_EXPRESSION:
      free_cast_expression(expression->value);
      break;
    case ASSIGNMENT_EXPRESSION:
      free_assignment(expression->assignment);
      break;
    default:
      free_expression(expression->left);
      free_expression(expression->right);
  }
  free(expression);
}

void free_condition(t_condition* condition) {
  if (condition == NULL) return;

  free_expression(condition->condition);
  free_statement(condition->body);
  free_statement(condition->else_body);

  free(condition);
}

void free_iteration(t_iteration* it) {
  if (it == NULL) return;

  free_expression(it->initialization);
  free_expression(it->condition);
  free_expression(it->step);
  free_statement(it->body);
  free(it);
}

void free_return(t_return* ret) {
  if (ret == NULL) return;
  free_expression(ret->expression);
  free(ret);
}

void free_print(t_print* print) {
  if (print == NULL) return;

  free_expression(print->expression);
  free(print);
}

void free_scan(t_scan* scan) {
  if (scan == NULL) return;

  free_declaration(scan->destiny);
  free(scan);
}

void free_declaration(st_element_t* declaration) { return; }

void free_declaration_list(t_declaration_list* list) {
  if (list == NULL) return;
  if (list->prev != NULL) {
    free_declaration_list(list->prev);
  }

  free_declaration(list->cur);
  free(list);
}

void free_program(t_program* program) {
  if (program == NULL) return;

  free_declaration_list(program->declaration_list);
  free(program);
}

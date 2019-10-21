#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>

void print_primitive_type(t_primitive_type type) {
  switch (type) {
    case BYTE_TYPE:
      printf("byte");
      break;
    case SHORT_TYPE:
      printf("short");
      break;
    case INT_TYPE:
      printf("int");
      break;
    case LONG_TYPE:
      printf("long");
      break;
    case FLOAT_TYPE:
      printf("float");
      break;
    case DOUBLE_TYPE:
      printf("double");
      break;
    case VOID_TYPE:
      printf("void");
      break;
  }
}

t_symbol_table_list* create_symbol_table_list() {
  t_symbol_table_list* list =
      (t_symbol_table_list*)malloc(sizeof(t_symbol_table_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void free_symbol_table_list(t_symbol_table_list* list) {
  if (list == NULL) return;

  t_symbol_table_node* last = list->tail;
  while (last != NULL) {
    t_symbol_table_node* prev = last->prev;
    free(last);
    last = prev;
  }

  free(list);
}

void free_symbol_table_node(t_symbol_table_node* node) {
  if (node == NULL) return;
  free(node);
}

t_symbol_table_node* append_symbol_table_node(t_symbol_table_list* list,
                                              t_declaration* declaration) {
  t_symbol_table_node* node =
      (t_symbol_table_node*)calloc(1, sizeof(t_symbol_table_node));

  node->declaration = declaration;

  if (list->tail) {
    node->prev = list->tail;
    list->tail->next = node;
  }

  if (!list->head) {
    list->head = node;
  }

  list->size += 1;
  list->tail = node;

  return node;
}

void print_symbol_table_list(t_symbol_table_list* list) {
  if (list == NULL) return;

  printf("==============================\n");
  printf("===== TABELA DE SIMBOLOS =====\n");
  printf("==============================\n");

  t_symbol_table_node* cur = list->head;
  while (cur != NULL) {
    print_symbol_table_node(cur);
    cur = cur->next;
  }
}

void print_symbol_table_node(t_symbol_table_node* node) {
  t_declaration* dec = node->declaration;

  if (dec->type == VAR_DECLARATION) {
    t_variable* var = dec->member.variable;
    printf("VARIABLE\n");
    printf("  Type: ");
    print_primitive_type(var->type);
    printf("\n");
    printf("  Identifier: %s\n", var->identifier);
    printf("  Structure: (%s)\n",
           var->structure == SET_TYPE
               ? "set"
               : var->structure == ARRAY_TYPE ? "array" : "primitive");
  } else {
    t_function* fun = dec->member.function;
    printf("FUNCTION\n");
    printf("  Return type: ");
    print_primitive_type(fun->return_type);
    printf("\n");
    printf("  Identifier: %s\n", fun->identifier);
  }
}

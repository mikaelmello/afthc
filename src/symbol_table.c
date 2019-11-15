#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

st_element_t* st_element_create(t_declaration* declaration) {
  st_element_t* element = (st_element_t*)calloc(1, sizeof(st_element_t));
  element->declaration = declaration;
  element->next = NULL;
  return element;
}

void st_element_free(st_element_t* element) {
  if (element == NULL) return;

  free_declaration(element->declaration);
  free(element);
}

int st_element_compare(st_element_t* element, char* label) {
  char* element_label = declaration_get_label(element->declaration);
  if (strcmp(element_label, label) == 0) return 1;
  return 0;
}

st_element_list_t* st_element_list_create() {
  st_element_list_t* list =
      (st_element_list_t*)calloc(1, sizeof(st_element_list_t));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void st_element_list_free(st_element_list_t* list) {
  if (list == NULL) return;

  while (list->head != NULL) {
    st_element_t* next = list->head->next;
    st_element_free(list->head);
    list->head = next;
  }

  free(list);
}

st_element_t* st_element_list_add(st_element_list_t* list,
                                  t_declaration* declaration) {
  st_element_t* element = st_element_create(declaration);
  if (list->head == NULL) {
    list->head = element;
    list->tail = element;
    list->size = 1;
  } else {
    list->tail->next = element;
    list->tail = element;
    list->size += 1;
  }

  return element;
}

st_element_t* st_element_list_find(st_element_list_t* list, char* label) {
  st_element_t* cur = list->head;

  while (cur != NULL) {
    if (st_element_compare(cur, label) == 1) {
      return cur;
    }
    cur = cur->next;
  }

  return NULL;
}

st_t* st_create() {
  st_t* st = (st_t*)calloc(1, sizeof(st_t));
  st->list = st_element_list_create();
  return st;
}

void st_free(st_t* st) {
  if (st == NULL) return;
  st_element_list_free(st->list);
  free(st);
}

st_element_t* st_add(st_t* st, t_declaration* declaration) {
  return st_element_list_add(st->list, declaration);
}

st_element_t* st_find(st_t* st, char* label) {
  return st_element_list_find(st->list, label);
}

void t_declaration_free(t_declaration* dec) {}

// t_symbol_table_list* create_symbol_table_list() {
//   t_symbol_table_list* list =
//       (t_symbol_table_list*)malloc(sizeof(t_symbol_table_list));
//   list->head = NULL;
//   list->tail = NULL;
//   list->size = 0;
//   return list;
// }

// void free_symbol_table_list(t_symbol_table_list* list) {
//   if (list == NULL) return;

//   t_symbol_table_node* last = list->tail;
//   while (last != NULL) {
//     t_symbol_table_node* prev = last->prev;
//     free(last);
//     last = prev;
//   }

//   free(list);
// }

// void free_symbol_table_node(t_symbol_table_node* node) {
//   if (node == NULL) return;
//   free(node);
// }

// t_symbol_table_node* append_symbol_table_node(t_symbol_table_list* list,
//                                               t_declaration* declaration) {
//   t_symbol_table_node* node =
//       (t_symbol_table_node*)calloc(1, sizeof(t_symbol_table_node));

//   node->declaration = declaration;

//   if (list->tail) {
//     node->prev = list->tail;
//     list->tail->next = node;
//   }

//   if (!list->head) {
//     list->head = node;
//   }

//   list->size += 1;
//   list->tail = node;

//   return node;
// }

// void print_symbol_table_list(t_symbol_table_list* list) {
//   if (list == NULL) return;

//   printf("==============================\n");
//   printf("===== TABELA DE SIMBOLOS =====\n");
//   printf("==============================\n");

//   t_symbol_table_node* cur = list->head;
//   while (cur != NULL) {
//     print_symbol_table_node(cur);
//     cur = cur->next;
//   }
// }

// void print_symbol_table_node(t_symbol_table_node* node) {
//   t_declaration* dec = node->declaration;

//   if (dec->type == VAR_DECLARATION) {
//     t_variable* var = dec->member.variable;
//     printf("VARIABLE\n");
//     printf("  Type: ");
//     print_primitive_type(var->type);
//     printf("\n");
//     printf("  Identifier: %s\n", var->identifier);
//     printf("  Structure: (%s)\n",
//            var->structure == SET_TYPE
//                ? "set"
//                : var->structure == ARRAY_TYPE ? "array" : "primitive");
//   } else {
//     t_function* fun = dec->member.function;
//     printf("FUNCTION\n");
//     printf("  Return type: ");
//     print_primitive_type(fun->return_type);
//     printf("\n");
//     printf("  Identifier: %s\n", fun->identifier);
//   }
// }

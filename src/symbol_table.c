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

int st_total_size(st_t* symbol_table) {
  int size = 0;

  st_element_list_t* list = symbol_table->list;
  if (list == NULL) return size;

  st_element_t* cur = list->head;
  while (cur != NULL) {
    st_element_t* next = cur->next;
    if (cur->declaration->type == VAR_DECLARATION) {
      size += cur->declaration->member.variable->size;
    }
    cur = next;
  }
}

st_element_t* st_add(st_t* st, t_declaration* declaration) {
  return st_element_list_add(st->list, declaration);
}

st_element_t* st_find(st_t* st, char* label) {
  return st_element_list_find(st->list, label);
}

void t_declaration_free(t_declaration* dec) {}

void st_print(st_t* st, int cur_level) {
  if (st == NULL) return;

  spaces(cur_level);
  printf("Symbol table\n");
  st_element_list_print(st->list, cur_level + 1);
}

void st_element_list_print(st_element_list_t* list, int cur_level) {
  if (list == NULL) return;

  st_element_t* cur = list->head;
  while (cur != NULL) {
    st_element_print(cur, cur_level + 1);
    cur = cur->next;
  }
}

void st_element_print(st_element_t* element, int cur_level) {
  if (element == NULL) return;
  t_declaration* dec = element->declaration;

  spaces(cur_level);
  if (dec->type == VAR_DECLARATION) {
    t_variable* var = dec->member.variable;
    printf("VARIABLE\n");
    print_primitive_type(var->type_info.primitive_type, cur_level + 1);
    print_data_structure(var->type_info.data_structure, cur_level + 1);
    spaces(cur_level + 1);
    printf("Identifier: %s\n", var->identifier);
  } else {
    t_function* fun = dec->member.function;
    printf("FUNCTION\n");
    print_primitive_type(fun->type_info.primitive_type, cur_level + 1);
    spaces(cur_level + 1);
    printf("Identifier: %s\n", fun->identifier);
  }
}

#include "scope.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "tac.h"

scope_t* scope_create(scope_t* parent);
void scope_free(scope_t* scope);
void scope_print_level(scope_t* scope, int cur_level);

scope_list_t* scope_list_create();
void scope_list_free(scope_list_t* current);
void scope_list_add(scope_list_t* list, scope_t* scope);
void scope_list_print(scope_list_t* list, int cur_level);

scope_error_t LAST_ERROR = 0;
extern tac_program_t tac_program;

scope_t* root_scope;
scope_t* current_scope;

void scope_initialize() {
  root_scope = scope_create(NULL);
  current_scope = root_scope;
}

void scope_clean() { scope_free(current_scope); }

void scope_print() { scope_print_level(current_scope, 0); }

void scope_new() { current_scope = scope_create(current_scope); }

void scope_exit() {
  if (current_scope == NULL) {
    printf("Trying to exit from null scope!");
    abort();
  }

  int size = st_total_size(current_scope->symbol_table);
  // decrease stack by size

  current_scope = current_scope->parent;
}

scope_list_t* scope_list_create() {
  scope_list_t* list = (scope_list_t*)calloc(1, sizeof(scope_list_t));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void scope_list_add(scope_list_t* list, scope_t* scope) {
  if (list->head == NULL) {
    list->head = list->tail = scope;
  } else {
    list->tail->next_sibling = scope;
    list->tail = scope;
  }
}

void scope_list_free(scope_list_t* list) {
  if (list == NULL) return;

  while (list->head != NULL) {
    scope_t* cur = list->head;
    list->head = cur->next_sibling;
    scope_free(cur);
  }

  free(list);
}

scope_t* scope_create(scope_t* parent) {
  scope_t* scope = (scope_t*)calloc(1, sizeof(scope_t));
  scope->symbol_table = st_create();
  scope->children = scope_list_create();
  scope->parent = parent;
  scope->next_sibling = NULL;
  scope->stack_head = tac_program.stack_head;

  if (parent != NULL) {
    scope_list_add(parent->children, scope);
  }
  return scope;
}

void scope_free(scope_t* scope) {
  if (scope == NULL) return;

  st_free(scope->symbol_table);
  scope_list_free(scope->children);
  free(scope);
}

scope_element_t* scope_add(t_declaration* declaration) {
  char* dec_label = declaration_get_label(declaration);
  scope_element_t* find = st_find(current_scope->symbol_table, dec_label);

  if (find != NULL) {
    LAST_ERROR = EXISTING_DECLARATION;
    return find;
  }

  return st_add(current_scope->symbol_table, declaration);
}

scope_element_t* scope_find(char* label) {
  scope_t* cur = current_scope;

  while (cur != NULL) {
    scope_element_t* find = st_find(cur->symbol_table, label);
    if (find != NULL) {
      return find;
    }
    cur = cur->parent;
  }
  return NULL;
}

void scope_print_level(scope_t* scope, int cur_level) {
  if (scope == NULL) return;

  spaces(cur_level);
  printf("Scope\n");
  st_print(scope->symbol_table, cur_level + 1);
  spaces(cur_level + 1);
  printf("Children\n");
  scope_list_print(scope->children, cur_level + 2);
}

void scope_list_print(scope_list_t* list, int cur_level) {
  if (list == NULL) return;

  spaces(cur_level);
  printf("List of scopes\n");
  scope_t* cur = list->head;
  while (cur != NULL) {
    scope_print_level(cur, cur_level + 1);
    cur = cur->next_sibling;
  }
}

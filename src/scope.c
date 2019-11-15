#include "scope.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

scope_error_t LAST_ERROR = 0;

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

scope_element_t* scope_add(scope_t* scope, t_declaration* declaration) {
  char* dec_label = declaration_get_label(declaration);
  scope_element_t* find = st_find(scope->symbol_table, dec_label);

  if (find != NULL) {
    LAST_ERROR = EXISTING_DECLARATION;
    return find;
  }

  return st_add(scope->symbol_table, declaration);
}

scope_element_t* scope_find(scope_t* scope, char* label) {
  scope_t* cur = scope;

  while (cur != NULL) {
    scope_element_t* find = st_find(cur->symbol_table, label);
    if (find != NULL) {
      return find;
    }
    cur = cur->parent;
  }
  return NULL;
}

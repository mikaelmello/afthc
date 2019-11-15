#include "scope.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

scope_error_t LAST_ERROR = 0;

scope_t* scope_create(scope_t* parent) {
  scope_t* scope = (scope_t*)calloc(1, sizeof(scope_t));
  scope->parent = parent;
  scope->symbol_table = st_create();
  return scope;
}

scope_t* scope_destroy(scope_t* current) {
  if (current == NULL) return NULL;

  scope_t* parent = current->parent;
  // scope_free(current);
  return parent;
}

void scope_free(scope_t* scope) {
  if (scope == NULL) return;
  st_free(scope->symbol_table);
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

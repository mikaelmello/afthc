#pragma once

#include "abstract_syntax_tree.h"
#include "symbol_table.h"

typedef struct scope_t scope_t;
typedef st_element_t scope_element_t;
typedef enum scope_error_t scope_error_t;

enum scope_error_t {
  EXISTING_DECLARATION = 1,
};

struct scope_t {
  scope_t* parent;
  st_t* symbol_table;
};

scope_error_t LAST_ERROR;

scope_t* scope_create(scope_t* parent);
scope_t* scope_destroy(scope_t* current);
void scope_free(scope_t* scope);
scope_element_t* scope_find(scope_t* cur_scope, char* label);
scope_element_t* scope_add(scope_t* cur_scope, t_declaration* declaration);

#pragma once

#include "abstract_syntax_tree.h"
#include "symbol_table.h"

typedef struct scope_t scope_t;
typedef struct scope_list_t scope_list_t;
typedef st_element_t scope_element_t;
typedef enum scope_error_t scope_error_t;

enum scope_error_t {
  EXISTING_DECLARATION = 1,
};

struct scope_t {
  int stack_head;
  scope_t* parent;
  scope_t* next_sibling;
  scope_list_t* children;

  st_t* symbol_table;
};

struct scope_list_t {
  scope_t* head;
  scope_t* tail;
};

scope_error_t LAST_ERROR;

void scope_initialize();
void scope_clean();
void scope_print();
scope_element_t* scope_add(t_declaration* declaration);
scope_element_t* scope_find(char* label);

void scope_new();
void scope_exit();

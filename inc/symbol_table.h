#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "abstract_syntax_tree.h"

typedef struct st_element_list_t st_element_list_t;
typedef struct st_t st_t;
typedef struct scope_t scope_t;

struct st_element_list_t {
  st_element_t* head;
  st_element_t* tail;
  int size;
};

struct st_t {
  st_element_list_t* list;
};

st_element_t* st_element_create(t_declaration* declaration);

void st_element_free(st_element_t* element);

int st_element_compare(st_element_t* element, char* label);

st_element_list_t* st_element_list_create();

void st_element_list_free(st_element_list_t* list);

st_element_t* st_element_list_add(st_element_list_t* list,
                                  t_declaration* declaration);

st_element_t* st_element_list_find(st_element_list_t* list, char* label);

st_t* st_create();

void st_free(st_t* symbol_table);

st_element_t* st_add(st_t* symbol_table, t_declaration* declaration);

st_element_t* st_find(st_t* symbol_table, char* label);

void st_print(st_t* st, int cur_level);
void st_element_list_print(st_element_list_t* list, int cur_level);
void st_element_print(st_element_t* element, int cur_level);

#endif

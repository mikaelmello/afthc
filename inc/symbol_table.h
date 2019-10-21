#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "abstract_syntax_tree.h"

typedef struct t_symbol_table_node t_symbol_table_node;
typedef struct t_symbol_table_list t_symbol_table_list;

struct t_symbol_table_node {
  t_declaration* declaration;
  t_symbol_table_node* next;
  t_symbol_table_node* prev;
};

struct t_symbol_table_list {
  t_symbol_table_node* head;
  t_symbol_table_node* tail;
  int size;
};

t_symbol_table_list* create_symbol_table_list();

t_symbol_table_node* append_symbol_table_node(t_symbol_table_list* list,
                                              t_declaration* declaration);

void free_symbol_table_list(t_symbol_table_list* list);

void free_symbol_table_node(t_symbol_table_node* node);

void print_symbol_table_list(t_symbol_table_list* list);

void print_symbol_table_node(t_symbol_table_node* node);

#endif

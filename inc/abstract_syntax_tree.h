#ifndef ABSTRACT_SYNTAX_TREE_H
#define ABSTRACT_SYNTAX_TREE_H

typedef struct t_declaration_list t_declaration_list;
typedef struct t_declaration t_declaration;

typedef struct t_program {
  t_declaration_list* declarations;
} t_program;

struct t_declaration_list {
  t_declaration_list* prev;
  t_declaration* cur;
};

struct t_declaration {};

#endif

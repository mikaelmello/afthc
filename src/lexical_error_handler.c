#include "lexical_error_handler.h"
#include "my_string.h"
#include <stdlib.h>

t_lexical_error_list* lex_error_list_create() {
  t_lexical_error_list* list = (t_lexical_error_list*)malloc(sizeof(t_lexical_error_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void lex_error_list_add(t_lexical_error_list* list, t_lexical_error* error) {
  if (list->size == 0) {
    list->head = error;
    list->tail = error;
    list->size = 1;
  } else {
    list->size += 1;
    list->tail->next = error;
    list->tail = error;
  }
}

t_lexical_error* lex_error_create(t_string* token, uint32_t line, uint32_t column) {
  t_lexical_error* e = (t_lexical_error*)malloc(sizeof(t_lexical_error));
  e->token = token;
  e->line = line;
  e->column = column;
  e->next = NULL;

  return e;
}

void lex_error_list_free(t_lexical_error_list* list) {
  t_lexical_error* next;
  t_lexical_error* current = list->head;

  while (current != NULL) {
    next = current->next;
    lex_error_free(current);
    current = next;
  }

  free(list);
}

void lex_error_free(t_lexical_error* error) {
  free_string(error->token);
  free(error);
}

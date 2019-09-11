#include "lexical_error_handler.h"
#include "my_string.h"
#include <stdlib.h>

t_lexical_error_list* create_lexical_error_list() {
  t_lexical_error_list* list = (t_lexical_error_list*)malloc(sizeof(t_lexical_error_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void add_lexical_error_to_list(t_lexical_error_list* list, t_lexical_error* error) {
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

t_lexical_error* create_lexical_error(t_string* token, uint32_t line, uint32_t column) {
  t_lexical_error* e = (t_lexical_error*)malloc(sizeof(t_lexical_error));
  e->token = token;
  e->line = line;
  e->column = column;
  e->next = NULL;

  return e;
}

void free_lexical_error_list(t_lexical_error_list* list) {
  t_lexical_error* next;
  t_lexical_error* current = list->head;

  while (current != NULL) {
    next = current->next;
    free_lexical_error(current);
    current = next;
  }

  free(list);
}

void free_lexical_error(t_lexical_error* error) {
  free_string(error->token);
  free(error);
}

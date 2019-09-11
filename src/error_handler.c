#include "error_handler.h"
#include "my_string.h"
#include <stdlib.h>

t_error_list* create_error_list() {
  t_error_list* list = (t_error_list*)malloc(sizeof(t_error_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void add_error(t_error_list* list, t_error* error) {
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

t_error* create_error(t_string* token, uint32_t line, uint32_t column) {
  t_error* e = (t_error*)malloc(sizeof(t_error));
  e->token = token;
  e->line = line;
  e->column = column;
  e->next = NULL;

  return e;
}

void free_error_list(t_error_list* list) {
  t_error* next;
  t_error* current = list->head;

  while (current != NULL) {
    next = current->next;
    free_error(current);
    current = next;
  }

  free(list);
}

void free_error(t_error* error) {
  free_string(error->token);
  free(error);
}

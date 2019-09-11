#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <stdlib.h>
#include "my_string.h"

typedef struct error {
  t_string* token;
  uint32_t line;
  uint32_t column;
  struct error* next;
} t_error;

typedef struct error_list {
  t_error* head;
  t_error* tail;
  uint32_t size;
} t_error_list;

/*
 * Creates an empty error list
 */
t_error_list* create_error_list();

/*
 * Adds an error to the end of a list
 */
void add_error(t_error_list* list, t_error* error);

/*
 * Creates an error struct
 * <token> String containing the current token where the error happened
 * <line> Line number of the first character of the token
 * <column> Column number of the first character of the token
 */
t_error* create_error(t_string* token, uint32_t line, uint32_t column);

/*
 * Frees all memory allocated for the list, all of its error elements
 * and their strings
 */
void free_error_list(t_error_list* list);

/*
 * Frees the memory allocated for this error struct and the underlying
 * string
 */
void free_error(t_error* error);

#endif

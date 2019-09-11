#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <stdlib.h>
#include "my_string.h"

typedef struct lexical_error {
  t_string* token;
  uint32_t line;
  uint32_t column;
  struct lexical_error* next;
} t_lexical_error;

typedef struct lexical_error_list {
  t_lexical_error* head;
  t_lexical_error* tail;
  uint32_t size;
} t_lexical_error_list;

/*
 * Creates an empty error list
 */
t_lexical_error_list* lex_error_list_create();

/*
 * Adds an error to the end of a list
 * <list> List struct
 * <error> The error to be a dded
 */
void lex_error_list_add(t_lexical_error_list* list, t_lexical_error* error);

/*
 * Creates an error struct
 * <token> String containing the current token where the error happened
 * <line> Line number of the first character of the token
 * <column> Column number of the first character of the token
 */
t_lexical_error* lex_error_create(t_string* token, uint32_t line,
                                  uint32_t column);

/*
 * Frees all memory allocated for the list, all of its error elements
 * and their strings
 * <list> The list to be freed
 */
void lex_error_list_free(t_lexical_error_list* list);

/*
 * Frees the memory allocated for this error struct and the underlying
 * string
 * <error> The error to be freed
 */
void lex_error_free(t_lexical_error* error);

#endif

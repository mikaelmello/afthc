#include "lexical_error_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int last_column = -1;
int last_line = -1;
t_string* current_error = NULL;

void add_error(char c, int line, int column) {
  if (current_error == NULL) {
    current_error = m_string_create();
  } else if (column != last_column + 1 || line != last_line) {
    printf("Location %d:%d - String of invalid characters: %s\n", last_line,
           last_column, current_error->characters);
    m_string_clear(current_error);
  }
  m_string_add_char(current_error, c);
  last_column = column;
  last_line = line;
}

void lexical_eror_handler_finalize() {
  printf("Location %d:%d - String of invalid characters: %s\n", last_line,
         last_column, current_error->characters);
  m_string_free(current_error);
}

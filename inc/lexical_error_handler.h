#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <stdlib.h>
#include "my_string.h"
#include "symbol_table.h"

int last_column;
int last_line;
t_string* current_error;

void add_error(char c, int line, int column);
void lexical_eror_handler_finalize();

#endif

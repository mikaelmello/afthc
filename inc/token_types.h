#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H

#include <stdio.h>
#include "abstract_syntax_tree.h"
#include "lexical_error_handler.h"
#include "parser.h"

void print_lexical_error(t_lexical_error* error);

void print_token_name(int token, char* match);

#endif

#include <stdio.h>
#include "lexical_error_handler.h"
#include "my_string.h"
#include "token_types.h"

extern FILE* yyin;
extern int yyparse();
extern uint32_t column;
extern uint32_t line;
extern int yyleng;
extern char* yytext;

int main(int argc, char* argv[]) {
  argc -= 1;
  argv++;

  if (argc > 0) {
    yyin = fopen(argv[0], "r");
  } else {
    yyin = stdin;
  }

  t_lexical_error_list* error_list = lex_error_list_create();
  t_lexical_error* current_error = NULL;

  printf("===============================================\n");
  printf("============== IDENTIFIED TOKENS ==============\n");
  printf("===============================================\n");
  printf("\n");

  TOKEN token;
  while ((token = yylex())) {
    if (token == T_ERROR) {
      if (current_error == NULL) {
        current_error = lex_error_create(m_string_create(), line, column);
      }
      m_string_add_char(current_error->token, *yytext);
    } else {
      if (current_error != NULL) {
        lex_error_list_add(error_list, current_error);
        current_error = NULL;
      }
      print_token_name(token, yytext);
    }
    column += yyleng;
  }

  if (current_error != NULL) {
    lex_error_list_add(error_list, current_error);
    current_error = NULL;
  }

  if (error_list->size > 0) {
    printf("\n");
    printf("===============================================\n");
    printf("============= UNIDENTIFIED TOKENS =============\n");
    printf("===============================================\n");
    printf("\n");

    current_error = error_list->head;
    while (current_error != NULL) {
      print_lexical_error(current_error);
      current_error = current_error->next;
    }
  }

  lex_error_list_free(error_list);
}

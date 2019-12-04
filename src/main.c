#include <stdio.h>
#include "abstract_syntax_tree.h"
#include "code_generator.h"
#include "lexical_error_handler.h"
#include "my_string.h"
#include "scope.h"
#include "symbol_table.h"
#include "tac.h"
#include "token_types.h"

extern FILE* yyin;
extern int yyparse();
extern uint32_t column;
extern uint32_t line;
extern int yyleng;
extern char* yytext;
extern t_program* program;
extern tac_program_t tac_program;

int main(int argc, char* argv[]) {
  argc -= 1;
  argv++;

  if (argc > 0) {
    yyin = fopen(argv[0], "r");
  } else {
    yyin = stdin;
  }
  tac_program_initialize(&tac_program);
  scope_initialize();

  yyparse();
  lexical_eror_handler_finalize();
  tac_program_print(&tac_program);

  // print_program(program, 0);
  // scope_print(current_scope, 0);
  free_program(program);
  scope_clean();
  tac_program_clean(&tac_program);
}

#include <stdio.h>
#include "abstract_syntax_tree.h"
#include "lexical_error_handler.h"
#include "my_string.h"
#include "scope.h"
#include "symbol_table.h"
#include "token_types.h"

extern FILE* yyin;
extern int yyparse();
extern uint32_t column;
extern uint32_t line;
extern int yyleng;
extern char* yytext;
extern scope_t* root_scope;
extern scope_t* current_scope;

int main(int argc, char* argv[]) {
  argc -= 1;
  argv++;

  if (argc > 0) {
    yyin = fopen(argv[0], "r");
  } else {
    yyin = stdin;
  }
  root_scope = scope_create(NULL);
  current_scope = root_scope;

  // sym_table = create_symbol_table_list();
  yyparse();
  // free_ast(ast_root, NT_PROGRAM);
  // free_symbol_table_list(sym_table);
}

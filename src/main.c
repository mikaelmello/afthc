#include <stdio.h>
#include "abstract_syntax_tree.h"
#include "lexical_error_handler.h"
#include "my_string.h"
#include "symbol_table.h"
#include "token_types.h"

extern FILE* yyin;
extern int yyparse();
extern uint32_t column;
extern uint32_t line;
extern int yyleng;
extern char* yytext;
extern t_symbol_table_list* sym_table;
extern node ast_root;
extern void free_ast(node root, node_type type);

int main(int argc, char* argv[]) {
  argc -= 1;
  argv++;

  if (argc > 0) {
    yyin = fopen(argv[0], "r");
  } else {
    yyin = stdin;
  }

  sym_table = create_symbol_table_list();
  yyparse();
  // free_ast(ast_root, NT_PROGRAM);
  free_symbol_table_list(sym_table);
}

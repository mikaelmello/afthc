#include <stdio.h>
#include "abstract_syntax_tree.h"
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

  yyparse();
}

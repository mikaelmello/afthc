
#include "token_types.h"
#include <stdio.h>
#include "lexical_error_handler.h"

void print_lexical_error(t_lexical_error* error) {
  printf("<ERROR WHEN PARSING> Match: %s - Location %d:%d\n",
         error->token->characters, error->line, error->column);
}

void print_token_name(int token, char* match) {
  int print = 1;

  switch (token) {
    case INTEGER:
      printf("<T_INTEGER>");
      break;
    case REAL:
      printf("<T_REAL>");
      break;
    case IDENTIFIER:
      printf("<T_IDENTIFIER>");
      break;
    case STRING:
      printf("<T_STRING>");
      break;
    case CHAR:
      printf("<T_CHAR>");
      break;
    case LEFT_BRACE:
      printf("<T_LEFT_BRACE>");
      break;
    case RIGHT_BRACE:
      printf("<T_RIGHT_BRACE>");
      break;
    case LEFT_BRACKET:
      printf("<T_LEFT_BRACKET>");
      break;
    case RIGHT_BRACKET:
      printf("<T_RIGHT_BRACKET>");
      break;
    case LEFT_PAREN:
      printf("<T_LEFT_PAREN>");
      break;
    case RIGHT_PAREN:
      printf("<T_RIGHT_PAREN>");
      break;
    case LEFT_ANGLE:
      printf("<T_LEFT_ANGLE>");
      break;
    case RIGHT_ANGLE:
      printf("<T_RIGHT_ANGLE>");
      break;

    case EQUAL:
      printf("<T_EQUAL>");
      break;
    case PLUS_EQUAL:
      printf("<T_PLUS_EQUAL>");
      break;
    case MINUS_EQUAL:
      printf("<T_MINUS_EQUAL>");
      break;
    case ASTERISK_EQUAL:
      printf("<T_ASTERISK_EQUAL>");
      break;
    case SLASH_EQUAL:
      printf("<T_SLASH_EQUAL>");
      break;
    case PERCENT_EQUAL:
      printf("<T_PERCENT_EQUAL>");
      break;
    case LANGLE_EQUAL:
      printf("<T_LANGLE_EQUAL>");
      break;
    case RANGLE_EQUAL:
      printf("<T_RANGLE_EQUAL>");
      break;
    case EQUAL_EQUAL:
      printf("<T_EQUAL_EQUAL>");
      break;
    case EXCL_EQUAL:
      printf("<T_EXCL_EQUAL>");
      break;
    case DOUBLE_LANGLE:
      printf("<T_DOUBLE_LANGLE>");
      break;
    case DOUBLE_RANGLE:
      printf("<T_DOUBLE_RANGLE>");
      break;

    case TILDE:
      printf("<T_TILDE>");
      break;
    case AND:
      printf("<T_AND>");
      break;
    case BAR:
      printf("<T_BAR>");
      break;
    case CARET:
      printf("<T_CARET>");
      break;
    case EXCL:
      printf("<T_EXCL>");
      break;
    case BAR_BAR:
      printf("<T_BAR_BAR>");
      break;
    case AND_AND:
      printf("<T_AND_AND>");
      break;
    case COMMA:
      printf("<T_COMMA>");
      break;
    case SEMICOLON:
      printf("<T_SEMICOLON>");
      break;
    case PLUS:
      printf("<T_PLUS>");
      break;
    case MINUS:
      printf("<T_MINUS>");
      break;
    case ASTERISK:
      printf("<T_ASTERISK>");
      break;
    case SLASH:
      printf("<T_SLASH>");
      break;
    case PERCENT:
      printf("<T_PERCENT>");
      break;

    case IN_RW:
      printf("<T_IN_RW>");
      break;
    case RM_RW:
      printf("<T_RM_RW>");
      break;
    case SIZEOF_RW:
      printf("<T_SIZEOF_RW>");
      break;
    case VOID_RW:
      printf("<T_VOID_RW>");
      break;
    case BOOL_RW:
      printf("<T_BOOL_RW>");
      break;
    case BYTE_RW:
      printf("<T_BYTE_RW>");
      break;
    case CHAR_RW:
      printf("<T_CHAR_RW>");
      break;
    case SHORT_RW:
      printf("<T_SHORT_RW>");
      break;
    case INT_RW:
      printf("<T_INT_RW>");
      break;
    case LONG_RW:
      printf("<T_LONG_RW>");
      break;
    case FLOAT_RW:
      printf("<T_FLOAT_RW>");
      break;
    case DOUBLE_RW:
      printf("<T_DOUBLE_RW>");
      break;
    case PRINT_RW:
      printf("<T_PRINT_RW>");
      break;
    case PRINTC_RW:
      printf("<T_PRINTC_RW>");
      break;
    case PRINTX_RW:
      printf("<T_PRINTX_RW>");
      break;
    case SCAN_RW:
      printf("<T_SCAN_RW>");
      break;
    case SCANC_RW:
      printf("<T_SCANC_RW>");
      break;
    case SCANF_RW:
      printf("<T_SCANF_RW>");
      break;
    case IF_RW:
      printf("<T_IF_RW>");
      break;
    case ELSE_RW:
      printf("<T_ELSE_RW>");
      break;
    case WHILE_RW:
      printf("<T_WHILE_RW>");
      break;
    case FOR_RW:
      printf("<T_FOR_RW>");
      break;
    case RETURN_RW:
      printf("<T_RETURN_RW>");
      break;
    default:
      print = 0;
      break;
  }

  if (print != 0) {
    printf(" Match: %s\n", match);
  }
}

#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H

#include <stdio.h>
#include "lexical_error_handler.h"

typedef enum TOKEN {
  T_ERROR = 1,
  T_INTEGER,
  T_WHITESPACE,
  T_REAL,
  T_IDENTIFIER,
  T_STRING,
  T_LEFT_BRACE,
  T_RIGHT_BRACE,
  T_LEFT_BRACKET,
  T_RIGHT_BRACKET,
  T_LEFT_PAREN,
  T_RIGHT_PAREN,
  T_LEFT_ANGLE,
  T_RIGHT_ANGLE,

  T_EQUAL,
  T_PLUS_EQUAL,
  T_MINUS_EQUAL,
  T_ASTERISK_EQUAL,
  T_SLASH_EQUAL,
  T_PERCENT_EQUAL,
  T_LANGLE_EQUAL,
  T_RANGLE_EQUAL,
  T_EQUAL_EQUAL,
  T_EXCL_EQUAL,
  T_DOUBLE_LANGLE,
  T_DOUBLE_RANGLE,

  T_TILDE,
  T_AND,
  T_BAR,
  T_CARET,
  T_EXCL,
  T_BAR_BAR,
  T_AND_AND,
  T_COMMA,
  T_SEMICOLON,
  T_PLUS,
  T_MINUS,
  T_ASTERISK,
  T_SLASH,
  T_PERCENT,

  T_IN_RW,
  T_RM_RW,
  T_SIZEOF_RW,
  T_BOOL_RW,
  T_BYTE_RW,
  T_CHAR_RW,
  T_SHORT_RW,
  T_INT_RW,
  T_LONG_RW,
  T_FLOAT_RW,
  T_DOUBLE_RW,
  T_IF_RW,
  T_ELSE_RW,
  T_WHILE_RW,
  T_FOR_RW,
  T_RETURN_RW,
} TOKEN;

void print_lexical_error(t_lexical_error* error) {
  printf("<ERROR WHEN PARSING> Match: %s - Location %d:%d\n",
         error->token->characters, error->line, error->column);
}

void print_token_name(TOKEN token, char* match) {
  int print = 1;

  switch (token) {
    case T_INTEGER:
      printf("<T_INTEGER>");
      break;
    case T_REAL:
      printf("<T_REAL>");
      break;
    case T_IDENTIFIER:
      printf("<T_IDENTIFIER>");
      break;
    case T_STRING:
      printf("<T_STRING>");
      break;
    case T_LEFT_BRACE:
      printf("<T_LEFT_BRACE>");
      break;
    case T_RIGHT_BRACE:
      printf("<T_RIGHT_BRACE>");
      break;
    case T_LEFT_BRACKET:
      printf("<T_LEFT_BRACKET>");
      break;
    case T_RIGHT_BRACKET:
      printf("<T_RIGHT_BRACKET>");
      break;
    case T_LEFT_PAREN:
      printf("<T_LEFT_PAREN>");
      break;
    case T_RIGHT_PAREN:
      printf("<T_RIGHT_PAREN>");
      break;
    case T_LEFT_ANGLE:
      printf("<T_LEFT_ANGLE>");
      break;
    case T_RIGHT_ANGLE:
      printf("<T_RIGHT_ANGLE>");
      break;

    case T_EQUAL:
      printf("<T_EQUAL>");
      break;
    case T_PLUS_EQUAL:
      printf("<T_PLUS_EQUAL>");
      break;
    case T_MINUS_EQUAL:
      printf("<T_MINUS_EQUAL>");
      break;
    case T_ASTERISK_EQUAL:
      printf("<T_ASTERISK_EQUAL>");
      break;
    case T_SLASH_EQUAL:
      printf("<T_SLASH_EQUAL>");
      break;
    case T_PERCENT_EQUAL:
      printf("<T_PERCENT_EQUAL>");
      break;
    case T_LANGLE_EQUAL:
      printf("<T_LANGLE_EQUAL>");
      break;
    case T_RANGLE_EQUAL:
      printf("<T_RANGLE_EQUAL>");
      break;
    case T_EQUAL_EQUAL:
      printf("<T_EQUAL_EQUAL>");
      break;
    case T_EXCL_EQUAL:
      printf("<T_EXCL_EQUAL>");
      break;
    case T_DOUBLE_LANGLE:
      printf("<T_DOUBLE_LANGLE>");
      break;
    case T_DOUBLE_RANGLE:
      printf("<T_DOUBLE_RANGLE>");
      break;

    case T_TILDE:
      printf("<T_TILDE>");
      break;
    case T_AND:
      printf("<T_AND>");
      break;
    case T_BAR:
      printf("<T_BAR>");
      break;
    case T_CARET:
      printf("<T_CARET>");
      break;
    case T_EXCL:
      printf("<T_EXCL>");
      break;
    case T_BAR_BAR:
      printf("<T_BAR_BAR>");
      break;
    case T_AND_AND:
      printf("<T_AND_AND>");
      break;
    case T_COMMA:
      printf("<T_COMMA>");
      break;
    case T_SEMICOLON:
      printf("<T_SEMICOLON>");
      break;
    case T_PLUS:
      printf("<T_PLUS>");
      break;
    case T_MINUS:
      printf("<T_MINUS>");
      break;
    case T_ASTERISK:
      printf("<T_ASTERISK>");
      break;
    case T_SLASH:
      printf("<T_SLASH>");
      break;
    case T_PERCENT:
      printf("<T_PERCENT>");
      break;

    case T_IN_RW:
      printf("<T_IN_RW>");
      break;
    case T_RM_RW:
      printf("<T_RM_RW>");
      break;
    case T_SIZEOF_RW:
      printf("<T_SIZEOF_RW>");
      break;
    case T_BOOL_RW:
      printf("<T_BOOL_RW>");
      break;
    case T_BYTE_RW:
      printf("<T_BYTE_RW>");
      break;
    case T_CHAR_RW:
      printf("<T_CHAR_RW>");
      break;
    case T_SHORT_RW:
      printf("<T_SHORT_RW>");
      break;
    case T_INT_RW:
      printf("<T_INT_RW>");
      break;
    case T_LONG_RW:
      printf("<T_LONG_RW>");
      break;
    case T_FLOAT_RW:
      printf("<T_FLOAT_RW>");
      break;
    case T_DOUBLE_RW:
      printf("<T_DOUBLE_RW>");
      break;
    case T_IF_RW:
      printf("<T_IF_RW>");
      break;
    case T_ELSE_RW:
      printf("<T_ELSE_RW>");
      break;
    case T_WHILE_RW:
      printf("<T_WHILE_RW>");
      break;
    case T_FOR_RW:
      printf("<T_FOR_RW>");
      break;
    case T_RETURN_RW:
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

#endif

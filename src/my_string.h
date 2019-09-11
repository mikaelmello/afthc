#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <stdint.h>

typedef struct string {
  char* characters;
  uint32_t size;
  uint32_t size_with_null;
  uint32_t capacity;
} t_string;

/*
 * Creates a string struct
 */
t_string* create_string();

/*
 * Adds a character to the string
 */
void add_char(t_string* s, char c);

/*
 * Clears all characters from the string
 */
void clear_string(t_string* s);

/*
 * Frees all memory allocated for this string
 */
void free_string(t_string* s);

#endif

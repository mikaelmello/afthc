#ifndef M_STRING_H
#define M_STRING_H

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
t_string* m_string_create();

/*
 * Adds a character to the string
 * <string> String where the character will be added
 * <character> Character to be added
 */
void m_string_add_char(t_string* string, char character);

/*
 * Clears all characters from the string
 * <string> String to be cleared
 */
void m_string_clear(t_string* string);

/*
 * Frees all memory allocated for this string
 * <string> String to be freed
 */
void m_string_free(t_string* string);

#endif

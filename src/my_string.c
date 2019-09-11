#include "my_string.h"
#include <stdlib.h>
#include <string.h>

t_string* create_string() {
  t_string* s = (t_string*)calloc(1, sizeof(t_string));

  // empty string, only a null terminator
  s->characters = (char*)calloc(1, sizeof(char));

  // no size and one capacity
  s->size = 0;
  s->size_with_null = 1;
  s->capacity = 1;
  return s;
}

void add_char(t_string* s, char c) {
  uint32_t available = s->capacity - s->size_with_null;
  if (available <= 0) {
    uint32_t new_capacity = s->capacity * 2;
    s->characters = (char*)realloc(s->characters, sizeof(char) * new_capacity);
    s->capacity = new_capacity;
  }

  s->characters[s->size] = c;
  s->size += 1;
  s->size_with_null += 1;
}

void clear_string(t_string* s) {
  free(s->characters);
  // empty string, only a null terminator
  s->characters = (char*)calloc(1, sizeof(char));

  // no size and one capacity
  s->size = 0;
  s->size_with_null = 1;
  s->capacity = 1;
}

void free_string(t_string* s) {
  // assuming nothing is NULL
  free(s->characters);
  free(s);
}

#include "code_generator.h"
#include <memory.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int condition_counter = 0;
int iteration_counter = 0;

tac_program_t* tac_program_create() {
  tac_program_t* program = (tac_program_t*)calloc(1, sizeof(tac_program_t));
  return program;
}

void tac_program_free(tac_program_t* program) {
  if (program == NULL) return;

  tac_table_free(program->table);
  tac_code_free(program->code);
  free(program);
}

void tac_program_add_label(tac_program_t* program, char* name) {
  if (program == NULL) {
    printf("Trying to add label to NULL program");
    abort();
  }

  tac_code_t* code = program->code;
  int current_position = code->line_count;

  int cap = code->label_capacity;
  int count = code->label_count;

  if (count >= cap) {
    code->labels = realloc(code->labels, (cap * 2) * sizeof(tac_label_t));
    code->label_capacity *= 2;
  }

  code->labels[count].name = name;
  code->labels[count].position = current_position;
}

void tac_program_print(tac_program_t* program) {
  if (program == NULL) {
    printf("Trying to print NULL program");
    abort();
  }

  tac_table_print(program->table);
  tac_code_print(program->code);
}

tac_table_t* tac_table_create() {
  tac_table_t* table = (tac_table_t*)calloc(1, sizeof(tac_table_t));
  return table;
}

void tac_table_free(tac_table_t* table) {
  if (table == NULL) return;

  free(table);
}

void tac_table_print(tac_table_t* table) {
  if (table == NULL) {
    printf("Trying to print NULL table");
    abort();
  }

  printf(".table\n");
}

tac_code_t* tac_code_create() {
  tac_code_t* code = (tac_code_t*)calloc(1, sizeof(tac_code_t));

  code->lines = (tac_line_t*)calloc(1, sizeof(tac_line_t));
  code->line_capacity = 1;
  code->line_count = 0;

  code->labels = (tac_label_t*)calloc(1, sizeof(tac_label_t));
  code->label_capacity = 1;
  code->label_count = 0;

  return code;
}

void tac_code_print(tac_code_t* code) {
  if (code == NULL) {
    printf("Trying to print NULL code");
    abort();
  }

  printf(".code\n");

  int line_pos = 0;
  int label_pos = 0;

  while (line_pos < code->line_count) {
    // print all labels up to this line
    while (label_pos < code->label_count) {
      tac_label_t cur_label = code->labels[label_pos];
      if (cur_label.position <= line_pos) {
        printf("%s:\n", cur_label.name);
        label_pos++;
      } else {
        break;
      }
    }

    tac_line_t* line = &code->lines[line_pos];
    tac_line_print(line);
    line_pos++;
  }
}

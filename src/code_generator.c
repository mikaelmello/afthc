#include "code_generator.h"
#include <memory.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int condition_counter = 0;
int iteration_counter = 0;

tac_program_t* tac_program_create() {
  tac_program_t* program = (tac_program_t*)calloc(1, sizeof(tac_program_t));
  tac_program_initialize(program);
  return program;
}

void tac_program_initialize(tac_program_t* program) {
  tac_table_initialize(&program->table);
  tac_code_initialize(&program->code);
}

void tac_program_clean(tac_program_t* program) {
  if (program == NULL) return;

  tac_table_clean(&program->table);
  tac_code_clean(&program->code);
}

void tac_program_add_label(tac_program_t* program, char* name) {
  if (program == NULL) {
    printf("Trying to add label to NULL program");
    abort();
  }

  tac_code_t* code = &program->code;
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

  tac_table_print(&program->table);
  tac_code_print(&program->code);
}

void tac_table_initialize(tac_table_t* table) {}

void tac_table_clean(tac_table_t* table) {
  if (table == NULL) return;
}

void tac_table_print(tac_table_t* table) {
  if (table == NULL) {
    printf("Trying to print NULL table");
    abort();
  }

  printf(".table\n");
}

void tac_code_initialize(tac_code_t* code) {
  code->lines = (tac_line_t*)calloc(1, sizeof(tac_line_t));
  code->line_capacity = 1;
  code->line_count = 0;

  code->labels = (tac_label_t*)calloc(1, sizeof(tac_label_t));
  code->label_capacity = 1;
  code->label_count = 0;
}

void tac_code_clean(tac_code_t* code) {
  if (code == NULL) return;

  for (int i = 0; i < code->label_count; i++) {
    tac_label_free_members(&code->labels[i]);
  }
  free(code->labels);

  for (int i = 0; i < code->line_count; i++) {
    tac_line_free_members(&code->lines[i]);
  }
  free(code->lines);
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

void tac_label_free_members(tac_label_t* label) {
  if (label == NULL) return;

  if (label->name != NULL) {
    free(label->name);
  }
}

void tac_line_print(tac_line_t* line) { printf("line\n"); }

void tac_line_free_members(tac_line_t* line) {
  if (line == NULL) return;

  tac_operand_free(line->operands[0]);
  tac_operand_free(line->operands[1]);
  tac_operand_free(line->operands[2]);
}

void tac_operand_free(tac_operand_t* operand) {
  if (operand == NULL) return;

  switch (operand->type) {
    case LABEL:
      free(operand->value.label_name);
      break;
    case SYMBOL:
      free(operand->value.symbol_name);
      break;
    default:
      break;
  }

  free(operand);
}

#include "tac.h"
#include <memory.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "abstract_syntax_tree.h"
#include "my_string.h"
#include "scope.h"

tac_program_t* tac_program_create() {
  tac_program_t* program = (tac_program_t*)calloc(1, sizeof(tac_program_t));
  tac_program_initialize(program);
  return program;
}

void tac_program_initialize(tac_program_t* program) {
  tac_table_initialize(&program->table);
  tac_code_initialize(&program->code);
  program->stack_head = 0;
}

void tac_program_clean(tac_program_t* program) {
  if (program == NULL) return;

  tac_table_clean(&program->table);
  tac_code_clean(&program->code);
}

int tac_program_add_label(tac_program_t* program, char* name) {
  if (program == NULL) {
    printf("Trying to add label to NULL program");
    abort();
  }

  tac_code_t* code = &program->code;
  int current_position = code->line_count;

  int cap = code->label_capacity;
  int count = code->label_count;
  int id = count;

  if (count >= cap) {
    code->labels = realloc(code->labels, (cap * 2) * sizeof(tac_label_t));
    code->label_capacity *= 2;
  }

  code->labels[count].name = duplicate(name);
  code->labels[count].id = id;
  code->labels[count].position = current_position;
  code->label_count += 1;

  return id;
}

tac_label_t* tac_program_get_label(tac_program_t* program, int label_id) {
  if (program == NULL) {
    printf("Trying to add label to NULL program");
    abort();
  }
  tac_code_t* code = &program->code;

  if (label_id >= code->label_count) {
    printf("Can not find label with invalid id %d when count is %d\n", label_id,
           code->label_count);
    abort();
  }

  return &code->labels[label_id];
}

int tac_program_add_line(tac_program_t* program, tac_instr_t instr,
                         tac_operand_t* operands[3]) {
  if (program == NULL) {
    printf("Trying to add line to NULL program");
    abort();
  }

  tac_code_t* code = &program->code;

  int cap = code->line_capacity;
  int count = code->line_count;

  if (count >= cap) {
    code->lines = realloc(code->lines, (cap * 2) * sizeof(tac_line_t));
    code->line_capacity *= 2;
  }

  code->lines[count].instruction = instr;
  code->lines[count].operands[0] = operands[0];
  code->lines[count].operands[1] = operands[1];
  code->lines[count].operands[2] = operands[2];
  code->line_count += 1;
  return 1;
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
        tac_label_print(&cur_label);
        label_pos++;
      } else {
        break;
      }
    }

    tac_line_t* line = &code->lines[line_pos];
    tac_line_print(line);
    line_pos++;
  }

  // print remaining labels
  while (label_pos < code->label_count) {
    tac_label_t cur_label = code->labels[label_pos];
    if (cur_label.position <= line_pos) {
      tac_label_print(&cur_label);
      label_pos++;
    } else {
      break;
    }
  }
}

void tac_label_print(tac_label_t* label) {
  if (label == NULL) {
    printf("Warning: Trying to print null label");
    return;
  }

  if (label->name != NULL) {
    printf("%s:\n", label->name);
  } else {
    printf("label_%d:\n", label->id);
  }
}

void tac_label_free_members(tac_label_t* label) {
  if (label == NULL) return;

  if (label->name != NULL) {
    free(label->name);
  }
}

void tac_line_print(tac_line_t* line) {
  switch (line->instruction) {
    case RETURN_INSTR:
      printf("return ");
      tac_operand_print(line->operands[0]);
      printf("\n");
      break;
    default:
      printf("MISSING CASE %d\n", line->instruction);
  }
}

void tac_line_free_members(tac_line_t* line) {
  if (line == NULL) return;

  tac_operand_free(line->operands[0]);
  tac_operand_free(line->operands[1]);
  tac_operand_free(line->operands[2]);
}

void tac_operand_free(tac_operand_t* operand) {
  if (operand == NULL) return;

  switch (operand->type) {
    case SYMBOL:
      free(operand->value.symbol_name);
      break;
    default:
      break;
  }

  free(operand);
}

void tac_operand_print(tac_operand_t* operand) {
  if (operand == NULL) return;

  switch (operand->type) {
    case FUN_PARAM:
      printf("#%d\n", operand->value.fun_param);
      break;
    case TEMP_VAR:
      printf("$%d\n", operand->value.temp_var);
      break;
    case LABEL:
      if (operand->value.label->name != NULL) {
        printf("%s", operand->value.label->name);
      } else {
        printf("label_%d", operand->value.label->id);
      }
      break;
    case SYMBOL:
      printf("%s\n", operand->value.symbol_name);
      break;
    case CONSTANT:
      printf("%d\n", operand->value.constant);
  }
}

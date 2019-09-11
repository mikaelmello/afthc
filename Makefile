C		= gcc
CINCS  	= -I"inc/"
CFLAGS 	= $(CINCS) -std=c11 -O2 -lfl
SRCS	= $(shell find src -name '*.c')
OBJ		= $(addprefix obj/,$(notdir $(SRCS:%.c=%.o))) 
LEXICAL = lexical-analyzer
BIN     = tokenizer
RM      = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(LEXICAL) all-after

debug: CFLAGS = -DDEBUG $(CINCS) -std=c11 -lfl -g3 -ggdb3 -Wall -Wextra -D_GLIBCXX_DEBUG -O2 -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -Wno-unused-parameter 
debug: all

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(LEXICAL): flex compile

flex:
	flex -o src/lex.yy.c src/tokenizer.lex

compile: $(OBJ)
	$(C) $(OBJ) -o $(BIN) $(CFLAGS)

obj/%.o: src/%.c
	$(C) -c $< -o $@ $(CFLAGS)

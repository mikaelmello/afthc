all: scanner 

scanner: scanner-flex scanner-gcc

scanner-flex: src/tokenizer.lex
	flex -o src/lex.yy.c src/tokenizer.lex

scanner-gcc: my_string lexical_error_handler
	gcc src/my_string.o src/lexical_error_handler.o src/lex.yy.c -lfl -o tokenizer -Wall -Isrc/

my_string:
	gcc src/my_string.c -c -o src/my_string.o

lexical_error_handler:
	gcc src/lexical_error_handler.c -c -o src/lexical_error_handler.o

clean:
	rm *.o *.out

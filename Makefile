all: scanner 

scanner: scanner-flex scanner-gcc

scanner-flex: src/tokenizer.lex
	flex -o src/lex.yy.c src/tokenizer.lex

scanner-gcc:
	gcc src/lex.yy.c -lfl -o tokenizer -Isrc/

clean:
	rm *.o *.out

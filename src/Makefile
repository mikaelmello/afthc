all: scanner 

scanner: scanner-flex scanner-gcc

scanner-flex: tokenizer.lex
	flex tokenizer.lex

scanner-gcc:
	gcc lex.yy.c -lfl -o tokenizer

clean:
	rm *.o *.out

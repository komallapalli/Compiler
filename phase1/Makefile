parser: parser.y scanner.l
	bison -d parser.y
	flex scanner.l
	gcc -o parser parser.tab.c lex.yy.c -ll
clean: parser parser.tab.h parser.tab.c lex.yy.c
	rm parser
	rm parser.tab.c
	rm parser.tab.h
	rm lex.yy.c

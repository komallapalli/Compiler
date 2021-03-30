%{
#include <stdio.h>
extern FILE *yyin;
int yylex();
void yyerror();
%}

%start file

%token MAIN INT UINT CHAR BOOL LIST ',' ';' ':' TEXT IF ELSEIF ELSE FUNC BREAK CONTINUE WHILE FOR SCANIN PRINTOUT READIN
%token WRITEOUT DIGIT NUMBER IDENTIFIER '+' '-' '*' '%' '/' '(' ')' '{' '}' '[' ']' LOGEQ LOGOR LOGAND LEQ NOTEQ GEQ '>'
%token '<' '&' '|' '=' '^' '!' '?' LOGPLUS LOGSUB RETURN TRUE FALSE

%left LOGOR LOGAND '|' '^' '&' NOTEQ LOGEQ GEQ '>' LEQ '<' '-' '+' '%' '/' '*' ')' '('

%right '='

%%

file : spec_function main_func | main_func ;

main_func : type FUNC MAIN '(' ')' '{' statement_list '}';

spec_function : type fname '(' arguments ')' '{' statement_list '}';

fname : IDENTIFIER ;

type : INT | CHAR | BOOL | UINT

arguments :  | nargument;

nargument : arg | nargument ',' arg

arg : type IDENTIFIER | LIST IDENTIFIER '[' NUMBER ']' | LIST IDENTIFIER '[' NUMBER ']' '[' NUMBER ']'  ;

statement_list : declaration statements;

declaration : d_state ';' declaration |  ;

d_state : type word ;

word : var ',' word | var ;

var : LIST IDENTIFIER '[' NUMBER ']' | LIST IDENTIFIER '[' NUMBER ']' '[' NUMBER ']' | IDENTIFIER ;

statements : forloop statements
            | whileloop statements
            | condition statements
            | print ';' statements
            | scan ';' statements
	          | stmt ';' statements
            | RETURN expression ';'
            |
	          ;

VARIABLE : IDENTIFIER | LIST IDENTIFIER '[' expression ']' | LIST IDENTIFIER '[' expression ']' '[' expression ']' ;

forcon : LEQ | GEQ ;

forend : LOGSUB | LOGPLUS ;

forloop : FOR '(' IDENTIFIER '=' expression ';' IDENTIFIER forcon expression ';' IDENTIFIER forend ')' '{' statement_list '}'

whileloop : WHILE '(' comexpression ')' '{' statement_list '}'

condition : IF '(' comexpression ')' '{' statement_list '}'
          | IF '(' comexpression ')' '{' statement_list '}' ELSEIF '(' comexpression ')' '{' statement_list '}'
          | IF '(' comexpression ')' '{' statement_list '}' ELSEIF '(' comexpression ')' '{' statement_list '}' ELSE '{' statement_list '}'
          | IF '(' comexpression ')' '{' statement_list '}' ELSE '{' statement_list '}'

print : PRINTOUT '(' IDENTIFIER ')'
      | PRINTOUT '(' TEXT ')'
      | PRINTOUT '(' expression ')'
      ;

scan : SCANIN '(' IDENTIFIER ')' ;

stmt : VARIABLE '=' stmt
     | expression
     ;

comexpression : expression LOGOR expression
     	        | expression LOGAND expression
     	        | expression LOGEQ expression
     	        | expression NOTEQ expression
     	        | expression GEQ expression
     	        | expression '>' expression
     	        | expression LEQ expression
     	        | expression '<' expression
     	        | '(' comexpression ')'
     	        ;

expression : expression '|' expression
           | expression '^' expression
           | expression '&' expression
           | expression '-' expression
           | expression '+' expression
           | expression '%' expression
           | expression '/' expression
           | expression '*' expression
           | '(' expression ')'
           | VARIABLE
           | NUMBER
           | DIGIT
           | fname '(' arguments ')'
           | TRUE
           | FALSE
           ;

%%

void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}

int main(int argc, char **argv)
{
        yyparse();
        printf("Parsing Done Succesfully!\n");
        return 0;
}

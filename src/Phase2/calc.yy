/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#include "ast.h"
#include "scanner.h"
#include "driver.h"

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start file

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="decaf"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

/*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
  int ival;
	std::string *sval;
	class FileASTnode* filenode;
	class Main_funcASTnode* mainfuncnode;
	class TypeASTnode* typenode;
  class Spec_funcASTnode* specfunctionnode;
  class FnameASTnode* fnamenode;
  class ArgumentsASTnode* argumentsnode;
  class NargumentASTnode* nargumentnode;
  class ArgASTnode* argnode;
  class Statement_listASTnode* statement_listASTnode;
  class DeclarationASTnode* declarationASTnode;
  class D_stateASTnode* d_stateASTnode;
  class WordASTnode* wordASTnode;
  class VarASTnode* VarASTnode;
  class StatementsASTnode* statementsASTnode;
  class VARIABLEASTnode* variableASTnode;
  class ForconASTnode* forconASTnode;
  class ForendASTnode* forendASTnode;
  class ForloopASTnode* forloopASTnode;
  class WhileloopASTnode* whileloopASTnode;
  class ConditionASTnode* conditionASTnode;
  class PrintASTnode* printASTnode;
  class ScanASTnode* scanASTnode;
  class StmtASTnode* stmtASTnode;
  class ExpressionASTnode* expressionASTnode;
}

%type <filenode> file
%type <mainfuncnode> main_func
%type <typenode> type
%type <specfunctionnode> spec_function
%type <fnamenode> fname
%type <argumentsnode> arguments
%type <nargumentnode> nargument
%type <argnode> arg
%type <statement_listASTnode> statement_list
%type <declarationASTnode> declaration
%type <d_stateASTnode> d_state
%type <wordASTnode> word
%type <VarASTnode> var
%type <statementsASTnode> statements
%type <variableASTnode> VARIABLE
%type <forconASTnode> forcon
%type <forendASTnode> forend
%type <forloopASTnode> forloop
%type <whileloopASTnode> whileloop
%type <conditionASTnode> condition
%type <printASTnode> print
%type <scanASTnode> scan
%type <stmtASTnode> stmt
%type <expressionASTnode> expression


//%destructor { delete $$; } expr

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%token END 0
%token EOL

%token<ival> NUMBER DIGIT
%token<sval> MAIN INT UINT CHAR BOOL LB RB LFB RFB FUNC IDENTIFIER COMMA LSB RSB LIST SEMICO EQ LEQ GEQ LOGSUB LOGPLUS
%token<sval> FOR WHILE IF ELSEIF ELSE PRINTOUT SCANIN PLUS MINUS MUL DIV PIP PO AMP PER TRUE FALSE RETURN LOGEQ
%token<sval> LOGOR NOTEQ LOGAND GREAT LESS TEXT 

%left LB RB

%%

file : main_func { $$ = new FileASTnode($1); driver.ast.pRoot = $$;}
     | spec_function main_func  { $$ = new FileASTnode($1,$2); driver.ast.pRoot = $$;}


main_func : type FUNC MAIN LB RB LFB statement_list RFB  { $$ = new Main_funcASTnode($1,$7);}

spec_function : type fname LB arguments RB LFB statement_list RFB  { $$ = new Spec_funcASTnode($1,$2,$4,$7);}

type : INT  { $$ = new TypeASTnode(*$1);}
      | CHAR { $$ = new TypeASTnode(*$1);}
      | BOOL { $$ = new TypeASTnode(*$1);}
      | UINT { $$ = new TypeASTnode(*$1);}

arguments : nargument   { $$ = new ArgumentsASTnode($1);}

fname : IDENTIFIER { $$ = new FnameASTnode(*$1);}

statement_list : declaration statements { $$ = new Statement_listASTnode($1,$2);}

nargument : arg  { $$ = new NargumentASTnode();$$->push_back($1);}
          | nargument COMMA arg  { $$ = $1;$$->push_back($3);}

arg : type IDENTIFIER   { $$ = new ArgASTnode($1,*$2);}
    | LIST IDENTIFIER LSB expression RSB  { $$ = new ArgASTnode(*$2,$4);}
    | LIST IDENTIFIER LSB expression RSB LSB expression RSB { $$ = new ArgASTnode(*$2,$4,$7);}

// statement_list : declaration statements { $$ = new Statement_listASTnode($1,$2);}

declaration : d_state SEMICO declaration  {$3->push_back($1);$$ = $3;}
            | {$$ = new DeclarationASTnode();}
            ;

d_state : type word { $$ = new D_stateASTnode($1,$2);}

word : var COMMA word  {$3->push_back($1);$$ = $3;}
      | var  { $$ = new WordASTnode();$$->push_back($1);}
      ;

var : LIST IDENTIFIER LSB expression RSB { $$ = new VarASTnode(*$2,$4);}
      | LIST IDENTIFIER LSB expression RSB LSB expression RSB  { $$ = new VarASTnode(*$2,$4,$7);}
      | IDENTIFIER  { $$ = new VarASTnode(*$1);}
      ;

statements : forloop statements     {$2->push_back($1);$$ = $2;}
            | whileloop statements  {$2->push_back($1);$$ = $2;}
            | condition statements  {$2->push_back($1);$$ = $2;}
            | print SEMICO statements  {$3->push_back($1);$$ = $3;}
            | stmt SEMICO statements   {$3->push_back($1);$$ = $3;}
      	    | scan SEMICO statements   {$3->push_back($1);$$ = $3;}
            | RETURN expression SEMICO  { $$ = new StatementsASTnode($2);}
            |  {$$ = new StatementsASTnode();}
            ;

VARIABLE : IDENTIFIER  { $$ = new VARIABLEASTnode(*$1);}
           | LIST IDENTIFIER LSB expression RSB   { $$ = new VARIABLEASTnode(*$2,$4);}
           | LIST IDENTIFIER LSB expression RSB LSB expression RSB   { $$ = new VARIABLEASTnode(*$2,$4,$7);}
                      ;

forcon : LEQ  { $$ = new ForconASTnode();}
        | GEQ  { $$ = new ForconASTnode();}
        ;

forend : LOGSUB  { $$ = new ForendASTnode();}
        | LOGPLUS { $$ = new ForendASTnode();}
        ;

whileloop : WHILE LB expression RB LFB statement_list RFB  { $$ = new WhileloopASTnode($3,$6);}

forloop : FOR LB IDENTIFIER EQ expression SEMICO IDENTIFIER forcon expression SEMICO IDENTIFIER forend RB LFB statement_list RFB  { $$ = new ForloopASTnode(*$3,$5,*$7,$9,*$11,$15);}


condition : IF LB expression RB LFB statement_list RFB  { $$ = new ConditionASTnode($3,$6);}
            | IF LB expression RB LFB statement_list RFB ELSEIF LB expression RB LFB statement_list RFB   { $$ = new ConditionASTnode($3,$6,$10,$13);}
            | IF LB expression RB LFB statement_list RFB ELSEIF LB expression RB LFB statement_list RFB ELSE LFB statement_list RFB  { $$ = new ConditionASTnode($3,$6,$10,$13,$17);}
            | IF LB expression RB LFB statement_list RFB ELSE LFB statement_list RFB  { $$ = new ConditionASTnode($3,$6,$10);}

print : PRINTOUT LB IDENTIFIER RB   { $$ = new PrintASTnode(*$3);}
      | PRINTOUT LB  RB    { $$ = new PrintASTnode();}
      | PRINTOUT LB TEXT RB { $$ = new PrintASTnode(*$3);}
      | PRINTOUT LB expression RB  { $$ = new PrintASTnode($3);}
      ;

scan : SCANIN LB VARIABLE RB     { $$ = new ScanASTnode($3);}

stmt : VARIABLE EQ stmt  {$3->push_back($1);$$ = $3;}
     |   expression  { $$ = new StmtASTnode();$$->push_back($1);}
     ;


expression : expression PIP expression    { $$ = new ExpressionASTnode(new BinaryASTnode("|", $1, $3)); }
            | expression PO expression    { $$ = new ExpressionASTnode(new BinaryASTnode("^", $1, $3)); }
            | expression AMP expression    { $$ = new ExpressionASTnode(new BinaryASTnode("&", $1, $3)); }
            | expression MINUS expression    { $$ = new ExpressionASTnode(new BinaryASTnode("-", $1, $3)); }
            | expression PLUS expression    { $$ = new ExpressionASTnode(new BinaryASTnode("+", $1, $3)); }
            | expression PER expression    { $$ = new ExpressionASTnode(new BinaryASTnode("%", $1, $3)); }
            | expression DIV expression    { $$ = new ExpressionASTnode(new BinaryASTnode("/", $1, $3)); }
            | expression MUL expression    { $$ = new ExpressionASTnode(new BinaryASTnode("*", $1, $3)); }
            | expression LOGOR expression    { $$ = new ExpressionASTnode(new BinaryASTnode("||", $1, $3)); }
            | expression LOGAND expression   { $$ = new ExpressionASTnode(new BinaryASTnode("&&", $1, $3)); }
            | expression LOGEQ expression     { $$ = new ExpressionASTnode(new BinaryASTnode("==", $1, $3)); }
            | expression NOTEQ expression     { $$ = new ExpressionASTnode(new BinaryASTnode("!=", $1, $3)); }
            | expression GEQ expression       { $$ = new ExpressionASTnode(new BinaryASTnode(">=", $1, $3)); }
            | expression GREAT expression       { $$ = new ExpressionASTnode(new BinaryASTnode(">", $1, $3)); }
            | expression LEQ expression       { $$ = new ExpressionASTnode(new BinaryASTnode("<=", $1, $3)); }
            | expression LESS expression       { $$ = new ExpressionASTnode(new BinaryASTnode("<", $1, $3)); }
            | VARIABLE                     { $$ = new ExpressionASTnode($1);}
            | NUMBER                       { $$ = new ExpressionASTnode();}
            | DIGIT                        { $$ = new ExpressionASTnode();}
            | fname LB arguments RB      { $$ = new ExpressionASTnode($1,$3);}
            | TRUE                         { $$ = new ExpressionASTnode();}
            | FALSE                        { $$ = new ExpressionASTnode();}
            ;


%%

void decaf::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

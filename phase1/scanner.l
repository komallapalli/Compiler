%{
#include "parser.tab.h"
int lineno = 0;
%}

character \\n|\\t|\\'|\\\\|\\\"|[^\\"']


%%


"main"	{return MAIN;}

"int"		{return INT;}
"uint"		{return UINT;}
\'{character}\'		{return CHAR;}
"bool"		{return BOOL;}
"list"		{return LIST;}
","		  {return ',';}
";"		{return ';';}
":"	  {return ':';}
\".*\"		{return TEXT;}

"if"		{return IF;}
"elsif"		{return ELSEIF;}
"else"		{return ELSE;}
"func"		{return FUNC;}
"break"		{return BREAK;}
"return"  {return RETURN;}
"continue"		{return CONTINUE;}
true        {return TRUE;}
false       {return FALSE;}

"while"		{return WHILE;}
"for"		{return FOR;}


"printout"		{return PRINTOUT;}
"scanin"	{return SCANIN;}
"readin"		{return READIN;}
"writeout"		{return WRITEOUT;}

([0-9])		{return DIGIT;}
[1-9][0-9]*	{return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* {return IDENTIFIER;}
"+"	{return '+';}
"-"	{return '-';}
"*"	{return '*';}
"/"	{return '/';}
"%"	{return '%';}

"("	{return '(';}
")"	{return ')';}
"{"	{return '{';}
"}"	{return '}';}
"["	{return '[';}
"]"	{return ']';}

"=="	{return LOGEQ;}
"||"	{return LOGOR;}
"<="	{return LEQ;}
"!="	{return NOTEQ;}
">="	{return GEQ;}
"&&"	{return LOGAND;}
"++"	{return LOGPLUS;}
"--"	{return LOGSUB;}

">"		{return '>';}
"<"		{return '<';}
"="		{return '=';}
"&"		{return '&';}
"|"		{return '|';}
"^"		{return '^';}
"!"		{return '!';}
"?"		{return '?';}
[ \t]		{ /* Do nothing */ }
"\n"		{++lineno;}
.		{
		  printf("Unexpected token encountered: %d\n", lineno);
		}

%%

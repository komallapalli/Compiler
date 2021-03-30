/* $Id$ -*- mode: c++ -*- */
/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>
#include "scanner.h"

/* import the parser's token type into a local typedef */
typedef decaf::Parser::token token;
typedef decaf::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "decafFlexLexer" */
%option prefix="decaf"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug
%option yylineno
/* no support for include files is planned */
%option yywrap nounput

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

char \\n|\\t|\\'|\\\\|\\\"|[^\\"']

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}




"uint"		{yylval->sval = new std::string(yytext); return token::UINT;}
"bool"		{yylval->sval = new std::string(yytext); return token::BOOL;}
"main"	{yylval->sval = new std::string(yytext); return token::MAIN;}
"int"		{yylval->sval = new std::string(yytext); return token::INT;}
"func"		{yylval->sval = new std::string(yytext); return token::FUNC;}
"list"		{yylval->sval = new std::string(yytext); return token::LIST;}
true        {yylval->sval = new std::string(yytext); return token::TRUE;}
false       {yylval->sval = new std::string(yytext); return token::FALSE;}
"for"		{yylval->sval = new std::string(yytext); return token::FOR;}
"while"		{yylval->sval = new std::string(yytext); return token::WHILE;}
"if"		{yylval->sval = new std::string(yytext); return token::IF;}
"elseif"		{yylval->sval = new std::string(yytext); return token::ELSEIF;}
"else"		{yylval->sval = new std::string(yytext); return token::ELSE;}
"printout"		{yylval->sval = new std::string(yytext); return token::PRINTOUT;}
"scanin"	{yylval->sval = new std::string(yytext); return token::SCANIN;}
"return"  {yylval->sval = new std::string(yytext); return token::RETURN;}
[a-zA-Z][a-zA-Z0-9]*  {yylval->sval = new std::string(yytext); return token::IDENTIFIER;}
[1-9][0-9]*	{yylval->ival = std::atoi(yytext); return token::NUMBER;}
([0-9])		{yylval->ival = std::atoi(yytext); return token::DIGIT;}
"=="	{yylval->sval = new std::string(yytext); return token::LOGEQ;}
"||"	{yylval->sval = new std::string(yytext); return token::LOGOR;}
"!="	{yylval->sval = new std::string(yytext); return token::NOTEQ;}
"&&"	{yylval->sval = new std::string(yytext); return token::LOGAND;}
">"		{yylval->sval = new std::string(yytext); return token::GREAT;}
"<"		{yylval->sval = new std::string(yytext); return token::LESS;}
"("	{yylval->sval = new std::string(yytext); return token::LB;}
")"	{yylval->sval = new std::string(yytext); return token::RB;}
"{"	{yylval->sval = new std::string(yytext); return token::LFB;}
"}"	{yylval->sval = new std::string(yytext); return token::RFB;}
","	{yylval->sval = new std::string(yytext); return token::COMMA;}
";"	{yylval->sval = new std::string(yytext); return token::SEMICO;}
"["	{yylval->sval = new std::string(yytext); return token::LSB;}
"]"	{yylval->sval = new std::string(yytext); return token::RSB;}
"="		{yylval->sval = new std::string(yytext); return token::EQ;}
"<="	{yylval->sval = new std::string(yytext); return token::LEQ;}
">="	{yylval->sval = new std::string(yytext); return token::GEQ;}
"++"	{yylval->sval = new std::string(yytext); return token::LOGPLUS;}
"--"	{yylval->sval = new std::string(yytext); return token::LOGSUB;}
"+"	{yylval->sval = new std::string(yytext); return token::PLUS;}
"-"	{yylval->sval = new std::string(yytext); return token::MINUS;}
"*"	{yylval->sval = new std::string(yytext); return token::MUL;}
"/"	{yylval->sval = new std::string(yytext); return token::DIV;}
"%"	{yylval->sval = new std::string(yytext); return token::PER;}
"&"		{yylval->sval = new std::string(yytext); return token::AMP;}
"|"		{yylval->sval = new std::string(yytext); return token::PIP;}
"^"		{yylval->sval = new std::string(yytext); return token::PO;}
\".*\" {yylval->sval = new std::string(yytext); return token::TEXT;}

\'{char}\'	{yylval->sval = new std::string(yytext); return token::CHAR;}


 /* gobble up white-spaces */
[ \t\r]+ {
    yylloc->step();
}

 /* gobble up end-of-lines */
\n {
    yylloc->lines(yyleng); yylloc->step();
    return token::EOL;
}

 /* pass all other characters up to bison */
. {
    return static_cast<token_type>(*yytext);
}


%% /*** Additional Code ***/

namespace decaf {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : decafFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of DecafFlexLexer::yylex() is required to fill the
 * vtable of the class DecafFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int decafFlexLexer::yylex()
{
    std::cerr << "in decafFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int decafFlexLexer::yywrap()
{
    return 1;
}

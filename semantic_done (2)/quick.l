%option yylineno
%{
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include "quick.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
%}

%%
[\t ]+					;
[\n]                     {printf("\n");};
"HEY"					{printf("<  HEY  > ");return HEY;}
">>"					{printf("<  >>  > ");yylval.STRINGG =  strdup(yytext);return FORWARD;}
"<<"					{printf("<  <<  > ");yylval.STRINGG =  strdup(yytext);return BACKWARD;}

"->"					{printf("<Pointer, ->  > ");yylval.STRINGG =  strdup(yytext);return POINTER;}
"&&"					{printf("<  &&  > ");yylval.STRINGG =  strdup(yytext);return AND_AND;}
"||"					{printf("<  ||  > ");yylval.STRINGG =  strdup(yytext);return OR_OR;}

"==" 					{printf("<  ==  > ");yylval.STRINGG =  strdup(yytext);return EQUAL_EQUAL;}
"!=" 					{printf("<  !=  > ");yylval.STRINGG =  strdup(yytext);return NOT_EQUAL;}
"<" 					{printf("<  <  > ");return yytext[0];}
">" 					{printf("<  >  > ");return yytext[0];}
"<=" 					{printf("<  <=  > ");yylval.STRINGG =  strdup(yytext);return LESS_THAN_EQUAL;}
">=" 					{printf("<  >=  > ");yylval.STRINGG =  strdup(yytext);return GREATER_THAN_EQUAL;}

"!" 					{printf("<  !  > ");return yytext[0];}


"("				{printf("<(> ");return yytext[0];return OB;}
")"				{printf("<)> ");return yytext[0];return CB;}
"{"				{printf("<{> ");return yytext[0];}
"}"				{printf("<}> ");return yytext[0];}

"["				{printf("<[> ");return yytext[0];}
"]"				{printf("<]> ");return yytext[0];}
","				{printf("<,> ");return yytext[0];return COMMA;}
"="				{printf("<=> ");return yytext[0];}
"#"             {printf("<#> ");return yytext[0];}
"++"					{printf("<++> ");yylval.STRINGG =  strdup(yytext);return PLUS_PLUS;}
"--"					{printf("<--> ");yylval.STRINGG =  strdup(yytext);return MINUS_MINUS;}

"%"				{printf("( mod ) ");return yytext[0];}
"/"					{printf("<Div> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
"*"					{printf("<Mult> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
"+"					{printf("<Add> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
"-"					{printf("<Sub> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}

"NULL"              {printf("<NULL> ");yylval.STRINGG =  strdup(yytext);return NULL1;}
"Main"				{printf("<main> ");yylval.STRINGG =  strdup(yytext);return MAIN;}
"quickin"				{printf("<quickin> ");yylval.STRINGG =  strdup(yytext);return QUICKIN;}
"quickout"				{printf("<quickout> ");yylval.STRINGG =  strdup(yytext);return QUICKOUT;}
";"				{printf("<end >");yylval.STRINGG =  strdup(yytext);return N;}
"include"				{printf("<include> ");yylval.STRINGG =  strdup(yytext);return INCLUDE;}
"Macro"				{printf("<macro> ");yylval.STRINGG =  strdup(yytext);return MACRO;}
"int"				{printf("<int> ");yylval.STRINGG =  strdup(yytext);return DATA_TYPE_INT;}
"char"				{printf("<char> ");yylval.STRINGG =  strdup(yytext);return DATA_TYPE_STRING;}
"string"			{printf("<string> ");yylval.STRINGG =  strdup(yytext);return DATA_TYPE_STRING;}
"float"				{printf("<float> ");yylval.STRINGG =  strdup(yytext);return DATA_TYPE_INT;}
"return"			{printf("<return> ");yylval.STRINGG =  strdup(yytext);return RETURN;}
"if"			{printf("<if> ");yylval.STRINGG =  strdup(yytext);return IF;}
"else"			{printf("<else> ");yylval.STRINGG =  strdup(yytext);return ELSE;}
"for"			{printf("< for > ");yylval.STRINGG =  strdup(yytext);return FOR;}

[a-zA-Z][a-zA-Z_]*           	   	{
						if(yyleng >=255){printf("Unrecognised stuff");}
						else 
						{	
							printf("<Variable> ");
							yylval.STRINGG =  strdup(yytext);
							return 	STRING;
						}
					}

[0-9]+ 	                                {printf("<VALUE> ");yylval.NUMBERR = atoi(yytext); return VALUE;}
".h"					{printf("<Header file extension, .h> ");yylval.STRINGG =  strdup(yytext);return H;}

"~"					{printf("<Spl.char> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
"`"					{printf("<Spl.char> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
"@"					{printf("<Spl.char> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
"$"					{printf("<Spl.char> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
"^"					{printf("<Spl.char> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
":"					{printf("<Spl.char> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
"."					{printf("<Spl.char> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}
"?"					{printf("<Spl.char> ");yylval.STRINGG =  strdup(yytext);return yytext[0];}


.		 			{printf("unrecognised stuff ");}
%%
int yywrap (void) {return 1;}

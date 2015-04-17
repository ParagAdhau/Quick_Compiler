%option yylineno
%{
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include "mips.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
%}

%%
[\t ]+					;
[\n]                     {printf("\n");};
";"				{yylval.STRINGG =  strdup(yytext);return N;}
":"				{yylval.STRINGG =  strdup(yytext);return C;}
","				{yylval.STRINGG =  strdup(yytext);return COMMA;}

"<" 					{return yytext[0];}
">" 					{return yytext[0];}
"<=" 					{yylval.STRINGG =  strdup(yytext);return LE;}
">=" 					{yylval.STRINGG =  strdup(yytext);return GE;}
"==" 					{yylval.STRINGG =  strdup(yytext);return EE;}

"= Call"				{yylval.STRINGG =  strdup(yytext);return NAYA;}
"Recp"				{yylval.STRINGG =  strdup(yytext);return RECIEVEPARAM;}
"End"				{yylval.STRINGG =  strdup(yytext);return END;}
"Call"				{yylval.STRINGG =  strdup(yytext);return CALL;}
"Push"				{yylval.STRINGG =  strdup(yytext);return PARAM;}
"Return"				{yylval.STRINGG =  strdup(yytext);return RETURN;}
"Func"				{yylval.STRINGG =  strdup(yytext);return FUNC;}
"Begin"				{yylval.STRINGG =  strdup(yytext);return BEGIN1;}
"False"				{yylval.STRINGG =  strdup(yytext);return FALSE;}
"if"				{yylval.STRINGG =  strdup(yytext);return IF;}
"Print"				{yylval.STRINGG =  strdup(yytext);return PRINT;}
"goto"				{yylval.STRINGG =  strdup(yytext);return GOTO;}
"!" 					{return yytext[0];}


"("				{return yytext[0];return OB;}
")"				{return yytext[0];return CB;}

"="				{return yytext[0];return EQUAL;}
"/"					{yylval.STRINGG =  strdup(yytext);return yytext[0];}
"*"					{yylval.STRINGG =  strdup(yytext);return yytext[0];}
"+"					{yylval.STRINGG =  strdup(yytext);return yytext[0];}
"-"					{yylval.STRINGG =  strdup(yytext);return yytext[0];}

[a-zA-Z][a-zA-Z_]*[0-9]*           	   	{
						if(yyleng >=255){printf("Unrecognised stuff");}
						else 
						{	
							yylval.STRINGG =  strdup(yytext);
							return 	STRING;
						}
					}
[0-9]+ 	                                {yylval.STRINGG =  strdup(yytext); return VALUE;}

.					{printf("unrecognised stuff ");}
%%
int yywrap (void) {return 1 ;}

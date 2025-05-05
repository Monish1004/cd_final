%{
#include<stdio.h>
%}

letter[a-zA-Z]
digit[0-9]
sign[+-]

%%
{letter}+ {
	printf("Found an identifier : %s\n" , yytext); 
}
{sign}?{digit}+ {
	printf("Found an constant : %s\n" , yytext);
}

%%

int yywrap(){
	return 1;
}

int main(){
	printf("Enter an expression : ");
	yylex();
	return 0;
}


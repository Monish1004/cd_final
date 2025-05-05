%{
#include<stdio.h>
int word_count = 0;
int line_count = 0;
%}

%%
[a-zA-Z_]	{ word_count++; }
[\n]		{ line_count++; }
\t		;

%%


int yywrap(){
	return 1;
}

int main(){
	yylex();
	printf("The number of lines are : %d \n" , line_count);
	printf("The number of words are : %d \n" , word_count);
	return 0;
}


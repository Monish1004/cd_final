%{
#include<stdio.h>
#include "y.tab.h"
#include<stdlib.h>
int yyerror(char *s);
int yylex(void);
%}

%token ID NUM
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

stmt :
     expn
     ;
expn :
      expn '+' expn
     |expn '-' expn
     |expn '*' expn
     |expn '/' expn
     |'-'expn  %prec UMINUS
     |'(' expn ')'
     |ID
     |NUM
     ;

%%

int main(){
	printf("Enter an expression : ");
	yyparse();
	printf("Valid Expression");
	return 0;
}

int yyerror(char *s){
	printf("Invalid expression\n");
	printf("Error -> %s" , s);
	return 0;
}


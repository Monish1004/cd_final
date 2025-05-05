%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
int yyerror(char *s);
%}

%token DIG LET

%%

varaible:
	var
	;
	var :
		var DIG
	    |	var LET
    	    |	LET
	    ;

%%

int main(){
	printf("Enter an expression : ");
	yyparse();
	printf("Valid expression\n");
	return 0;
}

int yyerror(char *s){

	printf("Invalid expression\n");
	exit(1);
	return 0;
}



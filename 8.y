%{
#include <stdio.h>
#include <stdlib.h>

// Declare the error function for yacc
int yylex(void);
extern int yyerror(char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

input:
    /* empty */
    | input line
    ;

line:
    '\n'
    | expr '\n'     { printf("Result = %d\n", $1); }
    ;

expr:
    NUMBER              { $$ = $1; }
    | expr '+' expr     { $$ = $1 + $3; }
    | expr '-' expr     { $$ = $1 - $3; }
    | expr '*' expr     { $$ = $1 * $3; }
    | expr '/' expr     { 
                            if ($3 == 0) {
                                printf("Error: Division by zero\n"); exit(1); 
                            } 
                            $$ = $1 / $3; 
                         }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | '(' expr ')'       { $$ = $2; }
    ;

%%

int yyerror(char *s) {
    printf("Syntax Error: %s\n", s);
    return 0;
}

int main() {
    printf("Enter an expression (Ctrl+D to exit):\n");
    return yyparse();
}


%{
#include<stdio.h>
#include "y.tab.h"

%}


%%

[a-zA-Z][0-9A-Za-z]* 	{ return ID; }
[0-9]+			{ return NUM; }
[ \t]			;
\n			return 0;
.			{ return yytext[0]; }


%%

int yywrap(){
	return 1;
}

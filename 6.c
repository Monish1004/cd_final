#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const char *input;
int pos = 0;

char lookahead(){
	return input[pos];
}

void error(){
	printf("Error at %d position\n" , pos);
	exit(1);
}

void match(char ch){
	if(lookahead() == ch){
		pos++;
	}
	else {
		error();
	}
}

void S();
void L();

void S(){
	if(lookahead() == 'a'){
		match('a');
	}
	else if(lookahead() == '('){
		match('(');
		L();
		match(')');
	}
	else {
		error();
	}
}

void L(){
	S();
	while(lookahead() == ','){
		match(',');
		S();
	}
}

int main(){
	char buff[100];
	printf("Enter a string : ");
	scanf("%s" , buff);
	input = buff;
	pos = 0;
	S();
	if(lookahead() == '\0'){
		printf("String is successfully parsed\n");
	}
	else {
		error();
	}
	return 0;
}


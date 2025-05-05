#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char input[100];
int i = 0;

void E();
void EPrime();
void T();
void TPrime();
void F();
void error();

void error(){
	printf("Error at %d position\n", i);
	exit(1);
}

void E(){
	T();
	EPrime();
}

void EPrime(){
	if(input[i] == '+'){
		i++;
		T();
		EPrime();
	}
}

void T(){
	F();
	TPrime();
}

void TPrime(){
	if(input[i] == '*'){
		i++;
		F();
		TPrime();
	}
}

void F(){
	if(input[i] == '('){
		i++;
		E();
		if(input[i] == ')'){
			i++;
		}
		else {
			error();
		}
	} 
	else if(isalnum(input[i])){
		i++;
	}
	else {
		error();
	}
}


int main(){
	printf("Enter an arithematic expression : ");
	fgets(input , sizeof(input) , stdin);
	
	input[strcspn(input , "\n")] = '\0';
	E();

	if(input[i] =='\0')
		printf("accepted\n");
	else 
		printf("rejected\n");
	return 0;
}



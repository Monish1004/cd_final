#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Variable {
	char name;
	char type;
};

int main(){
	int n;
	struct Variable vars[15];
	char expr[100];
	int i = 0 , f = 0;
	char name;
	printf("Enter the number of variables : ");
	scanf("%d" ,&n);
	getchar();
	for(int i = 0; i < n; i++){
		char type[10] , name;
		printf("Enter the variable declaration : ");
		scanf("%s %c" , type , &name);
		getchar();
		vars[i].name = name;
		if(strcmp(type , "int") == 0){
			vars[i].type = 'i';
		}
		else if(strcmp(type , "float") == 0){
			vars[i].type = 'f';
		}
		else if(strcmp(type , "char") == 0){
			vars[i]/type = 'c';
		}
		else {
			printf("Unsupported type\n");
			return 1;
		}
	}
	printf("Enter the expressions and end with $");
	i = 0;
	while((ch = getchar())!= '$'){
		if(ch == '/') f = 1;
		expr[i++] = ch;
	}	
	expr[i] = '\0';
	char first = expr[0];
	for(int i = 0; i < n; i++){
		if(vars[i].name == name){
			if(vars[i].type == 'c'){
				printf("Invalid comparision\n");
			}
			else if(vars[i].type == 'i'){
				printf("data type is correct\n");
			}
			else {
				printf("float\n");
			}
		}
		break;
	}
	return 0;
}
						
		

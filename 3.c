#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

void check(char str[]){
	const char* keywords[] = {
		"for" , "int" , "float" , "char" , "static" , "bool" , "const" , "while" , "do" , "auto"};
	int n = sizeof(keywords) / sizeof(keywords[0]);
	
	int flag = 0;
	for(int i = 0; i < n; i++){
		if(strcmp(str , keywords[i]) == 0){
			flag = 1;
			break;
		}
	}
	if(flag){
		printf("%s is a keyword\n" , str);
	}
	else {
		printf("%s is an identifier\n" , str);
	}
}

int main(){
	FILE *f1 , *f2 , *f3;
	int i = 0 , k = 0 , tokenValue = 0 , num[MAX] , lineno = 0;
	char ch , str[MAX];
	
	printf("Enter a C - Program : ");
	f1 = fopen("input.txt" , "w");
	if(f1 == NULL){
		printf("Error opening the file\n");
		return 1;
	}

	while((ch = getchar()) != EOF){
		putc(ch , f1);
	}
	fclose(f1);
	
	f1 = fopen("input.txt" , "r");
	if(f1 == NULL){
		printf("Error opening the file\n");
		return 1;
	}
	f2 = fopen("identifier.txt" , "w");
	f3 = fopen("specialcharacters.txt" , "w");
	if(f2 == NULL || f3 == NULL){
		printf("Error opening the files\n");
		return 1;
	}

	while((ch = getc(f1)) != EOF){
		if(isdigit(ch)){
			tokenValue = ch - '0';
			while(isdigit(ch = getc(f1))){
				tokenValue = tokenValue * 10 + (ch - '0');
			}
			num[i++] = tokenValue;
			ungetc(ch , f1);
		}	
		else if(isalpha(ch)){
			str[k++] = ch;
			while(isalnum(ch = getc(f1))){
				str[k++] = ch;
			}
			str[k] = '\0';
			check(str);
			k = 0;
			ungetc(ch , f1);
		}
		else if(!isspace(ch)){
			putc(ch , f3);
		}
		if(ch == '\n'){
			lineno++;
		}
	}

	fclose(f1);
	fclose(f2);
	fclose(f3);
	return 0;
}	

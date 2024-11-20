#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char expression[200];
char stack[100];
int check(char c){
	if(c == '/' || c == '*'){
		return 2;
	}else{
		return 1;
	}
}
void in2post(){
	int top_ptr = 0;
	int len = strlen(expression);
	for(int i=0;i<len ;i++){
		if((expression[i] <= 'z' && expression[i] >='a') || (expression[i] <= 'Z' && expression[i] >='A')){
			printf("%c",expression[i]);
		}else{
			while(check(stack[top_ptr-1]) >= check(expression[i]) && top_ptr != 0){
				printf("%c",stack[top_ptr-1]);
				top_ptr--;
			}
			stack[top_ptr++] = expression[i];
		}
	}
	while(top_ptr != 0){
		printf("%c",stack[top_ptr-1]);
		top_ptr--;
	}
	printf("\n");
}
int main(){
    scanf("%s",expression); 
	in2post();
}

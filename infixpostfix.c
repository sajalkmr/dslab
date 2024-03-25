#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x){
	stack[++top] = x;
}

char pop(){
	if(top == -1) return -1;
	return stack[top--];
}

int priority(char x){
	if (x== '(')            return 1;
	if (x == '+' || x== '-')     return 2;
	if (x == '*' || x == '/' || x=='%')  return 3;
	if( x == '^' || x== '$')    return 4;
	return 1;
}


int main(){
	char expression[100];
	char symbol, a;
	printf("Enter infix: ");
	scanf("%s", expression);
	
	printf("postfix expression: ");
	
	for( int i=0; i<strlen(expression); i++){
		symbol = expression[i];
		
		if(isalnum(symbol)){
			printf("%c ", symbol);
		}
		else if(symbol == '('){
			push(symbol);
		}
		else if(symbol == ')'){
			while((a=pop()) != '('){
				printf("%c ",a);
			}
		}
		else{
			while(priority(stack[top]) >= priority(symbol)){
				printf("%c", pop());
			}
			push(symbol);
		}
	}
	
	while(top != -1){
		printf("%c", pop());
	}
	
	printf("\n");
	
	
}
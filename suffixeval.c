#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int compute(char symbol, int op1, int op2){
	switch(symbol){
		case '+' : return op1+op2;
		case '-' : return op1-op2;
		case '*' : return op1*op2;
		case '%' : return op1%op2;
		case '/' : return op1/op2;
		case '^' : return pow(op1,op2);
	}
}

int main(){
	char expression[30];
	int stack[20];
	int top =-1;
	int result, final, i, op1, op2;
	char symbol;
	
	printf("Enter suffix exp: \n");
	scanf("%s", expression);
	
	for(int i=0; i<strlen(expression); i++){
		symbol = expression[i];
		if(isdigit(symbol)){
			stack[++top] = symbol - '0';
		}
		else{
			op2 = stack[top--];
			op1 = stack[top--];
			result = compute(symbol, op1, op2);
			stack[++top] = result;
		}
	}
	
	final = stack[top--];
	printf("eval: %d", final);
}
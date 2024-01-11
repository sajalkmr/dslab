#include<stdio.h>

#define MAX 5
int top = -1; 
int s[MAX - 1];

void push(int elem) {
   if(top == MAX - 1) {
      printf("\nStack Overflow!!!");
   }
   else {
      top = top + 1;  
      s[top] = elem; 
   }
}

int pop() {
   int del;
   if(top == -1) {
      printf("\nStack Underflow!!!");
      return(-1);
   }
   else {
      del = s[top];
      top = top - 1;
      return(del);
   } 
}

int palindrome() {
   int n, i, p[10], flag = 0;
   printf("\nEnter the number of digits: ");
   scanf("%d", &n);
   printf("\nEnter the digits: ");
   for(i = 0; i < n; i++)  
      scanf("%d", &p[i]);
      
   for(i = 0; i < n; i++)
      push(p[i]);
      
   for(i = 0; i < n; i++) {
      if(p[i] != pop()) {
         flag = 1;
         break;
      }
   }
   
   if(flag == 0)
      printf("\nPALINDROME!!!"); 
   else
      printf("\nNOT PALINDROME!!!");
}

void display() {
   int i;
   if(top == -1) {  
      printf("\nStack is Empty!!!");
   }
   else {
     printf("\nThe elements of stack are: ");
     for(i = top; i >= 0; i--)  
        printf("\t%d",s[i]);
   }
}

int main() {
   int ch, elem, del_elem, flag;
   
   for(;;) {
      printf("\n---------------------------------------------");
      printf("\nSTACK OPERATIONS");
      printf("\n1: Push \n2: Pop \n3: Check Palindrome \n4: Display \n5: Exit");
      printf("\n---------------------------------------------");
      printf("\nEnter your choice: ");
      scanf("%d", &ch);
      
      switch(ch) {
         case 1: 
            printf("\nEnter the element to push onto the stack: ");
            scanf("%d", &elem);
            push(elem);
            break;
            
         case 2: 
            del_elem = pop();
            if(del_elem == -1) 
               printf("\nNo element to delete!!!\n");
            else
               printf("\nThe deleted element is: %d", del_elem);
            break;
            
         case 3: 
            palindrome();
            break;
            
         case 4:
            display();
            break;
            
         case 5:
            return(0);
            
         default:
            printf("\nInvalid Choice!!!\n");
      }
   }
   
   return(0);
}
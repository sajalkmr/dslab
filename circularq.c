#include<stdio.h>
#include<stdlib.h>
#define cqsize 5

char cq[cqsize];
int f=0, r=-1;
int count =0;

void insert(char elem){
	if(r == cqsize){
		printf("cq full");
		return;
	}
	r = (r+1)%cqsize;
	cq[r] = elem;
	count++;
	printf("%d inserted",elem);
}

void delete(){
	if(count == 0){
		printf("cq empty");
		return;
	}
	
	char elem = cq[f];
	count--;
	printf("deleted item is: %c", elem);
	if(f==r){
		f= 0;
		r=-1;
	}
	f= (f+1)%cqsize;
}

void display(){
	if(count == 0){
		printf("cq empty");
		return;
	}
	int t= f;
	printf("cq contents: \n");
	for(int i=1; i<=count; i++){
		printf("%c", cq[t]);
		t= (t+1)%cqsize;
	}
	printf("\n");
	
}

void main(){
	printf("1. insert 2. delete 3. display 4.exit");
}

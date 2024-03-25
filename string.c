#include<stdio.h>

char str[50], pat[20], rep[20], ans[50];
int i =0, j=0, c=0, m=0, k, flag = 0;

void patternmatch(){
	while(str[c]!='\0'){
		if(str[m]==pat[i]){
			i++;
			m++;
			if(pat[i]=='\0'){
				flag =1;
				for(k=0; rep[k]!='\0';k++,j++){
					ans[j]=rep[k];
				}
				c=m;
				i=0;
			}
		}
		
		else{
			ans[j] = str[c];
			j++;
			c++;
			m=c;
			i=0;
		}
	}
	ans[j]='\0';
}

int main(){
	printf("Enter the main string: \n");
	gets(str);
	printf("Enter the pattern: \n");
	gets(pat);
	printf("Enter the replacement string: \n");
	gets(rep);
	patternmatch();
	
	if(flag == 1){
		printf("pattern found, new string: %s", ans);
		
	}
	else{
		printf("PAttern not found\n");
	}

	return 0;
}
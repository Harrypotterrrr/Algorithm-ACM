#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int tar,len,num[12],code[12];
char quo[12];
bool flag;
bool cmp(char a, char b){
	return a > b;
}

void decode(int x){
	if(x == 5){
		if(code[0] - pow(code[1],2) + pow(code[2],3)\
		 - pow(code[3],4) + pow(code[4],5) == tar){
		 	flag = true;
		 	printf("%c%c%c%c%c\n",code[0]+'@',code[1]+'@'\
			 ,code[2]+'@',code[3]+'@',code[4]+'@');
		 	return ;
		 }
		 return ;
	}
	for(int i=0 ; i<len ; i++){
		if(num[i]){
			int temp = num[i];
			code[x] = num[i];
			num[i] = 0;
			decode(x+1);
			if(flag)
				return;
			num[i] = temp;
		}
	}					
}

int main(){
	while(true){
		memset(quo,'\0',sizeof(quo));
		flag = false;
		scanf("%d%s",&tar,quo);
		if(!tar && !strcmp(quo,"END"))
			break;
		len = strlen(quo);
		for(int i=0 ; i<len ; i++)
			num[i] = quo[i] + 1 -'A';
		sort(num,num+len,cmp);	
		decode(0);		
		if(!flag)
			printf("no solution\n");
	}
	return 0;
}

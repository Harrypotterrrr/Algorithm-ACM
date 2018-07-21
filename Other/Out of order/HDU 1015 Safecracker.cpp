#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int tar,len;
char quo[12];
bool cmp(char a, char b){
	return a > b;
}
bool flag(int a, int b, int c, int d,int e){
	if(a != b && a != c && a != d && a != e && b != c \
	&& b != d && b != e && c != d && c != e && d != e)
		return 1;
	else 
		return 0;
}
void decode(){
	sort(quo,quo+len,cmp);
	int n[12];
	for(int i=0 ; i<len ; i++)	
		n[i] = quo[i] - '@';		
	for(int i_0=0; i_0<=len-1 ; i_0++)
		for(int i_1=0; i_1<=len-1 ; i_1++)
			for(int i_2=0; i_2<=len-1 ; i_2++)
				for(int i_3=0; i_3<=len-1 ; i_3++)
					for(int i_4=0; i_4<=len-1 ; i_4++)	{
							if(flag(n[i_0],n[i_2],n[i_3],n[i_4],n[i_1])\
							&& n[i_0] - pow(n[i_1],2) - pow(n[i_3],4) \
							+ pow(n[i_2],3) + pow(n[i_4],5) == tar){
								printf("%c%c%c%c%c\n",n[i_0]+'@',n[i_1]+\
								'@',n[i_2]+'@',n[i_3]+'@',n[i_4]+'@');
								return;
							}
					}
	printf("no solution\n");
	return;					
}

int main(){
	while(true){
		memset(quo,'\0',sizeof(quo));
		scanf("%d%s",&tar,quo);
		if(!tar && !strcmp(quo,"END"))
			break;
		len = strlen(quo);
		decode();
	}
	return 0;
}

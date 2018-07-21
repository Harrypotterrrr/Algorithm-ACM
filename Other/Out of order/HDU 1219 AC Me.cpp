#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
	int n[26];
	char str[100001],s='a';
	while(gets(str)){
		memset(n,0,sizeof(n));
		int len = strlen(str);
		for(int i=0 ; i<len ; i++)
			if(str[i] >= 97 && str[i] <= 122)
				n[ str[i] - 'a'] ++;	
		for(int i=0 ; i<=25 ; i++)
			printf("%c:%d\n",s+i,n[i]);
		printf("\n");
	}
	return 0;
}

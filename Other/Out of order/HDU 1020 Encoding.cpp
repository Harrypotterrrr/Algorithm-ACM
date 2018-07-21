#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
//	freopen("r.txt","r",stdin);
//	freopen("w.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		char c;
		int count=1;
		scanf(" %c",&c);
		while(true){
			char s;
			s = c;
			scanf("%c",&c);
			if(s == c)
				count++;
			else{
				if(count == 1)
					printf("%c",s);
				else
					printf("%d%c",count,s);
				count = 1;
			}
			if(c == '\n'){
				printf("\n");
				break;
			}	
		}
	}
	return 0;
}              

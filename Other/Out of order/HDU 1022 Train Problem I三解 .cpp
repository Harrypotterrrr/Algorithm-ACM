#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>
using namespace std ;
int main()
{
    stack<int> stac;
    char in[13],out[13],str[2][4] = {"out","in"};
	int n;
	bool flag[30];
	while(scanf("%d%s%s",&n,in,out) != EOF){
		while(!stac.empty()) 
			stac.pop();
		memset(flag,0,sizeof(flag));
		stac.push(in[0]);
		flag[0] = true;
		int p_out = 0,p_in = 0,p_flag = 0;
		while(p_in < n){
			if(stac.size() && stac.top() == out[p_out]){
				flag[++ p_flag] = false;
				stac.pop();
				p_out ++;
			}
			else{
				flag[++ p_flag] = true;
				stac.push(in[ ++ p_in]);
			}
		}
		if(p_out == n){
			printf("Yes.\n");
			for(int i=0 ; i<=2*n-1 ; i++)
				printf("%s\n",str[flag[i]]);
		}
		else
			printf("No.\n");
		printf("FINISH\n");
			
	}
    return 0 ;
}

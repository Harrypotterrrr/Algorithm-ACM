#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std ;
int main()
{
	int n;
	bool flag[24];
	char in[12],out[12],stac[12];
	char str[][4] = {"out","in"};
    while(scanf("%d%s%s",&n,in,out) != EOF){
    	memset(flag,false,sizeof(flag));
    	memset(stac,0,sizeof(stac));
    	int n_stack = 0,n_out = 0,n_in = 0,n_flag = 0;
		stac[0] = in[0];
		flag[0] = true;
		while(n_in < n && n_out < n){
    		if(n_stack >=0 && stac[n_stack] == out[n_out]){
    			flag[++ n_flag ] = false;
    			stac[n_stack --] = -1;
    			n_out ++;
    		}
			else{
    			flag[++ n_flag ] = true;
    			stac[++ n_stack] = in[++ n_in];
    		}
    	}
		if(n_in == n)
			printf("No.\n");
		else{ 
    		printf("Yes.\n");
			for(int i=0 ; i<=2*n-1 ; i++)
				printf("%s\n",str[flag[i]]);
		}
		printf("FINISH\n");
	}
    return 0 ;
}

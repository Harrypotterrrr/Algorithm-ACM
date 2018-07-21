#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std ;
int main()
{
	int n;
	bool flag[20];
	char in[9],out[9],stac[9];
	char str[][4] = {"out","in"};
    while(scanf("%d%s%s",&n,in,out) != EOF){
    	memset(flag,false,sizeof(flag));
    	memset(stac,0,sizeof(stac));
    	int n_stack = 0,n_out = 0,n_in = 1,n_flag = 1;
		stac[0] = in[0];
		flag[0] = true;
		while(n_in <= n && n_out <= n){
    		if(stac[n_stack] != out[n_out] && out[n_out] != in[n_in]){
    			flag[n_flag ++] = true;
    			stac[++ n_stack] = in[n_in ++];
    		}
    		else if(in[n_in] == out[n_out]){
    			flag[n_flag ++] = true;
    			flag[n_flag ++] = false;
    			n_in ++;
    			n_out ++;
    		}
			else if(stac[n_stack] == out[n_out]){
    			flag[n_flag ++] = false;
    			stac[n_stack --] = 0;
    			n_out ++;
    		}	
    	}
    	if(n_stack == -1){ 
    		printf("Yes.\n");
			for(int i=0 ; i<=n*2-1 ; i++)
				printf("%s\n",str[flag[i]]);
		}
		else
			printf("No.\n");
		printf("FINISH\n");
	}
    return 0 ;
}

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int num[100005],n;
int main(){
	int T;
	scanf("%d",&T);
    for(int k=1 ; k<=T ; k++){
    	scanf("%d",&n);
		int s_st=1,s_ed=1,t_st=1,t_ed=1;
    	int sum=0,temp=0;
		for(int i=1 ; i<=n ; i++){
    		scanf("%d",&num[i]);
			if(temp < 0){
				temp = 0;
				t_st = i;
			}
    		temp += num[i];
    		t_ed = i;
    		if(!sum || sum < temp){
    			sum = temp;
    			s_st = t_st;
    			s_ed = t_ed;
			}
		}
		printf("Case %d:\n%d %d %d\n",k,sum,s_st,s_ed);
		if(k != T)
			printf("\n");
	}
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	int T,t,x,START,start,END,end,max,sum,j=1,k=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&t);
		START = start = END = end = 1;
		scanf("%d",&x);
		max = sum = x;
		for(int i=2 ; i<=t ; i++){
			scanf("%d",&x);
			if(sum < 0){
				start = end = i;
				sum = x;
			}
			else{
				end ++;
				sum += x; 
			}
			if(max < sum){
				START = start;
				END = end;
				max = sum;
			}
		}
		if(j-- == 1)
			printf("Case %d:\n%d %d %d",k++,max,START,END);
		else
			printf("\nCase %d:\n%d %d %d",k++,max,START,END);
		printf("\n");
	}
	return 0;
} 

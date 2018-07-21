#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int main()  
{
	int n[4],ans[30];
	int time = 1;
	while(scanf("%d%d%d%d",&n[0],&n[1],&n[2],&n[3]) != EOF){
		if(n[0] + n[1] + n[2] + n[3] == 0)
			break;
		if(time != 1)
			cout<<endl;
		time ++;
		sort(n,n+4);
		int i=0;
		do{
			if(n[0] != 0){
				int tmp = 1000*n[0] + 100*n[1] + 10*n[2] + n[3];
				ans[i] = tmp;
				i++; 
			}
		}while(next_permutation(n,n+4));
		printf("%d",ans[0]);
		for(int j=1 ; j<i ; j++){
			if(ans[j]/1000 == ans[j-1]/1000)
				printf(" %d",ans[j]);
			else
				printf("\n%d",ans[j]);
		}
		puts("");
	}
    return 0;  
}

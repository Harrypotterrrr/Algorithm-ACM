#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int ans[1005][1005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		memset(ans,0,sizeof ans);
		int val[1005],vol[1005];
		int N,V;
		scanf("%d%d",&N,&V);
		for(int i=1 ; i<=N ; i++)
			scanf("%d",&val[i]);
		for(int i=1 ; i<=N ; i++)
			scanf("%d",&vol[i]);
		for(int i=1 ; i<=N ; i++){
			for(int j=0 ; j<=V ; j++){//从0开始,因为可能有物品体积为0 
				if(j >= vol[i])
					ans[i][j] = max(ans[i-1][j],ans[i-1][j-vol[i]]+val[i]);
				else
					ans[i][j] = ans[i-1][j];
			}
		}
		printf("%d\n",ans[N][V]);
	}
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int val[1005],vol[1005],ans[1005];
		int N,V;
		memset(ans,0,sizeof ans);
		scanf("%d%d",&N,&V);
		for(int i=1 ; i<=N ; i++)
			scanf("%d",&val[i]);
		for(int i=1 ; i<=N ; i++)
			scanf("%d",&vol[i]);
		for(int i=1 ; i<=N ; i++)
			for(int j=V ; j>=vol[i] ; j--)
				ans[j] = max(ans[j],ans[j-vol[i]]+val[i]);
		printf("%d\n",ans[V]);
	}
    return 0;
}

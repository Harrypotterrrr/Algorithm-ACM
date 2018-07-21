#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int T,N,ans[2005];
	int dis[2005],st[2005],ed[2005];
	while(scanf("%d%d",&T,&N) != EOF){
		memset(ans,0x3f,sizeof ans);
		memset(dis,0,sizeof dis);
		memset(st,0,sizeof st);
		memset(ed,0,sizeof ed);
		ans[N] = 0;
		for(int i=1 ; i<=T ; i++)
			scanf("%d%d%d",ed+i,st+i,dis+i);
		for(int i=1 ; i<N ; i++)
			for(int j=1 ; j<=T ; j++){
				ans[ed[j]] = min(ans[ed[j]],ans[st[j]]+dis[j]);
				ans[st[j]] = min(ans[st[j]],ans[ed[j]]+dis[j]);
				//Ë«±ß²Ù×÷
			}
		printf("%d\n",ans[1]);
	}
    return 0;  
}

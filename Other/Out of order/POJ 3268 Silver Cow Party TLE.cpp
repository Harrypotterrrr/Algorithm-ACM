#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int dis[1005][1005];
int N,M,X,x,y,ans;
void Floyd(){
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=N ; j++)
			for(int k=1 ; k<=N ; k++)
				dis[j][k] = min(dis[j][k],dis[i][k]+dis[j][i]);
}
int main()
{
	while(scanf("%d%d%d",&N,&M,&X) != EOF){
		ans = 0;
		memset(dis,0x3f,sizeof dis);
		for(int i=1 ; i<=M ; i++){
			scanf("%d%d",&x,&y);
			scanf("%d",dis[x]+y);
		}
		Floyd();
		for(int i=1 ; i<=N ; i++)
			ans = max(ans,dis[i][X] + dis[X][i]);
		printf("%d\n",ans);
	}
    return 0;  
}

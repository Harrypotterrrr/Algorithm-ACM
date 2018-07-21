#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int d[1005][1005];
int dis[1005][1005];
int N,M,X,a,b,ans;
typedef pair <int,int> P;
void Dijkstra(int x){
	priority_queue <P,vector<P>,greater<P> > Q;
	memset(dis[x]+1,0x3f,sizeof(dis[x]));
	Q.push(P(0,x));
	dis[x][x] = 0;
	while(!Q.empty()){
		P nw = Q.top();
		Q.pop();
		int far = nw.first,y = nw.second;
		if(dis[x][y] < far)
			continue;
		for(int i=1 ; i<=N ; i++){
			if(d[y][i] == INF)
				continue;
			if(dis[x][i] > far + d[y][i]){
				dis[x][i] = far + d[y][i];
				Q.push(P(dis[x][i],i));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&X);
	ans = 0;
	memset(d,0x3f,sizeof d);
	for(int i=1 ; i<=M ; i++){
		scanf("%d%d",&a,&b);
		scanf("%d",d[a]+b);
	}
	for(int i=1 ; i<=N ; i++)
		Dijkstra(i);
	for(int i=1 ; i<=N ; i++)
		ans = max(ans,dis[i][X] + dis[X][i]);
	printf("%d\n",ans);
    return 0;  
}

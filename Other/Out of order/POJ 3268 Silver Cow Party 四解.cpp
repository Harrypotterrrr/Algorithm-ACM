#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int d[1005][1005],d2[1005][1005];
int dis[1005],dis2[1005];
int N,M,X,a,b,ans;
typedef pair <int,int> P;
void Dijkstra(int x){
	priority_queue <P,vector<P>,greater<P> > Q;
	memset(dis,0x3f,sizeof dis);
	Q.push(P(0,x));
	dis[x] = 0;
	while(!Q.empty()){
		P nw = Q.top();
		Q.pop();
		int far = nw.first,y = nw.second;
		if(dis[y] < far)
			continue;
		for(int i=1 ; i<=N ; i++){
			if(d[y][i] == INF)
				continue;
			if(dis[i] > far + d[y][i]){
				dis[i] = far + d[y][i];
				Q.push(P(dis[i],i));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&X);
	ans = 0;
	memset(d,0x3f,sizeof d);
	memset(d2,0x3f,sizeof d2);
	for(int i=1 ; i<=M ; i++){
		scanf("%d%d",&a,&b);
		scanf("%d",d[a]+b);
		d2[b][a] = d[a][b];
	}
	Dijkstra(X);
	for(int i=1 ; i<=N ; i++){
		for(int j=1 ; j<=N ; j++)
			d[i][j] = d2[i][j];
		dis2[i] = dis[i];
	}
	Dijkstra(X);
	for(int i=1 ; i<=N ; i++)
		ans = max(ans,dis[i] + dis2[i]);
	printf("%d\n",ans);
    return 0;  
}

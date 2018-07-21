#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
int dis[1105][1105];
int ans[1105];
bool vis[1105];
int A,B,N,sum=0;
typedef pair<int,int> P;
void Dijkstra(int a,int b){
	priority_queue <P,vector<P>,greater<P> > Q;
	Q.push(P(0,a));
	ans[A] = 0;
	vis[A] = true;
	while(!Q.empty()){
		P nw = Q.top();
		Q.pop();
		vis[nw.second] = true;
		for(int i=1 ; i<=sum ; i++){
			if(!vis[i] && ans[i] > nw.first + dis[nw.second][i]){
				ans[i] = nw.first + dis[nw.second][i];
				Q.push(P(ans[i],i));
			}
		}
	}
}
void init(){
	memset(dis,0x3f,sizeof dis);
	memset(ans,0x3f,sizeof ans);
	memset(vis,false,sizeof vis);
	for(int i=1 ; i<=N ; i++)
		dis[i][i] = 0;
}
int main()
{
	while(scanf("%d%d%d",&N,&A,&B) != EOF){
		init();
		for(int i=1 ; i<=N ; i++){
			int T,temp_to;
			scanf("%d",&T);
			sum += T;
			for(int j=1 ; j<=T ; j++){
				scanf("%d",&temp_to);
				if(j == 1)
					dis[i][temp_to] = 0;
				else
					dis[i][temp_to] = 1;
			}
		}
		Dijkstra(A,B);
		if(ans[B] == INF)
			printf("-1\n");
		else
			printf("%d\n",ans[B]);
	}
    return 0;
}

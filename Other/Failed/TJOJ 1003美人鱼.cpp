#include <iostream>
#include <stdio.h>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
int dis[1005];
bool vis[1005];
int n,m,S,T;
struct Edge{
	int from,to,cost;
	Edge(){}
	Edge(int a,int b,int c){
		from = a;
		to = b;
		cost = c;
	}
	bool operator <(const Edge &r)const{
    	return cost>r.cost;
	}
}edge[15004];
void Dijkstra(int S){
	priority_queue <int,vector<int>,greater<int> > Q;
	dis[S] = 0;
	Q.push(S);
	while(!Q.empty()){
		int nw = Q.top();
		Q.pop();
		vis[nw] = false;
		for(int i=0 ; i<m ; i++){
			Edge temp = edge[i];
			if(temp.from != nw)
				continue;
			if(dis[temp.to] > dis[nw] + temp.cost){
				dis[temp.to] = dis[nw] + temp.cost;
				if(!vis[temp.to]){
					Q.push(temp.to);
					vis[temp.to] = true;
				}
			}
		}
	}
}
void init(){
	memset(dis,0x3f,sizeof dis);
	memset(vis,false,sizeof vis);
	memset(edge,0,sizeof edge);
}
int main()
{
	while(scanf("%d%d",&n,&m) != EOF){
		init();
		int t_from,t_to,t_cost;
		for(int i=0 ; i<m ; i++)
			scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].cost);
		scanf("%d%d",&S,&T);
		Dijkstra(S);
//		int ans = 0;
//		for(int i=0 ; i<m ; i++)
//			if(dis[i] == dis[T] +  1)
//				ans --;
//		printf("%d\n",ans + 1);
		printf("%d\n",dis[T]);
	}
	return 0;
}

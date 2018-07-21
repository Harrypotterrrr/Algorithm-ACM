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
int layer[10005],ans[10005];
bool vis[10005];
int N,M,C,k;
struct Node{
	int from,to,cost;
	Node(){}
	Node(int a,int b,int c){
		from = a;
		to = b;
		cost = c;
	}
}node[10005];
typedef pair<int,int> P;
void Dijkstra(){
	priority_queue <P,vector<P>,greater<P> > Q;
	ans[1] = 0;
	Q.push(P(0,1));
	while(!Q.empty()){
		P nw = Q.top();
		Q.pop();
		vis[nw.second] = true;
		if(ans[nw.second] > nw.first)
			continue;
		for(int i=1 ; i<k ; i++){
			Node n = node[i];
			if(n.from != nw.second)
				continue;
			if(!vis[n.to] && ans[n.to] > n.cost + nw.first){
				ans[n.to] = n.cost + nw.first;
				Q.push(P(ans[n.to],n.to));
			}
		}
	}
}
void init(){
	memset(node,0,sizeof node);
	memset(layer,0,sizeof layer);
	memset(ans,0x3f,sizeof ans);
	memset(vis,false,sizeof vis);
	k = 1;	
}
int main()
{
	int T,tmp;
	scanf("%d",&T);
	for(int t=1 ; t<=T ; t++){
		init();
		scanf("%d%d%d",&N,&M,&C);
		for(int i=1 ; i<=N ; i++){
			scanf("%d",&tmp);
			layer[tmp] = i;
		}
		for(int i=2 ; i<=N ; i++)
			if(layer[i] && layer[i-1]){
				node[k] = Node(layer[i],layer[i-1],C);
				node[k+1] = Node(layer[i-1],layer[i],C);
				k += 2;
			}
		int temp_from[10005],temp_to[10005],temp_cost[10005];
		for(int i=1 ; i<=M ; i++)
			scanf("%d%d%d",&temp_from[i],&temp_to[i],&temp_cost[i]);
		for(int i=1 ; i<=M ; i++){
			node[k] = Node(temp_from[i],temp_to[i],temp_cost[i]);
			node[k+1] = Node(temp_to[i],temp_from[i],temp_cost[i]);
			k += 2;
		}
		Dijkstra();
		if(ans[N] == INF)
			printf("Case #%d: -1\n",t);
		else
			printf("Case #%d: %d\n",t,ans[N]);
	}
    return 0;  
}

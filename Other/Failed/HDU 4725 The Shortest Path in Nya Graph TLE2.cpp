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
	Node(int a,int b){
		cost = a;
		to = b;
	}
	bool operator <(const Node &r)const{
        return cost>r.cost;
    }
}node[10005];
void Dijkstra(){
	priority_queue <Node> Q;
	ans[1] = 0;
	Q.push(Node(0,node[1].to));
	while(!Q.empty()){
		Node nw = Q.top();
		Q.pop();
		vis[nw.to] = true;
		if(ans[nw.to] > nw.cost)
			continue;
		for(int i=1 ; i<k ; i++){
			Node n = node[i];
			if(n.from != nw.to)
				continue;
			if(!vis[n.to] && ans[n.to] > n.cost + nw.cost){
				ans[n.to] = n.cost + nw.cost;
				Q.push(Node(ans[n.to],n.to));
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
			if(labs(layer[temp_from[i]] - layer[temp_to[i]]) == 1 && temp_cost[i] > C)
				continue;
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

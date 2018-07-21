#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 2005;
const int maxm = 205;
int N,M,k,st,ed;
int first[maxm],dis[maxm];
bool vis[maxm];
struct Edge{
	int to,cost,next;
}edge[maxn];
void SPFA(){
	queue <int> Q;
	dis[st] = 0;
	vis[st] = true;
	Q.push(st);
	while(!Q.empty()){
		int nw = Q.front();
		Q.pop();
		vis[nw] = false;		//??? 为什么要加这一行？ 
		for(int i=first[nw] ; i != -1 ; i = edge[i].next){
			int temp = edge[i].to;
			if(dis[temp] > dis[nw] + edge[i].cost){
				dis[temp] = dis[nw] + edge[i].cost;				
				if(!vis[temp]){
					vis[temp] = true;
					Q.push(temp);
				}
			}
		}
	}
}
void add(int from,int to,int cost){
	edge[k].to = to;
	edge[k].cost = cost;
	edge[k].next = first[from];
	first[from] = k ++;
}
void init(){
	memset(first,-1,sizeof first);
	memset(vis,false,sizeof vis); 
	memset(dis,0x3f,sizeof dis);
	k = 0;
}
int main()
{
	while(scanf("%d%d",&N,&M) != EOF){
		int temp_from,temp_to,temp_cost;
		init();
		for(int i=0 ; i<M ; i++){
			scanf("%d%d%d",&temp_from,&temp_to,&temp_cost);
			add(temp_from,temp_to,temp_cost);
			add(temp_to,temp_from,temp_cost);
		}
		scanf("%d%d",&st,&ed);
		SPFA();
		if(dis[ed] == INF)
			printf("-1\n");
		else
			printf("%d\n",dis[ed]);
	}
    return 0;  
}

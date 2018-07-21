#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int N,M,W,num;
int dis[505];
struct Edge{
	int from,to,cost;
	Edge(){}
	Edge(int a,int b,int c){
		from = a;
		to = b;
		cost = c;
	}
}edge[5205];
bool Bellman(){
	memset(dis,0x3f,sizeof dis);
	dis[edge[0].from] = 0;
	//这一行如果不加，将上一行改为 memset(dis,0,sizeof dis);也对？？ 
	for(int i=1 ; i<=N ; i++)
		for(int j=0 ; j<num ; j++){
			if(dis[edge[j].to] > dis[edge[j].from] + edge[j].cost){
				if(i == N)
					return true;
				dis[edge[j].to] = dis[edge[j].from] + edge[j].cost;
			}
		}
	return false;
}
int main()
{
	int T,x,y,z;
	scanf("%d",&T);
	while(T--){
		num = 0;
		memset(edge,0,sizeof edge);
		scanf("%d%d%d",&N,&M,&W);
		for(int i=1 ; i<=M ; i++){
			scanf("%d%d%d",&x,&y,&z);
			edge[num++] = Edge(x,y,z);
			edge[num++] = Edge(y,x,z);
		}
		for(int i=1 ; i<=W ; i++){
			scanf("%d%d%d",&x,&y,&z);
			edge[num++] = Edge(x,y,-z);
		}
		if(Bellman())
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;  
}

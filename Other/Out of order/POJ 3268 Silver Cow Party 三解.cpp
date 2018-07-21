#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
struct Node{
	int to,cost;
	Node(){}
	Node(int _to,int _cost):to(_to),cost(_cost) { }
};
int dis[1005][1005];
int N,M,X,a,b,c,ans;
typedef pair <int,int> P;
vector <Node> V[1005];
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
		for(int i=0 ; i< V[y].size() ; i++){
			int To = V[y][i].to,Cost = V[y][i].cost;
			if(dis[x][To] > Cost + dis[x][y]){
				dis[x][To] = Cost + dis[x][y];
				Q.push(P(dis[x][To],To));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&X);
	ans = 0;
	for(int i=1 ; i<=M ; i++){
		scanf("%d%d%d",&a,&b,&c);
		V[a].push_back(Node(b,c));
	}
	for(int i=1 ; i<=N ; i++)
		Dijkstra(i);
	for(int i=1 ; i<=N ; i++)
		ans = max(ans,dis[i][X] + dis[X][i]);
	printf("%d\n",ans);
    return 0;  
}

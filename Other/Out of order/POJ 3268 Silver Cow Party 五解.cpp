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
int dis[1005],dis2[1005];
int N,M,X,a,b,c;
typedef pair <int,int> P;
vector <vector<Node> > V(1005);
vector <vector<Node> > V2(1005);
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
		for(int i=0 ; i< V[y].size() ; i++){
			int To = V[y][i].to,Cost = V[y][i].cost;
			if(dis[To] > Cost + dis[y]){
				dis[To] = Cost + dis[y];
				Q.push(P(dis[To],To));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&X);
	for(int i=1 ; i<=M ; i++){
		scanf("%d%d%d",&a,&b,&c);
		V[a].push_back(Node(b,c));
		V2[b].push_back(Node(a,c));
	}
	Dijkstra(X);
	V = V2;
	memcpy(dis2,dis,sizeof dis);
	Dijkstra(X);
	for(int i=1 ; i<=N ; i++)
		dis[i] += dis2[i];
	printf("%d\n",*max_element(dis+1,dis+N+1));
    return 0;  
}

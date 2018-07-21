#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct Node{
	int to,cost;
	Node(){}
	Node(int a,int b){
		to = a;
		cost = b;
	}
	bool operator <(const Node &r)const{
        return cost>r.cost;
    }
};
vector <Node> V[1000005];
int sum[1000005];
long long ans;
bool vis[1000005];
void Dijkstra(){
	priority_queue <Node> Q;
	memset(sum,0x3f,sizeof sum);
	memset(vis,false,sizeof vis);
	sum[1] = 0;
	Q.push(Node(1,0));
	while(!Q.empty()){
		Node nw = Q.top();
		Q.pop();
		int Fst = nw.cost,Snd = nw.to;
		if(Fst > sum[Snd] || vis[Snd])
			continue;
		vis[Snd] = true;
		for(int i=0 ; i<V[Snd].size() ; i++){
			int To = V[Snd][i].to,Cost = V[Snd][i].cost;
			if(!vis[To] && sum[To] > sum[Snd] + Cost){
				sum[To] = sum[Snd] + Cost;
				Q.push(Node(To,sum[To]));
			}
		}
	}
}
int a[1000005],b[1000005],c[1000005];
int main()
{
	int N,p,q;
	scanf("%d",&N);
	while(N --){
		memset(sum,0,sizeof sum);
		ans = 0;
		scanf("%d%d",&p,&q);
		for(int i=0 ; i<=p ; i++)
			V[i].clear();
		for(int i=0 ; i<q ; i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		for(int i=0 ; i<q ; i++)
			V[a[i]].push_back(Node(b[i],c[i]));
		Dijkstra();
		for(int i=1 ; i<=p ; i++)
			ans += sum[i];
		for(int i=0 ; i<=p ; i++)
			V[i].clear();
		for(int i=0 ; i<q ; i++)
			V[b[i]].push_back(Node(a[i],c[i]));
		Dijkstra();
		for(int i=1 ; i<=p ; i++)
			ans += sum[i];
		printf("%lld\n",ans);
	}
    return 0;
}

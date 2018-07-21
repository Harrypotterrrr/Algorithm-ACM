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
};
vector <vector<Node> > V(1000005);
vector <vector<Node> > V2(1000005);
long long sum[1000005],ans;
typedef pair <int,int> P;
void Dijkstra(){
	priority_queue <P,vector<P>,greater<P> > Q;
	memset(sum,0x3f,sizeof sum);
	sum[1] = 0;
	Q.push(P(0,1));
	while(!Q.empty()){
		P nw = Q.top();
		Q.pop();
		int Fst = nw.first,Snd = nw.second;
		if(Fst > sum[Snd])
			continue;
		for(int i=0 ; i<V[Snd].size() ; i++){
			int To = V[Snd][i].to,Cost = V[Snd][i].cost;
			if(sum[To] > sum[Snd] + Cost){
				sum[To] = sum[Snd] + Cost;
				Q.push(P(sum[To],To));
			}
		}
	}
}
int main()
{
	int N,a,b,c,p,q;
	scanf("%d",&N);
	while(N --){
		memset(sum,0,sizeof sum);
		ans = 0;
		for(int i=0 ; i<1000005 ; i++){
			V[i].clear();
			V2[i].clear();
		}
		scanf("%d%d",&p,&q);
		while(q --){
			scanf("%d%d%d",&a,&b,&c);
			V[a].push_back(Node(b,c));
			V2[b].push_back(Node(a,c));
		}
		Dijkstra();
		for(int i=1 ; i<=p ; i++)
			ans += sum[i];
		V = V2;
		Dijkstra();	
		for(int i=1 ; i<=p ; i++)
			ans += sum[i];
		printf("%ld\n",ans);
	}
    return 0;  
}

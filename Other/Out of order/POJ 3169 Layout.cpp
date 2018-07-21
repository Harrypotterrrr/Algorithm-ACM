#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int N,ML,MD,k;
struct Node{
	int from,to,cost;
	Node(){}
	Node(int a,int b ,int c){
		from = a;
		to = b;
		cost = c;
	}
}node[20010];
int ans[1005];
bool bellman(){
	memset(ans,0x3f,sizeof ans);
	ans[1] = 0;
	for(int i=1 ; i<=N ; i++){
		for(int j=0 ; j<k ; j++){
			if(ans[node[j].to] > ans[node[j].from] + node[j].cost){
				if(i == N)
					return 0;
				ans[node[j].to] = ans[node[j].from] + node[j].cost;	
			}
		}
	}
	return 1;
}
int main()
{
	int tmp_from,tmp_to,tmp_cost;
	k = 0;
	scanf("%d%d%d",&N,&ML,&MD);
	for(int i=1 ; i<=ML ; i++){
		scanf("%d%d%d",&tmp_from,&tmp_to,&tmp_cost);
		node[k] = Node(tmp_from,tmp_to,tmp_cost);
		k ++;
	}
	for(int i=1 ; i<=MD ; i++){
		scanf("%d%d%d",&tmp_from,&tmp_to,&tmp_cost);
		node[k] = Node(tmp_to,tmp_from,-tmp_cost);
		k ++;
	}
	bool flag = bellman();
    if(ans[N] == INF)
    	printf("-2\n");
    else if(flag)
    	printf("%d\n",ans[N]);
    else
    	printf("-1\n");
	return 0;  
}

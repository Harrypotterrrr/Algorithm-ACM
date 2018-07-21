#define _CRT_SECURE_NO_WARNINGS
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
int ans[50005],first[50005];
bool vis[50005];
int N,M,C,k,maxn;
struct Edge{
    int to,cost,next;
}edge[50005];
int V[50005];
void SPFA(){
    queue <int> Q;
    Q.push(1);
    ans[1] = 0;
    vis[1] = true;
    while(!Q.empty()){
        int nw = Q.front();
        Q.pop();
        vis[nw] = false;
        for(int i=first[nw] ; i != -1 ; i = edge[i].next){
            int temp = edge[i].to;
            if(ans[temp] > ans[nw] + edge[i].cost){
                ans[temp] = ans[nw] + edge[i].cost;
                if(!vis[temp]){
                    vis[temp] = true;
                    Q.push(temp);
                }
            }
        }
    }
}
void init(){
    memset(ans,0x3f,sizeof ans);
    memset(vis,false,sizeof vis);
    memset(first,-1,sizeof first);
    memset(V,0,sizeof V);
    maxn = 0;
    k = 1;
}
void add(int from,int to,int cost){
    edge[k].to = to;
    edge[k].cost = cost;
    edge[k].next = first[from];
    first[from] = k ++;
}
int main()
{
    int T,tmp;
    scanf("%d",&T);
    for(int t=1 ; t<=T ; t++){
        scanf("%d%d%d",&N,&M,&C);
        init();
        for(int i=1 ; i<=N ; i++){
            scanf("%d",&tmp);
            V[tmp] = i;
            maxn = max(maxn,tmp);
        }
        for(int i=2 ; i<=tmp ; i++)
            if(!V[i] && !V[i-1]){
                add(V[i],V[i-1],C);
                add(V[i-1],V[i],C);
            }
        int temp_from,temp_to,temp_cost;
        for(int i=1 ; i<=M ; i++){
        	scanf("%d%d%d",&temp_from,&temp_to,&temp_cost);
			add(temp_from,temp_to,temp_cost);
	       	add(temp_to,temp_from,temp_cost);
		}
        SPFA();
        if(ans[N] == INF)
            printf("Case #%d: -1\n",t);
        else
            printf("Case #%d: %d\n",t,ans[N]);
    }
    return 0;  
}

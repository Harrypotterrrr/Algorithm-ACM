#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
double d[205][205];
double dis[205];
int cdn[205][2];
bool vis[205] = {false};
int n,k = 0;
void init(){
	memset(vis,false,sizeof vis);
	memset(cdn,0,sizeof cdn);
	memset(d,0,sizeof d);
	for(int i=2 ; i<=n ; i++)
		dis[i] = INF;
	vis[1] = true;
	dis[1] = 0;
	k ++;
}
double cal(int i,int j){
	double x = (cdn[i][0] - cdn[j][0]) * (cdn[i][0] - cdn[j][0]);
	double y = (cdn[i][1] - cdn[j][1]) * (cdn[i][1] - cdn[j][1]);
	return sqrt(x+y);
}
void SPFA(){
	queue <int> Q;
	Q.push(1);
	while(!Q.empty()){
		int nw = Q.front();
		Q.pop();
		vis[nw] = false;
		for(int i=1 ; i<=n ; i++)
			if(dis[i] > max(d[nw][i],dis[nw])){
				dis[i] = max(d[nw][i],dis[nw]);
				if(!vis[i]){
					Q.push(i);
					vis[i] = true;
				}
			}
	}
}
int main()
{
	while(scanf("%d",&n) != EOF,n){
		init();
		for(int i=1 ; i<=n ; i++)
			scanf("%d%d",cdn[i],cdn[i]+1);
		for(int i=1 ; i<=n ; i++)
			for(int j=i+1 ; j<=n ; j++)
				d[i][j] = d[j][i] = cal(i,j);
		for(int i=1 ; i<=n ; i++)
			d[i][i] = 0;
		SPFA();
		printf("Scenario #%d\nFrog Distance = ",k);
		printf("%.3f\n\n",dis[2]);
	}
    return 0;  
}

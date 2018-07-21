#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
int N,maxn = 0;
int num[100010];
bool vis[100010];
void dfs(int x,int y,int nw){
	if(x == 2){
		maxn = maxn > nw ? maxn : nw;
	}
	for(int i=y ; i<N ; i++){
		vis[num[i]] = true;
		dfs(x+1,i+1,(nw^num[i]));
		vis[num[i]] = false;
	}
}
int main()
{
	memset(vis,false,sizeof vis);
	scanf("%d",&N);
	for(int i=0 ; i<N ; i++)
		scanf("%d",num+i);
	dfs(0,0,0);
	printf("%d\n",maxn);
	return 0;
}

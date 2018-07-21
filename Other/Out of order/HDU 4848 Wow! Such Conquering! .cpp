#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int n,Min;
int T[32][32],D[32];
int vis[32];
void floyd(){
	for(int k=1 ; k<=n ; k++)
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=n ; j++)
				T[i][j] = min(T[i][j],T[i][k]+T[k][j]);
}
void dfs(int row,int arr,int sum,int t){
	if(t == n){
		Min = Min > sum ? sum : Min;
		return;
	}
	if(sum + arr*(n-t) >= Min)
		return;
	for(int i=2 ; i<=n ; i++)
		if(vis[i] && arr > D[i])
			return;
	for(int i=2 ; i<=n ; i++){
		if(vis[i] && row != i){
			if(arr + T[row][i] > D[i])
				continue;
			vis[i] = false;
			dfs(i,arr + T[row][i],sum + arr + T[row][i],t+1);
			vis[i] = true;
		}
	}
}
int main(){
    while(scanf("%d",&n) != EOF){
    	for(int i=1 ; i<=n ; i++)
    		for(int j=1 ; j<=n ; j++)
    			scanf("%d",&T[i][j]);
		for(int i=2 ; i<=n ; i++)
			scanf("%d",&D[i]);
		floyd();
    	Min = INF;	
		memset(vis,true,sizeof vis);
		dfs(1,0,0,1);
		Min == INF ? printf("-1\n") : printf("%d\n",Min);
	}
	return 0;
}

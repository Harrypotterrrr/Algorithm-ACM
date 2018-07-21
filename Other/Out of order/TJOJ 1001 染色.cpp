#include <stdio.h>
#include <iostream>
#include <cstring>	
bool vis[51][51];
int clr[12];
int ans,n,m,maxn;
bool judge(int x,int num){
	for(int i=1 ; i<=maxn ; i++)
		if(vis[x][i] && clr[i] == num)
			return false;
	return true;
}
void dfs(int x){
	if(x == n+1){
		ans ++;
		return ;
	}
	for(int i=1 ; i<=4 ; i++){
		if(judge(x,i)){
			clr[x] = i;
			dfs(x+1);
			clr[x] = 0;
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&m) != EOF){
		memset(vis,false,sizeof vis);
		memset(clr,0,sizeof 0);
		ans = 0;maxn = 0;
		int t1,t2;
		while(m--){
			scanf("%d%d",&t1,&t2);
			vis[t2][t1] = true;
			vis[t1][t2] = true;
			maxn = maxn > t1 ? maxn : t1;
			maxn = maxn > t2 ? maxn : t2;
		}
		dfs(1);
		printf("%d\n",ans);
	}
}

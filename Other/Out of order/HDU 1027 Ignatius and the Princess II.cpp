#include<iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int num[1002],n,k,p;
bool vis[1002],flag;
void dfs(int x){
	if(x == n+1){
		p ++;
		if(p == k){
			flag = true;
			printf("%d",num[1]);
			for(int i=2 ; i<=n ; i++)
				printf(" %d",num[i]);
			printf("\n");
		}
	}
	for(int i=1 ; i<=n ; i++){
		if(vis[i]){
			num[x] = i;
			vis[i] = false;
			dfs(x+1);
			if(flag)
				return;
			vis[i] = true;
		} 
	}
}
int main(){
	while(scanf("%d%d",&n,&k) != EOF){
		memset(vis,true,sizeof vis);
		p = 0;
		flag = false;
		dfs(1);
	}
	return 0;
}

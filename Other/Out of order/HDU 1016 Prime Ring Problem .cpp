#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const bool prime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,\
1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1};
int arr[21],n;
bool vis[21];
void dfs(int x){
	if(x == n && prime[arr[0] + arr[x-1]]){
		for(int i=0 ; i<=n-2 ; i++)
			printf("%d ",arr[i]);
		printf("%d\n",arr[n-1]);
		return;
	}
	else{
		for(int i=2 ; i<=n ; i++){
			if(vis[i] && prime[arr[x-1] + i]){
				arr[x] = i;
				vis[i] = false;
				dfs(x+1);
				vis[i] = true;
			}
		}
	}
}
int main(){
    int num = 0;
	while(scanf("%d",&n) != EOF){
    	memset(vis,true,sizeof vis);
    	memset(arr,0,sizeof arr);
		printf("Case %d:\n",++num);
		arr[0] = 1;
		dfs(1);
		printf("\n");
	}
	return 0;
}

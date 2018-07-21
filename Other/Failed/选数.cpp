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
int num[100],ans[100];
bool vis[100] = {0};
int N,M,sum = 0;
void solve(int x,int y){
	if(x == M+1){
		for(int j=1 ; j<=M ; j++)
			printf("%d ",ans[j]);
		puts("");
		sum ++;
		return;
	}
	for(int i=y ; i<=N ; i++){
		if(!vis[i]){
			ans[x] = i;
			vis[i] = true;
			solve(x+1,i+1);
			vis[i] = false;
		}
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0 ; i<=N ; i++)
		num[i] = i;
	solve(1,1);
	printf("总共%d种可能",sum);
	return 0;
}


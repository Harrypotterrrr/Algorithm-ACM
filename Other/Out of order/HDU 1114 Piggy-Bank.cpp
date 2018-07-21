#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define maxn 0x3f3f3f3f
using namespace std;
int val[505],wei[505];
int dp[10005],N;
void solve(int w){
	for(int i=0 ; i<N ; i++)
		for(int j=wei[i] ; j<=w ; j++)
			dp[j] = min(dp[j],dp[j-wei[i]]+val[i]);
}
int main()
{
	int T,w1,w2;
	scanf("%d",&T);
	while(T--){
		memset(dp, 0x3f, sizeof dp);
		dp[0] = 0; // живЊ!
		memset(val,0,sizeof val);
		memset(wei,0,sizeof wei);
		scanf("%d%d",&w1,&w2);
		int w = w2 - w1;
		scanf("%d",&N);
		for(int i=0 ; i<N ; i++)
			scanf("%d%d",&val[i],&wei[i]);
		solve(w);
		if(dp[w] == maxn)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
	}
    return 0;
}

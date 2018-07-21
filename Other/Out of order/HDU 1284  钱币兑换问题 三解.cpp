#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[32770],N;
void solve(){
	for(int i=1 ; i<=3 ; i++)
		for(int j=i ; j<=N ; j++)
			dp[j] += dp[j-i];
}
int main()
{
	while(scanf("%d",&N) != EOF){
		memset(dp,0,sizeof dp);
		dp[0] = 1;
		solve();
		printf("%d\n",dp[N]);
	}
    return 0;
}

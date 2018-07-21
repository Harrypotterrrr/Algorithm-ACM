#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int p[105],h[105],c[105];
int dp[2005];
void solve(int n,int m){
	for(int i=1 ; i<=m ; i++){
		int temp = j * c[i];
		for(int j=h[i] ; j<=temp ; j++)
			dp[j] = max(dp[j],dp[j-h[i]] + h[i]);
	}
}
int main()
{
	int C;
	scnaf("%d",&C);
	while(C--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0 ; i<m ; i++)
			scanf("%d%d%d",p+i,h+i,c+i);
		solve(n,m);
	}
    return 0;  
}

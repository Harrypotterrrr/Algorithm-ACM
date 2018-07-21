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
long long x,ans;
bool bry[33];
int p,n;
int main()
{
	while(scanf("%lld%d%d",&x,&p,&n) , x || p || n){
		memset(bry,false,sizeof bry);
		ans = 0;
		for(int i=0 ; x ; i++){
			bry[i] = x % 2;
			x /= 2;
		}
		for(int j=0 ; j<n ; j++)
			ans += pow(2,j) * bry[p-n+1+j];
		printf("%lld\n",ans);
	}
	return 0;
}

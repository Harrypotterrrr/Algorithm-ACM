#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxv = 50 * 100 * 50 / 2 + 5;
const int maxn = 50 * 100 + 5;
int ans[maxv],art[maxn];
int solve(int k,int s){
	for(int i=0 ; i<k ; i++)
		for(int j=s ; j>=art[i] ; j--)
			ans[j] = max(ans[j],ans[j-art[i]]+art[i]);
	return ans[s];
}
int main()
{
	int N;
	while(scanf("%d",&N),N > 0){
		memset(ans,0,sizeof ans);
		memset(art,0,sizeof art);
		int cst = 0,sum = 0;
		while(N--){
			int x,y;
			scanf("%d%d",&x,&y);
			sum += x * y;
			while(y--)
				art[cst++] = x;
		}
		int cs = solve(cst,sum/2),es = sum - cs;
		printf("%d %d\n",max(cs,es),min(cs,es));
	}
    return 0;
}

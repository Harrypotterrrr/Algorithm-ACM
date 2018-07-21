//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int num[100005],n,ans,sum;
void solve(int x,int k){
	if(k == 5){
		if(x - 2 == n - 1)
			ans = ans > sum ? ans : sum;
		return;
	}
	int temp = 0;
	for(int i=x ; i < n - (4 - k) * 2 ; i++){
		temp += num[i];
		if(temp > sum)
			return;
		if(temp == sum)
			solve(i+2,k+1);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1 ; i<=T ; i++){
		int maxn = 0;
		sum = ans = 0;
		scanf("%d",&n);
		memset(num,0,sizeof num);
		for(int j =0 ; j<n ; j++){
			scanf("%d",num+j);
			maxn += num[j];
		}
		for(int j=0 ; j < n-6 ; j++){
			sum += num[j];
//			if(sum > maxn / 4)
//				break;
			solve(j+2,2);
		}
		printf("Case #%d:\n",i);
		if(!ans)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;  
}

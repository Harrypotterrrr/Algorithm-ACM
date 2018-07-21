#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int main()
{
	int N;
	while(scanf("%d",&N),N > 0){
		int num[55][3],ans[250010],temp[250010];
		int V,M,sum=0;
		memset(ans,0,sizeof ans);
		memset(num,0,sizeof num);
		for(int i=0 ; i<N ; i++){
			scanf("%d%d",&num[i][0],&num[i][1]);
			num[i][2] = num[i][0] * num[i][1];
			sum += num[i][2];
		}
		for(int i=0 ; i<=sum ; i++){
			ans[i] = 1;
			temp[i] = 0;
		}
		int m=0;
		for(int i=0 ; i<N ; i++){
			for(int j=0 ; j<=m ; j++)
				for(int k=0 ; k<=num[i][2] ; k+=num[i][0])
					temp[j+k] += ans[j];
			m += num[i][2];
			for(int j=0 ; j<=m ; j++){
				ans[j] = temp[j];
				temp[j] = 0;
			}
		}
		for(int i=sum/2 ; i>=0 ; i--)
			if(ans[i]){
				printf("%d %d\n",sum-i,i);
				break;
			}
	}
    return 0;
}

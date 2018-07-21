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
int N,x,maxn1 = 0,maxn2 = 0;
int f1[1005],p1=0,min_f1[1000002];
int f2[1005],p2=0,min_f2[1000002];
bool vis_f1[1005],vis_f2[1005];
int main()
{
	memset(min_f1,0x3f,sizeof min_f1);
	memset(min_f2,0x3f,sizeof min_f2);
	min_f1[0] = 0;
	min_f2[0] = 0;
	scanf("%d",&N);
	for(int i=0 ; i<N ; i++){
		scanf("%d",&x);
		if(x > 0){
			if(!vis_f1[x]){
				f1[p1++] = x;
				vis_f1[x] = true;				
			}			
		}
		else if(x < 0){
			if(!vis_f2[-x]){
				f2[p2++] = -x;
				vis_f2[-x] = true;
			}			
		}
		else{
			printf("1\n");
			return 0;
		}
	}
	if(!p1 || !p2){
		printf("-1\n");
		return 0;
	}
	sort(f1,f1+p1);
	sort(f2,f2+p2);
	int ans = INF;
	for(int i=1 ; i<=999005 ; i++){
		for(int j=0 ; j<p1 && f1[j]<=i ; j++){
			int temp = min_f1[i-f1[j]] + 1;
			min_f1[i] = min_f1[i] < temp ? min_f1[i] : temp;
		}
		for(int j=0 ; j<p2 && f2[j]<=i ; j++){
			int temp = min_f2[i-f2[j]] + 1;
			min_f2[i] = min_f2[i] < temp ? min_f2[i] : temp;
		}
		if(min_f1[i] != INF && min_f2[i] != INF){
			int tmp = min_f1[i] + min_f2[i];
			ans = ans < tmp ? ans : tmp;
		}
		if(ans * 1000 < i)
			break;
	}
	printf("%d\n",ans);
	return 0;
}

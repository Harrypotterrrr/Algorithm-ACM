#include <iostream>
#include <stdio.h>
#include <algorithm>
#define inf 1e9
using namespace std;
struct obt
{
	int jbean;
	int fcat;
	double ratio;
};

bool cmp(obt x,obt y){
	return x.ratio > y.ratio;
}
int main()
{
	obt a[1000];
	int M,N;
	while(scanf("%d%d",&M,&N) != EOF){
		if(M == -1 && N == -1)
			break;
		else if(N == 0){
			printf("0.000\n");
			continue;
		}
		for(int i=0 ; i<N ; i++){
			scanf("%d%d",&a[i].jbean,&a[i].fcat);
			if(a[i].fcat == 0){
				a[i].ratio = inf;
				continue;
			}
			a[i].ratio = 1.0 * a[i].jbean / a[i].fcat;
		}
		sort(a,a+N,cmp);
		double sum = 0;
		int k=0;
		while(M > 0 && k <= N-1){
			if(M >= a[k].fcat)
				sum += a[k].jbean;
			else
				sum += a[k].ratio * M;
			M -= a[k].fcat;
			k ++;
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
long long n,m,k;
long long solve_1(long long x){
	if(!(x % k))
		return x / k;
	else if(x % 2){
		if(x % (2 * k) < k)
			return x / k + 1;
		else
			return x / k + 2;
	}
	else{
		if(x % (2 * k) < k)
			return x / k + 2;
		else
			return x / k + 1;
	}
}
long long solve_2(long long x){
	if(!(x % k))
		return x / k;
	else if(x % 2)
		return -1;
	else
		return x / k + 1;
}
int main()
{
	long long N,M;
	char str[20];
//	while(scanf("%s", str) != EOF){
//		if (!(str[1] == '1'))
//			putchar('\n');
		scanf("%lld%lld%lld", &n, &m, &k);
		if(!k){
			printf("-1\n");
//			continue;
		}
		if(k % 2){
			N = solve_1(n);
			M = solve_1(m);
		}
		else{
			N = solve_2(n);
			M = solve_2(m);
		}
		if(N == -1 && M == -1){
			printf("-1\n");
			return 0;
		}
		else if(N == -1)
			N = M + 1;
		else if(M == -1)
			M = N + 1;
		long long ans = N <= M ? N : M;
		printf("%lld\n",ans);
//	}
	return 0;
}

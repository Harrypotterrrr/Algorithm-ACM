#include <iostream>
typedef long long LL;
using namespace std;
LL N;
int solve(LL x){
	if(!x)
		return 1;
	if(x % 2)
		return N * solve(x-1) % 10;
	LL temp = solve(x/2);
	return temp * temp % 10;
}
int main()  
{  
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d",&N);
		printf("%d\n",solve(N));
	}
    return 0;  
}

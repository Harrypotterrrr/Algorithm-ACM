/************************************************
Problem: 		HDU 6322 Euler Function
Algorithm: 		Math
Difficulty: 	
Significance:	
Remark:			Euler function
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits\stdc++.h>
using namespace std;
int num[1005];
int oula(int n)
{
	int ans = n;
	for (int i = 2; i * i <= n; i++)
		if (n%i == 0) {
			ans -= ans / i;
			do
				n /= i;
			while (n % i == 0);
		}
	if (n > 1)
		ans -= ans / n;
	return ans;
}
int main()
{
	//for (int i = 0; i < 1000; i++) {
	//	num[i] = oula(i);
	//	printf("%d ", num[i]);
	//}

	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n == 1)
			printf("5\n");
		else
			printf("%d\n", n + 5);
	}
	return 0;
}
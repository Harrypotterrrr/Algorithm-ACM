/************************************************
Problem: 		HDU 6298 Maximum Multiple
Algorithm: 		Math
Difficulty: 	+
Significance:	+
Remark:			
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
int num[1000005] = { 0 };
int main()
{
	for (int i = 1; i * 4 < 1000005; i++)
		num[i * 4] = 1;
	for (int i = 0; i < 1000005; i += 3)
		num[i] = 2;
	num[1] = num[2] = 0;
	long long T, x;
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &x);
		if (num[x] == 0)
			printf("-1\n");
		else if (num[x] == 1)
			printf("%lld\n", x *x*x / 32);
		else
			printf("%lld\n", x *x*x / 27);
	}
	return 0;
}

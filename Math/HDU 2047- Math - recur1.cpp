/************************************************
Problem: 		HDU 2047 °¢Å£µÄEOFÅ£Èâ´®
Algorithm: 		math
Difficulty:
Significance:	
Remark:			Fn = g(fn-1)
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits\stdc++.h>
#define eps 1e-8
typedef __int64 ll;
ll num[45][2], n;
using namespace std;
int main()
{
	num[1][0] = 2;
	num[1][1] = 1;
	for (int i = 1; i < 42; i++) {
		num[i + 1][0] = 2 * (num[i][0] + num[i][1]);
		num[i + 1][1] = num[i][0];
	}
	while (scanf("%I64d",&n) != EOF) {
		printf("%I64d\n", num[n][0] + num[n][1]);
	}
	return 0;
}
/************************************************
Problem: 		HDU 2047 °¢Å£µÄEOFÅ£Èâ´®
Algorithm: 		math
Difficulty:		
Significance:	
Remark:			Fn = g(Fn-1, Fn-2)
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits\stdc++.h>
#define eps 1e-8
typedef __int64 ll;
ll num[45], n;
using namespace std;
int main()
{
	num[1] = 3;
	num[2] = 8;
	for (int i = 3; i < 42; i++)
		num[i] = 2 * (num[i - 1] + num[i - 2]);
	while (scanf("%I64d",&n) != EOF) {
		printf("%I64d\n", num[n]);
	}
	return 0;
}
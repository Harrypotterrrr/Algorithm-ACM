/************************************************
Problem: 		HDU 1087 Super Jumping! Jumping! Jumping!
Algorithm: 		DP 
Difficulty: 	+
Significance:	+
Remark:			similar to find the longest substr
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3F3F3F3F
using namespace std;

int main()
{
	int n, num[1010];
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		int sum[1010], maxn, ans = -INF;
		memset(sum, -1, sizeof(sum));
		sum[0] = num[0];
		for (int i = 1; i < n; i++) {
			maxn = 0;
			for (int j = 0; j < i; j++) {
				if (num[j] < num[i])
					maxn = maxn > sum[j] ? maxn : sum[j];
			}
			sum[i] = maxn + num[i];
			ans = ans > sum[i] ? ans : sum[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
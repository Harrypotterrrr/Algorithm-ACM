/************************************************
Problem: 		HDU 1176 Ãâ·ÑÏÚ±ý
Algorithm: 		DP
Difficulty: 	+
Significance:	+++
Remark:			reverse solution
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3F3F3F3F
using namespace std;

int dp[100005][15];
int main()
{
	int _;
	while (scanf("%d", &_) && _ != 0) {
		int x, T, t = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < _; i++) {
			scanf("%d%d", &x, &T);
			dp[T][x + 1]++;
			t = t > T ? t : T;
		}
		for (int i = t - 1; i >= 0; i--) {
			for (int j = 1; j <= 11; j++) {
				int tmp = max(dp[i + 1][j], max(dp[i + 1][j - 1], dp[i + 1][j + 1]));
				dp[i][j] += tmp;
			}
		}
		printf("%d\n", dp[0][6]);
	}
	return 0;
}
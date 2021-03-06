/************************************************
Problem: 		HDU 1176 ����ڱ�
Algorithm: 		DP
Difficulty: 	+
Significance:	+++
Remark:			sequential solution
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
		for (int i = 1; i <= 11; i++)
			if (i < 5 || i > 7)
				dp[1][i] = 0;

		for (int i = 2; i <= t; i++) {
			for (int j = 1; j <= 11; j++) {
				int tmp = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1]));
				dp[i][j] += tmp;
			}
		}

		int ans = -INF;
		for (int i = 1; i <= 11; i++)
			ans = ans > dp[t][i] ? ans : dp[t][i];
		printf("%d\n", ans);
	}
	return 0;
}
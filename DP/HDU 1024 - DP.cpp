/************************************************
Problem: 		HDU 1024 Max Sum Plus Plus
Algorithm: 		DP
Difficulty: 	++++
Significance:	+++++
Remark:			two dimension DP with great optimization
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3f3f3f3f
typedef __int64 ll;
using namespace std;
int m, n;
ll dp[1000005];
ll maxn[2][1000005];
ll num[1000005];

ll max(ll a, ll b)
{
	if (a > b)
		return a;
	return b;
}
int main()
{
	while (scanf("%d%d", &m, &n) != EOF) {
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; i++) {
			maxn[0][i] = 0;
			maxn[1][i] = 0;
		}

		for (int i = 1; i <= n; i++)
			scanf("%lld", num + i);
		bool tag = false;
		for (int i = 1, j; i <= m; i++, tag = !tag) {
			dp[i] = num[i] + dp[i - 1];
			maxn[tag][i] = dp[i];
			for (j = i+1; j < n - m + 1 + i; j++) {
				dp[j] = max(maxn[!tag][j - 1], dp[j - 1]) + num[j];
				maxn[tag][j] = max(maxn[tag][j - 1], dp[j]);
			}
		}
		printf("%lld\n", maxn[!tag][n]);
	}
	return 0;
}
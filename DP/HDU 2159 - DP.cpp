/************************************************
Problem: 		HDU 2159 FATE
Algorithm: 		DP
Difficulty: 	++
Significance:	++
Remark:			two dimension knapsack problem
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 0X3f3f3f3f
using namespace std;

int n, m, k, s, a[105], b[105];
int dp[106][105];
int main()
{
	while (scanf("%d%d%d%d", &n, &m, &k, &s) != EOF) {
		for (int _ = 0; _ < k; _++)
			scanf("%d%d", &a[_], &b[_]);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < k; i++)
			for (int u = b[i]; u <= m; u++)
				for (int j = 1; j <= s; j++)
					dp[u][j] = max(dp[u][j], dp[u - b[i]][j - 1] + a[i]);

		if (dp[m][s] < n) {
			printf("-1\n");
			continue;;
		}
		int minn = INF;
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= s; j++)
				if (dp[i][j] >= n)
					minn = min(minn, i);
		printf("%d\n", m - minn);
	}
	return 0;
}

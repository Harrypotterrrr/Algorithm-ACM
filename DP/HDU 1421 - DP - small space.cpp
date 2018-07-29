/************************************************
Problem: 		HDU 1421 ∞·«ﬁ “
Algorithm: 		DP
Difficulty: 	+++
Significance:	+++++
Remark:			DP with strategic solution
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#define INF 0X3f3f3f3f
typedef __int64 ll;
using namespace std;
int n, k;
int ob[4005];
int dp[2][2005];
bool cmp(const int a, const int b)
{
	return a < b;
}
#define dif(a,b) ((a - b)*(a - b))
int main()
{
	while (scanf("%d%d", &n, &k) != EOF) {
		memset(dp, 0x7f, sizeof(dp));
		memset(ob, 0, sizeof(ob));

		for (int i = 1; i <= n; i++)
			scanf("%d", &ob[i]);
		sort(ob + 1, ob + n + 1, cmp);

		int tag = 0;
		for (int i = 0; i <= n; i++)
			dp[tag][i] = 0;
		tag = 1;
		for (int i = 1; i <= k; tag = !tag, i++) {
			dp[tag][i * 2 - 1] = 0X7F7F7F7F;
			for (int j = i * 2; j <= n; j++) {
				dp[tag][j] = min(dp[tag][j - 1], dp[!tag][j - 2] + dif(ob[j], ob[j - 1]));
			}
		}
		printf("%d\n", dp[!tag][n]);
	}
	return 0;
}
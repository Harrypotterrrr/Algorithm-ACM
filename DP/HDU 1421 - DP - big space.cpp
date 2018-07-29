/************************************************
Problem: 		HDU 1421 ∞·«ﬁ “
Algorithm: 		DP
Difficulty: 	+++
Significance:	+++++
Remark:			DP with strategic solution
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3f3f3f3f
typedef __int64 ll;
using namespace std;
int n, k;
int ob[4005];
int dp[1001][2005];
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

		for (int i = 0; i < n; i++)
			scanf("%d", &ob[i]);
		sort(ob, ob + n, cmp);
		
		for (int i = 1; i < n; i++)
			dp[0][i] = min(dp[0][i-1],dif(ob[i],ob[i-1]));
		for (int i = 1; i < k; i++) {
			for (int j = i * 2 + 1; j < n; j++) {
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 2] + dif(ob[j], ob[j - 1]));
			}
		}
		printf("%d\n", dp[k-1][n-1]);
	}
	return 0;
}
/************************************************
Problem: 		HDU 2047 You Are the One
Algorithm: 		DP
Difficulty:		*****
Significance:	*****
Remark:			interval DP
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits\stdc++.h>
#define INF 0x3f3f3f3f
#define eps 1e-8
typedef __int64 ll;
int T, n;
int num[105];
int dp[105][105];
int sum[105];
using namespace std;
int main()
{
	scanf("%d", &T);
	for (int _ = 1; _ <= T; _++) {
		memset(num, 0, sizeof(num));
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));

		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", num + i);

		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + num[i];

		for (int u = 1; u < n; u++) {
			for (int i = n - u; i >= 1; i--) {
				int minn = INF;
				int j = i + u;
				for (int k = 1; k <= u + 1; k++)
					minn = min(minn, dp[i + 1][i + k - 1] + (k - 1) * num[i] + dp[i + k][j] + k*(sum[j]-sum[i+k-1]));
				dp[i][j] = minn;
			}
		}
		//for (int i = 1; i <= 5; i++) {
		//	for (int j = 1; j <= 5; j++)
		//		cout << dp[i][j] << " ";
		//	cout << endl;
		//}
		printf("Case #%d: %d\n", _,dp[1][n]);
	}
	return 0;
}
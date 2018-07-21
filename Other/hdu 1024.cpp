#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define INF 0X3F3F3F3F
using namespace std;
typedef long long ll;
// solution 1 TLE 
//int dp[1000][100];
//int num[1000];
//int main()
//{
//	int m, n;
//	while (scanf("%d%d", &m, &n)) {
//		for (int i = 1; i <= n; i++)
//			scanf("%d", num + i);
//		memset(dp, 0, sizeof(dp));
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= n; j++) {
//				int tmp = 0;
//				for (int k = i-1; k < j; k++)
//					tmp = tmp > dp[i - 1][k] ? tmp : dp[i-1][k];
//				dp[i][j] = tmp > dp[i][j - 1] ? tmp + num[j] : dp[i][j - 1] + num[j];
//			}
//		}
//		printf("%d\n", dp[m][n]);
//	}
//	return 0;
//}

//solution 2
int dp[2][1000005];
int num[1000005];
int main()
{
	int m, n;
	int maxn;
	bool k;
	while (scanf("%d%d", &m, &n) == 2) {
		for (int i = 1; i <= n; i++)
			scanf("%d", num + i);
		memset(dp, 0, sizeof(dp));
		k = 0;
		for (int i = 1; i <= m; i++, k ^= 1) {
			maxn = -INF;
			dp[k][i - 1] = -INF;
			for (int j = i; j <= i - m + n; j++) {
				maxn = maxn > dp[k ^ 1][j - 1] ? maxn : dp[k ^ 1][j - 1];
				dp[k][j] = maxn > dp[k][j - 1] ? maxn + num[j] : dp[k][j - 1] + num[j];
			}
		}
		maxn = -INF;
		for (int i = m; i <= n; i++)
			maxn = maxn > dp[k ^ 1][i] ? maxn : dp[k ^ 1][i];
		printf("%d\n", maxn);
	}
	return 0;
}
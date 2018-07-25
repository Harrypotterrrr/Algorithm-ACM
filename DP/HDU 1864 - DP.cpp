/************************************************
Problem: 		HDU 1864 最大报销额
Algorithm: 		DP
Difficulty: 	+
Significance:	++
Remark:			Knapsack problem
Attention to the double, it is brilliant to convert double to int
by multiplying by 10 to eliminate the spot
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3F3F3F3F
#define eps 1e-8
using namespace std;

int dp[3001000];
int main()
{
	int N, m, sum_price;
	double Q, temp;
	char str[100], type;
	int a_sum, b_sum, c_sum, price;

	while (scanf("%lf%d", &Q, &N) && N != 0) {
		memset(dp, 0, sizeof(dp));
		vector<int>V;
		sum_price = 0;

		for (int i = 0, j; i < N; i++) {
			scanf("%d", &m);
			a_sum = b_sum = c_sum = price = 0;
			bool tag = true;
			for (j = 0; j < m; j++) {
				scanf("%s", str);
				sscanf(str, "%c:%lf", &type, &temp);
				int tmp = int(temp * 100);
				if (type == 'A')
					a_sum += tmp;
				else if (type == 'B')
					b_sum += tmp;
				else if (type == 'C')
					c_sum += tmp;
				else
					tag = false;
				if (a_sum > 60000 || b_sum > 60000 || c_sum > 60000)
					tag = false;
				price += tmp;
				if (price > 100000)
					tag = false;
			}
			if (tag == true) {
				V.push_back(price);
				sum_price += price;
			}
		}
		int maxn = int(Q * 100) < sum_price ? int(Q * 100) : sum_price;
		for (int i = 0; i < V.size(); i++) {
			for (int j = maxn; j >= V[i]; j--) {
				dp[j] = max(dp[j], dp[j - V[i]] + V[i]);
			}
		}
		printf("%.2lf\n", dp[maxn] / 100.);
	}
	return 0;
}

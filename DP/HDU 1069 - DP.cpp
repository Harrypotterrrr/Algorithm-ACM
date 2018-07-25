/************************************************
Problem: 		HDU 1069 Monkey and Banana 
Algorithm: 		DP
Difficulty: 	++
Significance:	+
Remark:			similar to find the longest substr
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3F3F3F3F
using namespace std;

struct Node {
	int minn;
	int maxn;
	int high;
	Node() {};
	Node(int _a, int _b, int _c) {
		minn = _a < _b ? _a : _b;
		maxn = _a < _b ? _b : _a;
		high = _c;
	}
	bool operator<(const Node &n)const {
		return this->minn > n.minn;
	}
};
int main()
{
	int n, a, b, c, k = 1;
	int total_high[100], ans = -INF;
	vector<Node>V;
	while (scanf("%d", &n) && n != 0) {
		V.clear();
		memset(total_high, 0, sizeof(total_high));
		ans = -INF;

		for (int _ = 0; _ < n; _++) {
			scanf("%d%d%d", &a, &b, &c);
			V.push_back(Node(a, b, c));
			if(b != c)
				V.push_back(Node(a, c, b));
			if(a != c)
				V.push_back(Node(b, c, a));
		}
		sort(V.begin(), V.end());
		total_high[0] = V.begin()->high;
		for (int i = 1; i < V.size(); i++) {
			int t_max = 0;
			for (int j = 0; j < i; j++) {
				if (V[j].minn > V[i].minn && V[j].maxn > V[i].maxn)
					t_max = t_max > total_high[j] ? t_max : total_high[j];
			}
			total_high[i] = t_max + V[i].high;
			ans = ans > total_high[i] ? ans : total_high[i];
		}
		printf("Case %d: maximum height = %d\n", k++, ans);
	}
	return 0;
}
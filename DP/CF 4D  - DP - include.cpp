/************************************************
Problem: 		CF 4D  Mysterious Present
Algorithm: 		DP
Difficulty: 	++
Significance:	+++
Remark:			DF solution and ouput the detail by dfs
Vector include first constriction
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3f3f3f3f
using namespace std;
typedef long long ll;
struct Node
{
	int minn;
	int weigth;
	int height;
	int num;
	Node() {};
	Node(int w, int h, int k)
	{
		minn = min(w, h);
		weigth = w;
		height = h;
		num = k;
	}
};
bool cmp(Node &a, Node&b)
{
	return a.minn < b.minn;
}
int n, w, h;

struct List
{
	int pre;
	int length;
	int no;
};
List ans[1000005];

void dfs(int k)
{
	if (ans[k].pre == -1) {
		return;
	}
	dfs(ans[k].pre);
	printf("%d ", ans[k].no);
}

int main()
{
	while (scanf("%d%d%d", &n, &w, &h) != EOF) {
		int tw, th;
		vector<Node>V;
		memset(ans, -1, sizeof(ans));

		V.push_back(Node(w, h, 0));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &tw, &th);
			if (w < tw && h < th)
				V.push_back(Node(tw, th, i + 1));
		}
		sort(V.begin() + 1, V.end(), cmp);

		int ans_max = -INF, ans_index = 0;
		ans[0].length = 0;
		for (int i = 1, j; i < V.size(); i++) {
			int tmp_max = -INF, tmp_index = 0;
			for (j = 0; j < i; j++) {
				if (V[i].weigth > V[j].weigth && V[i].height > V[j].height) {
					if (tmp_max < ans[j].length) {
						tmp_max = ans[j].length;
						tmp_index = j;
					}
				}
			}
			ans[i].length = tmp_max + 1;
			ans[i].pre = tmp_index;
			ans[i].no = V[i].num;
			if (ans_max < ans[i].length) {
				ans_max = ans[i].length;
				ans_index = i;
			}
		}
		if (ans_index == 0)
			printf("0");
		else {
			printf("%d\n", ans[ans_index].length);
			dfs(ans_index);
		}
		puts("");
	}
	return 0;
}
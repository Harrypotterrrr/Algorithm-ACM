#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
struct Pos
{
	int x, y;
}pos[100010];
int N;
bool vis[100010];

bool dfs(int sum, int n, int last)
{
	if (n == 3)
		return sum == N;
	//x
	for (int i = last; i < N; i++) {
		if (pos[i].x == pos[last].x && !vis[i]) {
			sum++;
			vis[i] = true;
		}
	}
	if (sum == N)
		return true;
	for (int i = last + 1; i < N; i++) {
		if (!vis[i]) {
			if (dfs(sum, n + 1, i))
				return true;
			break;
		}
	}
	for (int i = last; i < N; i++) {
		if (pos[i].x == pos[last].x && vis[i]) {
			sum--;
			vis[i] = false;
		}
	}

	//y
	for (int i = last; i < N; i++) {
		if (pos[i].y == pos[last].y && !vis[i]) {
			sum++;
			vis[i] = true;
		}
	}
	if (sum == N)
		return true;
	for (int i = last + 1; i < N; i++) {
		if (!vis[i]) {
			if (dfs(sum, n + 1, i))
				return true;
			break;
		}
	}
	for (int i = last; i < N; i++) {
		if (pos[i].y == pos[last].y && vis[i]) {
			sum--;
			vis[i] = false;
		}
	}
	return 0;
}
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		memset(vis, false, sizeof(vis));
		cin >> N;
		for (int j = 0; j < N; j++)
			scanf("%d%d", &pos[j].x, &pos[j].y);
		printf("Case #%d:\n", i);
		if (dfs(0, 0, 0))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
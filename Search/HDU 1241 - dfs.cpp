/************************************************
Problem: 		HDU 1241 Oil Deposits
Algorithm: 		DFS
Difficulty: 	+
Significance:	+
Remark:
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int Move[8][2] = { {-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1} };
int n, m;
char Map[105][105];

void dfs(int x, int y)
{
	Map[x][y] = '\0';
	for (int i = 0; i < 8; i++) {
		int x_tmp = x + Move[i][0], y_tmp = y + Move[i][1];
		if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < m && Map[x_tmp][y_tmp] == '@')
			dfs(x_tmp, y_tmp);
	}
}

int main()
{
	while (scanf("%d%d", &n, &m) && n && m) {
		int ans = 0;
		memset(Map, '\0', sizeof(Map));
		for (int i = 0; i < n; i++)
			scanf("%s",Map[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (Map[i][j] == '@') {
					ans++;
					dfs(i, j);
				}
		printf("%d\n", ans);
	}
}
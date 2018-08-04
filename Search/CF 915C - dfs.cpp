/************************************************
Problem: 		CF 915C  Permute Digits
Algorithm: 		DFS
Difficulty: 	+
Significance:	++
Remark:			DF solution and ouput the detail by dfs
Vector exclude first constriction
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3f3f3f3f
using namespace std;
typedef long long ll;
int vis[10],len1,len2;
char str[20];
char num[20];
bool dfs(int k,string s)
{
	if (k == len1) {
		cout << s << endl;
		return true;
	}
	string cmp_str;
	for (int i = 0; i < k + 1; i++)
		cmp_str += num[i];

	for (int i = 9; i >= 0; i--) {
		if (vis[i]) {
			if (s+ char(i + '0') <= cmp_str) {
				vis[i] --;
				if (dfs(k + 1, s + char(i + '0')))
					return true;
				vis[i]++;
			}
		}

	}
	return false;
}
int main()
{

	while (scanf("%s",str) != EOF) {
		memset(vis, 0, sizeof(vis));

		scanf("%s", &num);
		len1 = strlen(str);
		len2 = strlen(num);

		for (int i = 0; i < len1; i++)
			vis[str[i] - '0']++;

		if (len2 > len1) {
			for (int i = 9; i >= 0; i--) {
				while (vis[i]) {
					vis[i]--;
					putchar(i+'0');
				}
			}
			puts("");
		}
		else {
			dfs(0, "");
		}
	}
	return 0;
}
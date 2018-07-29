/************************************************
Problem: 		CF 244C The Brand New Function
Algorithm: 		IQ
Difficulty:		++
Significance:	+
Remark:			
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3f3f3f3f

using namespace std;
int n, T;
int num[100005];
int t[100005][2];
bool vis[1000005];
int main()
{
	long long sum;
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		memset(vis, false, sizeof(vis));
		memset(num, 0, sizeof(num));
		memset(t, 0, sizeof(t));

		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		for(int i = 0; i < n; i++) {
			int start = num[i];
			int test = 0;
			if (vis[start] == false) {
				vis[start] = true;
				sum++;
			}
			for (int j = i + 1; j < n; j++) {
				start |= num[j];
				test |= num[j];
				if (vis[start] == false) {
					vis[start] = true;
					sum++;
				}
				if (start == test)
					break;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

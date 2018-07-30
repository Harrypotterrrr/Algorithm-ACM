/************************************************
Problem: 		HDU 6301 Distinct Values
Algorithm: 		IQ 
Difficulty: 	++++
Significance:	++++
Remark:			AC
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int min_start[100010];
int num[100010];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(min_start, 0, sizeof(min_start));
		memset(num, 0, sizeof(num));

		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			min_start[i] = i;
		for (int i = 1; i <= m; i++) {
			int start, end;
			scanf("%d%d", &start, &end);
			min_start[end] = min(min_start[end], start);
		}
		for (int i = n - 1; i >= 1; i--)
			min_start[i] = min(min_start[i],min_start[i + 1]);
		
		set<int>S;
		int p = 1;
		for (int i = 1; i <= n; i++)
			S.insert(i);
		for (int i = 1; i <= n; i++) {
			while (min_start[i] > p) {
				S.insert(num[p]);
				p++;
			}
			num[i] = *(S.begin());
			S.erase(*(S.begin()));
		}
		printf("%d", num[1]);
		for (int i = 2; i <= n; i++)
			printf(" %d", num[i]);
			puts("");
	}
}
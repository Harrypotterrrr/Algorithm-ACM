/************************************************
Problem: 		CF 27C Unordered Subsequence
Algorithm: 		water
Difficulty: 	
Significance:	
Remark:			
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3f3f3f3f

using namespace std;
int n, T;
int num[100005];
int Sign[100005];
int main()
{
	while (scanf("%d", &n) != EOF) {
		memset(num, 0, sizeof(num));
		memset(Sign, 0, sizeof(Sign));

		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);

		int i, big, small;
		big = small = -1;
		for (i = 1; i < n; i++) {
			if (num[i + 1] > num[i]) {
				big = i + 1;
			}
			else if (num[i + 1] < num[i]) {
				small = i + 1;
			}
			if (big != -1 && small != -1) {
				if(big < small)
					printf("3\n1 %d %d\n", big, small);
				else
					printf("3\n1 %d %d\n", small, big);
				break;
			}
		}
		if (i == n)
			printf("0\n");
	}
	return 0;
}

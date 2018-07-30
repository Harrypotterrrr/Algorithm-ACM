/************************************************
Problem: 		HDU 6324 Grab The Tree
Algorithm: 		Game
Difficulty:		***
Significance:	*
Remark:			Game problem
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits\stdc++.h>
using namespace std;

int a[100005];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		memset(a, 0, sizeof(0));

		int sum = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int x, y;
		for (int i = 1; i < n; i++) 
			scanf("%d%d", &x, &y);

		sum = a[0];
		for (int i = 1; i < n; i++)
			sum ^= a[i];
		if (sum == 0)
			printf("D\n");
		else
			printf("Q\n");
	}
	return 0;
}
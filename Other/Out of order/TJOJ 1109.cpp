#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int arr[100100];
int num[100100];
int Solve(int n)
{
	if (num[n]) {
		return num[n];
	}
	num[n] = Solve(arr[n]) + 1;
	return num[n];
}
int main()
{
	int t, n, m;
	queue <int>Q;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		memset(arr, 0, sizeof(arr));
		memset(num, 0, sizeof(num));
		num[1] = 1;
		scanf("%d%d", &n, &m);

		int num1, num2;
		for (int j = 0; j < n - 1; j++) {
			scanf("%d%d", &num1, &num2);
			arr[num2] = num1;
			if (!arr[num1])
				arr[num1] = num1;
		}
		printf("Case #%d:\n", i + 1);

		//for (int j = n; j >= 2; j--) {
		//	int k, tmp = j;
		//	for (k = 0; !num[tmp]; k++) {
		//		Q.push(tmp);
		//		tmp = arr[tmp];
		//	}
		//	for (; !Q.empty(); k--) {
		//		int nw = Q.front();
		//		Q.pop();
		//		num[nw] = num[tmp] + k;
		//	}
		//}
		for (int j = n; j >= 2; j--)
			Solve(j);
		for (int j = 0; j < m; j++) {
			int nw1 = 0, nw2 = 0;
			scanf("%d%d", &nw1, &nw2);

			if (num[nw1] <= num[nw2])
				printf("Teacher\n");
			else
				printf("Stone\n");
		}
	}

	return 0;
}
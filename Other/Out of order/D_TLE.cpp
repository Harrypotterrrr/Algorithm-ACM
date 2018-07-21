#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int N,M;
int num[500050];

int FindTop()
{
	for (int i = 0; i < N; i++) {
		if (!num[i])
			return i;
	}
	return num[N-1];
}
bool isFull(int des)
{
	for (int i = 0; i < N; i++) {
		if (!num[i] || num[i] + des <= 0)
			return false;
	}
	return true;
}
int main()
{
	int T;

	int start, time;
	scanf("%d", &T);
	for (int u = 1; u <= T; u++) {
		memset(num, 0, sizeof(num));
		int top = 0;
		int t = 0;
		scanf("%d%d", &N,&M);
		printf("Case #%d:\n", u);
		scanf("%d%d", &start, &time);

		int last_time = start;
		bool flag = false;

		for (int i = 0; i < M; i++) {
			if(i)
				scanf("%d%d", &start, &time);
			int des = last_time - start;

			if (isFull(des)) {
				printf("no space left\n");
				continue;
			}

			for (int j = 0; j < N; j++) {
				if (num[j] + des > 0) {
					num[j] += des;
				}
				else {
					num[j] = 0;
				}
			}

			top = FindTop();

			num[top] = time;
			t++;
			printf("%d\n", top);
			last_time = start;
		}
	}
	return 0;
}

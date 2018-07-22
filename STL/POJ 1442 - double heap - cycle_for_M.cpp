/************************************************
Problem: 		POJ 1442 Black Box
Algorithm: 		STL —— double heap
Difficulty: 	+++
Significance:	++++
Remark:			important idea and strategy!
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <map>
#include <set>

using namespace std;

int M, N;
int m[60004], n[60004];

struct cmp1 {
	bool operator()(const int &a, const int &b) const {
		return a > b;
	}
};
struct cmp2 {
	bool operator()(const int &a, const int &b) const {
		return a < b;
	}
};
priority_queue<int, vector<int>, cmp1>small;
priority_queue<int, vector<int>, cmp2>big;

void init()
{
	while (!small.empty())
		small.pop();
	while (!big.empty())
		big.pop();
	memset(m, 0, sizeof(m));
	memset(n, 0, sizeof(n));
}
int main()
{
	while (scanf("%d%d", &M, &N) != EOF) {
		init();

		for (int i = 0; i < M; i++)
			scanf("%d", m + i);
		for (int i = 0; i < N; i++)
			scanf("%d", n + i);

		for (int i = 0, j = 0; j < N; j++) {
			for (; i < n[j]; i++) {
				if (big.empty() || m[i] > big.top())
					small.push(m[i]);
				else {
					small.push(big.top());
					big.pop();
					big.push(m[i]);
				}
			}
			printf("%d\n", small.top());
			big.push(small.top());
			small.pop();
		}
		putchar('\n');
	}
	return 0;
}


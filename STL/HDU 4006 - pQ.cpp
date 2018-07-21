/************************************************
Problem: 		HDU 4006 The kth great number 
Algorithm: 		stl —— priority_queue
Difficulty: 	+
Significance:	+++
Remark:			the smallest heap!
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
#include <map>
#include <set>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a >= b;
	}
};
int main()
{
	int n, k, num;
	char c[3];
	while (~scanf("%d%d", &n, &k)) {
		priority_queue<int, vector<int>, cmp>pQ;
		for (int i = 0; i < n; i++) {
			scanf("%s", &c);
			if (c[0] == 'Q') {
				printf("%d\n", pQ.top());
			}
			else if (c[0] == 'I') {
				scanf("%d", &num);
				pQ.push(num);
				if (pQ.size() > k)
					pQ.pop();
			}
		}
	}
	return 0;
}

/************************************************
Problem: 		HDU 6301 Distinct Values
Algorithm: 		IQ 
Difficulty: 	++++
Significance:	++++
Remark:			TLE
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <functional>
#include <queue>
using namespace std;


struct Node {
	int start;
	int end;
	int length;
	Node() {};
	Node(int start, int end, int length) {
		this->start = start;
		this->end = end;
		this->length = length;
	}
	bool operator<(const Node &t)const {
		if (this->start == t.start)
			return this->length < t.length;
		else
			return this->start > t.start;
	}
};

bool node[100005];
int num[10005] = { 0 };
int main()
{
	int  n, m, tmp_s, tmp_e;
	int T;
	scanf("%d", &T);

	while (T--) {
		memset(node, false, sizeof(node));
		memset(num, 0, sizeof(num));
		priority_queue<Node>pQ;

		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &tmp_s, &tmp_e);
			pQ.push(Node(tmp_s, tmp_e, tmp_e - tmp_s + 1));
		}

		int p = 1;
		while (!pQ.empty()) {
			Node nw = pQ.top();
			pQ.pop();
			if (node[nw.start] != 0) {
				continue;
			}
			if (num[nw.start] == 0) {
				for (int i = 0; i < nw.length; i++)
					num[nw.start + i] = i + 1;
				node[nw.start] = true;
			}
			else if (num[nw.start] != 0) {
				priority_queue<int, vector<int>, greater<int> >tmp;
				for (int i = 0, j = 1; i < nw.length; i++) {
					if (num[nw.start + i] != 0)
						tmp.push(num[nw.start]);
					else if (j != tmp.top())
						num[nw.start + i] = j++;
					else if (j == tmp.top()) {
						j++;
						i--;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (num[i])
				printf("%d ", num[i]);
			else
				printf("1 ");
		}
		putchar('\n');
	}
	return 0;
}
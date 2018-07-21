/************************************************
Problem: 		HDU 4006 The kth great number 
Algorithm: 		stl —— multiset
Difficulty: 	+
Significance:	+++
Remark:			multiset is a container with balance property
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

struct Node {
	int num;
	Node(int num = 0) {
		this->num = num;
	}
	bool operator < (const Node &a) const {
		return this->num >= a.num;
	}
};

int main()
{
	int n, k, num;
	char c[3];
	while (~scanf("%d%d", &n, &k)) {
		multiset<Node>S;
		bool flag = false;
		multiset<Node>::iterator p;
		for (int i = 0; i < n; i++) {
			scanf("%s", &c);
			if (c[0] == 'Q') {
				if (flag) {
					printf("%d\n", p->num);
					continue;
				}
				p = S.begin();
				for (int j = 0; j < k - 1; j++)
					p++;
				flag = true;
				printf("%d\n", p->num);
			}
			else if (c[0] == 'I') {
				scanf("%d", &num);
				if (!flag)
					S.insert(Node(num));
				if (flag && num >= p->num) {
					S.insert(Node(num));
					p--;
				}
			}
		}
	}
	return 0;
}
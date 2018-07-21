#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Node
{
	int no;
	string str;
	bool tag;
	Node(int a, string b, bool c) : no(a), str(b), tag(c) {};
	Node() {};
	//bool operator<(const Node&a)const {
	//	return str > a.str;
	//}
};
Node node[50005 * 2];
int ranking[50005 * 2];

bool Cmp(char a, char b)
{
	return a < b;
}
bool Cmp2(Node &a, Node &b)
{
	int flag = a.str.compare(b.str);
	if (!flag)
		return a.tag;
	return flag < 0;	//from small to big

	//TLE:

	//if (a.str == b.str)
	//	return a.tag;
	//return a.str < b.str;
}
int main()
{
	int T, n;
	string str, tmp;
	scanf("%d", &T);
	for (int u = 0; u < T; u++) {
		scanf("%d", &n);
		printf("Case #%d:\n", u + 1);
		for (int i = 0; i < 2 * n; i += 2) {
			cin >> str;
			sort(str.begin(), str.end(), Cmp);
			tmp = string(str.rbegin(), str.rend());
			node[i] = Node(i / 2, str, true);
			node[i + 1] = Node(i / 2, tmp, false);
		}
		sort(node, node + n * 2, Cmp2);

		int ctr_best = 0, ctr_double = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (node[i].tag) {
				ranking[node[i].no * 2] = ctr_double + 1;
				ctr_best++;
			}
			else if (!node[i].tag) {
				ranking[node[i].no * 2 + 1] = ctr_best;
				ctr_double++;
			}
		}
		for (int i = 0; i < 2 * n; i += 2)
			printf("%d %d\n", ranking[i], ranking[i + 1]);
	}
	return 0;
}
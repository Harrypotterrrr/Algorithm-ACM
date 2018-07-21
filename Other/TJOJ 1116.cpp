#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int N, M;
int num[100050];

struct Cmp {
	bool operator () (const int &a, const int &b)const {
		return a > b;
	}
};
struct Node{
	int time;
	int no;
	//bool operator < (const Node &a)const {
	//	return time > a.time;
	//}
	Node(int a, int b) : time(a), no(b) {};
};
int main()
{
	int T;

	scanf("%d", &T);
	for (int u = 1; u <= T; u++) {
		memset(num, 0, sizeof(num));
		scanf("%d%d", &N, &M);
		printf("Case #%d:\n", u);
		priority_queue<int, vector<int>, Cmp> Q_no;
		priority_queue<Node> Q_time;

		for (int i = 0; i < N; i++)
			Q_no.push(i);

		int start, time;
		scanf("%d%d", &start, &time);
		Q_time.push( Node( start + time, 0 ));
		printf("0\n");
		Q_no.pop();
		for (int i = 1; i < M; i++) {
			scanf("%d%d", &start, &time);
			while (!Q_time.empty() && Q_time.top().time <= start) {
				Q_no.push(Q_time.top().no);
				Q_time.pop();
			}
			if (Q_time.size() == N) {
				printf("no space left\n");
				break;
			}
			int no = Q_no.top();
			printf("%d\n", no);
			Q_no.pop();
			Q_time.push({ start + time,no });
		}
	}
	return 0;
}

/*
Dijkstra的算法思想：
在所有没有访问过的结点中选出dis(s,x)值最小的x
对从x出发的所有边(x,y),更新
dis(s,y)=min(dis(s,y),dis(s,x)+dis(x,y))
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int Ni = 10000;
const int INF = 1 << 27;
struct node {
	int to, d;
	node() {}
	node(int a, int b) { x = a; d = b; }
	bool operator < (const node & a) const {
		if (d == a.d) return x < a.x;
		else return d > a.d;
	}
};
vector<node> eg[Ni];
int dis[Ni], n;
void Dijkstra(int s)
{
	int i;
	for (i = 0; i <= n; i++) dis[i] = INF;
	dis[s] = 0;
	//用优先队列优化
	priority_queue<node> q;
	q.push(node(s, dis[s]));
	while (!q.empty()) {
		node x = q.top(); q.pop();
		for (i = 0; i < eg[x.to].size(); i++) {
			node y = eg[x.to][i];
			if (dis[y.to] > x.d + y.d) {
				dis[y.to] = x.d + y.d;
				q.push(node(y.to, dis[y.to]));
			}
		}
	}
}
int main()
{
	int a, b, d, m;
	while (scanf("%d%d", &n, &m), n + m)
	{
		for (int i = 0; i <= n; i++) eg[i].clear();
		while (m--)
		{
			scanf("%d%d%d", &a, &b, &d);
			eg[a].push_back(node(b, d));
			eg[b].push_back(node(a, d));
		}
		Dijkstra(1);
		printf("%d\n", dis[n]);
	}
	return 0;
}
/*
6 6
1 2 2
3 2 4
1 4 5
2 5 2
3 6 3
5 6 3
*/
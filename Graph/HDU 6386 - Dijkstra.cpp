/************************************************
Problem: 		HDU 6386 Age of Moyu
Algorithm: 		Dijkstra
Difficulty:		***
Significance:	**
Remark:			select the least altered path
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifdef ONLINE_JUDGE 
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <assert.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define input(x) scanf("%d",&x)
#define inputl(x) scanf("%INT64d",&x)
#define inputd(x) scanf("%lf",&x)
#define inputs(x) scanf("%s",x)
#define input2(x,y) scanf("%d%d",&x,&y)
#define input3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define output(x) printf("%d\n",x)
#define outputl(x) printf("%INT64d\n",x)
#define outputd(x) printf("%lf\n",x)
#define outputs(x) printf("%s\n",x)
#define mst(x,y) memset(x,y,sizeof(x))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define INF 0x3f3f3f3f
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1000000007;
ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

#define MAXN 100005

int dis[MAXN], a, b, c, M, N;
bool vis[MAXN];
set<int>S[MAXN];
struct Edge {
	int tag, v;
	Edge(int a, int b) : tag(a), v(b) {}
};
vector<Edge>V[MAXN];
struct Node {
	int tag, w, v;
	Node(int a, int b, int c) : tag(a), w(b), v(c) {}
	bool operator<(const Node& cur)const {
		return this->w > cur.w;
	}
};
void bfs()
{
	priority_queue<Node>pQ;
	pQ.push(Node(-1, 0, 1));
	dis[1] = 0;
	while (!pQ.empty()) {
		Node cur = pQ.top();
		pQ.pop();
		//if (vis[cur.v] == true) continue;
		//vis[cur.v] = true;
		for (int i = 0; i < V[cur.v].size(); i++) {
			int nv = V[cur.v][i].v;
			int nt = V[cur.v][i].tag;
			bool tag = false;

			int cost = cur.w + (!S[cur.v].count(nt));
			//if (vis[nv] == false) {
				if (dis[nv] > cost) {
					dis[nv] = cost;
					pQ.push(Node(nt, dis[nv], nv));
					S[nv].clear();
					S[nv].insert(nt);
				}
				else if(dis[nv] == cost)
					S[nv].insert(nt);
			//}
		}
	}
}
void init()
{
	mst(vis, false);
	mst(dis, INF);
	rep(i, 0, N + 1)	V[i].clear();
	rep(i, 0, N + 1)	S[i].clear();
}
int main()
{
	while (input2(N, M) != EOF) {
		init();
		rep(i, 0, M) {
			input3(a, b, c);
			V[a].push_back(Edge(c, b));
			V[b].push_back(Edge(c, a));
		}
		bfs();
		if (dis[N] >= INF)
			printf("-1\n");
		else
			output(dis[N]);
	}
	return 0;
}

/************************************************
Problem: 		HDU 1847 Tram
Algorithm: 		Dijkstra
Difficulty:		
Significance:	
Remark:			the simplest
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

#define MAXN 120

int dis[MAXN], a, b, c, N, A, B;
bool vis[MAXN];
struct Edge {
	int v, w;
	Edge(int a, int b) :v(a), w(b) {}
};
vector<Edge>V[MAXN];
struct Node {
	int v, w;
	Node(int a, int b) :v(a), w(b) {}
	bool operator<(const Node& cur)const {
		return w > cur.w;
	}
};
void bfs()
{
	priority_queue<Node>pQ;
	pQ.push(Node(A, 0));
	dis[A] = 0;
	while (!pQ.empty()) {
		Node cur = pQ.top();
		pQ.pop();
		if (vis[cur.v] == true) continue;
		vis[cur.v] = true;
		for (int i = 0; i < V[cur.v].size(); i++) {
			int nv = V[cur.v][i].v;
			int nw = V[cur.v][i].w;
			if (!vis[nv] && dis[nv] > dis[cur.v] + nw) {
				dis[nv] = dis[cur.v] + nw;
					pQ.push(Node(nv, dis[nv]));
			}
		}
	}
}
void init()
{
	mst(vis, false);
	mst(dis, INF);
	rep(i, 0, N + 1)	V[i].clear();
}
int main()
{
	while (input3(N, A, B) != EOF) {
		init();
		rep(i, 1, N + 1) {
			input(a);
			rep(j, 0, a) {
				input(b);
				if(j == 0) V[i].push_back(Edge(b, 0));
				else V[i].push_back(Edge(b, 1));
			}
		}
		bfs();
		if (dis[B] >= INF)
			printf("-1\n");
		else
			output(dis[B]);
	}
	return 0;
}

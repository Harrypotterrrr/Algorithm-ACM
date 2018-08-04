/************************************************
Problem: 		CF 437D The Child and Zoo
Algorithm: 		Union-Found Greed
Difficulty:		***
Significance:	*****
Remark:			important Union-Found combined with Greed strategy
				to choose the maximum or minimum one!
				Using struct Edge to store the whole Graph!
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifdef ONLINE_JUDGE 
#include <iostream>
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
#define inputl(x) scanf("%lld",&x)
#define inputf(x) scanf("%lfd",&x)
#define inputs(x) scanf("%s",x)
#define input2(x,y) scanf("%d%d",&x,&y)
#define output(x) printf("%d\n",x)
#define outputl(x) printf("%lld\n",x)
#define outputf(x) printf("%lf\n",x)
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
int n, m, a, b;
int father[MAXN],value[MAXN],ctr[MAXN];
double ans;
struct Edge;
vector<Edge>V;

struct Edge {
	int u, v, w;
	Edge() {};
	Edge(int a, int b, int c) { u = a, v = b, w = c; };
};

bool cmp(Edge a, Edge b) {
	return a.w > b.w;
}

int Find(int x) {
	return father[x] == -1 ? x : father[x] = Find(father[x]);
}

void Union(const Edge &e) {
	int t1 = Find(e.u);
	int t2 = Find(e.v);
	if (t1 != t2) {
		father[t1] = t2;
		ans += 1.0 * ctr[t2] * ctr[t1] * e.w;
		ctr[t2] += ctr[t1];
	}
}
void init()
{
	mst(father, -1);
	mst(value, 0);
	rep(i, 1, n + 1)
		ctr[i] = 1;
	ans = 0;
}
int main()
{
	while (input2(n,m) == 2) {
		init();

		rep(i, 1, n + 1)
			input(value[i]);
		rep(i, 0, m) {
			input2(a, b);
			V.push_back(Edge(a, b, min(value[a], value[b])));
		}
		sort(V.begin(), V.end(), cmp);

		rep(i, 0, V.size())
			Union(V[i]);
		outputf(ans * 2.0 / n / (n - 1));
	}
}
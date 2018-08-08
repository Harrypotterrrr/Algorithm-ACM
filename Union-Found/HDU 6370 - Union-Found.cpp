/************************************************
Problem: 		HDU 6370 Werewolf
Algorithm: 		Union-Found
Difficulty:		****
Significance:	****
Remark:			IQ to construct model
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
#define output(x) printf("%d\next",x)
#define outputl(x) printf("%INT64d\next",x)
#define outputd(x) printf("%lf\next",x)
#define outputs(x) printf("%s\next",x)
#define mst(x,y) memset(x,y,sizeof(x))
#define rep(i,a,next) for (int i=a;i<next;i++)
#define per(i,a,next) for (int i=next-1;i>=a;i--)
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

int father[MAXN], x,T,N;
int w[MAXN];
char str[15];
bool isWolf[MAXN];
vector<int>V[MAXN];

int Find(int x)
{
	return father[x] == -1 ? x : father[x] = Find(father[x]);
}
void Union(int u, int v)
{
	int t1 = Find(u);
	int t2 = Find(v);
	if (t1 != t2)	father[t1] = t2;
}
void init()
{
	mst(father, -1);
	mst(isWolf, false);
	mst(w, 0);
	rep(i, 1, N + 1) V[i].clear();
}
void solve(int x)
{
	if (isWolf[x] == true)	return;
	isWolf[x] = true;
	rep(i, 0, V[x].size())	solve(V[x][i]);
}
int main()
{
	input(T);
	while (T--) {
		init();
		input(N);
		rep(i, 1, N + 1) {
			input(x);
			scanf("%s", str);
			if (str[0] == 'v') {
				Union(i, x);
				V[x].push_back(i);
			}
			else w[i] = x;
		}
		mst(isWolf, false);
		rep(i, 1, N + 1) {
			if (w[i] && Find(w[i]) == Find(i))
				solve(w[i]);
		}
		int ans = 0;	
		rep(i, 1, N + 1)	if (isWolf[i] == true)	ans++;
		printf("0 %d\n", ans);
	}
	return 0;
}

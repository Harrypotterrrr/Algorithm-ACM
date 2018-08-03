/************************************************
Problem: 		HDU 1213 How Many Tables
Algorithm: 		Union-Found
Difficulty:		
Significance:	*
Remark:			The simplest Union-Found
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifdef ONLINE_JUDGE 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <set>
#include <assert.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define input(x) scanf("%d",&x)
#define inputd(x) scanf("%lld",&x)
#define inputs(x) scanf("%s",x)
#define input2(x,y) scanf("%d%d",&x,&y)
#define output(x) printf("%d\n",x)
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

#define MAXN 1005
int father[MAXN];

int Find(int x) {
	return father[x] == -1 ? x : father[x] = Find(father[x]);
}

void Union(int u, int v)
{
	int t1 = Find(u);
	int t2 = Find(v);
	if (t1 != t2)
		father[t1] = t2;
}

int T, N, M, a, b;
int main()
{
	input(T);
	while (T--) {
		mst(father, -1);

		input2(N, M);
		rep(i, 0, M) {
			input2(a, b);
			Union(a, b);
		}
		int ans = 0;
		rep(i, 1, N + 1)	if (father[i] == -1) ans++;
		output(ans);
	}
}
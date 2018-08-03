/************************************************
Problem: 		HDU 1962 Corporative Network
Algorithm: 		Union-Found
Difficulty:		***
Significance:	****
Remark:			weighted union-found algorithm with diversified solutions
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

#define MAXN 20005
int T, N, a, b;
char order;
int dis[MAXN], father[MAXN];

int Find(int x) {
	if (father[x] == -1)
		return x;
	// solution 1:
	//int f = father[x];
	//father[x] = Find(father[x]);
	//dis[x] += dis[f];
	//return father[x];

	// solution 2:
	int tmp = Find(father[x]);
	dis[x] += dis[father[x]];
	return father[x] = tmp;
}

void Union(int u, int v) {
	int t1 = Find(u);
	int t2 = Find(v);
	if (t1 != t2)
		father[t1] = t2;	// same to: father[u] = t2;
	dis[u] = abs(v - u) % 1000 + dis[v];
}

char str[5];
int main()
{
	input(T);
	while (T--) {
		mst(dis, 0);
		mst(father, -1);

		input(N);
		while (inputs(str) && str[0] != 'O') {
			if (str[0] == 'E') {
				input(a);
				Find(a);	// IMPORTANT!
				output(dis[a]);
			}
			else if (str[0] == 'I'){
				input2(a, b);
				Union(a, b);
			}
		}
	}
}
/************************************************
Problem: 		HDU 3234 Exclusive-OR
Algorithm: 		Union-Found
Difficulty:		*****
Significance:	*****
Remark:			Very difficult and strategical solutions with ingenious
				algorithm, this problem is typical and essential!
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
int n, Q, st[18];
int dis[MAXN], father[MAXN];
int ctr[MAXN];

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
	dis[x] ^= dis[father[x]];
	return father[x] = tmp;
}

bool Union(int u, int v, int w)
{
	int t1 = Find(u);
	int t2 = Find(v);
	if (t1 == t2) return (dis[u] ^ dis[v]) == w;
	if (t1 == n) swap(t1, t2);	// IMPORTANT!
	father[t1] = t2;
	dis[t1] = dis[u] ^ dis[v] ^ w;
	return true;
}
void Query()
{
	int ans = 0;
	rep(i, 1, st[0] + 1) {
		int t = Find(st[i]);
		ctr[t] ++;
	}
	rep(i, 1, st[0] + 1) {
		int t = Find(st[i]);
		ans ^= dis[st[i]];
		if ((ctr[t] & 1) && t != n) {
			printf("I don't know.\n");
			return;
		}
	}
	output(ans);
}
char str[500];

void init()
{
	mst(dis, 0);
	mst(father, -1);
	mst(ctr, 0);
}
int main()
{
	int _ = 0;
	while (input2(n, Q) && n && Q) {
		_++;
		init();
		printf("Case %d:\n", _);
		bool tag, flag = true;
		int _q = 0;
		rep(__, 0, Q) {
			inputs(str);
			if (str[0] == 'Q') {
				input(st[0]);
				rep(i, 1, st[0] + 1) {
					input(st[i]);
					ctr[Find(st[i])] = 0;
				}
				if(flag) Query();
			}
			else if (str[0] == 'I'){
				_q++;
				cin.getline(str, 500, '\n');
				if (sscanf(str, "%d %d %d", &st[0], &st[1], &st[2]) == 3)
					tag = Union(st[0], st[1], st[2]);
				else
					tag = Union(st[0], n, st[1]);
				if (!tag) { printf("The first %d facts are conflicting.\n", _q); flag = false;}
			}
		}
		puts("");
	}
}

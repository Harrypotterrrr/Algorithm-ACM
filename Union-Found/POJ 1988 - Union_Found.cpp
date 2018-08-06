/************************************************
Problem: 		POJ 1988 Cube Stacking
Algorithm: 		Union-Found
Difficulty:		*
Significance:	**
Remark:			weighted Union-Found algorithm
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


#define MAXN 30005

char str[10];
int a, b;
int T,father[MAXN],dis[MAXN],ctr[MAXN];

int Find(int x)
{
	if (father[x] == -1)
		return x;
	int tmp = Find(father[x]);
	dis[x] += dis[father[x]];
	return father[x] = tmp;
}

void Union(int u, int v)
{
	int t1 = Find(u);
	int t2 = Find(v);
	if (t1 != t2) {
		father[t1] = t2;
		dis[t1] = ctr[t2];
		ctr[t2] += ctr[t1];
	}
}
void init()
{
	mst(father, -1);
	mst(dis, 0);
	rep(i, 0, MAXN - 1)
		ctr[i] = 1;
}
int main()
{
	while (input(T) == 1) {
		init();
		rep(i, 0, T) {
			scanf("%s", str);
			if (str[0] == 'M') {
				input2(a, b);
				Union(a, b);
			}
			else {
				input(a);
				Find(a);
				output(dis[a]);
			}
		}
	}
	return 0;
}
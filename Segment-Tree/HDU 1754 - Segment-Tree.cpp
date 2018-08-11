/************************************************
Problem: 		HDU 1754 I Hate It
Algorithm: 		Segment Tree
Difficulty:		*
Significance:	***
Remark:			Simplest
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

#define MAXN 200001
#define MOD 10007

int N, M, a, b;
char str[10];
int grade[MAXN], segTree[2 * MAXN];
void PushUp(int root)
{
	segTree[root] = max(segTree[root * 2 + 1], segTree[root * 2 + 2]);
}
void Build(int root, int nstart, int nend) 
{
	if (nstart == nend) { segTree[root] = grade[nstart]; return; }
	int mid = (nstart + nend) / 2;
	Build(root * 2 + 1, nstart, mid);
	Build(root * 2 + 2, mid + 1, nend);
	PushUp(root);
}
void Update(int root, int nstart, int nend, int k, int value)
{
	if (nstart == nend) { segTree[root] = value; return; }
	int mid = (nstart + nend) / 2;
	if (k <= mid)	Update(root * 2 + 1, nstart, mid, k, value);
	else	Update(root * 2 + 2, mid + 1, nend, k, value);
	PushUp(root);
}
int Query(int root, int nstart, int nend, int qstart, int qend) 
{
	if (qstart > nend || qend < nstart)	return -INF;
	if (qstart <= nstart && qend >= nend)	return segTree[root];
	int mid = (nstart + nend) / 2;
	return max(Query(root * 2 + 1, nstart, mid, qstart, qend), Query(root * 2 + 2, mid + 1, nend, qstart, qend));
}
int main()
{
	while (input2(N, M) != EOF) {
		rep(i, 0, N)	input(grade[i]);
		Build(0, 0, N - 1);
		while (M--) {
			inputs(str);
			if (str[0] == 'Q') { input2(a, b); output(Query(0, 0, N - 1, a - 1, b - 1)); }
			else if (str[0] == 'U') { input2(a, b); Update(0, 0, N - 1, a - 1, b); }
		}
	}
	return 0;
}
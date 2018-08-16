/************************************************
Problem: 		POJ 3090 Visible Lattice Points
Algorithm: 		Eular
Difficulty:		
Significance:	**
Remark:			
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

#define MAXN 1005
int T, n, ans[MAXN];
int Eular(int x)
{
	int rtn = x;
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			rtn -= rtn / i;
			do x /= i; while (x % i == 0);
		}
	}
	if (x > 1)	rtn -= rtn / x;
	return rtn;
}
int main()
{
	rep(i, 1, MAXN)	ans[i] = Eular(i);
	ans[1] = 3;
	rep(i, 2, MAXN) { ans[i] *= 2; ans[i] += ans[i - 1]; }
	// f(x) = f(x-1) + Eular(x) + 1
	input(T);
	rep(_, 1, T + 1) {
		input(n);
		printf("%d %d ", _, n);
		output(ans[n]);
	}
	return 0;
}
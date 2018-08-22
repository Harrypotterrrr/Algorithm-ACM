/************************************************
Problem: 		HDU 6432 Problem G. Cyclic
Algorithm: 		Combinatorics_InverseElement
Difficulty:		***
Significance:	*****
Remark:			combinatorics, and using Extended Euclid algorithm or
				quick power algorithm to calculate inverse element
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
//#include <time.h>
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
#define inputl(x) scanf("%I64d",&x)
#define inputd(x) scanf("%lf",&x)
#define inputs(x) scanf("%s",x)
#define input2(x,y) scanf("%d%d",&x,&y)
#define input3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define output(x) printf("%d\n",x)
#define outputl(x) printf("%I64d\n",x)
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
//ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

#define MAXN 100001
#define MOD 998244353

int T;
ll n;
ll fac[MAXN], ifac[MAXN];

ll powmod(ll a, ll x)
{
	ll rtn = 1;
	while (x) {
		if (x & 1)	rtn = rtn * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return rtn;
}
ll Calc()
{
	ll ans = (n & 1)? MOD - 1 : 1;
	rep(i, 0, n) {
		ll tmp = fac[n] * ifac[i] % MOD * fac[n - i - 1] % MOD  * ifac[n - i] % MOD;
		if (i & 1) { ans += (MOD - tmp); ans %= MOD; }
		else { ans += tmp; ans %= MOD; }
	}
	return ans;
}
int main()
{
	fac[0] = ifac[0] = 1;
	rep(i, 1, MAXN) {
		fac[i] = fac[i - 1] * i % MOD;
		ifac[i] = powmod(fac[i], MOD - 2);
	}

	input(T);
	while (T--) {
		inputl(n);
		outputl(Calc());
	}

	return 0;
}

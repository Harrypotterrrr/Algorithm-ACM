/************************************************
Problem: 		POJ 2480 Longge's problem
Algorithm: 		Euler Gcd
Difficulty:		***
Significance:	****
Remark:			skillful problem with igenious way to simplify
				arithmetical operation.
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
#define inputl(x) scanf("%lld",&x)
#define inputd(x) scanf("%lf",&x)
#define inputs(x) scanf("%s",x)
#define input2(x,y) scanf("%d%d",&x,&y)
#define input3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define output(x) printf("%d\n",x)
#define outputl(x) printf("%lld\n",x)
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
//ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

ll n;
ll Euler(ll x)
{
	ll ans = x;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			ans -= ans / i;
			do x /= i; while (x % i == 0);
		}
	}
	if (x > 1)	ans -= ans / x;
	return ans;
}

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	while (inputl(n) != EOF) {
		ll ans = 0, i;
		for (i = 1; i * i < n; i++) if (n%i == 0) ans += i * Euler(n / i) + n / i * Euler(i);
		if (i * i == n)	ans += i * Euler(i);
		outputl(ans);
	}
	return 0;
}
/************************************************
Problem: 		HDU 6418 Rikka with Stone-Paper-Scissors
Algorithm: 		IQ
Difficulty:		***
Significance:	*
Remark:			
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

#define MAXN 10001
#define MOD 998244353

int T;
ll a, b, c;
int main() {
	input(T);
	ll a1, b1, c1;
	ll a2, b2, c2;
	while (T--) {
		scanf("%I64d%I64d%I64d", &a1, &b1, &c1);
		scanf("%I64d%I64d%I64d", &a2, &b2, &c2);
		ll up = a1 * (b2 - c2) + b1 * (c2 - a2) + c1 * (a2 - b2);
		ll down = a1 + b1 + c1;
		if (up%down == 0) printf("%I64d\n", up / down);
		else {
			ll g = abs(gcd(up, down));
			printf("%I64d/%I64d\n", up/g, down/g);
		}
	}
	return 0;
}
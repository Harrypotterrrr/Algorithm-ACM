/************************************************
Problem: 		POJ 2115 C Looooops
Algorithm: 		Extend Euclid
Difficulty:		*****
Significance:	*****
Remark:			very skillful problem with important algorithm
				¡ª¡ªExEuclid, and more detail is posted on script
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
#define MOD 9901
ll A, B, C, k, X, Y;

ll ExGcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0) {
		x = 1, y = 0;	return a;
	}
	ll gcd = ExGcd(b, a%b, x, y);
	ll tmp = y;
	y = x - a / b * y;
	x = tmp;
	return gcd;
}
int main()
{
	while (true) {
		inputl(A), inputl(B), inputl(C), inputl(k);
		if (!A && !B && !C && !k)	break;
		k = (1ll << k);
		ll gcd = ExGcd(k, C, X, Y);
		if ((B - A) % gcd != 0) {
			printf("FOREVER\n");
			continue;
		}
		Y *= (B - A) / gcd;
		k /= gcd;
		Y = ( Y % k + k) % k;
		outputl(Y);
	}
	return 0;
}
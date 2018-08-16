/************************************************
Problem: 		POJ 1845 Sumdiv
Algorithm: 		PowMod GetPrime GetFactor SumGeo
Difficulty:		****
Significance:	*****
Remark:			very typical problem with difficult but essential
				algorithm to solve. Including many basic math solutions
				of number theor.
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
int A, B, fac_ctr;
int prime[MAXN];
void GetPrime()	// get the prime list
{
	mst(prime, 0);
	for (int i = 2; i <= MAXN; i++) {
		if (!prime[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++) {
			prime[prime[j] * i] = -1;
			if (i % prime[j] == 0) break;
		}
	}
}
ll factor[100][2];
void GetFactor(int x)	// decompose the number to its prime factor
{
	fac_ctr = 0;
	for (int i = 1; prime[i] && prime[i] <= x / prime[i]; i++) {
		if (x % prime[i] == 0) {
			factor[fac_ctr][0] = prime[i];
			while (x % prime[i] == 0) {
				factor[fac_ctr][1] ++;
				x /= prime[i];
			}
			fac_ctr++;
		}
	}
	if (x != 1) {
		factor[fac_ctr][0] = x;
		factor[fac_ctr++][1] ++;
	}
}
ll PowMod(ll a, ll n) //quick power mode
{
	ll rtn = 1;
	ll tmp = a % MOD;
	while (n) {
		if (n & 1) rtn = rtn * tmp % MOD;
		n >>= 1;
		tmp = tmp * tmp % MOD;
	}
	return rtn;
}
ll Sum_Geo(ll p, ll n) //calculate 1+p+p^2+....+p^n
{
	if (p == 0) return 0;
	if (n == 0) return 1;
	if (n & 1) return (Sum_Geo(p, n / 2) % MOD * (1 + PowMod(p, n / 2 + 1)) % MOD) % MOD;
	//   1+p+p^2+p^3+........+p^n=(1+p+p^2+....+p^(n/2))*(1+p^(n/2+1))
	else return (Sum_Geo(p, n / 2 - 1) % MOD * (1 + PowMod(p, n / 2 + 1)) % MOD + PowMod(p, n / 2) % MOD) % MOD;
	//	 1+p+p^2+p^3+........+p^n=(1+p+p^2+....+p^(n/2-1))*(1+p^(n/2+1)) + p^n/2;
}
int main()
{
	GetPrime();
	while (input2(A, B) != EOF) {
		GetFactor(A);
		ll ans = 1;
		rep(i, 0, fac_ctr) 
			ans = ans * Sum_Geo(factor[i][0], B*factor[i][1]) % MOD;
		outputl(ans);
	}
	return 0;
}
/************************************************
Problem: 		HDU 6434 Problem I. Count
Algorithm: 		Euler_LinearPrime_Sieve
Difficulty:		****
Significance:	*****
Remark:			Euler using linear prime sieve method
				to optimize, and mathematical derivation
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
#define SZ(x) ((int)(x).ctr())
#define INF 0x3f3f3f3f
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
//ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

#define MAXN 20000000
#define MOD 9901

int T, n;
ll sum[MAXN + 1];
int prime[MAXN + 5], phi[MAXN + 5];
int ctr;
//1. phi(p)=p-1   因为质数p除了1以外的因数只有p，故1至p的整数只有p与p不互质
//2. 如果i mod p = 0, 那么phi(i * p)=p * phi(i)
//3.若i mod p ≠0,  那么phi(i * p)=phi(i) * (p-1)
void Euler_PrimeSieve()
{
	ctr = 0;
	phi[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (prime[i] == 0) {
			prime[++ctr] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= ctr && i*prime[j] <= MAXN; j++) {
			prime[i*prime[j]] = -1;
			if (i%prime[j] == 0) {
				phi[i*prime[j]] = prime[j] * phi[i];
				break;
			}
			phi[i*prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}

int main()
{
	input(T);
	sum[1] = 0;
	Euler_PrimeSieve();
	rep(i, 2, 20000001) {
		if(i % 2) sum[i] = sum[i - 1] + phi[i] / 2;
		else sum[i] = sum[i - 1] + phi[i];
	}
	while (T--) {
		input(n);
		outputl(sum[n]);
	}
}
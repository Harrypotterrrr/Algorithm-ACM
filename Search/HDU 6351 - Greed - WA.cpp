/************************************************
Problem: 		HDU 1962 Corporative Network
Algorithm: 		Union-Found
Difficulty:		***
Significance:	****
Remark:			weighted union-found algorithm with diversified solutions
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

#define MAXN 1005


int T, k;
char n[150], minn[150],maxn[150];
int main()
{
	input(T);
	while (T--) {
		int M_min[12], M_max[12];
		mst(M_min, 0);
		mst(M_max, 0);

		scanf("%s", n);
		strcpy(maxn, n);
		strcpy(minn, n);
		input(k);
		int len = strlen(n), kmin = k, kmax = k;
		rep(i, 0, len) { M_min[n[i] - '0'] ++; M_max[n[i] - '0']++; }
		rep(j, 0, len) {
			int nw = minn[j] - '0', u, p;
			for (u = 0; u < nw; u++)
				if (M_min[u])
					if (u > 0 || (u == 0 && j > 0))
						break;

			if (u == nw) {
				M_min[minn[j] - '0']--;
				continue;
			}

			for (p = len - 1; p > j; p--)
				if (minn[p] == u + '0')	break;
			if (p == j) {
				M_min[minn[j] - '0']--;
				continue;
			}

			M_min[u]--;
			swap(minn[j], minn[p]);
			if (--kmin == 0)	break;
		}
		rep(j, 0, len) {
			int nw = maxn[j] - '0', u, p;
			for (u = 9; u > nw; u--)
				if (M_max[u])
					break;
			if (u == nw) {
				M_max[maxn[j] - '0']--;
				continue;
			}

			for (p = len - 1; p > j; p--)
				if (maxn[p] == u + '0')	break;
			if (p == j) {
				M_max[maxn[j] - '0']--;	
				continue;
			}

			M_max[u]--;
			swap(maxn[j], maxn[p]);

			if (--kmax == 0) break;
		}
		printf("%s %s\n", minn, maxn);
	}
}
/************************************************
Problem: 		HDU 6406 Taotao Picks Apples
Algorithm: 		IQ
Difficulty:		***
Significance:	**
Remark:			upper_bound & lower_bound Function
				difficult to program and easy to be trapped
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

#define MAXN 100050
int T, n, m, p, q;
int h[MAXN], no[MAXN], apple[MAXN];


void init()
{
	mst(no, 0);
	mst(apple, 0);
	mst(h, 0);
	apple[0] = -INF;
}
int main()
{
	input(T);
	while (T--) {
		init();

		input2(n, m);
		int pre = -INF, ctr = 0;
		rep(i, 1, n + 1) {
			input(h[i]);
			if (h[i] > pre) {
				apple[++ctr] = h[i];
				pre = h[i];
				no[ctr] = i;
			}
		}
		no[ctr + 1] = INF;
		apple[ctr + 1] = INF;
		rep(_, 1, m + 1) {
			input2(p, q);
			if (h[p] == q) {
				output(ctr);
				continue;
			}
			int pos = lower_bound(no + 1, no + ctr + 1, p) - no;
			if (no[pos] == p) {
				if (q < apple[pos]) {
					int cctr = 0;
					pre = apple[pos - 1];
					if (q > pre) {
						pre = q;
						cctr++;
					}
					for (int j = no[pos] + 1; j < no[pos + 1] && j <= n; j++) {
						if (h[j] > pre) {
							pre = h[j];
							cctr++;
						}
					}
					output(ctr + cctr - 1);
				}
				else {
					int findBigNo = upper_bound(apple + pos, apple + ctr + 1, q) - apple;
					output(ctr - (findBigNo - pos) + 1);
				}
			}
			else {
				if (apple[pos - 1] >= q)	output(ctr);
				else {
					int findBigNo = upper_bound(apple + pos, apple + ctr + 1, q) - apple;
					output(ctr - (findBigNo - pos) + 1);
				}
			}
		}
	}
	return 0;
}
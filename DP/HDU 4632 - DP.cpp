/************************************************
Problem: 		HDU 4632 Palindrome subsequence
Algorithm: 		DP
Difficulty:		**
Significance:	*
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
#define MOD 10007

int dp[MAXN][MAXN];
char str[MAXN];
int n;
int main()
{
	input(n);
	rep(_, 1, n + 1) {
		mst(dp, 0);

		inputs(str);
		auto len = strlen(str);
		rep(i, 0, len) dp[i][i] = 1;
		rep(k, 2, len + 1)
			rep(i, 0, len - k + 1) {
			int start = i, end = i + k - 1;
			dp[start][end] = (dp[start][end - 1] - dp[start + 1][end - 1] + dp[start + 1][end] + MOD) % MOD;
			if (str[start] == str[end])
				dp[start][end] = (dp[start][end] + dp[start + 1][end - 1] + 1) % MOD;
		}
		printf("Case %d: %d\n", _, dp[0][len - 1]);
	}
	return 0;
}
/************************************************
Problem: 		HDU 6351 Beautiful Now
Algorithm: 		DFS
Difficulty:		**
Significance:	*
Remark:			very easy to be in trapped for mistaking
				it into Greed 
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

int T, k, len;
char n[150], n2[15];
int Convert(char *s)
{
	int ans = 0;
	rep(i, 0, len) {
		ans *= 10;
		ans += s[i] - '0';
	}
	return ans;
}
int FindMax(int s, int p)
{
	if (p == k)	return s;
	int maxn = s;
	rep(i, p, len - 1)
		rep(j, i + 1, len) {
		if (n[i] < n[j]) {
			swap(n[i], n[j]);
			int nw = FindMax(Convert(n), p + 1);
			maxn = maxn > nw ? maxn : nw;
			swap(n[i], n[j]);
		}
	}
	return maxn;
}
int FindMin(int s, int p)
{
	if (p == k)	return s;
	int minn = s;
	rep(i, p, len - 1)
		rep(j, i + 1, len) {
		if (n2[i] > n2[j] && (i != 0 || n2[j] != '0')) {
			swap(n2[i], n2[j]);
			int nw = FindMin(Convert(n2), p + 1);
			minn = minn < nw ? minn : nw;
			swap(n2[i], n2[j]);
		}
	}
	return minn;
}
int main()
{
	input(T);
	while (T--) {

		scanf("%s", n);
		input(k);
		strcpy(n2, n);
		len = strlen(n);
		int num = Convert(n);
		int minn = FindMin(num, 0);
		int maxn = FindMax(num, 0);

		printf("%d %d\n", minn, maxn);
	}
}
/************************************************
Problem: 		CF 250C Movie Critics
Algorithm: 		IQ
Difficulty:		**
Significance:	
Remark:			
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifdef ONLINE_JUDGE 
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <set>
#include <assert.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define input(x) scanf("%d",&x)
#define inputd(x) scanf("%lld",&x)
#define inputs(x) scanf("%s",x)
#define input2(x,y) scanf("%d%d",&x,&y)
#define output(x) printf("%d\n",x)
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

#define MAXN 100005

int n, k;
int num[MAXN];
int ang[MAXN];
int main()
{
	while (input2(n, k) == 2) {
		mst(num, -1);
		mst(ang, 0);

		int len = 1, tmp;
		rep(i, 0, n) {
			input(tmp);
			if (tmp != num[len - 1])
				num[len++] = tmp;
		}
		rep(i, 1, len) {
			if (num[i - 1] != num[i + 1])
				ang[num[i]]--;
			else
				ang[num[i]] -= 2;
		}
		int minn = INF, ans;
		rep(i,1,k + 1)
			if (minn > ang[i]) {
				minn = ang[i];
				ans = i;
			}
		output(ans);
	}
		
}


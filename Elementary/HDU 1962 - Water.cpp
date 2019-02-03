/************************************************
Problem: 		HDU 1962 Everything Has Changed
Algorithm: 		Water
Difficulty:		
Significance:	
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
#define eps 1e-8
#define pai 3.141592653589793238462643383279

int T;
int m, R;
int x, y, r;
int main()
{
	input(T);
	while (T--) {
		input2(m, R);
		double C = 2 * pai * R;
		rep(i, 0, m) {
			scanf("%d%d%d", &x, &y, &r);
			double dis = sqrt(x * x + y * y);
			if (dis + r < R || dis - r > R)
				continue;
			double sita = acos((R * R + dis * dis - r * r) / (2.0 * R * dis));
			double sita2 = acos((r * r + dis * dis - R * R) / (2.0 * r * dis));
			C += (sita2 * r - sita * R) * 2;
		}
		printf("%lf\n", C);
	}
}
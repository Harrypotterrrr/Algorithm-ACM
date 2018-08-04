/************************************************
Problem: 		CF 33B String Problem
Algorithm: 		Floyd
Difficulty:		**
Significance:	*
Remark:			Convert alphabet to vertex and construct the Graph
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

#define MAXN 20005

char str[2][100005], ts[10];
int n, a, b,d;
int dis[30][30];
int main()
{
	while (scanf("%s %s", str[0], str[1]) != EOF) {
		mst(dis, INF);
		rep(i, 0, 26)	dis[i][i] = 0;

		input(n);
		rep(i, 0, n) {
			inputs(ts);
			a = ts[0] - 'a';
			inputs(ts);
			b = ts[0] - 'a';
			input(d);
			if(d < dis[a][b])
				dis[a][b] = d;
		}
		int len = strlen(str[0]);
		if (len != strlen(str[1])) {
			printf("-1\n");
			continue;
		}

		rep(k, 0, 26)
			rep(i, 0, 26)
			rep(j, 0, 26)
			if (dis[i][k] + dis[k][j] < dis[i][j])
				dis[i][j] = dis[i][k] + dis[k][j];
		int ans = 0,flag = 1;
		string anss;
		rep(i, 0, len) {
			if (str[0][i] == str[1][i]) {
				anss += str[0][i];
				continue;
			}
			int n1 = str[0][i] - 'a', n2 = str[1][i] - 'a';
			int minn = INF, k = -1;
			rep(j,0,26) 
				if (minn > dis[n1][j] + dis[n2][j]) {
					minn = dis[n1][j] + dis[n2][j];	
					k = j;
				}
			if (k == -1) {
				printf("-1\n");
				flag = 0;
				break;
			}
			ans += minn;
			anss += (k + 'a');
		}
		if (flag) {
			output(ans);
			cout << anss << endl;
		}
	}
}


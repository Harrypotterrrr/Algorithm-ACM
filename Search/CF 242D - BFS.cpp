/************************************************
Problem: 		CF 242D Dispute
Algorithm: 		BFS
Difficulty:		*
Significance:	
Remark:			strategic bfs search
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
#include <queue>
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

int n, m, a,b;
vector<int> V[MAXN],ans;
queue<int>Q;
int ctr[MAXN];
int num[MAXN];

void bfs()
{
	while (!Q.empty()) {
		int tmp = Q.front();
		Q.pop();

		ans.push_back(tmp);
		ctr[tmp]++;
		for (int i = 0; i < V[tmp].size(); i++) {
			int tar = V[tmp][i];
			ctr[tar] ++;
			if (ctr[tar] == num[tar]) {
				Q.push(tar);
			}
		}
	}
}
void init()
{
	mst(ctr, 0);
	rep(i, 0, n)
		V[i].clear();
	ans.clear();
	while (!Q.empty())
		Q.pop();
}
int main()
{
	while (input2(n, m) == 2) {
		init();

		rep(i, 0, m) {
			input2(a, b);
			V[a].push_back(b);
			V[b].push_back(a);
		}
		rep(i, 1, n + 1) {
			input(num[i]);
			if (num[i] == 0)
				Q.push(i);
		}
		if (Q.empty()) {
			printf("0\n");
			continue;
		}
		bfs();
		output(int(ans.size()));
		rep(i, 0, ans.size())
			printf("%d ", ans[i]);
		puts("");
		// the answer will never be -1 !
	}
	return 0;
}

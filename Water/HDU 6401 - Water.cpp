/************************************************
Problem: 		HDU 6401 Magic Square
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

#define MAXN 100005

char sq[5][5];
int T, n;
char str[10];

void Rotate(int x, int y, bool tag)
{
	if (tag) {
		int tmp = sq[x][y];
		sq[x][y] = sq[x + 1][y];
		sq[x + 1][y] = sq[x + 1][y + 1];
		sq[x + 1][y + 1] = sq[x][y + 1];
		sq[x][y + 1] = tmp;
	}
	else {
		int tmp = sq[x][y];
		sq[x][y] = sq[x][y+1];
		sq[x][y + 1] = sq[x + 1][y + 1];
		sq[x + 1][y + 1] = sq[x + 1][y];
		sq[x + 1][y] = tmp;
	}
}

int main()
{
	input(T);
	while (T--) {
		mst(sq, 0);
		input(n);
		rep(i, 1, 4) inputs(sq[i] + 1);
		rep(_, 0, n) {
			inputs(str);
			int num = str[0] - '0';
			bool tag = str[1] == 'C';
			int _x, _y;
			if (num == 1) { _x = 1, _y = 1; }
			else if (num == 2) { _x = 1, _y = 2; }
			else if (num == 3) { _x = 2, _y = 1; }
			else { _x = 2, _y = 2; }
			Rotate(_x, _y, tag);
		}
		rep(i, 1, 4) { rep(j, 1, 4) putchar(sq[i][j]); puts(""); };
	}
	return 0;
}

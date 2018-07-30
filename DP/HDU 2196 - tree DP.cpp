/************************************************
Problem: 		HDU 2196 Computer
Algorithm: 		tree - DP
Difficulty:		****
Significance:	*****
Remark:			tree Dp classical problem
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define input(x) scanf("%d",&x)
#define input2(x,y) scanf("%d%d",&x,&y)
#define output(x) printf("%d\n",x)
#define mst(x,y) memset(x,y,sizeof(x))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
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

struct Edge {
	int next, v;
	int w;
	Edge() {};
	Edge(int a, int b, int c) {
		next = a, v = b, w = c;
	}
};
vector<Edge>V;
int n, ctr;
int dp[10005][3];
int head[10005];

void addEdge(int u,int v,int w)
{
	V.push_back(Edge(head[u], v, w));
	head[u] = ctr++;
}
void dfs_down(int u)
{
	for (int i = head[u]; i != -1; i = V[i].next) {
		int v = V[i].v;
		dfs_down(v);
		int tmp_w = dp[v][0] + V[i].w;
		if (dp[u][0] < tmp_w) {
			dp[u][1] = dp[u][0];
			dp[u][0] = tmp_w;
		}
		else if (dp[u][1] < tmp_w)
			dp[u][1] = tmp_w;
	}
}

void dfs_up(int u)
{
	for (int i = head[u]; i != -1; i = V[i].next) {
		int v = V[i].v;
		dp[v][2] = max(dp[u][2], dp[v][0] + V[i].w == dp[u][0] ? dp[u][1] : dp[u][0]) + V[i].w;
		dfs_up(v);
	}
}

int main() {
	
	while (input(n) != EOF) {
		V.clear();
		mst(head, -1);
		mst(dp, 0);
		ctr = 0;

		int v, w;
		rep(i, 1, n) {
			input2(v,w);
			addEdge(v,i+1, w);
		}
		dfs_down(1);
		dfs_up(1);
		rep(i, 1, n + 1)
			output(max(dp[i][0], dp[i][2]));
	}
	return 0;
}
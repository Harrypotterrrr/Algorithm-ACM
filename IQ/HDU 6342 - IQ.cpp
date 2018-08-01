/************************************************
Problem:		HDU 6342 Expression in Memories
Algorithm:		IQ
Difficulty:     **
Significance:   
Remark:         IQ with logical selection
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

bool isDigital(char c)
{
	return c >= '1' && c <= '9';
}
bool isSign(char c)
{
	return (c == '+' || c == '*');
}
int T;
int main() {
	input(T);
	bool flag;
	while (T--) {
		char str[505];
		scanf("%s", str);
		int len = strlen(str);
		flag = true;

		rep(i, 1, len)	if (str[i] == '?' && str[i - 1] == '0' && (i == 1 || isSign(str[i - 2])))	str[i] = '+';
		rep(i, 0, len)	if (str[i] == '?') str[i] = '1';
		if (isSign(str[0]) || isSign(str[len - 1]))	flag = false;
		rep(i, 1, len)	if (flag && isSign(str[i]) && isSign(str[i - 1]))	flag = false;
		rep(i, 0, len - 1)	if (flag && (i == 0 || isSign(str[i - 1])) && str[i] == '0' && !isSign(str[i + 1]))	flag = false;
		if (flag)	printf("%s\n", str);
		else	printf("IMPOSSIBLE\n");
	}
	return 0;
}

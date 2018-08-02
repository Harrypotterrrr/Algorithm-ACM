/************************************************
Problem: 		HDU 3183 A Magic Lamp
Algorithm: 		Greed
Difficulty:		*
Significance:	
Remark:			
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

string str;
int n;
int main()
{
	while (cin >> str) {
		input(n);
		for (int i = 0; i < str.size() - 1 && n; ) {
			if (str[i] > str[i + 1]) {
				str.erase(i, 1);
				n--;
				if(i)
					i--;
				continue;
			}
			i++;
		}
		while (n--)
			str.erase(str.size() - 1);
		bool flag = false;
		for (string::iterator i = str.begin(); i != str.end(); i++)
			if (flag || *i != '0') {
				putchar(*i);
				flag = true;
			}
		if (!flag)
			printf("0");
		puts("");
	}
}
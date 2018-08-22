/************************************************
Problem: 		HDU 6433 Problem H. Pow
Algorithm: 		Big Number
Difficulty:		
Significance:	*
Remark:			
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
//#include <time.h>
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
#define inputl(x) scanf("%I64d",&x)
#define inputd(x) scanf("%lf",&x)
#define inputs(x) scanf("%s",x)
#define input2(x,y) scanf("%d%d",&x,&y)
#define input3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define output(x) printf("%d\n",x)
#define outputl(x) printf("%I64d\n",x)
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
//ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

#define MAXN 1002
#define MOD 9901

#define maxn 1000
#define MAXSIZE 10
#define DLEN 4

struct bigNum {
	int len, s[maxn];
	bigNum() {
		memset(s, 0, sizeof(s));
		len = 1;
	}
	bigNum(const char num[]) { *this = num; }
	bigNum(const int num) { *this = num; }
	bigNum operator = (const char num[]) {
		int l = 0, r = int(strlen(num)) - 1;
		while (num[l] == '0')l++;
		len = 0;
		for (int i = r; i >= l; i--)s[len++] = num[i] - '0';
		return *this;
	}
	bigNum operator = (int num) {
		len = 0;
		if (num == 0) { len = 1; s[0] = 0; }
		while (num) {
			s[len++] = num % 10;
			num /= 10;
		}
		return *this;
	}
	bigNum operator + (const bigNum& b) const {
		bigNum c;
		c.len = 0;
		for (int i = 0, w = 0; w || i<max(len, b.len); i++) {
			int x = w + s[i] + b.s[i];
			c.s[c.len++] = x % 10;
			w = x / 10;
		}
		return c;
	}
	bool operator < (const bigNum& b) {
		if (len != b.len)return len<b.len;
		for (int i = len - 1; i >= 0; i--)
			if (s[i] != b.s[i])return s[i]<b.s[i];
		return false;
	}
	bool operator >= (const bigNum& b) {
		return !(*this<b);
	}
	void clean() {
		while (len>1 && s[len - 1] == 0)len--;
	}
	bigNum operator - (const bigNum& b) const {
		bigNum c;
		c.len = 0;
		for (int i = 0, w = 0; i<len; i++) {
			int x = s[i] - w - b.s[i];
			if (x >= 0)w = 0;
			else {
				w = 1; x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}
	bigNum operator * (const bigNum& b) const {
		bigNum c;
		c.len = len + b.len;
		for (int i = 0; i<len; i++)
			for (int j = 0; j<b.len; j++)
				c.s[i + j] += s[i] * b.s[j];
		for (int i = 0; i<c.len; i++) {
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}
	bigNum operator / (const bigNum& b) const {
		bigNum c, f = 0;
		for (int i = len - 1; i >= 0; i--) {
			f = f * 10;
			f.s[0] = s[i];
			while (f >= b) {
				f = f - b;
				c.s[i]++;
			}
		}
		c.len = len;
		c.clean();
		return c;
	}
	bigNum operator % (const bigNum& b) const {
		bigNum c = *this / b;
		c = *this - c * b;
		return c;
	}
};

istream& operator >> (istream& in, bigNum& x) {
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream& out, const bigNum& x) {
	for (int i = x.len - 1; i >= 0; i--)out << x.s[i];

	return out;
}
int T, n;
bigNum bg[MAXN];
int main()
{
	input(T);
	bg[0] = 1; bg[1] = 2;
	rep(i, 2, 1001) bg[i] = bg[i - 1] * 2;
	rep(i, 0, T) { input(n); cout << bg[n] << endl; }
}
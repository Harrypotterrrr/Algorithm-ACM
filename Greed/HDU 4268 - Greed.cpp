/************************************************
Problem: 		HDU 4268 Alice and Bob
Algorithm: 		Greed
Difficulty:		**
Significance:	***
Remark:			Very important Greed strategy for two dimension
				selection, and very easy to be trapped!
				Use multiset to optimize the algorithm
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

struct Card {
	int a, b;
	Card() {};
	Card(int a, int b) {
		this->a = a;
		this->b = b;
	}
};
bool cmp(const Card c1, const Card c2)
{
	if (c1.a == c2.a)
		return c1.b < c2.b;
	return c1.a < c2.a;
}
int T, n;
vector<Card>Bob, Alice;
multiset<int>mS;
multiset<int>s;

int main()
{
	input(T);
	while (T--) {
		Bob.clear();
		Alice.clear();
		mS.clear();

		int a, b;
		input(n);
		rep(i, 0, n) {
			input2(a, b);
			Alice.push_back(Card(a, b));
		}
		rep(i, 0, n) {
			input2(a, b);
			Bob.push_back(Card(a, b));
		}
		sort(Alice.begin(), Alice.end(), cmp);
		sort(Bob.begin(), Bob.end(), cmp);
		vector<Card>::iterator j = Bob.begin();
		int ans = 0;
		for (vector<Card>::iterator i = Alice.begin(); i != Alice.end(); i++) {
			while (j != Bob.end() && j->a <= i->a) {
				mS.insert(j->b);
				j++;
			}
			if (!mS.empty()) {
				multiset<int>::iterator k = mS.upper_bound(i->b);
				if (k != mS.begin()) {
					k--;
					ans++;
					mS.erase(k);
				}
			}
		}
		output(ans);
	}
}
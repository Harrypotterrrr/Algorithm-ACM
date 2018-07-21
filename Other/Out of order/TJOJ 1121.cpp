#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <string>  
#include <cstring>  
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000;

struct bigInt {
	int d[maxn], len;

	void clean() { while (len > 1 && !d[len - 1]) len--; }

	bigInt() { memset(d, 0, sizeof(d)); len = 1; }
	bigInt(int num) { *this = num; }
	bigInt(char* num) { *this = num; }
	bigInt operator = (const char* num) {
		memset(d, 0, sizeof(d)); len = strlen(num);
		for (int i = 0; i < len; i++) d[i] = num[len - 1 - i] - '0';
		clean();
		return *this;
	}
	bigInt operator = (int num) {
		char s[20]; sprintf(s, "%d", num);
		*this = s;
		return *this;
	}

	bigInt operator + (const bigInt& b) {
		bigInt c = *this; int i;
		for (i = 0; i < b.len; i++) {
			c.d[i] += b.d[i];
			if (c.d[i] > 9) c.d[i] %= 10, c.d[i + 1]++;
		}
		while (c.d[i] > 9) c.d[i++] %= 10, c.d[i]++;
		c.len = max(len, b.len);
		if (c.d[i] && c.len <= i) c.len = i + 1;
		return c;
	}
	bigInt operator - (const bigInt& b) {
		bigInt c = *this; int i;
		for (i = 0; i < b.len; i++) {
			c.d[i] -= b.d[i];
			if (c.d[i] < 0) c.d[i] += 10, c.d[i + 1]--;
		}
		while (c.d[i] < 0) c.d[i++] += 10, c.d[i]--;
		c.clean();
		return c;
	}
	bigInt operator * (const bigInt& b)const {
		int i, j; bigInt c; c.len = len + b.len;
		for (j = 0; j < b.len; j++) for (i = 0; i < len; i++)
			c.d[i + j] += d[i] * b.d[j];
		for (i = 0; i < c.len - 1; i++)
			c.d[i + 1] += c.d[i] / 10, c.d[i] %= 10;
		c.clean();
		return c;
	}
	bigInt operator / (const bigInt& b) {
		int i, j;
		bigInt c = *this, a = 0;
		for (i = len - 1; i >= 0; i--)
		{
			a = a * 10 + d[i];
			for (j = 0; j < 10; j++) if (a < b*(j + 1)) break;
			c.d[i] = j;
			a = a - b * j;
		}
		c.clean();
		return c;
	}
	bigInt operator % (const bigInt& b) {
		int i, j;
		bigInt a = 0;
		for (i = len - 1; i >= 0; i--)
		{
			a = a * 10 + d[i];
			for (j = 0; j < 10; j++) if (a < b*(j + 1)) break;
			a = a - b * j;
		}
		return a;
	}
	bigInt operator += (const bigInt& b) {
		*this = *this + b;
		return *this;
	}

	bool operator <(const bigInt& b) const {
		if (len != b.len) return len < b.len;
		for (int i = len - 1; i >= 0; i--)
			if (d[i] != b.d[i]) return d[i] < b.d[i];
		return false;
	}
	bool operator >(const bigInt& b) const { return b < *this; }
	bool operator<=(const bigInt& b) const { return !(b < *this); }
	bool operator>=(const bigInt& b) const { return !(*this < b); }
	bool operator!=(const bigInt& b) const { return b < *this || *this < b; }
	bool operator==(const bigInt& b) const { return !(b < *this) && !(b > *this); }

	string str() const {
		char s[maxn] = {};
		for (int i = 0; i < len; i++) s[len - 1 - i] = d[i] + '0';
		return s;
	}
};

istream& operator >> (istream& in, bigInt& x)
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream& out, const bigInt& x)
{
	out << x.str();
	return out;
}

int main()
{
	int T;
	bigInt n;
	scanf("%d", &T);
	for (int u = 1; u <= T; u++) {
		cin >> n;
		printf("Case #%d:\n", u);
		bigInt tmp = 1;
		while (tmp <= n)
			tmp = tmp * 2;
		tmp = tmp / 2;
		n = n - tmp;
		n = n * 2;
		n = n + 1;
		cout << n << endl;
	}
	return 0;
}
/************************************************
Problem: 		ZOJ 1004 Anagrams by Stack
Algorithm: 		dfs-Search
Difficulty: 	+
Significance:	+
Remark:
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string str[2];

void dfs(string s, string ans, int p, int q)
{
	if (p == str[0].length() - 1 && q == str[1].length())
		cout << ans << endl;
	if (p < int(str[0].length()))
		dfs(s + str[0][p + 1], ans + "i ", p + 1, q);
	if (s.length() > 0 && s[s.length() - 1] == str[1][q]) {
		if (s[s.length() - 1] != str[1][q])
			return;
		dfs(s.erase(s.length() - 1), ans + "o ", p, q + 1);
	}
}

int main()
{
	while (cin >> str[0] >> str[1]) {
		cout << "[\n";
		if (str[0].length() == str[1].length()) {
			string s;
			s += str[0][0];
			dfs(s, "i ", 0, 0);
		}
		cout << "]\n";
	}
}
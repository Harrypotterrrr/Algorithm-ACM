/************************************************
Problem: 		POJ 1256 Anagram
Algorithm: 		dfs-Search
Difficulty: 	++
Significance:	++
Remark:			important solution!
*************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>

using namespace std;

int Max_len, kind_ctr;
string ori_str, str;
int alp_ctr[100];

bool cmp(char a, char b)
{
	int A = a, B = b;
	if (a >= 'a')
		A -= 32;
	if (b >= 'a')
		B -= 32;
	if (A != B)
		return A < B;
	return a < b;
}
void dfs(string s, int n)
{
	if (n == Max_len) {
		cout << s << endl;
		return;
	}
	for (int i = 0; i < kind_ctr; i++) {
		if (alp_ctr[str[i] - 'A'] != 0) {
			alp_ctr[str[i] - 'A']--;
			dfs(s + str[i], n + 1);
			alp_ctr[str[i] - 'A']++;
		}
	}
}
void init()
{
	memset(alp_ctr, 0, sizeof(alp_ctr));
	ori_str.clear();
	str = "";
	cin >> ori_str;
	kind_ctr = 0;
	Max_len = ori_str.length();
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		init();

		for (int i = 0; i < int(ori_str.length()); i++)
			alp_ctr[ori_str[i] - 'A']++;

		for (int i = 0; i < 100; i++)
			if (alp_ctr[i] != 0) {
				kind_ctr++;
				str += char('A' + i);
			}

		sort(str.begin(), str.end(), cmp);
		dfs(string(""), 0);
	}
	return 0;
}

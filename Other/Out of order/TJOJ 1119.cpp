#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>

using namespace std;

const string Alp[30] = { 
"aa",
"abab",
"aabab",
"abbbb",
"aaabab",
"abaabb",
"aaab",
"abaab",
"aabbb",
"abbaab",
"aaaabb",
"abb",
"aaaab",
"ababb",
"aabaab",
"abbbab",
"aab",
"abbb",
"aaabb",
"abaaab",
"aabbab",
"ab",
"aabb","abbab","aaaaab","ababab" };
int main()
{
	int T;
	map<string, char>M;
	for (int i = 0; i < 26; i++) {
		M[Alp[i]] = char('A' + i);
	}

	scanf("%d", &T);
	char str[50000];
	for (int u = 1; u <= T; u++) {
		string s = "";
		bool flag = false;
		printf("Case #%d:\n", u);
		while(scanf("%s",str)){
			if (str[strlen(str) - 1] == '!') {
				str[strlen(str) - 1] = '\0';
				flag = true;
			}
			if (!strcmp(str, "pika"))
				s += "a";
			else
				s += "b";
			if (flag) {
				putchar(M[s]);
				flag = false;
				s = "";
			}
			char c = getchar();
			if (c == '\n')
				break;
			//if (cin.peek() == '\n')
			//	break;
		}
		putchar('\n');
	}

	return 0;
}

/************************************************
Problem: 		POJ 1265 Anagram
Algorithm: 		STL ¡ª¡ª next_permutation
Difficulty: 	+
Significance:	+++
Remark:			
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
#include <functional>
#include <map>
#include <set>

using namespace std;

bool cmp(char a, char b) {
	if (toupper(a) == toupper(b))
		return a < b;
	return toupper(a) < toupper(b);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		char str[15];
		scanf("%s", str);
		int len = strlen(str);
		sort(str, str + len, cmp);
		do {
			printf("%s\n", str);
		} while (next_permutation(str, str + len, cmp));
	}
	return 0;
}
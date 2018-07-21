#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int n,l,r;
int num[200005];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int u = 1; u <= T; u++) {
		scanf("%d%d%d", &n,&l,&r);

		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		sort(num,num+n,cmp);
		int  sum = 0;
		for (int j = l-1; j < r; j++) {
			sum = (sum % 1000000007 + num[j] % 1000000007) % 1000000007;
		}
		printf("Case #%d:\n", u);
		printf("%d\n", sum);
	}
	return 0;
}

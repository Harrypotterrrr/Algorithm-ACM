#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1000
char str1[MAX], str2[MAX];
int num[MAX+1][MAX+1] = { 0 };
int len1, len2;
void Solve()
{
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i-1] == str2[j-1])
				num[i][j] = num[i - 1][j - 1] + 1;
			else if (str1[i-1] != str2[j-1])
				num[i][j] = num[i][j - 1] >= num[i - 1][j] ? num[i][j - 1] : num[i - 1][j];
		}
	}
}

int main()
{
	while (cin >> str1 >> str2) {
	//while (scanf("%s%s",str1,str2) != EOF) {
		len1 = strlen(str1);
		len2 = strlen(str2);
		Solve();
		//printf("%d\n", num[len1][len2]);
		cout << num[len1][len2]<<endl;
	}
	return 0;
}
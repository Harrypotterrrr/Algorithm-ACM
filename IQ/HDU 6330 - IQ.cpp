/************************************************
Problem: 		HDU 6330 Visual Cube
Algorithm: 		IQ
Difficulty:		**
Significance:	
Remark:			loop
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits\stdc++.h>
#define INF 0x3f3f3f3f
#define eps 1e-8
typedef __int64 ll;
int T, n;
int num[105];
int dp[105][105];
int sum[105];
using namespace std;
int main()
{
	scanf("%d", &T);
	int a, b, c;
	for (int _ = 1; _ <= T; _++) {
		scanf("%d%d%d", &a, &b, &c);
		for (int i = 0, j = 0; i < 2 * (b + c) + 1; i++, j = 0) {
			for (int k = 0; k < 2 * b - i; k++, j++)
				putchar('.');
			///////////////////////////////////
			if (i % 2 == 0) {
				for (int k = 0; k < a; k++, j += 2)
					printf("+-");
				printf("+");
				j++;
			}
			else {
				for (int k = 0; k < a; k++, j += 2) {
					if (i > 2 * b)
						printf("|.");
					else
						printf("/.");
				}
				if (i < 2 * b)
					printf("/");
				else
					printf("|");
				j++;
			}
			///////////////////////////////////
			if (i % 2 == 0) {
				if (i < 2 * b) {
					for(int k=0 ; k<i/2 && k < c;k++,j+=2)
						printf(".+");
				}
				else if (i > 2 * c) {
					for (int k = 0; k < (2 * (c + b) - i) / 2 && k < c; k++, j += 2)
						printf(".+");
				}
				else {
					for (int k = 0; k < b&& k < c; k++, j += 2)
						printf(".+");
				}
			}
			else {
				if (i < 2 * b) {
					for (int k = 0; k<i/2 && k < c; k++, j += 2)
						printf("|/");
					if (i <= 2 * c) {
						printf("|");
						j++;
					}
				}
				else if (i > 2 * c) {
					for (int k = 0; k < (2*(c+b)-i)/2 && k < c; k++, j += 2)
						printf("/|");
					printf("/");
					j++;
				}
				else {
					int k;
					for (k = 0; k < b&& k < c; k++, j += 2)
						printf("/|");
				}
			}
			///////////////////////////////////
			for (; j < 2 * (a + b) + 1; j++)
				putchar('.');
			printf("\n");
		}
	}
	return 0;
}
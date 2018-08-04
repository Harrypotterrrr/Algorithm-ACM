/************************************************
Problem: 		ZOJ 1008 Gnome Tetravex
Algorithm: 		Strategic search
Difficulty: 	+++
Significance:	++
Remark:
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
	int square[4];
	int ctr;
	Node() { ctr = 0; };
}node[25];

int n, Max, kind_ctr;
int arr[25];
bool flag;

bool dfs(int k)
{
	if (k == Max)
		return true;

	int x = k % n;
	int y = k / n;
	for (int i = 0; i < kind_ctr; i++) {
		if (!node[i].ctr)
			continue;

		if (x == 0 || node[i].square[3] == node[arr[k - 1]].square[1])
			if (y == 0 || node[i].square[0] == node[arr[k - n]].square[2]) {
				arr[k] = i;
				node[i].ctr--;
				if (dfs(k + 1))
					return true;
				node[i].ctr++;
			}
	}
	return false;
}

int main()
{
	int k = 1;
	while (scanf("%d", &n) && n) {
		Max = n * n;
		kind_ctr = 0;
		memset(arr, -1, sizeof(arr));
		memset(node, 0, sizeof(node));
		flag = false;

		for (int i = 0, j; i < Max; i++) {
			int tmp[4];
			for (j = 0; j < 4; j++)
				scanf("%d", &tmp[j]);

			for (j = 0; j < kind_ctr; j++)
				if (!memcmp(node[j].square, tmp, 16))
					break;
			if (j == kind_ctr) {
				memcpy(node[kind_ctr].square, tmp, 16);
				kind_ctr++;
			}
			node[j].ctr++;
		}

		flag = dfs(0);

		if (k != 1)
			printf("\n");

		printf("Game %d: ", k++);
		if (flag)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	return 0;
}
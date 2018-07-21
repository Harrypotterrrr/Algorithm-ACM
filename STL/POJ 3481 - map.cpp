/************************************************
Problem: 		POJ 3481 Double Queue
Algorithm: 		STL —— map
Difficulty: 	+
Significance:	+++
Remark:			map is a container with weak descending sorted!
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

using namespace std;

int main()
{
	int code;
	map<int, int>M;
	while (true) {
		scanf("%d", &code);
		if (code == 0)
			break;
		if (code == 1) {
			int k, p;
			scanf("%d%d", &k, &p);
			M.insert(pair<int,int>(p,k));
			//M[p] = k;
		}
		else if (code == 2) {
			if (M.size() == 0)
				printf("0\n");
			else {
				printf("%d\n", M.rbegin()->second);	
				M.erase(M.find(M.rbegin()->first));
			}
		}
		else if (code == 3) {
			if (M.size() == 0)
				printf("0\n");
			else {
				printf("%d\n", M.begin()->second);
				M.erase(M.find(M.begin()->first));
			}
		}
	}
	return 0;
}
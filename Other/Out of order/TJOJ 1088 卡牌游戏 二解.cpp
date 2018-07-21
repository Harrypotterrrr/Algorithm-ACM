#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <memory.h>
using namespace std;
int main()
{
	int q[2010], step[2010];
	int counter = 0, a = 0, b = 0, n, temp,i,input_nbr;
	memset(step, 0, sizeof(step));
	memset(q, 0, sizeof(q));
	scanf("%d", &n);
	while (n--){
		scanf("%d", &temp);
		if (step[temp + 1000] == 0){
			step[temp + 1000] = 1;
			q[counter++] = temp;
		}
	}
	input_nbr = counter;
	if (step[1000] == 1){
		printf("1\n");
		return 0;
	}
	while(q[a] != 0){
		for (i = 0;i < input_nbr;i++){
			temp = q[a] + q[i];
			if (temp <= 1000 && temp >= -1000){
				if (step[temp + 1000] == 0){
					q[counter++] = temp;
					step[temp + 1000] = step[q[a] + 1000] + 1;
				}
				if (temp == 0){
					printf("%d\n", step[q[a]+1000] + 1);
					return 0;
				}
			}
		}
		a ++;
	}
	printf("-1\n");
	return 0;
}

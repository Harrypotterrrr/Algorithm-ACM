#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
double S = 0;
int num = 1;
int n[16];
int calc(){
	for(int i=1 ; num <= 15 ; i++){
		double temp = 1.0 / i;
		S += temp;
		if(S > num){
			n[num] = i;
			num ++;		
		}
	}
}
int main()
{
	calc();
	int a;
	while(scanf("%d",&a) != EOF)
		printf("%d\n",n[a]);
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#define eps 1e-8
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int num;
		double sum = 0;
		scanf("%d",&num);
		for(int i=1 ; i<=num ; i++)
			sum += log10(i);
		printf("%d\n",int(sum) + 1);
	}
	return 0;
}

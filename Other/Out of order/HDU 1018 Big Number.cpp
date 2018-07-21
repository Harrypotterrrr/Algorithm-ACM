#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#define eps 1e-8
using namespace std;
double mult;
int k;
void calc(){
	while(mult >= 10){
		mult /= (1.0 * 10);
		k ++; 
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int num;
		mult = 1;
		k = 1;
		scanf("%d",&num);
		for(int i=1 ; i<=num ; i++){
			mult *= (1.0 * i);
			if(mult >= 10)
				calc();
		}
		printf("%d\n",k);
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
	int T;
	scanf("%d",&T); 
	while(T--){
		int n;
		double t;
		scanf("%d",&n);
		t = n * log10(n);
		t = t - floor(t);
		t = pow(10,t);
		printf("%d\n",int(t));
	}
	return 0;
}

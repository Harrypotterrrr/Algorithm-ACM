#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int f(int x, int y){
	return y == 0 ? x : f(y,x%y);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int t,n[10000];
		scanf("%d",&t);
		for(int i=0 ; i<t ; i++)
			scanf("%d",&n[i]);
		for(int i=1 ; i<=t-1 ; i++)
			n[i] = n[i] / f(n[i],n[i-1]) * n[i-1] ;
		printf("%d\n",n[t-1]);
	}
	return 0;
}

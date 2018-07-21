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
		int t,a,b;
		scanf("%d",&t);
		scanf("%d%d",&a,&b);
		t -= 2;
		while(t--){
			a = a * b / f(a,b);
			scanf("%d",&b);
		}
		printf("%d\n",a * b / f(a,b));
	}
	return 0;
}

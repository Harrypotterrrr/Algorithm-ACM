#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath> 
#include <algorithm>
using namespace std;
int dp(int x,int y){
	if(x == 1 || y == 1)	return 1;
	if(x == y)	return dp(x,y-1) + 1;
	if(x < y)	return dp(x,x);
	return dp(x-y,y) + dp(x,y-1);
}
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		printf("%d\n",dp(n,n));
	}
	return 0;
}

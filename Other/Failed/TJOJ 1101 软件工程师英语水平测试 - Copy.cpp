//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int solve(int a,int b){
	return !(a % b) ? b : solve(b,a % b);
}
int main()
{
	int n,x;
	cin>>n>>x;
	for(int i=2; i<=x ;i++){
		if(n % i == 0)
			printf("1\n");
		else{
			int t = solve(n,i);	
			int ans = i / t;
			printf("%d\n",ans);	
		}
	}
	return 0;  
}

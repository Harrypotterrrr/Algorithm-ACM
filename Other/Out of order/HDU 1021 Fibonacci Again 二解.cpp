#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int solve(int a,int b,int k){
	if(n == k)
		return (a%3 + b%3) % 3;
	else
		return solve(b%3,(a%3+b%3)%3,k+1);
}
int main(){
	while(scanf("%d",&n) != EOF){
		if(n == 1 || n == 0)
			printf("no\n");
		else{
			int temp = solve(7%3,11%3,2);
			if(temp % 3 == 0)
				printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath> 
#include <algorithm>
using namespace std;
int solve(int n){
	int sum1[122],sum2[122];
	for(int i=0 ; i<=n ; i++){
		sum1[i] = 1;
		sum2[i] = 0;
	}
	for(int k=2 ; k<=n ; k++){
		for(int i=0 ; i<=n ; i++)
			for(int j=0 ; j+i<=n ; j+=k)
				sum2[i+j] += sum1[i];
		for(int i=0 ; i<=n ; i++){
			sum1[i] = sum2[i];
			sum2[i] = 0;
		}
	}
	return sum1[n];
}
int main(){
	int n;
	while(scanf("%d",&n) != EOF)
		printf("%d\n",solve(n));
	return 0;
}

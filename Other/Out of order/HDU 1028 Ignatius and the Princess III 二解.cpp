#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath> 
#include <algorithm>
using namespace std;
int k[122][122];
void dp(int n){
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=i ; j++){
			if(i == 1 || j == 1)
				k[i][j] = 1;
			else if(i == j)
				k[i][j] = k[i][j-1] + 1;
			else
				k[i][j] = k[i][j-1] + k[i-j][j];
		}
		for(int j=i+1 ; j<=n ; j++)
			k[i][j] = k[i][i];
	}
}
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		dp(n);
		printf("%d\n",k[n][n]);
	}
	return 0;
}

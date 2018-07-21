#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int main(){
	while(scanf("%d",&n),n){
		int num1[305],num2[305];
		for(int i=0 ; i<=n ; i++){
			num1[i] = 1;
			num2[i] = 0;
		}
		for(int i=2 ; i*i<=n ; i++){
			for(int j=0 ; j<=n ; j++)
				for(int k=0 ; k+j<=n ; k+=i*i)
					num2[k+j] += num1[j];
			for(int j=0 ; j<=n ; j++){
				num1[j] = num2[j];
				num2[j] = 0;
			}
		}
		printf("%d\n",num1[n]);
	}
}

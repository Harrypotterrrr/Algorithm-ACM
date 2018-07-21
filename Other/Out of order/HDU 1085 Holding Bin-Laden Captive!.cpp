#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int num[6]={0,0,0,0,0,0},Max;
	int num1[8005],num2[8005];
	while(scanf("%d%d%d",&num[1],&num[2],&num[5]),num[1]||num[2]||num[5]){
		int M = num[1] + num[2] * 2 + num[5] * 5;
		memset(num1,0,sizeof num1);
		for(int i=0 ; i<=M ; i++){
			num1[i] = 1;
			num2[i] = 0;
		}
		Max  = 0;
		for(int k=1 ; k<=5 ; k++){
			if(num[k]){
				for(int i=0 ; i<=Max ; i++)
					for(int j=0 ; j<=num[k]*k ; j+=k)
						num2[i+j] += num1[i];
				Max += num[k]*k;
				for(int i=0 ; i<=Max ; i++){
					num1[i] = num2[i];
					num2[i] = 0;
				}
			}
		}
		for(int i=1 ; ; i++)
			if(!num1[i]){
				printf("%d\n",i);
				break;
			}
	}
    return 0;  
}

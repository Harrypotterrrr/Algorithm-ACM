#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char A[100],B[100];
	int a[100],b[100],result[200];
	int T,len_a,len_b,len_res,carry_mult,carry_plus;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(result,0,sizeof(result));
		scanf("%s%s",&A,&B);
		len_a = strlen(A);
		len_b = strlen(B);
		for(int i=0 ; i<len_a ; i++)
			a[len_a-i-1] = A[i] - '0';
		for(int i=0; i<len_b ; i++)
			b[len_b-i-1] = B[i] - '0';
		for(int i=0 ; i<len_a ; i++){
			carry_plus = carry_mult = 0;
			for(int j=0 ; j<len_b ; j++){
				int mult = a[i] * b[j] + carry_mult;
				carry_mult = mult / 10;
				mult %= 10;
				result[i+j] += mult + carry_plus;
				carry_plus = result[i+j] / 10;
				result[i+j] %= 10;
			}
			result[len_b+i] += carry_mult + carry_plus;
		}
		if(result[len_a+len_b-1] == 0)
			len_res = len_a + len_b - 1;
		else
			len_res = len_a +len_b;
		for(int i=len_res-1 ; i>=0 ; i--)
			printf("%d",result[i]);
		printf("\n");
	}
	return 0;
} 

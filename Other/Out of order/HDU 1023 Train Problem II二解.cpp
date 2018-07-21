#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int catelan[101][1000];
int cat_len[101]={1,1};
void calc(){
	memset(catelan,0,sizeof catelan);
	catelan[1][0] = 1;
	int len = 1;
	for(int i=2 ; i<=100 ; i++){
		int carry = 0;
		for(int j=0 ; j<len ; j++)
			catelan[i][j] = (4 * i - 2) * catelan[i-1][j];
		for(int j=0 ; j<len ; j++){
			catelan[i][j] += carry;
			carry = catelan[i][j] / 10;
			catelan[i][j] = catelan[i][j] % 10;
		}
		while(carry){
			catelan[i][len++] = carry % 10;
			carry /= 10;
		}
		for(int j=len-1 ; j>=0 ; j--){
			catelan[i][j] += carry * 10;
			carry = catelan[i][j] % (i + 1);
			catelan[i][j] /= (i + 1);
		}
		while(!catelan[i][len-1])	
			len --;
		cat_len[i] = len;
//		for(int j=len-1 ; j>=0 ; j--)
//			cout<<catelan[i][j];
//		cout<<'\n';
	}
}
int main(){
	calc();
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i=cat_len[n]-1 ; i>=0 ; i--)
			printf("%d",catelan[n][i]);
		printf("\n");
	}
	return 0;
}

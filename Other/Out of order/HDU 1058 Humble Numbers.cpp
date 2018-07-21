#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n[5842] = {1};
int main(){
//	freopen("r.txt","r",stdin);
//	freopen("w.txt","w",stdout);
	void func();
	int k;
	func();
	while(scanf("%d",&k) , k != 0){
		printf("The %d",k);
		if( k % 10 == 1 && k % 100 != 11)
			printf("st humble number is ");
		else if( k % 10 == 2 && k % 100 != 12)
			printf("nd humble number is ");
		else if( k % 10 == 3 && k % 100 != 13)
			printf("rd humble number is ");
		else
			printf("th humble number is ");
		printf("%d.\n",n[k-1]);
	}
	return 0;
}

void func(){
	int Min(int,int,int,int);
	int p_2 = 0 , p_3 = 0 , p_5 = 0 , p_7 = 0;
	for(int i=1 ; i<5842 ; i++){
		n[i] = Min(n[p_2]*2 ,n[p_3]*3 ,n[p_5]*5 ,n[p_7]*7);
		if(n[i] == n[p_2]*2)
			p_2 ++;
		if(n[i] == n[p_3]*3)
			p_3 ++;
		if(n[i] == n[p_5]*5)
			p_5 ++;
		if(n[i] == n[p_7]*7)
			p_7 ++;
	}
}

int Min(int a,int b,int c,int d){
	return min(a , min(b , min(c , d)));
}

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int a,b,n[4];
	while(scanf("%d%d",&a,&b) != EOF){
		a = a % 10;
		n[0] = a;
		for(int i=1 ; i<=3 ; i++)
			n[i] = n[i-1] * a % 10;
		int T = b % 4;
		if(!T)
			printf("%d\n",n[3]);
		else
			printf("%d\n",n[T-1]);
	}
	return 0;
}

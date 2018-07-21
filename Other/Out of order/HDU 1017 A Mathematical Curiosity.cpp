#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,k=1;
		while(scanf("%d%d",&n,&m),n||m){
			int count=0;
			for(int a=1 ; a<n-1 ; a++){
				for(int b=a+1 ; b<n ; b++){
					int Sum = a * a + b * b + m;
					if( Sum % ( a * b ) == 0 )
						count ++;
				}
			}
			printf("Case %d: %d\n",k++,count);		
		}
		if(T)
			printf("\n");
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int num,last[5];
		scanf("%d",&num);
		int num_last = num % 10;
		last[1] = num_last;
		for(int i=2 ; i<=4 ; i++)
			last[i] = last[i-1] * num_last % 10;
		int period = num % 4;
		if(!period)
			printf("%d\n",last[4]);
		else
			printf("%d\n",last[period]);
	}
	return 0;
}

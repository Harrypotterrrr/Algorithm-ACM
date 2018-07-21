#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int main(){
	char N[1024];int str;
	int f(int);
	while(scanf("%s",&N)){
		str = strlen(N);
		if(str == 1 && N[0] == '0')
			break;
		int sum = 0; 
		for(int i=0 ; i<str ; i++)
			sum += N[i] - '0';
		while(sum > 9)
			sum = f(sum);
		printf("%d\n",sum);
	}
	return 0;
}

int f(int x){
	int SUM=0;
	while(x>0){
			SUM += x % 10;
			x /= 10;
		}
	return SUM;
}

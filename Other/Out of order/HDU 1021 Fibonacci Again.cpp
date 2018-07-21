#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int num;
	while(scanf("%d",&num) != EOF){
		if(num % 4 == 2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}

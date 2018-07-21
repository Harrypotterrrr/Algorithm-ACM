#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int N;
	while(scanf("%d",&N) != EOF){
		int sum = 0;
		int temp1 = N / 3;
		for(int i=temp1 ; i>=0 ; i--){
			int n = N - 3 * i;
			sum += n / 2 + 1;
		}
		printf("%d\n",sum);
	}
    return 0;
}

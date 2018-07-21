#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int T,sum,n,floor;
	while(scanf("%d",&T),T != 0){
		sum = floor = 0;
		while(T--){
			scanf("%d",&n);
			if(floor > n)
				sum +=  5 + 4 * (floor - n);
			else if(floor < n)
				sum += 5 + 6 * (n - floor);
			else 
				sum += 5;
			floor = n;
		}
		printf("%d\n",sum);
	}
}

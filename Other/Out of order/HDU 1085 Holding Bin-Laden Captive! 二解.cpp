#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int num_1,num_2,num_5;
	while(scanf("%d%d%d",&num_1,&num_2,&num_5),num_1||num_2||num_5){
		int ans = (num_1 ? ( (num_1 + num_2 * 2 < 4) ? (num_1 + num_2 * 2) : (num_1 + num_2 * 2 + num_5 * 5) ) : 0) + 1;
		printf("%d\n",ans);
	}
    return 0;  
}

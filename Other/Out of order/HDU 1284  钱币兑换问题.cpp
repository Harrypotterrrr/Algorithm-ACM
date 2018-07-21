#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int N;
	int ans[32770],temp[32770];
	memset(ans,0,sizeof ans);
	for(int i=0 ; i<=32768 ; i++){
		ans[i] = 1;
		temp[i] = 0;
	}
	for(int k=2 ; k<=3 ; k++){
		for(int i=0 ; i<=32768 ; i++)
			for(int j=0 ; j+i<=32768 ; j+=k)
				temp[i+j] += ans[i];
		for(int i=0 ; i<=32768 ; i++){
			ans[i] = temp[i];
			temp[i] = 0;
		}
	}
	while(scanf("%d",&N) != EOF){
		printf("%d\n",ans[N]);
	}
    return 0;
}

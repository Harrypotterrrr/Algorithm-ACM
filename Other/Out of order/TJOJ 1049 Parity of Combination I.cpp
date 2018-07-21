#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
int NCM[1002][1002];
int calc(){
	for(int i=0 ; i<=1000 ; i++)
		NCM[i][0] = NCM[i][i] = 1;
	for(int i=2 ; i<=1000 ; i++)
		for(int j=1 ; j<=i/2 ; j++){
			NCM[i][j] = (NCM[i-1][j] + NCM[i-1][j-1]) % 2;
			NCM[i][i-j] = NCM[i][j];
		}
}
int main()
{
	calc();
	int T,N,M;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		if(NCM[N][M] == 1)
			printf("odd\n");
		else
			printf("even\n");
	}
	return 0;
}

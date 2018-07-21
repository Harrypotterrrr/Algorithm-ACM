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
int n,m,X,Y;
long long Map[23][23];
int main()
{
	scanf("%d%d%d%d",&n,&m,&X,&Y);
	for(int i=0 ; i<=20 ; i++)
		for(int j=0 ; j<=20 ; j++)
			Map[i][j] = 1;
    Map[X][Y] = 0;
    Map[X+2][Y+1] = 0;
    Map[X+1][Y+2] = 0;
    if(X>=1)Map[X-1][Y+2] = 0;
    if(X>=2)Map[X-2][Y+1] = 0;
    if(X>=2&&Y>=1)Map[X-2][Y-1] = 0;
    if(X>=1&&Y>=2)Map[X-1][Y-2] = 0;
    if(Y>=2)Map[X+1][Y-2] = 0;
    if(Y>=1)Map[X+2][Y-1] = 0;
	for(int i=0 ; i<=n ; i++)
		for(int j=0 ; j<=m ; j++){
			if(!Map[i][j])
				continue;
			if(i == 0 && j == 0)
				continue;
			else if(i==0)
				Map[i][j] = Map[i][j-1];
            else if(j==0)
				Map[i][j] = Map[i-1][j];
			else
				Map[i][j] = Map[i-1][j] + Map[i][j-1];
		}
	printf("%lld",Map[n][m]);
	return 0;
}

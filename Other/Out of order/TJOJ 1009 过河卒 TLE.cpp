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
const int divx[8] = {-2,-1,-2,-1,1,2,1,2};
const int divy[8] = {1,2,-1,-2,2,1,-2,-1};
int n,m,X,Y,temp_x,temp_y,ans;
int Map[22][22];
void dfs(int x,int y){
	if(x == n && y == m){
		ans ++;
		return ;	
	}
	if(!Map[x+1][y] && x+1 <= n){
		Map[x+1][y] = true;
		dfs(x+1,y);
		Map[x+1][y] = false;
	}

	if(!Map[x][y+1] && y+1 <= m){
		Map[x][y+1] = true;
		dfs(x,y+1);
		Map[x][y+1] = false;
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&X,&Y);
	ans = 0;
	memset(Map,false,sizeof Map);
	Map[X][Y] = true;
	for(int i=0 ; i<8 ; i++)
		if(divx[i]+X >= 0 && divx[i]+X <= n && divy[i]+Y >=0 && divy[i]+Y <= m)
			Map[divx[i]+X][divy[i]+Y] = true;
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}

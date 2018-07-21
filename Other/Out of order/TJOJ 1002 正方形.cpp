#include <stdio.h>
#include <iostream>
#include <cstring>	
bool map[1003][1003];
int n,m,ans=1;
bool judge(int array,int column,int x,int y){
	for(int i=column ; i<y ; i++)
		if(!map[x][i])
			return false;
	for(int i=array ; i<x ; i++)
		if(!map[i][y])
			return false;
	return true;
}
void solve(){
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
			if(map[i][j])
				for(int t_i = i+1,t_j = j+1; t_i<=n && t_j<=m ; t_i++,t_j++)
					if(map[t_i][t_j] && judge(i,j,t_i,t_j))
						ans = ans > t_i - i + 1 ? ans : t_i - i + 1;
					else
						break;
}
int main()
{
	while(scanf("%d%d",&n,&m) != EOF){
		memset(map,false,sizeof map);
		ans = 1;
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=m ; j++)
				scanf("%d",&map[i][j]);
		solve();
		printf("%d\n",ans);
	}
}

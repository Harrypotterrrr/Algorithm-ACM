#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int N,M,W;
int field[505][505];
bool Floyd(){
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=N ; j++){
			for(int k=1 ; k<=N ; k++){
				if(field[j][k] > field[j][i]+field[i][k])
					field[j][k] = field[j][i]+field[i][k];
			}
			if(field[j][j] < 0)
				return true;
		}
	return false;
}
int main()
{
	int T,x,y,z;
	scanf("%d",&T);
	while(T--){
		memset(field,0x3f,sizeof field);
		scanf("%d%d%d",&N,&M,&W);
		for(int i=1 ; i<=M ; i++){
			scanf("%d%d%d",&x,&y,&z);
			if(z<field[x][y])
				field[x][y] = field[y][x] = z;
		}
		for(int i=1 ; i<=W ; i++){
			scanf("%d%d%d",&x,&y,&z);
			field[x][y] = -z;
		}
		if(Floyd())
			printf("YES\n");
		else
			printf("NO\n");
	}
	
    return 0;  
}

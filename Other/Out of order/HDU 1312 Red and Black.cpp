#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char field[22][22];
int p_x[4] = {-1,0,1,0};
int p_y[4] = {0,1,0,-1};
int W,H,num;
void reach(int x,int y){
	for(int i=0 ; i<4 ; i++){
		if(field[x+p_x[i]][y+p_y[i]] != '#' && x+p_x[i] <= H\
		&& x+p_x[i] > 0 && y+p_y[i] <= W && y+p_y[i] > 0){
			field[x+p_x[i]][y+p_y[i]] = '#';
			num ++;
			reach(x+p_x[i],y+p_y[i]);
		}
	}
}
int main(){
	while(scanf("%d%d",&W,&H),W || H){
   		memset(field,'\0',sizeof(field));
		num = 1;
		int st_x,st_y;
		    for(int i=1 ; i<=H ; i++){
   				getchar();
				for(int j=1 ; j<=W ; j++){
					scanf("%c",&field[i][j]);
   					if(field[i][j] == '@'){
   						st_x = i;
   						st_y = j;
					}
			    }
			}
		field[st_x][st_y] = '#';
		reach(st_x,st_y);
		printf("%d\n",num);
	}
	return 0;
}

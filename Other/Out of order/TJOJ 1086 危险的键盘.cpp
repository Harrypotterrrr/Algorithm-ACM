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
map< char,int > M;
int R,C;
bool flag;
char str[355][355];
int num[355][355],ans = 0;
int gox[5]={0,-1,0,1,0};
int goy[5]={0,0,1,0,-1};
bool judge(int x,int y,int m){
	int temp_x = x+gox[m],temp_y = y+goy[m];
	if(temp_x == 0 || temp_x == R+1 || temp_y == 0 || temp_y == C+1 )
		return false;
	else if(num[temp_x][temp_y] == 0){
		while(true){
			temp_x += gox[m];
			temp_y += goy[m];
			if(temp_x == 0 || temp_x == R+1 || temp_y == 0 || temp_y == C+1)
				return false;
			else if(num[temp_x][temp_y] <= 4 && num[temp_x][temp_y] >= 1)
				return true;
		}
	}
	return true;
}
void turn(int x,int y){
	for(int i=1 ; i<=4 ; i++){
		int temp_x = x+gox[i],temp_y = y+goy[i];
		if(num[temp_x][temp_y] <= 4 && num[temp_x][temp_y] >= 1){
			ans ++;
			return ;
		}
		else if(num[temp_x][temp_y] == 0)
			while(true){
				temp_x += gox[i];
				temp_y += goy[i];
				if(num[temp_x][temp_y] <= 4 && num[temp_x][temp_y] >= 1){
					ans ++;
					return ;
				}
				if(temp_x == 0 || temp_x == R+1 || temp_y == 0 || temp_y == C+1)
					break;
			}
	}
	flag = false;
}
void find(){
	for(int i=1 ; i<=R ; i++)
		for(int j=1 ; j<=C ; j++){
			if(num[i][j] > 0 && !judge(i,j,num[i][j]))
				turn(i,j);
			if(!flag)
				return;
		}
}
int main()
{
	flag = true;
	memset(num,-1,sizeof num);
	M['^'] = 1;M['>'] = 2;M['v'] = 3;M['<'] = 4;M['.'] = 0;
	scanf("%d%d",&R,&C);
	for(int i=1 ; i<=R ; i++)
		scanf("%s",*(str+i) + 1);
	for(int i=1 ; i<=R ; i++)
		for(int j=1 ; j<=C ; j++)
			num[i][j] = M[str[i][j]];
	find();
	if(!flag)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}

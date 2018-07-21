#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
char str[9][9];
bool vis[9][9],flag;
int N,M,T,n_X;
int px[] = {1,0,-1,0};
int py[] = {0,1,0,-1};
struct pos{
	int x,y;
}st,ed; 
int dfs(int x,int y,int d){
	pos nw;
	if(str[x][y] == 'D' && d == T){
		flag = true;
		return 0;
	}
	if(d >= T)
		return 0;
	for(int i=0 ; i<4 ; i++){
		nw.x = x + px[i];
		nw.y = y + py[i];
		if(nw.x > 0 && nw.x <= N && nw.y > 0 \
		&& nw.y <= M && vis[nw.x][nw.y] && str[nw.x][nw.y] != 'X'){
			vis[x][y] = false;
			dfs(nw.x,nw.y,d+1);
			if(flag)
				return 0;
			vis[x][y] = true;
		}
	}
}
int main(){
    while(scanf("%d%d%d",&N,&M,&T),N || M || T){
    	memset(str,'\0',sizeof(str));
    	memset(vis,true,sizeof(vis));
    	n_X = 0;
    	flag = false;
    	getchar();
		for(int i=1 ; i<=N ; i++){
    		for(int j=1 ; j<=M ; j++){
    			str[i][j] = getchar();
    			if(str[i][j] == 'S'){
    				st.x = i;
    				st.y = j;
				}
				else if(str[i][j] == 'D'){
    				ed.x = i;
    				ed.y = j;
				}
				else if(str[i][j] == 'X')
					n_X ++;
			}
			getchar();	
		} 
		if(T > N * M - 1 - n_X || \
		(abs(st.x-ed.x)+abs(st.y-ed.y)) % 2 != T % 2)
			flag = false;
		else
			dfs(st.x,st.y,0);
		flag ? printf("YES\n") : printf("NO\n");
	}
	
	return 0;
}

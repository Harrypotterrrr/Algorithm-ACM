#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
int mx[] = {0,1,0,-1};
int my[] = {1,0,-1,0};
char maz[102][102];
bool vis[102][102];
struct pos{
	int x,y;
	int mst;
	queue <pos> m;
	pos(){}
	pos(int _x,int _y,int _mst){
		x = _x;
		y = _y;
		mst = _mst;
	}
};
void print(pos s){
//	cout<<s.m.size();
	printf("It takes %d seconds to reach the target position,let me show you the way.\n",s.m.size()-1);
	int k = 0;
	pos last = pos(0,0,0);
	int t = s.m.size();
	for(int i=1 ; i<=t-1 ; i++){
		s.m.pop();		
		pos temp = s.m.front();
		if(temp.x == last.x && temp.y == last.y)
			printf("%ds:FIGHT AT (%d,%d)\n",i,temp.x,temp.y);
		else
			printf("%ds:(%d,%d)->(%d,%d)\n",i,last.x,last.y,temp.x,temp.y);	
		last = temp;
	}
}
bool bfs(){
	queue <pos> Q;
	pos st = pos(0,0,0);
	st.m.push(st);
	Q.push(st);
	memset(vis,true,sizeof vis);
	while(!Q.empty()){
		pos nw = Q.front();
		Q.pop();
		if(nw.mst){
			nw.mst --;
			pos nx = nw;
			nx.m.push(nw);
			Q.push(nx);
			continue;
		}
		if(nw.x == N-1 && nw.y == M-1){
			print(nw);
			return true;
		}
		for(int i=0 ; i<4 ; i++){
			pos nx = pos(mx[i]+nw.x,my[i]+nw.y,0);
			if(nx.x>=0 && nx.y>=0 && maz[nx.x][nx.y] != 'X' && nx.x<N && nx.y<M && vis[nx.x][nx.y]){
				vis[nx.x][nx.y] = false;
				if(maz[nx.x][nx.y] > '0' && maz[nx.x][nx.y] <= '9')
					nx.mst = maz[nx.x][nx.y] - '0';
				nx.m = nw.m;
				nx.m.push(nx);
				Q.push(nx);
			}
		}
		nw.m.pop();
	}
	return false;
}
int main(){
	while(scanf("%d%d",&N,&M),N || M){
		memset(maz,'\0',sizeof maz);
		for(int i=0 ; i<N ; i++)
			scanf("%s",maz[i]);
		if(!bfs())
			printf("God please help our poor hero.\n");
		printf("FINISH\n"); 
	}
	return 0;
}

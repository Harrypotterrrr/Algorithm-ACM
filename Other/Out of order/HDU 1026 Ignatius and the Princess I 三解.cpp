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
struct Pos{
	int x,y;
	int prex,prey;
	int dir;
	int mst;
	int time;
	bool operator<(const Pos &a)const{
        return a.time < time;	
	}
	Pos(){}
	Pos(int _x,int _y){
		x = _x;
		y = _y;
	}
}pos[102][102];
void print(int x,int y){
	if(x == 0 && y == 0)
		return ;
	int prex = pos[x][y].prex;
	int prey = pos[x][y].prey;
	print(prex,prey);
	if(pos[x][y].mst < 0){
		printf("%ds:(%d,%d)->(%d,%d)\n",pos[prex][prey].time+1,prex,prey,x,y);
		for(int i=1 ; i<=-pos[x][y].mst ; i++)
			printf("%ds:FIGHT AT (%d,%d)\n",pos[prex][prey].time+i+1,x,y);
	}
	else
		printf("%ds:(%d,%d)->(%d,%d)\n",pos[x][y].time,prex,prey,x,y);
}
bool bfs(){
	priority_queue <Pos> Q;
	pos[0][0].time = 0;
	vis[0][0] = false;
	Q.push(pos[0][0]);
	while(!Q.empty()){
		Pos nw = Q.top();
		Q.pop();
		if(nw.mst > 0){
			pos[nw.x][nw.y].time = nw.time + nw.mst;
			pos[nw.x][nw.y].mst *= -1;
			Q.push(pos[nw.x][nw.y]);
			continue;
		}
		if(nw.x == N-1 && nw.y == M-1)
			return true;
		for(int i=0 ; i<4 ; i++){
			Pos nx = Pos(mx[i]+nw.x,my[i]+nw.y);
			if(nx.x>=0 && nx.y>=0 && maz[nx.x][nx.y] != 'X' && nx.x<N && nx.y<M && vis[nx.x][nx.y]){
				vis[nx.x][nx.y] = false;
				pos[nx.x][nx.y].prex = nw.x;
				pos[nx.x][nx.y].prey = nw.y;
				pos[nx.x][nx.y].time = nw.time + 1;
				pos[nx.x][nx.y].mst = 0;
				if(maz[nx.x][nx.y] > '0' && maz[nx.x][nx.y] <= '9')
					pos[nx.x][nx.y].mst = maz[nx.x][nx.y] - '0';
				Q.push(pos[nx.x][nx.y]);
			}
		}
	}
	return false;
}
int main(){
	while(scanf("%d%d",&N,&M) != EOF){
		memset(maz,'\0',sizeof maz);
		memset(vis,true,sizeof vis);
		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<M ; j++)
				pos[i][j] = Pos(i,j);
		for(int i=0 ; i<N ; i++)
			scanf("%s",maz[i]);
		if (!bfs())
            printf("God please help our poor hero.\n");
        else{
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",pos[N-1][M-1].time);
            print(N-1,M-1);
        }
		printf("FINISH\n");
	}
	return 0;
}

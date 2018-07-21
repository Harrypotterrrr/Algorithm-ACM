#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
char maz[32][32][32];
const int px[]={1,-1,0,0,0,0};
const int py[]={0,0,0,0,1,-1};
const int pz[]={0,0,1,-1,0,0};
int L,R,C;
struct pos{
	int x,y,z;
}st,ed;
int bfs(pos w){
	bool vis[32][32][32];
	int day[32][32][32];
	memset(day,0,sizeof day);
	memset(vis,1,sizeof vis);
	queue <pos> Q;
	pos nw,nx;
	Q.push(st);
	vis[w.x][w.y][w.z] = false;
	day[1][1][1] = 0;
	while(!Q.empty()){
		nw = Q.front();
		Q.pop();
		for(int i=0 ; i<6 ; i++){
			nx.x = nw.x + px[i];
			nx.y = nw.y + py[i];
			nx.z = nw.z + pz[i];
			if(maz[nx.x][nx.y][nx.z] == 'E'){
				return day[nw.x][nw.y][nw.z] + 1;
			}
			else if(vis[nx.x][nx.y][nx.z] && nx.x > 0 && nx.y > 0 \
			&& nx.z > 0 && nx.x <= L && nx.y <= R && \
			nx.z <= C && maz[nx.x][nx.y][nx.z] != '#'){				
				day[nx.x][nx.y][nx.z] = day[nw.x][nw.y][nw.z] + 1;
				vis[nx.x][nx.y][nx.z] = false; 
				Q.push(nx);
			}
		}
	}
	return 0;
}
int main(){
    while(scanf("%d%d%d",&L,&R,&C),L||R||C){
    	memset(maz,'\0',sizeof maz);
		for(int i=1 ; i<=L ; i++)
    		for(int j=1 ; j<=R ; j++)
				scanf("%s",&maz[i][j][1]);
		for(int i=1 ; i<=L ; i++)
    		for(int j=1 ; j<=R ; j++)
    			for(int k=1 ; k<=C ; k++){
    				if(maz[i][j][k] == 'S'){
    					st.x = i;
    					st.y = j;
    					st.z = k;
    					goto L1;
					}
				}
	L1:
		int time = bfs(st);
    	if(!time)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",time);
	}
	return 0;
}

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
void print(Pos s){
    int ans[200000][2],time = s.time;
    for(int i=s.time ; i>=0 ; i--){
        if(maz[s.x][s.y] !='.'){
            while(maz[s.x][s.y] >= '0'){
                ans[i][0] = pos[s.x][s.y].x;
                ans[i][1] = pos[s.x][s.y].y;
                maz[s.x][s.y] --;
                i--;
            }
            i ++; 
        }
        else{
            ans[i][0] = pos[s.x][s.y].x;
            ans[i][1] = pos[s.x][s.y].y;
        }
        s = Pos(pos[s.x][s.y].prex , pos[s.x][s.y].prey);
    }
    int temx = ans[0][0];
    int temy = ans[0][1];
    for(int i=1 ; i<=time ; i++){
        if(ans[i][0] == temx && ans[i][1] == temy)
            printf("%ds:FIGHT AT (%d,%d)\n",i,ans[i][0],ans[i][1]);
        else
            printf("%ds:(%d,%d)->(%d,%d)\n",i,temx,temy,ans[i][0],ans[i][1]);    
        temx = ans[i][0];
        temy = ans[i][1];
    }
}
bool bfs(){
    priority_queue <Pos> Q;
    Pos st = Pos(0,0);
    st.time = 0;
    vis[0][0] = false;
    Q.push(st);
    while(!Q.empty()){
        Pos nw = Q.top();
        Q.pop();
        if(nw.mst){
            pos[nw.x][nw.y].time = nw.time + nw.mst;
            pos[nw.x][nw.y].mst = 0;
            Q.push(pos[nw.x][nw.y]);
            continue;
        }
        if(nw.x == N-1 && nw.y == M-1){
//            print(nw);
            return true;
        }
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
            print(pos[N-1][M-1]);
        }
        printf("FINISH\n");
    }
    return 0;
}

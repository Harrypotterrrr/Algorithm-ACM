#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
char field[202][202];
int n,m,k,pace;
int ans[202][202];
struct pos{
	int x;
	int y;
}Y,M,KFC[4005];
void go(pos start){
    queue <pos> Q,temp;
    pos p_nw,p_nx;
    int p_x[4] = {-1,0,1,0};
	int p_y[4] = {0,1,0,-1};
    bool flag[202][202];
    memset(flag , true , sizeof(flag));
    temp.push(start);
    flag[start.x][start.y] = false;
    pace = 0;
	while(!Q.empty() || !temp.empty()){
		if(Q.empty()){
			Q = temp;
			while(!temp.empty())
				temp.pop();
			pace ++;
		}
		p_nw = Q.front();
   		Q.pop();
   		for(int i=0 ; i<4 ; i++){
			p_nx.x = p_nw.x + p_x[i];
			p_nx.y = p_nw.y + p_y[i];
			if(p_nx.x > 0 && p_nx.x <= n && p_nx.y > 0 && p_nx.y <= m\
			 && flag[p_nx.x][p_nx.y] && field[p_nx.x][p_nx.y] != '#'){
				if(field[p_nx.x][p_nx.y] == '@')
					ans[p_nx.x][p_nx.y] += pace;
				temp.push(p_nx);
				flag[p_nx.x][p_nx.y] = false;
			}          
		}
	}
}

int main(){
    while(scanf("%d%d",&n,&m) != EOF){
        memset(ans,0,sizeof(ans));
		memset(field,'\0',sizeof(field));
        k = 0;
        for(int i=1 ; i<=n ; i++){
            getchar();
            for(int j=1 ; j<=m ; j++){
                field[i][j] = getchar();
                if(field[i][j] == 'Y'){
                    Y.x = i;
                    Y.y = j;
                    field[i][j] = '.';
                }
                else if(field[i][j] == 'M'){
                    M.x = i;
                    M.y = j;
                    field[i][j] = '.';
                }
                else if(field[i][j] == '@'){
                    KFC[k].x = i;
                    KFC[k].y = j;
                    k ++;
                }
            }    
        }           
        go(Y);
        go(M);
        int min= 10000;
        for(int i=1 ; i<=n ; i++)
        	for(int j=1 ; j<=m ; j++){
        		if(min > ans[i][j] && ans[i][j])
        			min = ans[i][j];
			}
        printf("%d\n",min * 11);        
    }
    return 0;
}

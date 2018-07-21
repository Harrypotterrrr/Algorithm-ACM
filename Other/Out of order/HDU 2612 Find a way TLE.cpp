#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
char field[202][202];
int KFC[201][2],k;
int p_x[4] = {-1,0,1,0};
int p_y[4] = {0,1,0,-1};
int pace_Y,pace_M;
int n,m,pace,pace_temp;
void MIN(int t){
    if(t < pace_temp)
        pace_temp = t; 
}
void go(bool flag,int x, int y,int z){
    for(int i=0 ; i<4 ; i++){
        if(field[x+p_x[i]][y+p_y[i]] != '#' && x+p_x[i] > 0 && \
        x+p_x[i] <= n && y+p_y[i] > 0 && y+p_y[i] <= m){
            if(x+p_x[i] == KFC[z][0] && y+p_y[i] == KFC[z][1]){
                if(!flag){
                    MIN(pace + 1);
                    pace_Y = pace_temp;
					return;
                }
                else{
                        MIN(pace + 1);
                        pace_M = pace_temp;
					    return;
                }
                
            }
            else{
                field[x][y] = '#';
                pace ++;
                go(flag,x+p_x[i],y+p_y[i],z);
                pace --;
                field[x][y] = '.';
            }    
        }
    }    
}
int main(){
    while(scanf("%d%d",&n,&m) != EOF){
        memset(field,'\0',sizeof(field));
        pace_Y = pace_M = k = 0;
        int Y_x,Y_y,M_x,M_y;
        for(int i=1 ; i<=n ; i++){
            getchar();
            for(int j=1 ; j<=m ; j++){
                field[i][j] = getchar();
                if(field[i][j] == 'Y'){
                    Y_x = i;
                    Y_y = j;
                    field[i][j] = '.';
                }
                else if(field[i][j] == 'M'){
                    M_x = i;
                    M_y = j;
                    field[i][j] = '.';
                }
                else if(field[i][j] == '@'){
                    KFC[k][0] = i;
                    KFC[k][1] = j;
                    k ++;
                }
            }    
        }           
        int min=10000;
        for(int i=0 ; i<k ; i++){
            pace_temp = 10000;
            pace = 0;
            go(false,Y_x,Y_y,i);
            pace_temp = 10000;
            pace = 0;
            go(true,M_x,M_y,i);
            int temp = pace_Y + pace_M;
            min = (min < temp ? min : temp);
        }
        printf("%d\n",min * 11);        
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const int px[8]={1,1,1,0,-1,-1,-1};
const int py[8]={-1,0,1,-1,1,-1,0,1};
int N,M,num;
char field[105][105];
void search(int x, int y){
	for(int i=0 ; i<8 ; i++)
		if(x+px[i] <= N && x+px[i] >=1 && y+py[i] <= M && y+py[i] >=1)
			if(field[x+px[i]][y+py[i]] == '@'){
				field[x+px[i]][y+py[i]] = 's';
				search(x+px[i],y+py[i]);
			}	
}
int main(){
	while(scanf("%d%d",&N,&M),N || M){
		memset(field,'\0',sizeof (field));
		num = 0;
		for(int i=1 ; i<=N ; i++)
			scanf("%s",&field[i][1]);		
		for(int i=1 ; i<=N ; i++)
			for(int j=1 ; j<=M ; j++){
				if(field[i][j] == '@'){
					field[i][j] = 's';
					search(i,j);
					num ++;
				}
			}
		printf("%d\n",num);				
	}
	return 0;	
}

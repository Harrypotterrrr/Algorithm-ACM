#include <iostream>
#include <stdio.h>
using namespace std;
const int px[8]={1,1,1,0,-1,-1,-1};
const int py[8]={-1,0,1,-1,1,-1,0,1};
int N,M,num = 0;
char field[105][105];
void search(int x, int y){
	for(int i=0 ; i<8 ; i++)
		if(x+px[i] <= N && x+px[i] >=1 && y+py[i] <= M && y+py[i] >=1)
			if(field[x+px[i]][y+py[i]] == 'W'){
				field[x+px[i]][y+py[i]] = '.';
				search(x+px[i],y+py[i]);
			}	
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1 ; i<=N ; i++){
		getchar();
		for(int j=1 ; j<=M ; j++)
			scanf("%c",&field[i][j]);
	}
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=M ; j++){
			if(field[i][j] == 'W'){
				field[i][j] = '.';
				search(i,j);
				num ++;
			}
		}
	printf("%d",num);				
	return 0;	
}

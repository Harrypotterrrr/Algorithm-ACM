#include <iostream>
#include <cstring>
using namespace std;
int father[50005];
int rel[50005];
int N,K,ans;
void init(){
	for(int i=0 ; i<=N ; i++)
		father[i] = i;
	memset(rel,0,sizeof rel);
	ans = 0;
}
int findFather(int x){
	if(x != father[x]){
		int temp = father[x];
		father[x] = findFather(father[x]);
		rel[x] = (rel[x] + rel[temp]) % 3;
	}
	return father[x];
}
int main()  
{  
	int D,X,Y;
	scanf("%d%d",&N,&K);
	init();
	while(K--){
		scanf("%d%d%d",&D,&X,&Y);
		if(X > N || Y > N || (D == 2 && X == Y)){
			ans ++;
			continue;
		}
		int findX = findFather(X);
		int findY = findFather(Y);
		if(findX != findY){
			father[findY] = findX;
			rel[findY] = (rel[X] - rel[Y] + D + 2) % 3;
		}
		else if(rel[Y] != (rel[X] + D - 1) % 3)
			ans ++;
	}
	printf("%d",ans);
    return 0;  
}

#include <iostream>  
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int N,d;
int father[1050];
bool vis[1050];
struct pos{
	int x,y;
}cpt[1050];
void init(){
	for(int i=1 ; i<=N ; i++)
		father[i] = i;
	memset(vis,false,sizeof vis);
}
int findFather(int x){
	int s = x;
	while(x != father[x])
		x = father[x];
	while(s != father[s]){
		int gs = s;
		s = father[s];
		father[gs] = x;
	}
	return x;
}
void Union(int x,int y){
	int findx = findFather(x);
	int findy = findFather(y);
	if(findx != findy)
		father[findx] = findy;
}
double dis(int a,int b){
	double x = abs(cpt[a].x-cpt[b].x);
	double y = abs(cpt[a].y-cpt[b].y);
	double z = sqrt(x*x + y*y);
	return z;
}
int main()
{  
	scanf("%d%d",&N,&d);
	init();
	for(int i=1 ; i<=N; i++)
		scanf("%d%d",&cpt[i].x,&cpt[i].y);
	char str[100];
	while(scanf("%s",str) != EOF){
		if(str[0] == 'O'){
			int j;
			scanf("%d",&j);
			vis[j] = true;
			for(int i=1 ; i<=N ; i++){
				if(j != i && vis[i] && dis(i,j) <= d){
//					cout<<"i="<<i<<" j="<<j<<endl;
					Union(i,j);
				}
			}
		}
		else if(str[0] == 'S'){
			int x1,x2;
			scanf("%d%d",&x1,&x2);
			if(findFather(x1) == findFather(x2))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
    return 0;  
}

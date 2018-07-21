#include <iostream>
#include <cstring>
using namespace std;
int father[2005];
int sex[2005];
int N,M;
bool flag;
void init(){
	for(int i=1 ; i<2005; i++)
		father[i] = i;
	memset(sex,0,sizeof sex);
	flag = true;
}
int findFather(int x){
	if(x != father[x]){
		int temp = father[x];
		father[x] = findFather(father[x]);
		sex[x] = (sex[x] + sex[temp]) % 2;
	}
	return father[x];
}
void Union(int x,int y){
	int findx = findFather(x);
	int findy = findFather(y);
	if(findx != findy){
		father[findy] = findx;
		sex[findy] = (sex[x] - sex[y] + 1) % 2;
	}
	findFather(y);	//ÎªÊ²Ã´£¿ 
	if(sex[x] == sex[y]){
		flag = false;
		return;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1 ; i<=T ; i++){
		scanf("%d%d",&N,&M);
		init();
		while(M--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(flag){
				Union(a,b);
			}
		}
		if(flag)
			printf("Scenario #%d:\nNo suspicious bugs found!\n",i);
		else
			printf("Scenario #%d:\nSuspicious bugs found!\n",i);
		puts("");
	}
    return 0;  
}

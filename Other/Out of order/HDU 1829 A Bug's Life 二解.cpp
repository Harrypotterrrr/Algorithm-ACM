#include <iostream>
#include <cstring>
using namespace std;
int father[4010];
int N,M;
bool flag;
void init(){
	for(int i=1 ; i<=N+2000 ; i++)
		father[i] = i;
	flag = true;
}
int findFather(int x){
	if(x != father[x])
		father[x] = findFather(father[x]);
	return father[x];
}
void Union(int x,int y){
	int findx = findFather(x);
	int findy = findFather(y);
	if(findx == findy){
		flag = false;
		return;
	}
	findy = findFather(y+2000);
	if(findx != findy)
		father[findx] = findy;
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
				Union(b,a);
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

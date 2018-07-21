#include <iostream>
#include <cstring>
using namespace std;
int father[2010];
int sex[2010];
int N,M;
bool flag;
int findFather(int x){
	int s = x;
	while(x != father[x])
		x = father[x];
	while(s != father[s]){
		int gs = s;
		s = father[s];
		father[s] = x;
	}
	return x;
}
void init(){
	for(int i=0 ; i<=2009 ; i++)
		father[i] = i;
	memset(sex,0,sizeof sex);
	flag = true;
}
void Union(int x,int y){
	int findx = findFather(x);
	int findy = findFather(y);
	if(findx != findy)
		father[findx] = findy;
}
int main()  
{  
	int T;
	scanf("%d",&T);
	for(int i=1 ; i<=T ; i++){
		init();
		scanf("%d%d",&N,&M);
		while(M--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(!flag)
				continue;
			if(findFather(a) == findFather(b)){
				flag = false;
				continue;
			}
			else{
				if(!sex[a])
					sex[a] = b;
				else
					Union(sex[a],b);
				if(!sex[b])
					sex[b] = a;
				else
					Union(sex[b],a);
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

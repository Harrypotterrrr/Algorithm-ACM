#include <iostream>
#include <cstring>
using namespace std;
int father[1005];
bool vis[1005];
int N,M;
void init(){
	for(int i=1 ; i<=N ; i++)
		father[i] = i;
	memset(vis, false, sizeof vis);
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
int main()  
{  
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		init();
		while(M--){
			int a,b;
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		for(int i=1 ; i<=N ; i++)
			vis[findFather(i)] = true;
		int ans = 0;
		for(int i=1 ; i<=N ; i++)
			if(vis[i])
				ans ++;
		printf("%d\n",ans);
	}
    return 0;  
}

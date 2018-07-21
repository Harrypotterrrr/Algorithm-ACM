#include <iostream>
#include <cstring>
using namespace std;
int father[30005];
int n,m,k;
void init(){
	for(int i=0 ; i<n ; i++)
		father[i] = i;
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
	while(scanf("%d%d",&n,&m),n||m){
		init();
		while(m--){
			scanf("%d",&k);
			int temp[30005];
			for(int i=1 ; i<=k ; i++)
				scanf("%d",&temp[i]);
			if(k == 1)
				continue;
			for(int i=2 ; i<=k ; i++)
				Union(temp[i],temp[i-1]);
		}
		int ans = 0;
		for(int i=0 ; i<n ; i++)
			if(findFather(i) == findFather(0))
				ans ++;
		printf("%d\n",ans);
	}
    return 0;  
}

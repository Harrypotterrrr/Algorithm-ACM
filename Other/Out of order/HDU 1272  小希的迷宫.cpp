#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int father[100005];
bool vis[100005];
bool flag;
int num,maxn = 100005;
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
void init(){
	for(int i=1 ; i<=maxn; i++)
		father[i] = i;
	memset(vis,false,sizeof vis);
	flag = true;
	maxn = num = 0;
}
void Union(int x,int y){
	int findx = findFather(x);
	int findy = findFather(y);
	if(findx == findy){
		flag = false;
		return;
	}
	if(findx != findy)
		father[findx] = findy;
}
int main()  
{  
	int a,b;
	while(true){
		init();
		while(scanf("%d%d",&a,&b),a||b){
			if(a == -1 && b == -1)
				return 0;
			if(!flag)
				continue;
			Union(a,b);
			vis[a] = vis[b] = true;
			maxn = max(maxn,max(a,b));
		}
		for(int i=1 ; i<=maxn ; i++)
			if(vis[i] && i == father[i])
				num ++;
		if(!flag || num > 1)
			printf("No\n");
		else
			printf("Yes\n");
	}
}

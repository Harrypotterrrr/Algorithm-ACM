#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int father[100000];
int kase = 0,maxn = 99999,num;
bool vis[100000];
bool flag;
void init(){
	for(int i=1 ; i<=maxn ; i++)
		father[i] = i;
	memset(vis,false,sizeof vis);
	flag = true;
	maxn = num = 0;
}
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
void Union(int x,int y){
	int findx = findFather(x);
	int findy = findFather(y);
	if(findx == findy || findy != y){
		flag = false;
		return;
	}
	if(findx != findy)
		father[findy] = findx;
}
int main()  
{  
	int a,b;
	while(true){
		init();
		while(scanf("%d%d",&a,&b),a||b){
			if(a < 0 && b < 0)
				return 0;
			if(!flag)
				continue;
			Union(a,b);
			maxn = max(maxn,max(a,b));
			vis[a] = vis[b] = true;
		}
		for(int i=1 ; i<=maxn ; i++)
			if(vis[i] && i == father[i])
				num ++;
		if(flag && num == 1 || !maxn)
			printf("Case %d is a tree.\n",++kase);
		else			
			printf("Case %d is not a tree.\n",++kase);
	}
}

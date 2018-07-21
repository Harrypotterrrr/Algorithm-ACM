#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int N,M;
int father[1050];
bool vis[1050];
int findFather(int x){
	int s = x;
	while(father[x] != x)
		x = father[x];
	while(s != father[s]){
		int gs = s;
		s = father[s];
		father[gs] = x;
	}
	return x;
}
void Union(int a,int b){
	int finda = findFather(a);
	int findb = findFather(b);
	if(finda != findb)
		father[finda] = findb;
}
void init(){
	for(int i=1 ; i<=N; i++)
		father[i] = i;
	memset(vis,false,sizeof vis);
}
int main(){
	while(scanf("%d%d",&N,&M),N){
		init();
		for(int i=1 ; i<=M ; i++){
			int a,b;
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		for(int i=1 ; i<=N ; i++)
			vis[findFather(i)] = true;
		// 为什么换成vis[father[i]] = true; 就不对了 
		int ans = 0;
		for(int i=1 ; i<=N ; i++)
			if(vis[i])
				ans ++;
		printf("%d\n",ans-1);
	}
	return 0;
}

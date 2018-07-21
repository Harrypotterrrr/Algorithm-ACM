#include <cstdio>
#include <cstring>
#include <iostream>
#define N 50001
using namespace std;
int father[N*3+1];
void init(int n)
{
	for(int i = 1; i <= n; i++)
		father[i] = i;
}
int findFather(int x)
{
	if(x != father[x])
		father[x] = findFather(father[x]);
	return father[x];
}
void Union(int a, int b)
{
	int finda = findFather(a);
	int findb = findFather(b);
	if(finda != findb)
		father[findb] = finda;
} 
void Solve(int n, int m)
{
	int ans = 0;
	for(int i=1; i<=m; i++){
		int T, x, y;
		scanf("%d%d%d",&T,&x,&y);
		if(x <= 0 || y <= 0 || x > n || y > n){
			ans++;
			continue;
		}
		if(T == 1){
			if(findFather(x)==findFather(y+n) || findFather(x)==findFather(y+2*n)){
				ans ++;
				continue;
			}
			else{
				Union(x,y);
				Union(x+n,y+n);
				Union(x+2*n,y+2*n);
			}
		}
		else{
			if(findFather(x)==findFather(y) || findFather(x)==findFather(y+2*n)){
				ans ++;
				continue;
			}
			else{
				Union(x,y+n);
				Union(x+n,y+2*n);
				Union(x+2*n,y);
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init(n*3); 
	Solve(n, m);
	return 0;
}

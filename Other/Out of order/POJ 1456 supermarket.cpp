#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N,maxn;
bool vis[10010];
struct art{
	int px,dx;
}pro[10010];
bool cmp(art x,art y){
	if(x.px != y.px)
		return x.px > y.px;
	else
		return x.dx > y.dx;
}
int main()  
{
	while(scanf("%d",&N) != EOF){
		memset(pro,0,sizeof pro);
		memset(vis,false,sizeof vis);
		maxn = 0;
		for(int i=1 ; i<=N ; i++){
			scanf("%d%d",&pro[i].px,&pro[i].dx);
			maxn = max(maxn , pro[i].dx);
		}
		sort(pro+1,pro+N+1,cmp);
		for(int i=1 ; i<=N ; i++){
			if(!vis[pro[i].dx])
				vis[pro[i].dx] = true;
			else{
				do{
					pro[i].dx --;
				}while(vis[pro[i].dx] && pro[i].dx);
				vis[pro[i].dx] = true;
			}
		}
		int ans = 0;
		for(int i=1 ; i<=N ; i++)
			if(pro[i].dx)
				ans += pro[i].px;
		printf("%d\n",ans);
	}
    return 0;  
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N,maxn;
int ans[10010];
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
		memset(ans,0,sizeof ans);
		maxn = -1;
		for(int i=1 ; i<=N ; i++){
			scanf("%d%d",&pro[i].px,&pro[i].dx);
			maxn = max(maxn , pro[i].dx);
		}
		sort(pro+1,pro+N+1,cmp);
		for(int i=1 ; i<=N ; i++){
			if(!ans[pro[i].dx])
				ans[pro[i].dx] = pro[i].px;
			else
				for(int j=pro[i].dx ; j>=1 ; j--)
					if(!ans[j]){
						ans[j] = pro[i].px;
						break;
					}
		}
		int sum = 0;
		for(int i=1 ; i<=maxn ; i++)
			sum += ans[i];
		printf("%d\n",sum);
	}
    return 0;  
}

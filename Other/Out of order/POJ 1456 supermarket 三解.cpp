#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N,sum;
int father[10010];
struct art{
	int px,dx;
}pro[10010];
bool cmp(art x,art y){
	if(x.px != y.px)
		return x.px > y.px;
	else
		return x.dx > y.dx;
}
void init(){
	memset(pro,0,sizeof pro);
	for(int i=1 ; i<=10009 ; i++)
		father[i] = i;
	sum = 0;
}
int findFather(int x){
	if(x != father[x])
		father[x] = findFather(father[x]);
	return father[x];
}
int main()  
{
	while(scanf("%d",&N) != EOF){
		init();
		for(int i=1 ; i<=N ; i++){
			scanf("%d%d",&pro[i].px,&pro[i].dx);
		}
		sort(pro+1,pro+N+1,cmp);
		for(int i=1 ; i<=N ; i++){
			int find = findFather(pro[i].dx);
			if (find > 0){
				father[find] = find - 1;
				sum += pro[i].px;
			}
		}
		printf("%d\n",sum);
	}
    return 0;  
}

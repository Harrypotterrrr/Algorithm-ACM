#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int n,q,from,to;
struct Card{
	int x,h,rch;
}card[10005];
int solve(int st,int ed){
	int maxn=0,cost=0;
	maxn = card[1].rch;
	for(int i=2 ; i<= ed ; i++){
		if(card[i].x <= maxn)
			maxn = maxn > card[i].rch ? maxn : card[i].rch;			
		else if(i >= st)
			cost += (card[i].x - maxn);
		maxn = card[i].rch;
	}
	return cost;
}
int main()
{
//	freopen("r.txt","r",stdin);
//	freopen("w.txt","w",stdout);
	while(scanf("%d",&n) != EOF){
		memset(card,0,sizeof card);
		for(int i=1 ; i<=n ; i++){
			scanf("%d%d",&card[i].x,&card[i].h);
			card[i].rch = card[i].x + card[i].h;
		}
		scanf("%d",&q);
		for(int i=1 ; i<=q ; i++){
			scanf("%d%d",&from,&to);
			printf("%d\n",solve(from,to));
		}
	}
	return 0;
}

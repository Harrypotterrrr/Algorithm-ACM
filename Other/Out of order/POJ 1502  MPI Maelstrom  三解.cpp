#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
int dis[10005];
int N,k=0,ans=-1;
char str[100005];
struct Line{
	int n1,n2;
	int cost;
}line[10005];
typedef pair <int,int> P;
void chg(int x){
	int lth = strlen(str);
	int t=0,num=0,tmp;
	for(int i=0 ; i<=lth ; i++){
		if(str[i] > 57){
			line[k].n1  = x;
			line[k].n2  = t;
			line[k].cost  = INF;
			k ++;
			t ++;
			i ++;
			continue;
		}
		while(str[i] != ' ' && str[i] != '\0'){
			num *= 10;
			tmp = str[i] - '0';
			num += tmp;
			i ++;
		}
		line[k].n1  = x;
		line[k].n2  = t;
		line[k].cost = num;
		num = 0;
		k ++;
		t ++;
	}
}
void Dijkstra(){
	priority_queue <P,vector<P>,greater<P> > Q;
	memset(dis,0x3f,sizeof dis);
	dis[0] = 0;
	Q.push(P(0,0));
	while(!Q.empty()){
		P nw = Q.top();
		Q.pop();
		if(nw.first > dis[nw.second])
			continue;
		for(int i=0 ; i<k ; i++){
			if(nw.second != line[i].n2 && nw.second != line[i].n1)
				continue;
			Line temp = line[i];
			if(dis[temp.n2] > dis[temp.n1] + temp.cost){
				dis[temp.n2] = dis[temp.n1] + temp.cost;
				Q.push(P(dis[temp.n2],temp.n2));
			}
			if(dis[temp.n1] > dis[temp.n2] + temp.cost){
				dis[temp.n1] = dis[temp.n2] + temp.cost;
				Q.push(P(dis[temp.n1],temp.n1));
			}
		}
	}
}
int main()
{
	scanf("%d",&N);
	getchar();
	memset(dis,0x3f,sizeof dis);
	for(int i=1 ; i<N ; i++){
		memset(str,'\0',sizeof str);
		gets(str);
		chg(i);
	}
	Dijkstra();
//	for(int j=0 ; j<N ; j++)
//		printf("%12d",dis[j]);
//	cout<<endl;
	for(int i=1 ; i<N ; i++)
		if(ans < dis[i])
			ans = dis[i];
	printf("%d\n",ans);
	return 0;  
}

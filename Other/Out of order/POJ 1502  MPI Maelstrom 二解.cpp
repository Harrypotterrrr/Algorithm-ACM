#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int dis[105];
int N,k=0,ans=-1;
char str[100005];
struct Line{
	int n1,n2;
	int cost;
}line[10005];
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
void Bellman(){
	memset(dis,0x3f,sizeof dis);
	dis[0] = 0;
	for(int i=1 ; i<N ; i++){
		for(int j=0 ; j<k ; j++){
			if(dis[line[j].n2] > dis[line[j].n1] + line[j].cost)
				dis[line[j].n2] = dis[line[j].n1] + line[j].cost;
			if(dis[line[j].n1] > dis[line[j].n2] + line[j].cost)
				dis[line[j].n1] = dis[line[j].n2] + line[j].cost;
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
	Bellman();
//	for(int j=0 ; j<N ; j++)
//		printf("%12d",dis[j]);
//	cout<<endl;
	for(int i=1 ; i<N ; i++)
		if(ans < dis[i])
			ans = dis[i];
	printf("%d\n",ans);
	return 0;  
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int dis[105][105],N,ans=0;
char str[100005];
void chg(int x){
	int lth = strlen(str);
	int t=0,num=0,tmp;
	for(int i=0 ; i<=lth ; i++){
		if(str[i] > 57){
			dis[x][t] = dis[t][x] = INF;
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
		dis[x][t] = dis[t][x] = num;
		num = 0;
		t ++;
	}
}
void Floyd(){
	for(int k=0 ; k<N ; k++)
		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<N ; j++)
				if(dis[i][j] > dis[k][j] + dis[i][k])
					dis[i][j] = dis[k][j] + dis[i][k];
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
	Floyd();
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++)
			printf("%12d",dis[i][j]);
		cout<<endl;
	}
	for(int i=0 ; i<N ; i++)
		if(ans < dis[i][0])
			ans = dis[i][0];
	printf("%d\n",ans);
	return 0;  
}

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int father[200050];
int sum[200050];
int N,M;
struct len{
	int st,ed,dis;
}res;
void init(){
	for(int i=0 ; i<=N ; i++)
		father[i] = i;
	memset(sum,0,sizeof sum);
}
int findFather(int x){
	if(x != father[x]){
		int temp = findFather(father[x]);
		sum[x] += sum[father[x]];
	/*
		1——> 2——> 3——> 4 
		sum[2] = sum[2] + sum[1];
		sum[3] = sum[3] + sum[2];
		sum[4] = sum[4] + sum[3];
		设根节点 S, a的父节点 b 
		向量 aS = ab + bS (aS表示a到S距离)
	*/
		father[x] = temp;	
	}
	return father[x];
}
int main()
{
	while(scanf("%d%d",&N,&M) != EOF){
		init();
		int ans = 0;
		for(int i=1 ; i<=M ; i++){
			scanf("%d%d%d",&res.st,&res.ed,&res.dis);
			res.st --;
	//	重要!
			int findst = findFather(res.st);
			int finded = findFather(res.ed);
			if(findst != finded){
				father[findst] = finded;
				sum[findst] = -sum[res.st] + res.dis + sum[res.ed];
	/*
		设a,b的根节点分别为A,B (a<b)
		向量 AB = Aa + ab + bB = -aA + ab + bB
	*/
			}
			else if(abs(sum[res.st] - sum[res.ed]) != res.dis)
				ans ++;
		}
		printf("%d\n",ans);
	}
    return 0;  
}

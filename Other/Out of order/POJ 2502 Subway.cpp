#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
const double v1 = 10000.0/60;
const double v2 = 40000.0/60;
typedef pair<double,int> P;
double time[205][205];
double ans[205];
bool vis[205];
struct Node{
	int x,y;
}node[205];
struct cmp{
	bool operator ()(P &a,P &b){
		return a.first > b.first;
	}
};
void Dijkstra(int s){
	for(int i=1 ; i<=s ; i++)
		ans[i] = INF;
	memset(vis,false,sizeof vis);
	priority_queue <P,vector<P>,cmp> Q;
	Q.push(P(0,1));
	ans[1] = 0;
	vis[1] = true;
	while(!Q.empty()){
		P nw = Q.top();
		Q.pop();
		vis[nw.second] = true;
		for(int i=1 ; i<=s ; i++){
			if(!vis[i] && ans[i] > nw.first + time[nw.second][i]){
				ans[i] = nw.first + time[nw.second][i];
				Q.push(P(ans[i],i)); 
			} 
				
		}
	}
}
double count_time1(Node a,Node b){
	double dis = sqrt(double((a.x-b.x)*(a.x-b.x))+double((a.y-b.y)*(a.y-b.y)));
	return dis / v1 * 1.0;
}
double count_time2(Node a,Node b){
	double dis = sqrt(double((a.x-b.x)*(a.x-b.x))+double((a.y-b.y)*(a.y-b.y)));
	return dis / v2 * 1.0;
}
int main()
{
	int temp_x,temp_y,k=3,flag=3;
	for(int i=1 ; i<205 ; i++)
		for(int j=1 ; j<205 ; j++){
			if(i == j)
				time[i][i] = 0;
			else
				time[i][j] = INF;				
		}
	scanf("%d%d%d%d",&node[1].x,&node[1].y,&node[2].x,&node[2].y);
	while(scanf("%d%d",&temp_x,&temp_y) != EOF){
		if(temp_x == -1 && temp_y == -1){
			flag = k;
			continue;
		}
		node[k].x = temp_x;
		node[k].y = temp_y;
		if(flag != k)
			time[k-1][k] = time[k][k-1] = count_time2(node[k],node[k-1]);
		k ++;
	}
	for(int i=1 ; i<k ; i++)
		for(int j=i+1 ; j<=k ; j++){
			double tmp = count_time1(node[i],node[j]);
			if(tmp > time[i][j])
				continue;
			time[i][j] = time[j][i] = tmp;
		}
	Dijkstra(k-1);
	printf("%.0lf\n",ans[2]);
    return 0;
}

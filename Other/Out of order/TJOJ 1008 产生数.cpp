#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector <int> V[12];
int ans[35];
bool vis[12];
int k,count,h;
char num[35];
void dfs(int x){
	vis[x] = true;
	for(int i=0 ; i<V[x].size() ; i++){
		if(!vis[V[x][i]]){
			count ++;
			dfs(V[x][i]);
		}
	}
}
void multiple(int x){
	int carry = 0,temp;
	for(int i=0 ; i<h ; i++){
		temp = (x * ans[i]  + carry) / 10;
		ans[i] = (x * ans[i]  + carry) % 10;
		carry = temp;
	}
	if(carry){
		ans[h] = carry;
		h ++;
	}
}
int main()
{
	memset(ans,0,sizeof ans);
	ans[0] = h = 1;
    scanf("%s%d",num,&k);
    int a,b;
	for(int i=0 ; i<k ; i++){
    	scanf("%d%d",&a,&b);
    	V[a].push_back(b);
	}
	int length = strlen(num);
	for(int i=0 ; i<length ; i++){
		int tmp = num[i] - '0';
		if(V[tmp].size()){
			memset(vis,false,sizeof vis);
			count = 1;
			dfs(tmp);
			multiple(count);
		}
	}
	for(int i=h-1 ; i>=0 ; i--)
		printf("%d",ans[i]); 
}


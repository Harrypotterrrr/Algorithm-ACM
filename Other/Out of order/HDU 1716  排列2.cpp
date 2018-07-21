#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n[9],ans[9];
bool vis[9],VIS[10004];
int last;
string str;
void dfs(int x){
	if(x == 4){
		int k = 1000*ans[0] + 100*ans[1] + 10*ans[2] + ans[3];
		if(!VIS[k])
			return;
		VIS[k] = false;
		if(ans[0] == last){
			str += " ";
			for(int i=0 ; i<4 ; i++)
				str += ('0' + ans[i]);
		}
		else{
			str += '\n';
			for(int i=0 ; i<4 ; i++)
				str += ('0' + ans[i]);
			last = ans[0];
		}
	}
	for(int i=0 ; i<=3 ; i++)
		if(vis[i]){
			ans[x] = n[i];
			if(x == 0 && !ans[x])
				continue;
			vis[i] = false;
			dfs(x+1);
			vis[i] = true;
		}
}
int main()  
{
	int time = 1;
	while(scanf("%d%d%d%d",&n[0],&n[1],&n[2],&n[3]) != EOF){
		if(n[0] + n[1] + n[2] + n[3] == 0)
			break;
		if(time != 1)
			cout<<endl;
		time ++;
		memset(vis,true,sizeof vis);
		memset(VIS,true,sizeof VIS);
		sort(n,n+4);
		last = (ans[0] ? ans[1] : ans[0]);
		dfs(0);
		str.erase(str.begin());
		cout<<str<<endl;
		str.clear();
	}
    return 0;  
}

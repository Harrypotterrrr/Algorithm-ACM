#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>
using namespace std;
char temp[102];
bool flag[102];
int n,k;
stack<int>sum;

bool func(){
	stack<int> stac;
	int p_temp = 0,p = 1;
	stac.push(1);
	while(p < n + 1){
		if(stac.size() && stac.top() == temp[p_temp] - '0'){
			stac.pop();
			p_temp ++;
		}
		else
			stac.push(++ p);
	}
	if(p_temp == n){
//		printf("%s\n",temp);
		return true;
	}	
	else
		return false;
}

void array(int x){
	if(x >= n){
		bool judge = func();
			if(judge)
				sum.push(1);
		return;
	}
	else {
		for(int i=1 ; i<=n ; i++){
			if(flag[i]){
				flag[i] = false;
				temp[x] = i + '0';
				array(x+1);
				flag[i] = true;
			}
		}
	}
}

int main(){
	while(scanf("%d",&n) != EOF){
		memset(flag,1,sizeof(flag));
		k = -1;
		while(!sum.empty())
			sum.pop();
		array(0);
//		for(int i =0 ; i<=k ; i++)
//			cout<<num[i]<<endl;
		printf("%d\n",sum.size());
	}
	return 0;
}

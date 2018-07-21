#include <iostream>
#include <stdio.h>
#include <cstring>
//#include <algorithm>
using namespace std;
int num[11],k,sum;
bool vis[11],flag;
int C(int x,int y){
	if(!y)
		return 1;
	if(y > x / 2)
		y = x - y;
	int mult = 1;
	for(int i=y+1 ; i<=x ; i++)
		mult *= i;
	for(int i=2 ; i<=x-y ; i++)
		mult /= i;
	return mult;
}
int calc(){
	int temp = 0;
	for(int i=1; i<=k ; i++){
		temp += C(k-1,i-1)*num[i];
	}
	return temp;
}
void array(int n){
	if(flag)
		return;
	if(n == k+1){
		int w=calc();
		if(w == sum){
			flag = true;
			cout<<num[1];
			for(int i=2 ; i<=k ; i++)
				cout<<" "<<num[i];
			cout<<endl;
		}	
		return;
	}
	for(int i=1 ; i<=k ; i++){
		if(vis[i]){
			num[n] = i;
			vis[i] = false;
			array(n+1);
			vis[i] = true;
		}
	} 
}

int main(){
	while(scanf("%d%d",&k,&sum) != EOF){
		flag = false;
		memset(vis,true,sizeof vis);
    	array(1);
    	
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int n;
void bfs(){
	queue <long long> Q;
	Q.push(1);
	while(true){
		long long m = Q.front();
		Q.pop();
		if(!(m % n)){
			printf("%lld\n",m);
			return;
		}
		Q.push(m * 10);
		Q.push(m * 10 + 1);
	} 
}
int main(){
	while(scanf("%d",&n),n){
		bfs();
	}
	return 0; 
}

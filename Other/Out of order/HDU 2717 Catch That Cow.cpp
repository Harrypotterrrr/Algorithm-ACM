#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
int cow,john;
int time[200004];
int retrieve(int x){
	queue <int> Q;
	bool flag[200004];
	memset(flag, true, sizeof(flag));
	int nw,nx;
	Q.push(x);
	flag[x] = false;
	time[x] = 0;
	while (!Q.empty()) {
		nw = Q.front();
		Q.pop();
		for (int i = 1; i <= 3; i++) {
			switch (i) {
				case(1) : nx = nw + 1;break;
				case(2) : nx = nw - 1;break;
				default : nx = nw * 2;break;
			}
			if (nx >= 0 && nx <= 200000 && flag[nx]) {
				if (nx == cow)
					return time[nw] + 1;
				else {
					Q.push(nx);
					time[nx] = time[nw] + 1;
					flag[nx] = false;
				}
			}
		}
	}
}
int main(){
    while(scanf("%d%d",&john,&cow) != EOF){
		memset(time,0,sizeof(0));
		if(john != cow)
			printf("%d\n",retrieve(john));
		else
			printf("%d\n",0);	
	}
	return 0;
}

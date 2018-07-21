#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
const char ACT[][12] = {"0","FILL(1)", "FILL(2)", \
"DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"};
int A,B,C,n = 0;
bool vis[3000][3000];
struct cdt{
	int a,b;
	queue <int> q;
};

bool bfs(){
	queue <cdt> Q;
	cdt st1,st2;
	n = 1;
	st1.a = A; st1.b = 0; st1.q.push(1);
	st2.a = 0; st2.b = B; st2.q.push(2);
	Q.push(st1);
	Q.push(st2);
	memset(vis,true,sizeof(vis));
	while(!Q.empty()){
		cdt nw = Q.front();
		Q.pop();
		if(!vis[nw.a][nw.b])
			continue;
		vis[nw.a][nw.b] = false;
//		cout<<nw.a<<"  "<<nw.b<<"  "<<nw.q.size()<<endl;
		if(nw.a == C || nw.b == C){
			printf("%d\n",nw.q.size());
			while(!nw.q.empty()){
				int m = nw.q.front();
				printf("%s\n",ACT[m]);
				nw.q.pop();
			}
			return true; 
		}	
/*  start */
		cdt temp;
	// 	一满 一空 
		if((nw.a == 0 && nw.b == B)||(nw.a == A && nw.b == 0)){
			if(nw.a > nw.b){
				temp.a = nw.a; 
				nw.a = nw.a - B;
				nw.a = nw.a < 0 ? 0 : nw.a;
				nw.b = temp.a - nw.a;
				nw.q.push(5);
			}
			else{
				temp.b = nw.b; 
				nw.b = nw.b - A;
				nw.b = nw.b < 0 ? 0 : nw.b;
				nw.a = temp.b - nw.b;
				nw.q.push(6);
			}
			Q.push(nw);
			continue;
		}
	//	一半 一空
		if(nw.a == 0 || nw.b == 0){
			if(nw.a > 0)
				for(int i=1 ; i<=2 ; i++){
					cdt n = nw;
					switch(i){
					case(1):
						n.b = B;
						n.q.push(2);
						break;
					case(2):
						temp.a = n.a;
						n.a = n.a - B;
						n.a = n.a < 0 ? 0 : n.a;
						n.b = temp.a - n.a;
						n.q.push(5);
						break;
					}
					Q.push(n);
				}
			else
				for(int i=1 ; i<=2 ; i++){
					cdt n = nw;
					switch(i){
					case(1):
						n.a = A;
						n.q.push(1);
						break;
					case(2):
						temp.b = n.b;
						n.b = n.b - A;
						n.b = n.b < 0 ? 0 : n.b;
						n.a = temp.b - n.b;
						n.q.push(6);
						break;
					} 
					Q.push(n);
				}
		}
	//	一满 一半
		else{
			if(nw.a == A)
				for(int i=1 ; i<=2 ; i++){
					cdt n = nw;
					switch(i){ 
					case(1):
						n.a = 0;
						n.q.push(3);
						break;
					case(2):
						temp.a = n.a;
						n.a = n.a - (B - n.b);
						n.a = n.a < 0 ? 0 : n.a;
						n.b = n.b + temp.a - n.a;
						n.q.push(5);
						break;
					}
					Q.push(n);
				}
			else
				for(int i=1 ; i<=2 ; i++){
					cdt n = nw;
					switch(i){ 
					case(1):
						n.b = 0;
						n.q.push(4);
						break;
					case(2):
						temp.b = n.b;
						n.b = n.b - (A - n.a);
						n.b = n.b < 0 ? 0 : n.b;
						n.a = n.a + temp.b - n.b;
						n.q.push(6);
						break;
					}
					Q.push(n);
				}
		}
/*  end */		
	}
	return false;
}
int main(){
//	freopen("r.txt","r",stdin);
//	freopen("2.txt","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	n = 0;
	if(	!bfs() )
		printf("impossible\n");	
	getchar();	
	return 0;
}	

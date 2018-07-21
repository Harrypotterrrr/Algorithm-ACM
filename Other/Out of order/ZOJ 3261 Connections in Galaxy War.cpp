#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int father[10005];
int ans[100000];
int N,M,Q,p;
struct Star{
	int pwr;
	int max_num;
	int max_val;
}star[10005];
struct Tnnl{
	bool flag;
	int fst;
	int snd;
}tnnl[20005];
struct Qry{
	bool flag;
	int fst;
	int snd;
}qry[50005];
bool cmp(Tnnl a,Tnnl b){
	if(a.fst != b.fst)
		return a.fst > b.fst;
	return a.snd > b.snd;
}
void change(int a,int b){
	int left = 0,right = M - 1;
	while(true){
		int mid = (left + right) >> 1;
		if(tnnl[mid].fst == a && tnnl[mid].snd == b){
			tnnl[mid].flag = false;
			return;
		}
		if(tnnl[mid].fst > a){
			left = mid + 1;
			continue;	
		}
		else if(tnnl[mid].fst < a){
			right = mid - 1;
			continue;
		}
		else if(tnnl[mid].snd > b){
			left = mid + 1;
			continue;	
		}
		else
			right = mid - 1;
	}
}
int findFather(int x){
	if(x != father[x])
		father[x] = findFather(father[x]);
	return father[x];
}
void Union(int a,int b){
	father[b] = a;
	if(star[a].max_val < star[b].max_val){
		star[a].max_val = star[b].max_val;
		star[a].max_num = star[b].max_num;
	}
	else if(star[a].max_val == star[b].max_val && star[a].max_num > star[b].max_num)
		star[a].max_num = star[b].max_num;
}
void init(){
	for(int i=0 ; i<N ; i++){
		star[i].max_num = i;
		star[i].max_val = star[i].pwr;
		father[i] = i;
	}
	memset(ans,0,sizeof ans);
	p = 0;
}
int main()  
{
	int blank = 0;
	while(scanf("%d",&N) != EOF){
		if(blank==0)
            blank=1;
        else
            puts("");
		for(int i=0 ; i<N ; i++)
			scanf("%d",&star[i].pwr);
		scanf("%d",&M);
		for(int i=0 ; i<M ; i++){
			scanf("%d%d",&tnnl[i].fst,&tnnl[i].snd);
			if(tnnl[i].fst > tnnl[i].snd)
				swap(tnnl[i].fst,tnnl[i].snd);
			tnnl[i].flag = true;
		}
		sort(tnnl,tnnl+M,cmp);
		scanf("%d",&Q);
		char str[10];
		for(int i=0 ; i<Q ; i++){
			scanf("%s",str);
			if(str[0] == 'q'){
				scanf("%d",&qry[i].fst);
				qry[i].flag = false;
			}
			else{
				scanf("%d%d",&qry[i].fst,&qry[i].snd);
				if(qry[i].fst > qry[i].snd)
					swap(qry[i].fst,qry[i].snd);
				qry[i].flag = true;	
				change(qry[i].fst,qry[i].snd);
			}
		}
		init();
		for(int i=0 ; i<M ; i++){
			if(tnnl[i].flag == false)
				continue;
			int finda = findFather(tnnl[i].fst);
			int findb = findFather(tnnl[i].snd);
			if(finda != findb)
				Union(finda,findb);
		}
		for(int i=Q-1 ; i>=0 ; i--){
			if(!qry[i].flag){
				int temp = findFather(qry[i].fst);
				if(star[temp].max_val > star[qry[i].fst].pwr)
					ans[p++] = star[temp].max_num;
				else
					ans[p++] = -1;
			}
			else{
				int finda = findFather(qry[i].fst);
				int findb = findFather(qry[i].snd);
				if(finda != findb)
					Union(finda,findb);
			}
		}
		for(int i=p-1 ; i>=0 ; i--)
			printf("%d\n",ans[i]);
	}
    return 0;  
}

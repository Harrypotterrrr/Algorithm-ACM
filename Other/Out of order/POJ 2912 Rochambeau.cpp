#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int father[505],rel[505];
int a[2005],b[2005],s[2005];
int N,M,num,wrong_line,wrong_num;
char c[2005];
int findFather(int x){
	if(x != father[x]){
		int temp = father[x];
		father[x] = findFather(father[x]);
		rel[x] = (rel[x] + rel[temp]) % 3;
	}
	return father[x];
}
void init(){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(s,0,sizeof s);
	memset(c,'\0',sizeof c);
	for(int i=1 ; i<=M ; i++){
		scanf("%d%c%d",&a[i],&c[i],&b[i]);
		if(c[i] == '=')
			s[i] = 0;
		else if(c[i] == '<')
			s[i] = 1;
		else
			s[i] = 2;
	}
	wrong_line = 0;
	num = 0;
}
int main()  
{  
	while(scanf("%d%d",&N,&M) != EOF){
		if(N == 1 && M == 0){
			printf("Player 0 can be determined to be the judge after 0 lines\n");
			continue;
		}
		init();
		for(int i=0 ; i<N ; i++){
			for(int i=0 ; i<N+1 ; i++)
				father[i] = i;
			memset(rel,0,sizeof rel);
			bool flag = true;
			for(int k=1 ; k<=M ; k++){
				if(a[k] == i || b[k] == i)
					continue;
				int finda = findFather(a[k]);
				int findb = findFather(b[k]);
				if(finda != findb){
					father[findb] = finda;
					rel[findb] = (rel[a[k]] - rel[b[k]] + s[k] + 3) % 3;
				}
				else if(rel[b[k]] != (rel[a[k]] + s[k]) % 3){
					flag = false;
					wrong_line = max(wrong_line,k);
					break;
				}
			}
			if(flag){
				num ++;
				wrong_num = i;
			}
		}
		if(num == 1)
			printf("Player %d can be determined to be the judge after %d lines\n",wrong_num,wrong_line);
		else if(!num)
			printf("Impossible\n");
		else
			printf("Can not determine\n");
	}
    return 0;  
}

#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int main(){
	map <int,int> M;
//	map<int,int>::iterator it; //有这句话L中不用再定义it 
	int T,a;
	while(scanf("%d",&T) != EOF){
		M.clear();
		for(int i=0 ; i<T ; i++){
			scanf("%d",&a);
			if(!M[a])
				M[a] = 1;
			else
				M[a] ++;
		}
		// L:
		for(map<int,int>::iterator it=M.begin() ; it!=M.end() ; it++)
			if(it->second >= (T+1) / 2){
				printf("%d\n",it->first);
				break;
			}
	}
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int main()
{
	int N;
	while(scanf("%d",&N),N >= 0){
		map <int,int> Map;
		int V,M,Max=0,cs = 0,se = 0;
		bool flag = 0;
		for(int i=1 ; i<=N ; i++){
			scanf("%d%d",&V,&M);
			Map[V] = M;
			Max = max(Max,V);
		}
		for(int i=Max ; i>=1 ; i--){
			if(!Map[i])
				continue;
			while(Map[i]){
				if(!flag){
					cs += i;
					Map[i] --;
					if(cs > se)
						flag = !flag;
					continue;
				}
				else{
					se += i;
					Map[i] --;
					if(se > cs)
						flag = !flag;
				}
			}
		}
		Map.clear();
		if(cs < se)
			swap(cs,se);
		printf("%d %d\n",cs,se);
	}
    return 0;  
}

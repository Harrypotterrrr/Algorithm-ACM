#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int T,count[1000],max;
	char color[1000][16];
	while(scanf("%d",&T),T){
		memset(count,0,sizeof(count));
		memset(color,NULL,sizeof(color));
		max = 0;
		for(int i=0 ; i<T ; i++){
			scanf("%s",&color[i]);
			if(!i)
				count[0] ++ ;
			else
				for(int j=0; j<=i ;j++)
					if(strcmp(color[j],color[i]) == 0)
						count[i] ++;
		}
		for(int i=0 ; i<T ; i++){
			if(count[i] > max)
				max = i;
		}
		printf("%s\n",color[max]);
	}
	return 0;
} 

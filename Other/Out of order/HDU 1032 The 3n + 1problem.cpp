#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
//	freopen("r.txt","r",stdin);
//	freopen("w.txt","w",stdout);
 	int a,b;
	while(scanf("%d%d",&a,&b) != EOF){
		int max=0,m,n;
		m = a <= b ? a : b;
		n = a  > b ? a : b;
		for(int i=m ; i<=n ; i++){	
			int count = 0,temp;
			temp = i;
			while(temp != 1){
				if(temp%2 == 0)
					temp /= 2;
				else 
					temp = temp*3 + 1;
				count++;
			}
			if(max < count)
				max = count+1;
		}
		printf("%d %d %d\n",a,b,max);		
	}
	return 0;
}              

#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int A,B,n,s[100]={1,1},i,T;
    while(scanf("%d%d%d",&A,&B,&n) , A||B||n ){
        for(i=2 ; i<100 ; i++){
            if(i>2 && s[i-1]==1 && s[i-2]==1)
                break;
            else
                s[i] = (A*s[i-1]+B*s[i-2]) % 7;
        }
        T = n % (i - 2);
        if(!T)
        	printf("%d\n",s[i-3]);
        else
        	printf("%d\n",s[T-1]);
    }
  return 0;
}

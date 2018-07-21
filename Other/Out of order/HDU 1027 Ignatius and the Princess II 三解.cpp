#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int n,k;
    while(scanf("%d%d",&n,&k) != EOF){
    	int a[1005];
    	for(int i=0 ; i<n ; i++)
    		a[i] = i+1;
    	for(int i=1 ; i<k ; i++)
    		next_permutation(a,a+n);
    	for(int i=0 ; i<n ; i++)
    		printf(i == n-1 ? "%d" : "%d ",a[i]);
    	printf("\n");
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
const int fac[] ={1,1,2,6,24,120,720,5040,40320};
using namespace std;
void Cantor(int st,int n,int k){
    vector <int> num;
    vector <int> ans;
	for(int i=0 ; i<n ; i++)
    	num.push_back(st+i);
    int quo,rem; 
    for(int i=0 ; i<n ; i++){
    	quo = k / fac[n-i-1];
    	rem = k % fac[n-i-1];
    	k = rem;
    	sort(num.begin(),num.end());
    	ans.push_back(num[quo]);
		num.erase(num.begin()+quo);
	}
	vector <int> ::iterator it;
	printf("%d",*ans.begin());
	for(it=ans.begin()+1 ; it!=ans.end() ; it++)
		printf(" %d",*it);
}
int main(){
	int n,k;
    while(scanf("%d%d",&n,&k) != EOF){
    	if(n <= 8)
       		Cantor(1,n,k-1);
       	else{
       		for(int i=1 ; i<=n-8 ; i++)
			   printf("%d ",i);
			  Cantor(n-7,8,k-1);	
		}
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
typedef long long LL; 
using namespace std;
int main()
{
	vector <int> v;
	__int64 num[22]={1,1};
	__int64 m;
	int n,ans[22],p;
	for(int i=2 ; i<=21 ; i++)
		num[i] = num[i-1] * (i-1) + 1;
	while(scanf("%d%I64d",&n,&m) != EOF){
		p = 0;
		m --;
		v.clear();
		for(int i=1 ; i<=n ; i++)
			v.push_back(i);
		while(true){
			__int64 dev = m / num[n];
			__int64 quo = m % num[n];
			ans[p++] = v[dev];
			v.erase(v.begin()+dev);
			sort(v.begin(),v.end());
			if(!quo)
				break;
			if(quo == 1){
				ans[p++] = *v.begin();
				break;
			}
			m = quo - 1;
			n --;
		}
		printf("%d",ans[0]);
		for(int i=1 ; i<p ; i++)
			printf(" %d",ans[i]);
		puts("");
	}
    return 0;  
}

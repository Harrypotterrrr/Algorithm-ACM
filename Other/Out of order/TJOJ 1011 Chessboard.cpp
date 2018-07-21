#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
bool judge(int n,int m){
	if (!(n % 2) && !(m % 2))
		return false;
	return true;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n*m % 2){
			printf("My God!\n");
			continue;			
		}
		if(judge(n,m))
			printf("God save the pig!\n");			
		else
			printf("My God!\n");		
	}
	return 0;
}

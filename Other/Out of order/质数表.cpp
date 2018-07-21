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
bool vis[2500];
bool judge(int y){
	int Sqrt = sqrt(y);
	for(int i=2 ; i<Sqrt ; i++)
		if(!(y % i))
			return false;
	return true;
}
int main()
{
	freopen("w.txt","w",stdout);
	cout<<"const bool factorial[] = {";
	memset(vis,false,sizeof vis);
	for(int i=2 ; i<=sqrt(5000000) ; i++)
		if(judge(i)){
			vis[i] = true;
		}
	cout<<vis[0];
	for(int i=1 ; i<= sqrt(5000000) ; i++)
		cout<<","<<vis[i];
	cout<<"};";
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int week[5000];
int n,year,month,day;
int judge(int x){
	if(!(x%4) && x%100 || !(x%400))
		return 2;
	return 1;
}
void solve(){
	week[1900] = 1;
	for(int i=1 ; i<=2000 ; i++){
		int nw = i + 1900;
		week[nw] = (week[nw-1] - judge(nw) + 7000 - 1) % 7 + 1;
	}
//	for(int i=1900 ; i<=1908 ; i++)
//		cout<<week[i]<<"  ";
//	cout<<endl;
//	cout<<"2007"<<week[2007]<<" ";
//	cout<<"2015"<<week[2015]<<" ";
//	cout<<"2014"<<week[2014]<<" ";
//	cout<<"2017"<<week[2017]<<" ";
//	cout<<"2016"<<week[2016]<<" ";
}
int main()
{
	solve();
	int T,sum;
	scanf("%d",&T);
	for(int i=1 ; i<=T ; i++){
		scanf("%d%d-%d-%d",&n,&year,&month,&day);
		printf("Case #%d:\n",i);
		if(month == 12){
			int nw = week[year];
			bool flag1=false,flag2=false;
			if(day < nw)
				flag1 = true;
			if(day > week[year+n])
				flag2 = true;
			if(flag1 && flag2)
				sum = n * 2 + 1;
			else if(!flag1 && !flag2)
				sum = n * 2 - 1;
			else
				sum = n * 2;
		}
		else
			sum = 2 * n;
		printf("%d\n",sum);
	}
	return 0;  
}

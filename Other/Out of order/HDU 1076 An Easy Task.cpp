#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	bool f(int);
	int T;
	scanf("%d",&T);
	while(T --){
		int year,seq;
		scanf("%d%d",&year,&seq);
		if ( f(year) )
			seq --;
		else{
			for( ; !f(year) ; year++)
				;
			seq --;
		}
		while(seq){
			year += 4;
			if( f(year) ){
				seq --;
			}		
		}
		printf("%d\n",year);
	}
    return 0;
}
bool f(int year){
	if ( !(year % 4) && year % 100 || !(year % 400) )
		return true;
	else
		return false;
}

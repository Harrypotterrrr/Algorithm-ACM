#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	double e=0,x=1;
	printf("n e\n");
	printf("- -----------\n");
	for(int i=0 ; i<=9 ; i++){
		if(i > 0)
			x /= i;
		e += x; 
		if(i<3)
			printf("%d %g\n",i,e);
		else
			printf("%d %.9f\n",i,e);
	}
		   
	return 0;
}

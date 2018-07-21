#include <iostream>
using namespace std;
int main()
{
    int n, sum=0,flag=0;
    while(scanf("%d",&n)!=EOF){
        if(n%2==0)
            sum = n/2*(1+n);
        else
            sum = (n+1)/2*n;
        printf("%d\n\n",sum);
    }
    return 0;
}

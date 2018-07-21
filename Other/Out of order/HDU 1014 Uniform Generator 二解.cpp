#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
     return b==0?a:gcd(b,a%b);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%10d%10d    ",a,b);
        printf(gcd(a,b)==1?"Good Choice\n\n":"Bad Choice\n\n");
    }	
    return 0;
}

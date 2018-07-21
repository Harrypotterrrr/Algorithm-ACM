#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,n;
    while(scanf("%d%d%d",&a,&b,&n)==3)
    {
        if(!a&&!b&&!n)
            break;
        int arr[50];
        arr[1]=1;
        arr[2]=1;
        for(int i=3;i<50;i++)
            arr[i]=((a*arr[i-1]+b*arr[i-2])%7);
        printf("%d\n",arr[n%48]);
    }
    return 0;}

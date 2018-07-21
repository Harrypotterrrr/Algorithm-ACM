#include <iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#define N 122000  
  
using namespace std;  
  
int d[N],m,s[7];  
  
void completepack(int c,int w)  
{  
    for(int i=c;i<=m;i++)  
        if(d[i-c]+w>d[i])   d[i]=d[i-c]+w;  
}  
  
void zeroonepack(int c,int w )  
{  
    for(int i=m;i>=c;i--)  
        if(d[i-c]+w>d[i])   d[i]=d[i-c]+w;  
}  
  
void multiplepack(int c,int w,int t)  
{  
    if(t*w>=m)  completepack(c,w);  
    else  
    {  
        int k=1;  
        while(k<t)  
        {  
            zeroonepack(c*k,w*k);  
            t-=k;  
            k<<=1;  
        }  
        zeroonepack(c*t,w*t);  
    }  
}  
  
int main()  
{  
    int kase=0;  
    while(1)  
    {  
        m=0;  
        for(int i=1;i<=6;i++)  
        {  
            scanf("%d",&s[i]);  
            m+=s[i]*i;  
        };  
        if(!m)   break;  
        printf("Collection #%d:\n",++kase);  
        if(m&1)  
        {  
            printf("Can't be divided.\n\n");  
            continue;  
        }  
        m/=2;  
        memset(d,0,sizeof(d));  
        for(int i=1;i<=6;i++)  
            multiplepack(i,i,s[i]);  
        if(d[m]==m) printf("Can be divided.\n\n");  
            else printf("Can't be divided.\n\n");  
    }  
}  

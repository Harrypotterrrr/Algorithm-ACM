#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int k=1 ; k<=n ; k++){
        char A[1000],B[1000];
        int a[1000],b[1000],sum[1001];
        int len_a,len_b,carry=0;
        scanf("%s%s",&A,&B);
//        getchar();
//        gets(A);
//        gets(B);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(sum,0,sizeof(sum));
        len_a = strlen(A);
        len_b = strlen(B);
        for(int i=0 ; i<len_a ; i++)
            a[len_a - 1 - i] = A[i] - '0'; 
        for(int i=0 ; i<len_b ; i++)
            b[len_b - 1 - i] = B[i] - '0'; 
        int len_max = max(len_a , len_b);
        for(int i = 0 ; i<= len_max ; i++){
            sum[i] = (a[i] + b[i] + carry) % 10 ;
            carry = (a[i] + b[i] + carry) / 10;
        }
        if(sum[len_max] == 0)
            len_max--;
        printf("Case %d:\n",k);
        printf("%s",A);
        printf(" + ");
        printf("%s",B);
        printf(" = ");
        for(int i= len_max ; i>=0 ;i--)
            printf("%d",sum[i]);
        if(k!=n)
            printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}

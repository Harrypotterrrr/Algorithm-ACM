#include<cstdio>
#include<cstring>

int main()
{
//    freopen("in.txt","r",stdin);
    char n[1005];
    while(scanf("%s",n) != EOF && n[0] != '0'){
        int sum = 0;
        int length = strlen(n);
        for(int i = 0;i < length; i++){
            sum += n[i] - '0';
        }
        int temp = sum;
        while(temp > 9){
            sum = 0;
            while(temp > 9){
                sum += temp%10;
                temp /= 10;
            }
            sum += temp;
            if(sum > 9)
                temp = sum;
        }
        printf("%d\n",sum);
    }
    return 0;
}

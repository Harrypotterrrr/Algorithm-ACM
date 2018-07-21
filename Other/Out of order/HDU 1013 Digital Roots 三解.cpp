#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[10000];
    while(cin>>str)
    {
        if(strlen(str)==1&&str[0]-'0'==0)
            return 0;
        int sum=0;
        for(int i=0; i<strlen(str); i++)
            sum+=str[i]-'0';
        if(sum%9==0)
            cout<<9<<endl;
        else
            cout<<sum%9<<endl;
    }
    return 0;
}

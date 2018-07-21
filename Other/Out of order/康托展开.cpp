#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int f[10] = {1,1,2,6,24,120,720,5040};
//康托展开逆运算
//康托展开
LL Work(char str[])
{
    int len = strlen(str);
    LL ans = 0;
    for(int i=0; i<len; i++)
    {
        int tmp = 0;
        for(int j=i+1; j<len; j++)
            if(str[j] < str[i]) tmp++;
        ans += tmp * f[len-i-1];
    return ans;
}  
void Work(LL m,LL n)
{
    n--;
    vector<int> v;
    vector<int> a;
    for(int i=1;i<=m;i++)
        v.push_back(i);
    for(int i=m;i>=1;i--)
    {
        LL r = n % f[i-1];
        LL t = n / f[i-1];
        n = r;
        sort(v.begin(),v.end());
        a.push_back(v[t]);
        v.erase(v.begin()+t);
    }
    vector<int>::iterator it;
    for(it = a.begin();it != a.end();it++)
        cout<<*it;
    cout<<endl;
}
int main(){
	int a,b;
	char c[100];
	cin>>c;
	int ans = Work(c);
	cout<<ans<<endl;
	cin>>a>>b;
	Work(a,b);
	return 0;
}
 


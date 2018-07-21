#include<iostream>
#include<string>
using namespace std;
string s1="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; 
string s2;
char a[128];
void Init()
{
        for(int i=1;i<s1.length();i++)
             a[s1[i]]=s1[i-1];
             a[' ']=' ';
}
int main()
{
        Init();
        int i;
        while(getline(cin,s2))
        {
                for(i=0;i<s2.length();i++)
                {
                        cout<<a[s2[i]];
                }
                cout<<endl;
        }
        return 0;
}
/**************************************************************
	Problem: 1093
	User: coder
	Language: C++
	Result: Accepted
	Time:0 ms
	Memory:1520 kb
****************************************************************/

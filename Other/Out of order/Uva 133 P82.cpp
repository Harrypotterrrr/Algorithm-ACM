#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
//	freopen("r.txt","r",stdin);
//	freopen("w.txt","w",stdout);
	int a[100];
	memset(a,1,10);
	int n,A,B;
	cin>>n;
	while(n != -1){
		cin>>A>>B;
		memset(a,1,sizeof(a));
		int A_s = -1;
		int B_s = n;
		int num = n;
		while(true){
			int A_go = A;
			int B_go = B;	
			while(A_go--){
				A_s = (A_s+1) % n;
				if (a[A_s] == 0)
					A_go ++;
				else if(!A_go)
					num --;
			}
			while(B_go--){
				B_s = (B_s-1+100) % n;
				if(!(B_go) && B_s == A_s)
					break;
				else if (a[B_s] == 0)
					B_go ++;
				else if(!B_go)
					num --;				
			}
			a[A_s] = a[B_s] = 0;
			if(A_s==B_s)
				cout<<A_s+1<<" ";
			else
				cout<<A_s+1<<" "<<B_s+1<<" ";
			if(!num)
				break;
		}
	}
	return 0;
}

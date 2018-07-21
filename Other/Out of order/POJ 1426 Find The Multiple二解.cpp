#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
bool jdg(int *p,int t){
	int temp[205],carry = 0;
	for(int i=t ; i>=0 ; i--){
		temp[i] = *(p+i) + carry * 10;
		carry = temp[i] % n;
		temp[i] /= n; 
	}
	if(carry)
		return false;
	return true;
}
int main(){
	while(scanf("%d",&n),n != 0){
		int w = 0;
		bool flag = true;
		int num[205] = {1};
		while(true){
			if(jdg(num,w))
				break;
			flag = true;
			int st = 0;
			while(flag){
				if(num[st] == 1){
					num[st] = 0;
					st ++;
				}
				else{
					num[st] = 1;
					flag = !flag;
				}
			}
			w = w < st ? st : w;
		}
		for(int i=w ; i>=0 ; i--)
			printf("%d",num[i]);
		printf("\n");
	}
	return 0;
}

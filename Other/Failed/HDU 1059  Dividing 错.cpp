#include <iostream>
#include <algorithm> 
#include <stdio.h>
using namespace std;
const char* reply[] = {"Collection #","Can't be divided\
			.","Can be divided."};
int mar[6],n = 0;
bool flag = 0;

bool cmp(int x, int y){ 
	return x > y;
}

void select(int left){
	if(left == 0)
		flag = 1;
	for(int i=1 ; i<=5 ; i++){
		if(mar[i] <= left){
			int temp = mar[i];
			mar[i] = 20001;
			select(left - temp);
			mar[i] = temp;
		} 
	}
}  

int main(){
	while(++n){
		int sum = 0;
		for(int i=0 ; i<=5 ; i++){
			scanf("%d",&mar[i]);
			sum += mar[i];
		}
		if( !sum )
			break;
		else if( sum % 2 )
			flag = 0;
		else{
			sort(mar,mar+6,cmp);
			if(mar[0] > sum / 2){
				flag = 0;
				break;
			}
			else
				select(sum / 2 - mar[0]);
		}
		if(n > 1)
			printf("\n");
		if(!flag)
			printf("%s%d:\n%s\n",reply[0],n,reply[1]);
		else
			printf("%s%d:\n%s\n",reply[0],n,reply[2]);
	}
	return 0;
}

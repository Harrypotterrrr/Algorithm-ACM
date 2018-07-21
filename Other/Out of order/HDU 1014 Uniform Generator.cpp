#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
//	int t[100],step,mod;
//	cin>>step>>mod;
//	cin>>t[0];
//	for(int i=0;;i++){
//		t[i+1]= (t[i] + step) % mod;
//		cout<< t[i+1]<<'\t';
//		if(t[i+1] == 0){
//			cout<<"周期为："<<i+1 ;
//			break;
//		}
//	}
//  模拟计算——互质数
	freopen("r.txt","r",stdin);
	freopen("t.txt","w",stdout);
	int step,mod;
	while(scanf("%d%d",&step,&mod) != EOF){
		int temp_mod = mod;
		int temp_step = step;
		while(true){
			if(mod == 0 && step == 1){
				printf("%10d%10d    Good Choice\n\n",temp_step,temp_mod);
				break;
			}
			if(mod == 0 && step > 1){
				printf("%10d%10d    Bad Choice\n\n",temp_step,temp_mod);
				break;
			}
			int temp = mod;
			mod = step % mod;
			step = temp;
		}
	}
	return 0;
}

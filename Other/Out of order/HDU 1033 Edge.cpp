#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char str[10000];
	int flag,x,y;
	while(gets(str) != NULL){
		flag = 2;
		x = 310,y = 420;
		printf("300 420 moveto\n310 420 lineto\n");
		int l = strlen(str);
		for(int i=0 ; i<l ; i++){
			if(str[i] == 'V')
				flag = (flag + 1) % 4 + 1;
			switch(flag){
				case(1): x += 10;flag = 2;break;
				case(2): y -= 10;flag = 3;break;
				case(3): x -= 10;flag = 4;break;
				default: y += 10;flag = 1;
			}
			printf("%d %d lineto\n",x,y);
		}
		printf("stroke\nshowpage\n");
		memset(str,'\0',sizeof str);
	}
}

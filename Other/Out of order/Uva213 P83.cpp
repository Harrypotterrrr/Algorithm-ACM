#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int code[1<<10][1<<10];

int readchar(){
	while(true){
		int s = getchar();
		if(s != '\n' && s!= '\r')
			return s;
	}
}

int readint(int x){
	int y = 0;
	while(x--)
		y = 2 * y + readchar() - '0';
	return y;
}

int readcode(){
	memset(code,0,sizeof(code));
	code[1][0] = readchar();
	for(int i=2 ; ; i++)
		for(int j=0 ; j < (1<<i)-1 ; j++){
			int chr = getchar();
			if(chr == EOF)
				return 0;
			else if(chr == '\n' || chr == '\r')
				return 1;
			code[i][j] = chr;
		}
}

int main(){
	while(readcode()){
		while(true){
			int len = readint(3);
			if(len == 0)
				break;
			while(true){
				int w = readint(len);
				if(w == (1<<len) - 1)
					break;
				putchar(code[len][w]);
			}
		}
		putchar('\n');
	}
	return 0;
}

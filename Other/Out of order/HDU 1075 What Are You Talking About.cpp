#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int main()
{
	map<string,string>dic;
	string a,b;
	cin>>a;
	while(cin>>a &&a != "END"){
		cin>>b;
		dic[b] = a;
	}
	cin>>a;
	getchar();
	char str[1002];
	while(gets(str)){
		if(strcmp(str,"END") == 0)
			break;
		a = "";
		for(int i=0 ; i<strlen(str) ; i++){
			if(str[i] >= 'a' && str[i] <= 'z')
			 	a += str[i];
			else if(a == "")
				printf("%c",str[i]);
			else{
				if(dic[a] == "")
					printf("%s",a.c_str());
				else
					printf("%s",dic[a].c_str());
				a = "";
				printf("%c",str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

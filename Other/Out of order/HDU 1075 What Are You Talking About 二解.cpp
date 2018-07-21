#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
	char start[11],marti[11],c;
	char earth[1000][11],mars[1000][11];
	int i,j=-1;
	scanf("%s",&start);
	for(i=0 ; i<1000 ; i++){
		scanf("%s",&earth[i]);
		if(strcmp(earth[i] ,"END") == 0)
			break;
		scanf("%s",&mars[i]);
	}
	
	scanf("%s",&start);
	getchar();
	memset(marti,'\0',sizeof(marti));

	while(true){
		c = getchar();
		if(c == 'E' || c == 'N'\
		|| c == 'D' )
			marti[++j] = c;
		else if(c < 97 || c > 122){
			if(strcmp(marti , "END") == 0)
				break;
			for(int k=0 ; k<=i-1 ; k++){
				if(marti[0] == '\0')
					break;
				if(strcmp( marti , mars[k]) == 0){
					printf("%s",earth[k]);
					break;
				}
				else if(k == i-1)
					printf("%s",marti);
			}
			printf("%c",c);
			memset(marti,'\0',sizeof(marti));
			j = -1;
		}
		else
			marti[++j] = c;
	}
	return 0;
}

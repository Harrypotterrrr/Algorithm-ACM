#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int s1[1024],s2[1024],Sum[1024];
	int T,len_s1,len_s2,len_S,j=1,k=1;
	char S1[1024],S2[1024];
	scanf("%d",&T);
	while(T--){
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(Sum,0,sizeof(Sum));
		scanf("%s%s",&S1,&S2);
		len_s1 = strlen(S1);
		len_s2 = strlen(S2);
		for(int i=0 ; i<=len_s1-1 ; i++)
			s1[len_s1-i-1] = S1[i] - '0';
		for(int i=0 ; i<=len_s2-1 ; i++)
			s2[len_s2-i-1] = S2[i] - '0';
		len_S = max(len_s1,len_s2);
		int carry=0;
		for(int i=0 ; i<=len_S ; i++){
			Sum[i] = s1[i] + s2[i] + carry;
			carry = Sum[i] / 10;
			Sum[i] %= 10;
		}
		if(Sum[len_S] != 0)
			len_S ++;
		if( j-- == 1 )
			printf("Case %d:\n%s + %s = ",k++,S1,S2);
		else
			printf("\nCase %d:\n%s + %s = ",k++,S1,S2);
		for(int i=len_S-1 ; i>=0 ; i--)
			printf("%d",Sum[i]);
		printf("\n");
	}
	return 0;
} 

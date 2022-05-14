#include<stdio.h>

#define moji 1000

int main(void)
{
	int i,j;
	
	char s[moji][128];
	
	for(i=0;i<moji;i++){
		printf("s[%d] : ",i);
		scanf("%s",s[i]);
		
		for(j=0;s[i][j]!='\0';j++){
            if(s[i][j]!='$') break;
		}
		if(j==5)
		break;
	}
	
	for(j=0;j<i;j++){
		printf("s[%d]=\"%s\"\n",j,s[j]);
		
	}
	
	return 0;
}
		
#include<stdio.h>

void delete_number(char string[])
{
	int i,j;
	
	for(i=0;string[i]!='\0';i++){
        if('0'<=string[i]&&string[i]<='9'){
            for(j=i;string[j]!='\0';j++){
                string[j]=string[j+1];
            }
			i++;
        }
	}
}

int main(void)
{
	char string[256];
	
	printf("•¶Žš—ñ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
	scanf("%s",string);
	
	delete_number(string);
	
	printf("íœ‚ªŠ®—¹‚µ‚Ü‚µ‚½\n\"%s\"\n‚Å‚·", string);
	
	return 0;
	
}
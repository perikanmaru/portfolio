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
	
	printf("���������͂��Ă��������B\n");
	scanf("%s",string);
	
	delete_number(string);
	
	printf("�폜���������܂���\n\"%s\"\n�ł�", string);
	
	return 0;
	
}
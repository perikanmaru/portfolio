#include<stdio.h>

char str_copy(char ptr2[128],char tmp2[128])
{
	int i;
	for(i=0;tmp2[i]!='\0';i++){
		ptr2[i]=tmp2[i];
	}
}
int main(void)
{
	char ptr[128]="ABC";
	char tmp[128]={0};
	
	printf("str=%s\n",ptr);
	
	printf("�R�s�[���镶������͂��Ă��������B\n",tmp);
	scanf("%s",tmp);
	
	str_copy(ptr,tmp);
	
	puts("�R�s�[���������܂����B");
	printf("%s\n",ptr);
	
	return 0;
}
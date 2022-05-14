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
	
	printf("コピーする文字を入力してください。\n",tmp);
	scanf("%s",tmp);
	
	str_copy(ptr,tmp);
	
	puts("コピーが完了しました。");
	printf("%s\n",ptr);
	
	return 0;
}
#include<stdio.h>

void adjust_point(int *n)
{
	if(*n>100)
	*n=100;
	else
	if(*n<0)
	*n=0;
	printf("更新しました。値は%dです。",*n);
}

int main(void)
{
	int k;
	
	printf("整数を入力してください。\n");
	scanf("%d",&k);
	if(k>100||k<0)
	adjust_point(&k);
	else
	printf("更新しませんでした。値は%dです。\n",k);
	
	return 0;
}

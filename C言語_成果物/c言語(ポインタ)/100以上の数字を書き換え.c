#include<stdio.h>

void adjust_point(int *n)
{
	if(*n>100)
	*n=100;
	else
	if(*n<0)
	*n=0;
	printf("�X�V���܂����B�l��%d�ł��B",*n);
}

int main(void)
{
	int k;
	
	printf("��������͂��Ă��������B\n");
	scanf("%d",&k);
	if(k>100||k<0)
	adjust_point(&k);
	else
	printf("�X�V���܂���ł����B�l��%d�ł��B\n",k);
	
	return 0;
}

#include<stdio.h>

#define sanjyou(x) ((x)*(x)*(x))
 

int main(void)
{
	double n;
	
	printf("��������͂��Ă��������B\n");
	scanf("%lf",&n);
	printf("���̐���3���\n%f\n�ł��B",sanjyou(n));
	
	return 0;
}
#include<stdio.h>

#define sanjyou(x) ((x)*(x)*(x))
 

int main(void)
{
	double n;
	
	printf("実数を入力してください。\n");
	scanf("%lf",&n);
	printf("その数の3乗は\n%f\nです。",sanjyou(n));
	
	return 0;
}
#include<stdio.h>

int main(void)
{
	int n;
	int k;
	int j;
	k=1;
	
	printf("整数を入力してください。\n");
	scanf("%d",&n);
	
	if(n>0){
	
	for(j=1;j<=n;j++){
		k=k*j;
	}
	printf("%d",k);
	}
	else
	printf("不正な値が入力されました。正の整数を入力してください。\n");
	
	return 0;
}
#include<stdio.h>

void swap(int *n,int *k)
{
	int temp=*n;
	*n=*k;
	*k=temp;
}

void sort(int *n1,int *n2,int *n3)
{
	if(*n1>*n2)
	;
	else
	swap(n1,n2);
	
	if(*n1>*n3)
	;
	else
	swap(n1,n3);
	
	if(*n2>*n3)
	;
	else
	swap(n2,n3);
}

int main(void)
{
	int a,b,c;
	
	printf("整数を入力してください。\n");
	printf("1つめ　"); scanf("%d",&a);
	printf("2つめ　"); scanf("%d",&b);
	printf("3つめ　"); scanf("%d",&c);
	
	sort(&a,&b,&c);
	
	printf("並び替えが完了しました。\n");
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	
	return 0;
}


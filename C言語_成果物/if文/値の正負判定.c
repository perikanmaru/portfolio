#include<stdio.h>

int main(void)
{
	int n;
	int k;
	int j;
	k=1;
	
	printf("��������͂��Ă��������B\n");
	scanf("%d",&n);
	
	if(n>0){
	
	for(j=1;j<=n;j++){
		k=k*j;
	}
	printf("%d",k);
	}
	else
	printf("�s���Ȓl�����͂���܂����B���̐�������͂��Ă��������B\n");
	
	return 0;
}
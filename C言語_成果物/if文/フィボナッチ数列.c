#include<stdio.h>

int fibo(int n){
	
	int count=0;
	
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	if(n>=2){
		count++;
		return fibo(n-1)+fibo(n-2);
	}
}

int main(void){
	int count=0;
	int k;
	printf("���̐�������͂��Ă��������B\n");
	scanf("%d",&k);
	if(k<=0)
	printf("1�ȏ�̐�������͂��Ă��������B");
	else
	printf("��%d���̃t�B�{�i�b�`�����%d�ł��B\n",k,fibo(k));

	
	return 0;
}
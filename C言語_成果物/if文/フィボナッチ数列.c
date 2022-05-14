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
	printf("正の整数を入力してください。\n");
	scanf("%d",&k);
	if(k<=0)
	printf("1以上の整数を入力してください。");
	else
	printf("第%d項のフィボナッチ数列は%dです。\n",k,fibo(k));

	
	return 0;
}
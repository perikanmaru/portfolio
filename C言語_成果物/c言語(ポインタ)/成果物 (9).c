#include<time.h>
#include<stdio.h>
#include<string.h>

int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (100.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

 void bput(char *ap,int k){
 	int i,j;
	
	for(i=0;i<k;i++){
	printf("%s",ap);
	sleep(50);
	printf("\r");
	
	for(j=0;j<5;j++){
		printf(" ");
	}
	
	sleep(50);
	printf("\r");
	}
 }

int main(void) {
	int k;
	k=10;
	char *ap = "abcde";

	bput(ap,k);

	return 0;
	
}
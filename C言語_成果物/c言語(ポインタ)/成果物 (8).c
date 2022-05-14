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

 void gput(char *ap){
	int i;
		for (;*ap!='\0';ap++) {
			putchar(*ap);
			fflush(stdout);
			sleep(100);
		}

}

int main(void) {
	char *ap = "abcde";

	gput(ap);

	return 0;
	
}
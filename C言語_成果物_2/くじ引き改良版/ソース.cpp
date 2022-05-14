#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int kuji;
	int retry;

		srand((unsigned int)time(NULL));

		do {
			kuji = rand() % 199;
			
			if (kuji < 1)
				printf("おめでとうございます！1等です。\n");
			else if (kuji < 5)
				printf("おめでとうございます！2等です。\n");
			else if (kuji < 21)
				printf("おめでとうございます！3等です。\n");
			else
				printf("はずれです。\n");
			printf("もう一度引きますか？\n");
			scanf("%d", &retry);
		} while (retry != 0);
		return 0;

}
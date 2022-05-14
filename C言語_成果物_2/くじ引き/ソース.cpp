#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, k;
	int kuji;
	int retry;
	int atari_1[1];
	int atari_2[4];
	int atari_3[15];

	srand((unsigned int)time(NULL));

	for (i = 0; i < 1; i++) {
		atari_1[i] = rand() % 199;
	}

	for (j = 0; j < 4; j++) {
		atari_2[j] = rand() % 199;
	}

	for (k = 0; j < 15; j++) {
		atari_3[k] = rand() % 199;
	}

	do {
		kuji = rand();
		if (atari_3[14] == kuji)
			printf("おめでとうございます！3等が当たりました！！\n");
		else if (atari_2[3] == kuji)
			printf("おめでとうございます！２等が当たりました。\n");
		printf("もう一度しますか？\n");
		scanf("%d", &retry);
	} while (retry != 1);

	return 0;
}
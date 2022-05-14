#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE	10      /* ステージ数 */

/*--- xミリ秒経過するのを待つ ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int i, stage;
	                                
	int k = 0;						/*逆向き用変数*/
	char a[4 * 2];

	int success = 0;		         /* 正解数 */
	clock_t start, end;		         /* 開始時刻・終了時刻 */

	srand(time(NULL));		         /* 乱数の種を設定 */

	printf("数値記憶トレーニング\n");

	
	printf("4桁の数値を記憶しましょう。\n");
	printf("数値を逆向きに入力してください\n");
	                            
	start = clock();				/*計測開始*/

	for (stage = 0; stage < MAX_STAGE; stage++) {

		char no[4 + 1];				/* 乱数の並び */
		char x[4 * 2];				/* 読みこむ数字の並び(プレイヤー入力) */

		no[0] = '1' + rand() % 9;			/* 先頭文字は'1'～'9' */

		for (i = 1; i < 4; i++)
			no[i] = '0' + rand() % 10;		/* それ以降は'0'～'9' */

		no[4] = '\0';

		printf("%s", no);
		fflush(stdout);
		sleep(2000);					/* 問題提示は1500ミリ秒 */

		printf("\r入力せよ：");
		scanf("%s", x);

		for (k = 0; k < 4; k++) {         /*配列を逆向きにする。(プレイヤーは逆向きに入力しているはずなので逆向きにすれば配列の並びが同じになる。)*/
			a[k] = x[3 - k];
		}

		a[4] = '\0';                    /*逆にした配列の最後はナル文字*/


		if (strcmp(no,a)==0) {			/*正誤判定*/
			printf("正解です。\n");
			success++;
		}
		else
			printf("間違いです。\n");

	}

	end = clock();						/*計測終了*/

	printf("%d回中%d回成功しました。\n", MAX_STAGE, success);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

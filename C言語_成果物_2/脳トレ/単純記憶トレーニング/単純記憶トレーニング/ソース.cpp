#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE	10							/* ステージ数 */

/*--- xミリ秒経過するのを待つ ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* エラー */
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int stage;
	int success = 0;						/* 正解数 */
	clock_t start, end;				

	int k, L;									/*答え合わせ用変数*/
	int correct = 0;
	srand(time(NULL));						/* 乱数の種を設定 */

	printf("４桁の数値を記憶しましょう。\n");
	printf("逆向きに入力してください。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {

		int o, p, q, r = 0;						/*入力用変数*/

		int a, b, c, d = 0;						/*四桁の乱数生成 (a>1)*/
		a =1+rand() % 9;
		b =0+rand() % 10;
		c =0+rand() % 10;
		d =0+rand() % 10;



		printf("%d%d%d%d",a,b,c,d);
		fflush(stdout);
		sleep(2000);

		printf("\r入力せよ：");
		fflush(stdout);
		scanf("%d", &o);
		scanf("%d", &p);
		scanf("%d", &q);
		scanf("%d", &r);

		for (k = 0; k < 4; k++) {
			switch (k)			/*数字の正誤判定*/
			{
			case 0:
				if (o != d) {
					correct = 0;
					break;
				}
				else
					correct++;
				break;
			case 1:
				if (p != c) {
					correct = 0;
					break;
				}
				else
					correct++;
				break;
			case 2:
				if (q != b) {
					correct = 0;
					break;
				}
				else
					correct++;
				break;
			case 3:
				if (r != a) {
					correct = 0;
					break;
				}
				else
					correct++;
					break;
			default:
				break;
			}

		}
		
		if (correct == 4) {
			printf("正解です！\n");
			success++;
			correct = 0;
		}
		else {
			printf("間違いです\n");
			correct = 0;
		}

	}
	end = clock();

	printf("%d回中%d回成功しました。\n", MAX_STAGE, success);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

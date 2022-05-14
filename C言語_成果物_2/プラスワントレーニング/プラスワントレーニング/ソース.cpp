#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define LEVEL_MIN	2				/* 最小レベル（数値の個数）*/
#define LEVEL_MAX	6				/* 最大レベル（数値の個数）*/

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
	int i, stage;
	int max_stage;					/* ステージ数 */
	int level;						/* レベル */
	int success;					/* 正解数 */
	int* score;						/* 全ステージの正解数 */
	int k = 0;
	int n;
	int l = 0;
	int j = 0;
	clock_t	start, end;					/* 開始時刻・終了時刻 */

	srand(time(NULL));					/* 乱数の種を設定 */

	printf("プラスワントレーニング開始!!\n");
	printf("２桁の数値を記憶します。\n");
	printf("１を加えた値を入力してください。\n");

	do {
		printf("挑戦するレベル（%d～%d）：", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	do {
		printf("トレーニング回数：");
		scanf("%d", &max_stage);
	} while (max_stage <= 0);

	score = (int*)calloc(max_stage, sizeof(int));

	success = 0;
	start = clock();

	for (stage = 0; stage < max_stage; stage++) {
		int no[LEVEL_MAX];					/* 記憶する数 */
		int x[LEVEL_MAX];					/* 読み込んだ値 */
		int seikai = 0;						/* このステージでの正解数 */
		int backup[LEVEL_MAX];					

		printf("\n第%dステージ開始!!\n", stage + 1);

		for (i = 0; i < level; i++) {		/* level個だけ */
			no[i] = rand() % 90 + 9;		/* 10～98の乱数を生成して */
			printf("%d ", no[i]);			/* 表示する */
		}

		fflush(stdout);
		sleep(300 * level);					/* 0.30×level秒待って */
		printf("\r%*s\r", 3 * level, "");	/* 問題を消す */
		fflush(stdout);

		switch (l)
		{
		case 0:
			for (i = 0; i < stage; i++) {		/* 1回目の解答を読み込む */
				printf("%d番目の数：", i + 1);
				scanf("%d", &x[i]);
			}
			l = 1;
			k = 1;
			break;

		case 1:
			for (; i < stage; i++) {				/*2回目以降の回答を読み込む*/
				printf("最後の回答に-1を入力するとひとつ前の問題に戻ることができます。\n");
				printf("%d番目の数字 : ", i + 1);
				scanf("%d", &x[i]);
			}
			k = x[i];							/*スイッチ用の変数に代入*/
			break;
		}

			switch (k)
			{
			case -1:

				for (i = 0; i < level; i++) {		/* level個だけ */
					printf("%d ",backup[i] );			/* 表示する */
				}
				fflush(stdout);
				sleep(300 * level);					/* 0.30×level秒待って */
				printf("\r%*s\r", 3 * level, "");	/* 問題を消す */
				fflush(stdout);

				for (n = 0; n < stage; n++) {		/*回答を読み込む。*/
					scanf("%d", &x[i]);
				}

				for (; i < level; ) {		/* 正誤を判定・表示 */
					if (x[i] != backup[i] + 1)
						printf("× ");
					else {
						printf("○ ");
						seikai++;
					}
				}
				putchar('\n');

				for (i = 0; i < level; i++)			/* 正解を表示 */
					printf("%2d ", backup[i]+1);

				printf(" … %d個正解です。\n", seikai);
				score[stage - 1] = seikai;				/*1つ前のステージの正解数を記録 */
				success += seikai;					/* 全体の正解数を更新 */
				break;

			default:
				for (i = 0; i < level; i++) {		/* 正誤を判定・表示 */
					if (x[i] != no[i] + 1)
						printf("× ");
					else {
						printf("○ ");
						seikai++;
					}
				}
				putchar('\n');

				for (i = 0; i < level; i++)			/* 正解を表示 */
					printf("%2d ", no[i]);

				printf(" … %d個正解です。\n", seikai);
				score[stage] = seikai;				/* ステージの正解数を記録 */
				success += seikai;					/* 全体の正解数を更新 */
				break;
			}
	}
	end = clock();

	printf("%d個中%d個正解しました。\n", level * max_stage, success);

	for (stage = 0; stage < max_stage; stage++)
		printf("第%2dステージ：%d\n", stage + 1, score[stage]);

	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	free(score);

	return 0;
}

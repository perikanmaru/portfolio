#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	

static void init_getputch(void) { /* 空 */ }

static void term_getputch(void) { /* 空 */ }


#define MAX_STAGE	5			/* 挑戦回数 */
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	int i, j, stage;
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8];
	double jikan;				/* 時間 */
	clock_t start, end;			/* 開始時刻・終了時刻 */

	srand(time(NULL));			/* 乱数の種を設定 */

	printf("欠けている数字を入力してください。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* 0～8の乱数を生成 */
		int no = 10;					/* 読み込んだ値 */
		int k = 0;
		int n = 0;
		i = j = 0;
		while (i < 9) {			/* dgt[x]を飛ばしてコピー */
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {			/* 配列aをシャッフル */
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++) {		/* 全要素を表示 */
			k = rand() % 4;

				switch (k)
				{
				case 0:
					for (n = 0; n < 3; n++) {
						printf("   ");
					}
					printf("%d", a[i]);
					break;
				case 1:
					printf("%d",a[i]);
					break;
				case 2:
					for (n = 0; n < 5; n++) {
						printf(" ");
					}
					printf("%d", a[i]);
					break;
				case 3:
					for (n = 0; n < 1; n++) {
						printf("  ");
					}
					printf("%d", a[i]);
					break;
				default:
					printf("%d",a[i]);
					break;
				}

				if (i == 2)
					printf("\n");
				else if (i == 5)
					printf("\n");
				else if (i == 7)
					printf("\n");
		}
		printf("\n : ");
		do {
			no = getch();
			putch(no);
			printf("\n");	/* 改行 */
		} while (no != dgt[x] + 48);		/* 正解が入力されるまで繰り返すnoが＋48されてるので48をdgxに足す*/
		printf("\n");
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0)
		printf("鈍すぎます。\n");
	else if (jikan > 20.0)
		printf("少し鈍いですね。\n");
	else if (jikan > 17.0)
		printf("まあまあですね。\n");
	else
		printf("素早いですね。\n");

	return 0;
}
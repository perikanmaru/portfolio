#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	CNO		4		/* 選択肢の数 */

#define swap(type, x, y)   do { type t = x; x = y; y = t; } while (0)

int	QNO;				/* 単語の数 */
char** jptr;			/* 日本語単語へのポインタの配列 */
char** eptr;			/* 英　語単語へのポインタの配列 */

/*--- 選択肢を表示 ---*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d) %s  ", i, sw ? jptr[c[i]] : eptr[c[i]]);
	printf("：");
}

/*--- 選択肢を生成して正解の添字を返す ---*/
int make_cand(int c[], int n)
{
	int i, j, x;

	c[0] = n;						/* 先頭要素に正解を入れる */

	for (i = 1; i < CNO; i++) {
		do {						/* 重複しないように乱数を生成 */
			x = rand() % QNO;
			for (j = 0; j < i; j++)
				if (c[j] == x)		/* 既に同じ乱数が生成ずみ */
					break;
		} while (i != j);
		c[i] = x;
	}

	j = rand() % CNO;
	if (j != 0)
		swap(int, c[0], c[j]);	/* 正解を移動 */

	return j;
}

/*--- 単語を読み込む ---*/
int read_tango(void)
{
	int	i = 0;
	FILE* fp;

	if ((fp = fopen("TANGO", "r")) == NULL) return 1;

	fscanf(fp, "%d", &QNO);			/* 単語数を読み込む */

	if ((jptr = (char **)calloc(QNO, sizeof(char*))) == NULL) return -1;
	if ((eptr = (char **)calloc(QNO, sizeof(char*))) == NULL) return -1;

	for (i = 0; i < QNO; i++) {
		char etemp[1024];
		char jtemp[1024];

		fscanf(fp, "%s%s", etemp, jtemp);
		if ((eptr[i] = (char *)malloc(strlen(etemp) + 1)) == NULL) return i;
		if ((jptr[i] = (char *)malloc(strlen(jtemp) + 1)) == NULL) return i;
		strcpy(eptr[i], etemp);
		strcpy(jptr[i], jtemp);
	}
	fclose(fp);

	return 0;/*成功時は0を返す*/
}

int main(void)
{
	int i;
	int j;
	int nq, pq;			/* 問題番号・前回の問題番号 */
	int na;				/* 正解の番号 */
	int sw;				/* 問題の言語（0：日本語／1：英語） */
	int retry;			/* 再挑戦するか？ */
	int cand[CNO];		/* 選択肢の番号 */
	int clean = 0;		/*メモリ解放用変数*/
	int k = 0;
	
		k = read_tango();

		switch (k)
		{
		case 0:/*ファイルの読み込みに成功*/
			break;
		case 1:
			/*そもそもファイルが開けなかった場合の処理*/
			printf("\a単語ファイルの読込みに失敗しました。\n");
			return 1;
			break;
		case -1:
			/*メモリ(領域)の確保ができなかった場合*/
			printf("\a単語ファイルの読込みに失敗しました。\n");
			return 1;
			break;
		default:
			/*メモリ(領域)の確保はできたが文字列のメモリ(領域)の確保が失敗した場合*/
			printf("\a単語ファイルの読込みに失敗しました。\n単語学習ソフトを終了します...");
			for (clean = 0; clean < k; clean++) {
				free(eptr[i]);
				free(jptr[i]);
			}
			free(eptr);
			free(jptr);
			return 1;
			break;
		}

	srand(time(NULL));	/* 乱数の種を設定 */

	pq = QNO;			/* 前回の問題番号（存在しない番号） */

	do {
		int no;

		do {						/* 出題する単語の番号を決定 */
			nq = rand() % QNO;
		} while (nq == pq);			/* 同じ単語を連続して出題しない */

		na = make_cand(cand, nq);	/* 選択肢を生成 */
		sw = rand() % 2;

		printf("%sはどれですか？\n", sw ? eptr[nq] : jptr[nq]);

		do {
			print_cand(cand, sw);	/* 選択肢を表示 */
			scanf("%d", &no);
			if (no != na)
				puts("違います。");
		} while (no != na);
		puts("正解です。");

		pq = nq;

		printf("もう一度？ 0-いいえ／1-はい：");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < QNO; i++) {
		free(eptr[i]);
		free(jptr[i]);
	}
	free(jptr);
	free(eptr);

	return 0;
}

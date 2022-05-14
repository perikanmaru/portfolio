#include <time.h>
#include <float.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	

static void init_getputch(void) { /* 空 */ }

static void term_getputch(void) { /* 空 */ }
#define MAX_STAGE	10
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

char dtfile[] = "LACKNUM.txt";				/* ファイル名最後にした日時とベスト10のスコア記録用 */
char dtfile_time[] = "TIME_RECORD.txt";		/*過去10回を記録する用*/

/*--- 前回のトレーニング情報を取得・表示して最高得点を返す ---*/
double get_data(void)
{
	FILE* fp;
	double best;		/* 最高得点 */
	double best_2;

	if ((fp = fopen(dtfile, "r")) == NULL) {
		printf("本プログラムを実行するのは初めてですね。\n\n");
		best = DBL_MAX;
	}
	else {
		int year, month, day, h, m, s;

		fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
		fscanf(fp, "%lf", &best);
		fscanf(fp, "%lf", &best_2);

		printf("前回の終了は%d年%d月%d日%d時%d分%d秒でした。\n\n",year, month, day, h, m, s);

		printf("これまでの最高得点（最短所要時間）は%.1f秒です。\n", best);
		fclose(fp);
	}

	return best;
}
/*１０回目の記録がされた後ファイルを削除してリセット*/
int time_record_reset(void) {
	
	if (remove("TIME_RECORD.txt") == 0) {
		puts("ファイルの削除に成功");
	}
	else {
			puts("ファイルの削除に失敗");
	}
	return 0;

}
/*過去10回の実行日時を記録する*/
double time_record( double score) {

	FILE* fp2;
	time_t t = time(NULL);
	struct tm* local = localtime(&t);

	int year, month, day, h, m, s;
	int k = 0;
	int i = 0;
	int c = 0;

	if ((fp2 = fopen(dtfile_time, "a+")) == NULL) {
		printf("10回までの履歴を保存するファイルを作成しました。　次回から保存が開始されます\n");

	}else {

		while (fgets(dtfile_time,256, fp2) != NULL) {
			fscanf(fp2, "%d",&k);
			k++;
		}

		if (k < 10) {
			fprintf(fp2, "%d回目 %d %d %d %d %d %d %.1f秒かかりました。\n",
				k, local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
				local->tm_hour, local->tm_min, local->tm_sec,score);

		}
		else {

			fclose(fp2);
			return -1;
		}
		fclose(fp2);
	}
	return 0;
}

/*過去の点数(時間)の所得*/
double get_result(int n) {
	FILE* fp;

	double best = 1000;
	double best_2 = 1000;
	double best_3 = 1000;
	double best_4 = 1000;
	double best_5 = 1000;
	double best_6 = 1000;
	double best_7 = 1000;
	double best_8 = 1000;
	double best_9 = 1000;
	double best_10 = 1000;

	if ((fp = fopen(dtfile, "r")) == NULL) {
		fclose(fp);
		return 1000;
	}
	else {
		int year, month, day, h, m, s;

		fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);

		fscanf(fp, "%lf", &best);
		fscanf(fp, "%lf", &best_2);
		fscanf(fp, "%lf", &best_3);
		fscanf(fp, "%lf", &best_4);
		fscanf(fp, "%lf", &best_5);
		fscanf(fp, "%lf", &best_6);
		fscanf(fp, "%lf", &best_7);
		fscanf(fp, "%lf", &best_8);
		fscanf(fp, "%lf", &best_9);
		fscanf(fp, "%lf", &best_10);
		fclose(fp);
	}
	switch (n)
	{
	case 0:
		return best_2;
		break;
	case 1:
		return best_3;
		break;
	case 2:
		return best_4;
		break;
	case 3:
		return best_5;
		break;
	case 4:
		return best_6;
		break;
	case 5:
		return best_7;
		break;
	case 6:
		return best_8;
		break;
	case 7:
		return best_9;
		break;
	case 8:
		return best_10;
		break;
	default:
		return 0;
	break;
	}

}

/*--- 今回のトレーニング情報を書き込む ---*/
void put_data(double best, double best_2, double best_3, double best_4, double best_5, double best_6, double best_7, double best_8, double best_9, double best_10)
{
	FILE* fp;
	time_t t = time(NULL);
	struct tm* local = localtime(&t);

	if ((fp = fopen(dtfile, "w+")) == NULL)
		printf("エラー発生!!");
	else {
		fprintf(fp, "%d %d %d %d %d %d\n",
			local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
			local->tm_hour, local->tm_min, local->tm_sec);

		fprintf(fp, "%f\n", best);
		fprintf(fp, "%f\n", best_2);
		fprintf(fp, "%f\n", best_3);
		fprintf(fp, "%f\n", best_4);
		fprintf(fp, "%f\n", best_5);
		fprintf(fp, "%f\n", best_6);
		fprintf(fp, "%f\n", best_7);
		fprintf(fp, "%f\n", best_8);
		fprintf(fp, "%f\n", best_9);
		fprintf(fp, "%f\n", best_10);

		fclose(fp);
	}
}

/*--- トレーニングを実行して得点（所要時間）を返す ---*/
double go(void)
{
	int i, j, stage;
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8];
	double jikan;				/* 時間 */
	clock_t start, end;			/* 開始時刻・終了時刻 */

	printf("欠けている数字を入力してください。\n");
	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* 0～8の乱数を生成 */
		int	no;					/* 読み込んだ値 */

		i = j = 0;
		while (i < 9) {			/* dgt[x]を飛ばしてコピー */
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {		/* 配列aをシャッフル */
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++)		/* 全要素を表示 */
			printf("%d ", a[i]);
		printf("：");
		fflush(stdout);

		do {
			no = getch();
			if (isprint(no)) {				/* 表示可能であれば */
				putch(no);					/* 押されたキーを表示 */
				if (no != dgt[x] + '0')		/* 正解でなければ */
					putch('\b');			/* カーソルを一つ戻す */
				else
					printf("\n");			/* 改行 */
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
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

	return jikan;
}

int main(void)
{
	int retry;		/* もう一度？ */
	double score;	/* 得点（所要時間） */
	double best;	/* 最高得点（最短所要時間）*/
	double best_2;
	double best_3;
	double best_4;
	double best_5;
	double best_6;
	double best_7;
	double best_8;
	double best_9;
	double best_10;
	double recored;

	best = get_data();			/* 前回までの最高得点を得る */
	best_2 = get_result(0);		/*10までの成績を読み込む初期値は1000*/
	best_3 = get_result(1);
	best_4 = get_result(2);
	best_5 = get_result(3);
	best_6 = get_result(4);
	best_7 = get_result(5);
	best_8 = get_result(6);
	best_9 = get_result(7);
	best_10 = get_result(8);

	init_getputch();
	srand(time(NULL));			/* 乱数の種を設定 */

	do {
		score = go();			/* トレーニング実行 トレーニングにかかった時間がscoreに代入される*/

			if (score < best) {
				printf("最高得点（所要時間）を更新しました!!\n");
				best = score;		/* 最高得点更新 */
			}
			else if (best < best_2 && score < best_2) {
				best_2 = score;
				
			}
			else if (best_2 < best_3 && score < best_3) {
				best_3 = score;
				
			}
			else if (best_3 < best_4 && score < best_4)
			{
				best_4 = score;
				
			}
			else if (best_4 < best_5 && score < best_5)
			{
				best_5 = score;
				
			}
			else if (best_5 < best_6 && score < best_6)
			{
				best_6 = score;
				
			}
			else  if (best_6 < best_7 && score < best_7) {
				best_7 = score;
				
			}
			else if (best_7 < best_8 && score < best_8)
			{
				best_8 = score;
				
			}
			else if (best_8 < best_9 && score < best_9)
			{
				best_9 = score;
				
			}
			else if (best_9 < best_10 && score < best_10)
			{
				best_10 = score;
				
			}
			else
				;

			recored = time_record(score);
			if (recored == -1) {
				time_record_reset();
			}

		printf("もう一度しますか … (0)いいえ (1)はい：");
		scanf("%d", &retry);

	} while (retry == 1);



	put_data(best,best_2,best_3,best_4,best_5,best_6,best_7,best_8,best_9,best_10);				/* 今回の日付・時刻・得点を書き込む */

	term_getputch();

	return 0;

}
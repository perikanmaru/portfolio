#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- 各月の日数 ---*/
int mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/*--- year年month月day日の曜日を求める ---*/
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}

/*--- year年は閏年か？（0…平年／1…閏年） ---*/
int is_leap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- year年month月の日数（28～31） ---*/
int monthdays(int year, int month)
{
	if (month-- != 2)						/* monthが２月でないとき */
		return mday[month];
	return mday[month] + is_leap(year);		/* monthが２月であるとき */
}

/*--- y年m月のカレンダーを２次元配列sに格納 ---*/
void make_calendar(int y, int m, char s[7][22])
{
	int i, k;
	int wd = dayofweek(y, m, 1);		/* y年m月1日の曜日 */
	int mdays = monthdays(y, m);		/* y年m月の日数 */
	char tmp[4];
	int a = 0;

	sprintf(s[0], "%10d / %02d      ", y, m);	/* タイトル（年／月） */

	for (k = 1; k < 7; k++)				/* タイトル以外のバッファをクリア */
		s[k][0] = '\0';

	k = 1;
	sprintf(s[k], "%*s", 3 * wd, "");	/* 1日の左側を空白文字で埋める */

	for (i = 1; i <= mdays; i++) {
		sprintf(tmp, "%3d", i);
		strcat(s[k], tmp);				/* i日の日付を追加 */
		if (++wd % 7 == 0)				/* 土曜日を格納したら */
			k++;						/* 次の行へ進む */
	}

	if (wd % 7 == 0)
		k--;
	else {
		for (wd %= 7; wd < 7; wd++)		/* 最終日の右側に空白文字を追加 */
			strcat(s[k], "   ");
	}
	while (++k < 7)						/* 未使用行を空白文字で埋めつくす */
		sprintf(s[k], "%21s", "");
	a = a + 1;
}

/*--- ３次元配列sbufに格納されたカレンダーを横にn個並べて表示 ---*/
void print(char sbuf[3][7][22], int n)
{
	FILE* fp;
	int i, j;
	fp = fopen("calendar.txt", "a+");		/*テキストファイルを読み込みと書き込み両方で開く*/

	if (n == 3) {
		for (i = 0; i < 2; i++)
			fprintf(fp,"%21s   ", sbuf[i][0]);
		fprintf(fp,"%21s", sbuf[2][0]);

		fprintf(fp,"\n");

		for (i = 0; i < 2; i++)
			fprintf(fp,"  日 月 火 水 木 金 土  ");

		fprintf(fp," 日 月 火 水 木 金 土 ");	/*３ヶ月ごとに空白文字を入れない*/
		fprintf(fp,"\n");

		for (i = 0; i < 2; i++)
			fprintf(fp,"----------------------  ");
		fprintf(fp,"---------------------");		/*3か月ごとに空白文字をいれない*/
		fprintf(fp,"\n");

		for (i = 1; i < 7; i++) {
			for (j = 0; j < 2; j++)
				fprintf(fp,"%-22s  ", sbuf[j][i]);

			fprintf(fp,"%-22s", sbuf[2][i]);	/*3か月ごとに空白文字を入れない*/

			if (i == 5) {
				if (*sbuf[0][6] == *sbuf[1][6] && *sbuf[1][6] == *sbuf[2][6])	/*3ヶ月分すべてが5行で終わる時6行目以降を追加しない*/
					i = i + 2;
			}
			fprintf(fp,"\n");
		}

		fprintf(fp,"\n");

	}
	else {									/*表示が3か月未満の場合はelseの部分で処理する*/
		for (i = 0; i < n; i++)
			fprintf(fp,"%22s   ", sbuf[i][0]);
		fprintf(fp,"\n");

		for (i = 0; i < n; i++)
			fprintf(fp,"  日 月 火 水 木 金 土  ");
		fprintf(fp,"\n");

		for (i = 0; i < n; i++)
			fprintf(fp,"----------------------  ");
		fprintf(fp,"\n");

		for (i = 1; i < 7; i++) {
			for (j = 0; j < n; j++)
				fprintf(fp,"%-22s  ", sbuf[j][i]);
			fprintf(fp,"\n");
		}

		fprintf(fp,"\n");

	}
	fclose(fp);
}

/*--- y1年m1月からy2年m2月までのカレンダーを表示 ---*/
void put_calendar(int y1, int m1, int y2, int m2)
{

	int y = y1;
	int m = m1;
	int n = 0;						/* バッファに蓄えている月数 */
	char sbuf[3][7][22];			/* カレンダー文字列のバッファ */

	while (y <= y2) {
		if (y == y2 && m > m2) break;
		make_calendar(y, m, sbuf[n++]);
		if (n == 3) {				/* ３ヶ月分たまったら表示 */

			print(sbuf, n);
			n = 0;
		}
		m++;						/* 次の月へ */
		if (m == 13 && y < y2) {	/* 年を繰り越す */
			y++;
			m = 1;
		}
	}
	if (n)							/* 未表示月があれば */
		print(sbuf, n);				/* それらを表示する */
}

int main(void)
{
	int y1, m1, y2, m2;

	printf("カレンダーを表示します。\n");

	printf("開始年月を入力せよ。\n");
	printf("年： ");	  scanf("%d", &y1);
	do {
		if (y1 < 1970) {
			printf("\n1970年から表示することができます。\n1970年以降を入力してください。\n");
			printf("年: ");
			scanf("%d", &y1);
		}
		else if (y1 >= 1970) {
			break;
		}
	} while (1);
	printf("月 ：");	  scanf("%d", &m1);
	do {
		if (1 <= m1 && m1 <= 12) {
			break;
		}
		else {
			printf("1月から12月までしか存在しませんよ\n1～12の間で入力してください。\n");
			printf("月: ");
			scanf("%d", &m1);
		}

	} while (1);


	printf("終了年月を入力せよ。\n");
	printf("年： ");	  scanf("%d", &y2);
	do {
		if (y2 < y1) {
			printf("\n開始年月より大きな値もしくは同じ値を入力してください。\n開始年月は%d年でした。\n", y1);
			printf("年: ");
			scanf("%d", &y2);
		}
		else if (y1 <= y2) {
			break;
		}
	} while (1);

	printf("月： ");	  scanf("%d", &m2);
	do {
		if (m1 <= m2 && m2 <= 12) {
			break;
		}
		else {
			printf("開始年月より同じか、それより大きい値を\n1～12の間で入力してください。\n開始年月は%d年%d月でした\n", y1, m1);
			printf("月: ");
			scanf("%d", &m2);
		}

	} while (1);

	putchar('\n');

	put_calendar(y1, m1, y2, m2);

	return 0;
}

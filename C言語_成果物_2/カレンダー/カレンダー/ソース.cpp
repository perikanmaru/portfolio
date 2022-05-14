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
	else{
		if (a % 3 != 0) {					/*3の倍数以外の月は空白文字を追加する*/
			for (wd %= 7; wd < 7; wd++)		/* 最終日の右側に空白文字を追加 */
				strcat(s[k], "   ");
		}
	}
	while (++k < 7)						/* 未使用行を空白文字で埋めつくす */
		sprintf(s[k], "%21s", "");
	a++;
}

/*--- ３次元配列sbufに格納されたカレンダーを横にn個並べて表示 ---*/
void print(char sbuf[3][7][22], int n)
{
	int i, j;

	for (i = 0; i < n; i++)					/* タイトル（年／月）を表示 */
		printf("%s   ", sbuf[i][0]);
	putchar('\n');

	for (i = 0; i < n; i++)
		printf(" 日 月 火 水 木 金 土   ");
	putchar('\n');

	for (i = 0; i < n; i++)
		printf("----------------------  ");
	putchar('\n');

	for (i = 1; i < 7; i++) {				/* カレンダー本体部を */
		for (j = 0; j < n; j++)				/* 横にn個並べて */
			printf("%s   ", sbuf[j][i]);	/* 表示 */
		putchar('\n');
	}
	putchar('\n');
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
	printf("年：");	  scanf("%d", &y1);
	printf("月：");	  scanf("%d", &m1);

	printf("終了年月を入力せよ。\n");
	printf("年：");	  scanf("%d", &y2);
	printf("月：");	  scanf("%d", &m2);

	putchar('\n');

	put_calendar(y1, m1, y2, m2);

	return 0;
}

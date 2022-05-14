#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<time.h>

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

int strncmpx(const char* s1, const char* s2, size_t n)
{
	while (n && toupper(*s1) && toupper(*s2)) {
		if (toupper(*s1) != toupper(*s2))			/* 等しくない */
			return (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
		n--;
	}
	if (!n)	 return 0;
	if (*s1) return 1;
	return -1;
}

/*--- 文字列から月の値を得る ---*/
int get_month(char* s)
{
	int i;
	int m;		/* 月 */
	const char* month[] = { "", "January", "February", "March", "April",
						   "May", "June", "July", "August", "September",
							"October", "November", "December" };

	m = atoi(s);
	if (m >= 1 && m <= 12)			/* 数字表記："1", "2", …, "12" */
		return m;

	for (i = 1; i <= 12; i++)		/* 英語表記 */
		if (strncmpx(month[i], s, 3) == 0)
			return i;

	return -1;						/* 変換失敗 */
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
	int i, j;

	if (n == 3) {
		for (i = 0; i < 2; i++)
			printf("%21s   ", sbuf[i][0]);
		printf("%21s", sbuf[2][0]);

		printf("\n");

		for (i = 0; i < 2; i++)
			printf("  日 月 火 水 木 金 土  ");

		printf(" 日 月 火 水 木 金 土 ");	/*３ヶ月ごとに空白文字を入れない*/
		printf("\n");

		for (i = 0; i < 2; i++)
			printf("----------------------  ");
		printf("---------------------");		/*3か月ごとに空白文字をいれない*/
		printf("\n");

		for (i = 1; i < 7; i++) {
			for (j = 0; j < 2; j++)
				printf("%-22s  ", sbuf[j][i]);

			printf("%-22s", sbuf[2][i]);	/*3か月ごとに空白文字を入れない*/

			if (i == 5) {
				if (*sbuf[0][6] == *sbuf[1][6] && *sbuf[1][6] == *sbuf[2][6])	/*3ヶ月分すべてが5行で終わる時6行目以降を追加しない*/
					i = i + 2;
			}
			printf("\n");
		}

		printf("\n");

	}
	else {									/*表示が3か月未満の場合はelseの部分で処理する*/
		for (i = 0; i < n; i++)
			printf("%22s   ", sbuf[i][0]);
		printf("\n");

		for (i = 0; i < n; i++)
			printf("  日 月 火 水 木 金 土  ");
		printf("\n");

		for (i = 0; i < n; i++)
			printf("----------------------  ");
		printf("\n");

		for (i = 1; i < 7; i++) {
			for (j = 0; j < n; j++)
				printf("%-22s  ", sbuf[j][i]);
			printf("\n");
		}

		printf("\n");
	}

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


int main(int argc, char* argv[])
{
	int  y1, m1,y2,m2;							/*表示の指定の仕方は*/
	time_t t = time(NULL);				/* 現在の時刻を取得 */
	struct tm* local = localtime(&t);	/* 要素別の時刻（地方時）に変換 */

	y1 = local->tm_year + 1900;			/* 今日の年 */
	m1 = local->tm_mon + 1;				/* 今日の月 */

	if (argc >= 2) {				/* argv[1]の解析 */
		m1 = get_month(argv[1]);
		if (m1 < 0 || m1 > 12) {
			fprintf(stderr, "月の値が不正です。\n");
			return 1;
		}
	}
	if (argc >= 3) {				/* argv[2]の解析 */
		y1 = atoi(argv[2]);
		if (y1 < 0) {
			fprintf(stderr, "年の値が不正です。\n");
			return 1;
		}
	}

	if (argc >= 4) {				/* argv[3]の解析 */
		m2 = get_month(argv[3]);
		if (m2 < 0 || m2 > 12) {
			fprintf(stderr, "月の値が不正です。\n");
			return 1;
		}
	}
	if (argc >= 5) {				/* argv[4]の解析 */
		y2 = atoi(argv[4]);
		if (y2 < 0) {
			fprintf(stderr, "年の値が不正です。\n");
			return 1;
		}
	}
	printf("%d年%d月から%d年%d月まで表示します\n\n", y1, m1,y2,m2);

	put_calendar(y1, m1,y2,m2);		/* y年m月のカレンダーを表示 */

	return 0;
}
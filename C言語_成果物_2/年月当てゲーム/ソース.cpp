#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void) {


	int a = 0;
	int b = 0;
	int c = 0;
	int break_loop = 0;
	int year = 0;
	int month = 0;
	int day = 0;

	int correct_year = 0;
	int correct_month = 0;
	int correct_day = 0;

	clock_t start, end;

	srand(time(NULL));

	printf("数当てゲームを開始します！\n");

	year  = rand() % 300 + 1970;
	month = rand() % 12 + 1;
	day   = rand() % 31 + 1;

	printf("%d\n%d\n%d\n", year, month, day);

	do {
		start = clock();

		if ( correct_year == 0) {						/*年、月、日の入力　正解すると入力を無視する*/
			printf("\n年を入力してください。\n年 : ");
			scanf("%d", &a);
		}
		else {
			;
		}

		if (correct_month == 0) {
			printf("\n月を入力してください。\n月 : ");
			scanf("%d", &b);
		}
		else {
			;
		}

		if (correct_day == 0) {
			printf("\n日を入力してください。\n日 : ");
			scanf("%d", &c);
		}
		else {
			;
		}

		if (a > year&&correct_year==0) {				/*判定開始*/
			printf("もっと小さいですよ\n");
		}
		else if (a < year) {
			printf("もっと大きいですよ\n");
		}
		else if(correct_year==0){
			printf("正解です\n");
			correct_year = 1;
		}
		else
			;

		if (b > month && correct_month == 0) {
			printf("もっと小さいですよ\n");
		}
		else if (b < month) {
			printf("もっと大きいですよ\n");
		}
		else if (correct_month == 0) {
			printf("正解です\n");
			correct_month = 1;
		}
		else
			;

		if (c > day && correct_day == 0) {
			printf("もっと小さいですよ\n");
		}
		else if (c < day) {
			printf("もっと大きいですよ\n");
		}
		else if (correct_day == 0) {
			printf("正解です\n");
			correct_day = 1;
		}
		else
			;

		break_loop = (correct_year + correct_month + correct_day);			/*すべて正解したか判定するための変数に代入*/


	} while (break_loop<=2);	/*ループを抜けるか判定*/

	end = clock();

	printf("\nすべてに正解しました！正解は%d年%d月%d日でした\n",year,month,day);
	printf("正解にかかった時間は%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
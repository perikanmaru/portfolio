#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void make_colors(int x[])
{
	int i, j, val;
	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 8;
			for (j = 0; j < i; j++)
				if (val == x[j])
					break;
		} while (j < i);
		x[i] = val;
	}
}

int check(const char s[])
{
	int i, j;
	if (strlen(s) != 4)
		return 1;

	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;

		for (j = 0; j < i; j++)
			if (s[i] == s[j])
				return 3;
	}

	return 0;
}

void judge(const char s[], const int no[], int* hit, int* brow)
{
	int i, j;

	*hit = *brow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j])
				if (i == j)
					(*hit)++;
				else
					(*brow)++;
		}
	}

}

void result(int snum, int spots)
{
	if (spots == 4)
		printf("正解です！");
	else if (snum == 0)
		printf("それらの色は1つも含まれません。\n");
	else {
		printf("それらの数字のうち%d個の色が含まれます。\n", snum);

		if (spots == 0)
			printf("ただし位置のあっている色はありません。\n");
		else
			printf("その中の%d個の色は位置もあっています。\n", spots);
	}
	putchar('\n');
}

void print_colors(const int color[])
{
	int k;
	for (k = 0; k < 4; k++) {
		printf("\x1b[0m");/*色指定のリセット*/
		printf("\x1b[47m");/*背景を灰色に*/
		switch (color[k])
		{
		case 0: printf("\x1b[42m");/*背景が白色と見えなくなるので背景を緑に*/
			printf("\x1b[37m");
			printf("白");
			break;
		case 1: printf("\x1b[30m黒");
			break;
		case 2: printf("\x1b[31m赤");
			break;
		case 3:printf("\x1b[34m青");
			break;
		case 4: printf("\x1b[33m黄");
			break;
		case 5: printf("\x1b[32m緑");
			break;
		case 6: printf("\x1b[35m紫");
			break;
		case 7: printf("\x1b[36m暗い青");
			break;
		default:
			break;
		}
	}
	printf("\x1b[0m");/*最後に色の変更をリセットして色指定より下の処理に色変更が適用されないようにする*/
}

int main(void) {

	int try_no = 0;
	int chk = 0;
	int hit;
	int blow;
	int no[4];
	char buff[10];
	int k = 0;
	int n = 0;
	int i = 0;
	int j = 0;

	clock_t start, end;

	srand(time(NULL));

	puts("マスターマインドを始めます...");
	puts("４つの色の並びをあててください");
	puts("同じ色が複数含まれることはありません。つまり赤白青黄のような連続する異なる色です。\n");
	puts("ここでは色を入力するときに数字を用います");
	puts(" 白...(0) 黒...(1) 赤...(2) 青...(3) 黄...(4) 緑...(5) 紫...(6) 暗い青...(7) \n");
	puts("スペース文字などを入れないでください。\n");

	make_colors(no);/*色を4色作成する*/

	start = clock();

	for (j = 0; j < 4; j++) {
		printf("%d", no[j]);
	}
	printf("\n");

	printf("挑戦回数を入力してください。\n");
	scanf("%d", &n);

	do {
		do {
			printf("残り回数は%d回です。", n - k);
			printf("入力してください。\n");
			scanf("%s", buff);
			printf("\n");

			chk = check(buff);

			switch (chk)
			{
			case 1:
				puts("きちんと４つの色で入力してください。");
				break;
			case 2:
				puts("数字以外の文字を入力しないでください。\n白...(0) 黒...(1) 赤...(2) 青...(3) 黄...(4) 緑...(5) 橙(オレンジ)...(6) 茶...(7)");
				break;
			case 3:
				puts("同じ数字を複数入力しないでください。");
				break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, no, &hit, &blow);

		result(hit + blow, hit);
		k++;
	} while (k < n && hit != 4);

	if (k == n) {
		printf("\n失敗しました。また挑戦してくださいね。");
		return 0;
	}

	printf("正解の色は...");
	print_colors(no);
	printf("でした。");

	end = clock();

	printf("\n%d回かかりました。\n所要時間は%1.lf秒でした。\n", try_no, (double)(end - start) / CLOCKS_PER_SEC);



	return 0;
}
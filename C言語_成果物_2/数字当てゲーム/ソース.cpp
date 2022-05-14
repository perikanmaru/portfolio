#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void make_number(int x[])
{
	int i,j,val;
	for (i = 0; i < 4; i++){
		do {
			val = rand() % 10;
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

void hint(const int no[])
{

	printf("ヒントを表示します。\n最初の１文字目は%dです。\n",no[0]);

}

void judge(const char s[], const int no[], int* hit, int* brow)
{
	int i, j;

	*hit = *brow = 0;
	for (i = 0; i < 4; i++){
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
		printf("それらの数字は1つも含まれません。\n");
	else {
		printf("それらの数字のうち%d個の数字が含まれます。\n",snum);

		if (spots == 0)
			printf("ただし位置のあっている数字はありません。\n");
		else
			printf("その中の%d個の数字は位置もあっています。\n",spots);
	}
	putchar('\n');
}

int main(void)
{
	int try_no = 0;
	int chk = 0;
	int hit;
	int blow;
	int no[4];
	char buff[10];
	int k = 0;
	int n = 0;
	int i = 0;
	clock_t start, end;

	srand(time(NULL));

	puts("マスターマインドを始めます...");
	puts("４つの数字の並びをあててください");
	puts("同じ数字が複数含まれることはありません。つまり4307のような連続する異なる数字です。");
	puts("スペース文字などを入れないでください。\n");
	
	start = clock();

	printf("挑戦回数を入力してください。\n");
	scanf("%d",&n);
	make_number(no);

		do {
			do {
				printf("入力してください。\n");
				scanf("%s", buff);

				chk = check(buff);

				switch (chk)
				{
				case 1:
					puts("きちんと４つの数字で入力してください。");
					break;
				case 2:
					puts("数字以外の文字を入力しないでください。");
					break;
				case 3:
					puts("同じ数字を複数入力しないでください。");
					break;
				}
			} while (chk != 0);

			try_no++;
			judge(buff, no, &hit, &blow);
			
			result(hit + blow, hit);
			if (try_no == 2) {
				hint(no);
			}
			k++;
			printf("残り回数は%d回です",n-k);
		} while (k<n&&hit!=4);

		if (k == n) {
			printf("\n失敗しました");
			return 0;
		}

	end = clock();
	printf("%d回かかりました。\n所要時間は%1.lf秒でした。\n",try_no,(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
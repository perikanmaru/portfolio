#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int human;
int comp;
int win;
int lose;
int draw;

const char *hd[] = { "グー","チョキ","パー" };

void initialize(void)
{
	win = 0;
	lose = 0;
	draw = 0;
	srand(time(NULL));
	printf("\n"); 
}

void jyanken(void)
{
	int i;

	comp = rand() % 3;
	do {
		printf("じゃんけんポンっ...");
		for (i = 0; i < 3; i++)
			printf("(%d)%s", i, hd[i]);
			printf(" : ");
			scanf("%d", &human);
			if (human > 3)
				printf("0～２の数字を入力してくださいね。\n");
	} while (human < 0 || human>2);
}

void count(int result)
{
	switch (result)
	{
	case 0:
		draw++;
		break;
	case 1:
		lose++;
		break;
	case 2:
		win++;
		break;
	default:
		break;
	}
}

void disp(int result)
{
	switch (result)
	{
	case 0:
		puts("引き分けです。");
		break;
	case 1:
		puts("あなたの負けです。");
		break;
	case 2:
		puts("あなたの勝ちです。");
		break;
	default:
		break;
	}
}

void jyanken_1(void)
{
	int k,j;
	do
	{
		printf("最初はグーじゃんけんポンっ\n");
		for (k = 0; k < 3; k++)
			printf("(%d)%s", k, hd[k]);

		scanf("%d", &j);

		if (j == 0)
			break;
		else if (j == 1)
			printf("最初はグーですよ\n");
		else if (j == 2)
			printf("最初はグーですよ\n");
		else if (j > 2)
			printf("0～2の数字で入力してください。");

	} while (1);
}

int main(void)
{
	int judge;
	int n, j = 0;
	int a;
	int t = 1;
	int* score_comp;		/*手の履歴用*/
	int* score_human;
	int* score_judge;	/*勝敗履歴用*/

	printf("何回じゃんけんしますか？\n");
	scanf("%d", &n);

	score_comp = (int*)calloc(n, sizeof(int));	/*記憶域の確保(手の履歴)*/
	score_human = (int*)calloc(n, sizeof(int));
	score_judge = (int*)calloc(n, sizeof(int));

	initialize();								/*初期化*/


	do {

		jyanken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		score_comp[j] = comp;	/*手の履歴を保存*/
		score_human[j] = human;

		judge = (human - comp + 3) % 3;

		count(judge);
		disp(judge);
		printf("\n");
		score_judge[j] = judge;
		j++;
	} while (win < n && lose < n);	/*n回勝つかn回負けるまでじゃんけんを続ける。*/

	printf(win == n ? "\n あなたの勝ちです。\n" : "\n 私の勝ちです。\n");

	printf("じゃんけんの結果を表示します...\n");

	for (a = 0; a < win+lose+draw; a++) {			/*手の履歴表示*/

		printf("%d回目 : ",t);

		switch (score_comp[a])
		{
		case 0:
			printf("コンピュータはグーで");
			break;
		case 1:
			printf("コンピュータはチョキで");
			break;
		case 2:
			printf("コンピュータはパーで");
			break;
		default:
			break;
		}

		switch (score_human[a])
		{
		case 0:
			printf("あなたはグーでした。 : ");
			break;
		case 1:
			printf("あなたはチョキでした。 : ");
			break;
		case 2:
			printf("あなたはパーでした。 : ");
			break;
		default:
			break;
		}

		switch (score_judge[a])
		{
			case 0:
				printf("引き分けです。");
				break;
			case 1:
				printf("あなたの負けです。");
				break;
			case 2:
				printf("あなたの勝ちです。");
				break;
			default:
				break;
		}

		puts("");
		t++;

	}

	printf("\n%d勝%d敗%d分けでした。\n", win, lose, draw);

	return 0;
}

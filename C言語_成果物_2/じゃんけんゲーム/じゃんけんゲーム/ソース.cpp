#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int human;
int comp;
int win;
int lose;
int draw;

const char *hd[] = { "�O�[","�`���L","�p�[" };

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
		printf("����񂯂�|����...");
		for (i = 0; i < 3; i++)
			printf("(%d)%s", i, hd[i]);
			printf(" : ");
			scanf("%d", &human);
			if (human > 3)
				printf("0�`�Q�̐�������͂��Ă��������ˁB\n");
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
		puts("���������ł��B");
		break;
	case 1:
		puts("���Ȃ��̕����ł��B");
		break;
	case 2:
		puts("���Ȃ��̏����ł��B");
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
		printf("�ŏ��̓O�[����񂯂�|����\n");
		for (k = 0; k < 3; k++)
			printf("(%d)%s", k, hd[k]);

		scanf("%d", &j);

		if (j == 0)
			break;
		else if (j == 1)
			printf("�ŏ��̓O�[�ł���\n");
		else if (j == 2)
			printf("�ŏ��̓O�[�ł���\n");
		else if (j > 2)
			printf("0�`2�̐����œ��͂��Ă��������B");

	} while (1);
}

int main(void)
{
	int judge;
	int n, j = 0;
	int a;
	int t = 1;
	int* score_comp;		/*��̗���p*/
	int* score_human;
	int* score_judge;	/*���s����p*/

	printf("���񂶂�񂯂񂵂܂����H\n");
	scanf("%d", &n);

	score_comp = (int*)calloc(n, sizeof(int));	/*�L����̊m��(��̗���)*/
	score_human = (int*)calloc(n, sizeof(int));
	score_judge = (int*)calloc(n, sizeof(int));

	initialize();								/*������*/


	do {

		jyanken();

		printf("����%s�ŁA���Ȃ���%s�ł��B\n", hd[comp], hd[human]);

		score_comp[j] = comp;	/*��̗�����ۑ�*/
		score_human[j] = human;

		judge = (human - comp + 3) % 3;

		count(judge);
		disp(judge);
		printf("\n");
		score_judge[j] = judge;
		j++;
	} while (win < n && lose < n);	/*n�񏟂�n�񕉂���܂ł���񂯂�𑱂���B*/

	printf(win == n ? "\n ���Ȃ��̏����ł��B\n" : "\n ���̏����ł��B\n");

	printf("����񂯂�̌��ʂ�\�����܂�...\n");

	for (a = 0; a < win+lose+draw; a++) {			/*��̗���\��*/

		printf("%d��� : ",t);

		switch (score_comp[a])
		{
		case 0:
			printf("�R���s���[�^�̓O�[��");
			break;
		case 1:
			printf("�R���s���[�^�̓`���L��");
			break;
		case 2:
			printf("�R���s���[�^�̓p�[��");
			break;
		default:
			break;
		}

		switch (score_human[a])
		{
		case 0:
			printf("���Ȃ��̓O�[�ł����B : ");
			break;
		case 1:
			printf("���Ȃ��̓`���L�ł����B : ");
			break;
		case 2:
			printf("���Ȃ��̓p�[�ł����B : ");
			break;
		default:
			break;
		}

		switch (score_judge[a])
		{
			case 0:
				printf("���������ł��B");
				break;
			case 1:
				printf("���Ȃ��̕����ł��B");
				break;
			case 2:
				printf("���Ȃ��̏����ł��B");
				break;
			default:
				break;
		}

		puts("");
		t++;

	}

	printf("\n%d��%d�s%d�����ł����B\n", win, lose, draw);

	return 0;
}

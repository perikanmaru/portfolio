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
		printf("�����ł��I");
	else if (snum == 0)
		printf("�����̐F��1���܂܂�܂���B\n");
	else {
		printf("�����̐����̂���%d�̐F���܂܂�܂��B\n", snum);

		if (spots == 0)
			printf("�������ʒu�̂����Ă���F�͂���܂���B\n");
		else
			printf("���̒���%d�̐F�͈ʒu�������Ă��܂��B\n", spots);
	}
	putchar('\n');
}

void print_colors(const int color[])
{
	int k;
	for (k = 0; k < 4; k++) {
		printf("\x1b[0m");/*�F�w��̃��Z�b�g*/
		printf("\x1b[47m");/*�w�i���D�F��*/
		switch (color[k])
		{
		case 0: printf("\x1b[42m");/*�w�i�����F�ƌ����Ȃ��Ȃ�̂Ŕw�i��΂�*/
			printf("\x1b[37m");
			printf("��");
			break;
		case 1: printf("\x1b[30m��");
			break;
		case 2: printf("\x1b[31m��");
			break;
		case 3:printf("\x1b[34m��");
			break;
		case 4: printf("\x1b[33m��");
			break;
		case 5: printf("\x1b[32m��");
			break;
		case 6: printf("\x1b[35m��");
			break;
		case 7: printf("\x1b[36m�Â���");
			break;
		default:
			break;
		}
	}
	printf("\x1b[0m");/*�Ō�ɐF�̕ύX�����Z�b�g���ĐF�w���艺�̏����ɐF�ύX���K�p����Ȃ��悤�ɂ���*/
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

	puts("�}�X�^�[�}�C���h���n�߂܂�...");
	puts("�S�̐F�̕��т����ĂĂ�������");
	puts("�����F�������܂܂�邱�Ƃ͂���܂���B�܂�Ԕ����̂悤�ȘA������قȂ�F�ł��B\n");
	puts("�����ł͐F����͂���Ƃ��ɐ�����p���܂�");
	puts(" ��...(0) ��...(1) ��...(2) ��...(3) ��...(4) ��...(5) ��...(6) �Â���...(7) \n");
	puts("�X�y�[�X�����Ȃǂ����Ȃ��ł��������B\n");

	make_colors(no);/*�F��4�F�쐬����*/

	start = clock();

	for (j = 0; j < 4; j++) {
		printf("%d", no[j]);
	}
	printf("\n");

	printf("����񐔂���͂��Ă��������B\n");
	scanf("%d", &n);

	do {
		do {
			printf("�c��񐔂�%d��ł��B", n - k);
			printf("���͂��Ă��������B\n");
			scanf("%s", buff);
			printf("\n");

			chk = check(buff);

			switch (chk)
			{
			case 1:
				puts("������ƂS�̐F�œ��͂��Ă��������B");
				break;
			case 2:
				puts("�����ȊO�̕�������͂��Ȃ��ł��������B\n��...(0) ��...(1) ��...(2) ��...(3) ��...(4) ��...(5) ��(�I�����W)...(6) ��...(7)");
				break;
			case 3:
				puts("���������𕡐����͂��Ȃ��ł��������B");
				break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, no, &hit, &blow);

		result(hit + blow, hit);
		k++;
	} while (k < n && hit != 4);

	if (k == n) {
		printf("\n���s���܂����B�܂����킵�Ă��������ˁB");
		return 0;
	}

	printf("�����̐F��...");
	print_colors(no);
	printf("�ł����B");

	end = clock();

	printf("\n%d�񂩂���܂����B\n���v���Ԃ�%1.lf�b�ł����B\n", try_no, (double)(end - start) / CLOCKS_PER_SEC);



	return 0;
}
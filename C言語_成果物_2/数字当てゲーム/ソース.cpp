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

	printf("�q���g��\�����܂��B\n�ŏ��̂P�����ڂ�%d�ł��B\n",no[0]);

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
		printf("�����ł��I");
	else if (snum == 0)
		printf("�����̐�����1���܂܂�܂���B\n");
	else {
		printf("�����̐����̂���%d�̐������܂܂�܂��B\n",snum);

		if (spots == 0)
			printf("�������ʒu�̂����Ă��鐔���͂���܂���B\n");
		else
			printf("���̒���%d�̐����͈ʒu�������Ă��܂��B\n",spots);
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

	puts("�}�X�^�[�}�C���h���n�߂܂�...");
	puts("�S�̐����̕��т����ĂĂ�������");
	puts("���������������܂܂�邱�Ƃ͂���܂���B�܂�4307�̂悤�ȘA������قȂ鐔���ł��B");
	puts("�X�y�[�X�����Ȃǂ����Ȃ��ł��������B\n");
	
	start = clock();

	printf("����񐔂���͂��Ă��������B\n");
	scanf("%d",&n);
	make_number(no);

		do {
			do {
				printf("���͂��Ă��������B\n");
				scanf("%s", buff);

				chk = check(buff);

				switch (chk)
				{
				case 1:
					puts("������ƂS�̐����œ��͂��Ă��������B");
					break;
				case 2:
					puts("�����ȊO�̕�������͂��Ȃ��ł��������B");
					break;
				case 3:
					puts("���������𕡐����͂��Ȃ��ł��������B");
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
			printf("�c��񐔂�%d��ł�",n-k);
		} while (k<n&&hit!=4);

		if (k == n) {
			printf("\n���s���܂���");
			return 0;
		}

	end = clock();
	printf("%d�񂩂���܂����B\n���v���Ԃ�%1.lf�b�ł����B\n",try_no,(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
#include <time.h>
#include <float.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	

static void init_getputch(void) { /* �� */ }

static void term_getputch(void) { /* �� */ }
#define MAX_STAGE	10
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

char dtfile[] = "LACKNUM.txt";				/* �t�@�C�����Ō�ɂ��������ƃx�X�g10�̃X�R�A�L�^�p */
char dtfile_time[] = "TIME_RECORD.txt";		/*�ߋ�10����L�^����p*/

/*--- �O��̃g���[�j���O�����擾�E�\�����čō����_��Ԃ� ---*/
double get_data(void)
{
	FILE* fp;
	double best;		/* �ō����_ */
	double best_2;

	if ((fp = fopen(dtfile, "r")) == NULL) {
		printf("�{�v���O���������s����̂͏��߂Ăł��ˁB\n\n");
		best = DBL_MAX;
	}
	else {
		int year, month, day, h, m, s;

		fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
		fscanf(fp, "%lf", &best);
		fscanf(fp, "%lf", &best_2);

		printf("�O��̏I����%d�N%d��%d��%d��%d��%d�b�ł����B\n\n",year, month, day, h, m, s);

		printf("����܂ł̍ō����_�i�ŒZ���v���ԁj��%.1f�b�ł��B\n", best);
		fclose(fp);
	}

	return best;
}
/*�P�O��ڂ̋L�^�����ꂽ��t�@�C�����폜���ă��Z�b�g*/
int time_record_reset(void) {
	
	if (remove("TIME_RECORD.txt") == 0) {
		puts("�t�@�C���̍폜�ɐ���");
	}
	else {
			puts("�t�@�C���̍폜�Ɏ��s");
	}
	return 0;

}
/*�ߋ�10��̎��s�������L�^����*/
double time_record( double score) {

	FILE* fp2;
	time_t t = time(NULL);
	struct tm* local = localtime(&t);

	int year, month, day, h, m, s;
	int k = 0;
	int i = 0;
	int c = 0;

	if ((fp2 = fopen(dtfile_time, "a+")) == NULL) {
		printf("10��܂ł̗�����ۑ�����t�@�C�����쐬���܂����B�@���񂩂�ۑ����J�n����܂�\n");

	}else {

		while (fgets(dtfile_time,256, fp2) != NULL) {
			fscanf(fp2, "%d",&k);
			k++;
		}

		if (k < 10) {
			fprintf(fp2, "%d��� %d %d %d %d %d %d %.1f�b������܂����B\n",
				k, local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
				local->tm_hour, local->tm_min, local->tm_sec,score);

		}
		else {

			fclose(fp2);
			return -1;
		}
		fclose(fp2);
	}
	return 0;
}

/*�ߋ��̓_��(����)�̏���*/
double get_result(int n) {
	FILE* fp;

	double best = 1000;
	double best_2 = 1000;
	double best_3 = 1000;
	double best_4 = 1000;
	double best_5 = 1000;
	double best_6 = 1000;
	double best_7 = 1000;
	double best_8 = 1000;
	double best_9 = 1000;
	double best_10 = 1000;

	if ((fp = fopen(dtfile, "r")) == NULL) {
		fclose(fp);
		return 1000;
	}
	else {
		int year, month, day, h, m, s;

		fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);

		fscanf(fp, "%lf", &best);
		fscanf(fp, "%lf", &best_2);
		fscanf(fp, "%lf", &best_3);
		fscanf(fp, "%lf", &best_4);
		fscanf(fp, "%lf", &best_5);
		fscanf(fp, "%lf", &best_6);
		fscanf(fp, "%lf", &best_7);
		fscanf(fp, "%lf", &best_8);
		fscanf(fp, "%lf", &best_9);
		fscanf(fp, "%lf", &best_10);
		fclose(fp);
	}
	switch (n)
	{
	case 0:
		return best_2;
		break;
	case 1:
		return best_3;
		break;
	case 2:
		return best_4;
		break;
	case 3:
		return best_5;
		break;
	case 4:
		return best_6;
		break;
	case 5:
		return best_7;
		break;
	case 6:
		return best_8;
		break;
	case 7:
		return best_9;
		break;
	case 8:
		return best_10;
		break;
	default:
		return 0;
	break;
	}

}

/*--- ����̃g���[�j���O������������ ---*/
void put_data(double best, double best_2, double best_3, double best_4, double best_5, double best_6, double best_7, double best_8, double best_9, double best_10)
{
	FILE* fp;
	time_t t = time(NULL);
	struct tm* local = localtime(&t);

	if ((fp = fopen(dtfile, "w+")) == NULL)
		printf("�G���[����!!");
	else {
		fprintf(fp, "%d %d %d %d %d %d\n",
			local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
			local->tm_hour, local->tm_min, local->tm_sec);

		fprintf(fp, "%f\n", best);
		fprintf(fp, "%f\n", best_2);
		fprintf(fp, "%f\n", best_3);
		fprintf(fp, "%f\n", best_4);
		fprintf(fp, "%f\n", best_5);
		fprintf(fp, "%f\n", best_6);
		fprintf(fp, "%f\n", best_7);
		fprintf(fp, "%f\n", best_8);
		fprintf(fp, "%f\n", best_9);
		fprintf(fp, "%f\n", best_10);

		fclose(fp);
	}
}

/*--- �g���[�j���O�����s���ē��_�i���v���ԁj��Ԃ� ---*/
double go(void)
{
	int i, j, stage;
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8];
	double jikan;				/* ���� */
	clock_t start, end;			/* �J�n�����E�I������ */

	printf("�����Ă��鐔������͂��Ă��������B\n");
	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* 0�`8�̗����𐶐� */
		int	no;					/* �ǂݍ��񂾒l */

		i = j = 0;
		while (i < 9) {			/* dgt[x]���΂��ăR�s�[ */
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {		/* �z��a���V���b�t�� */
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++)		/* �S�v�f��\�� */
			printf("%d ", a[i]);
		printf("�F");
		fflush(stdout);

		do {
			no = getch();
			if (isprint(no)) {				/* �\���\�ł���� */
				putch(no);					/* �����ꂽ�L�[��\�� */
				if (no != dgt[x] + '0')		/* �����łȂ���� */
					putch('\b');			/* �J�[�\������߂� */
				else
					printf("\n");			/* ���s */
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f�b������܂����B\n", jikan);

	if (jikan > 25.0)
		printf("�݂����܂��B\n");
	else if (jikan > 20.0)
		printf("�����݂��ł��ˁB\n");
	else if (jikan > 17.0)
		printf("�܂��܂��ł��ˁB\n");
	else
		printf("�f�����ł��ˁB\n");

	return jikan;
}

int main(void)
{
	int retry;		/* ������x�H */
	double score;	/* ���_�i���v���ԁj */
	double best;	/* �ō����_�i�ŒZ���v���ԁj*/
	double best_2;
	double best_3;
	double best_4;
	double best_5;
	double best_6;
	double best_7;
	double best_8;
	double best_9;
	double best_10;
	double recored;

	best = get_data();			/* �O��܂ł̍ō����_�𓾂� */
	best_2 = get_result(0);		/*10�܂ł̐��т�ǂݍ��ޏ����l��1000*/
	best_3 = get_result(1);
	best_4 = get_result(2);
	best_5 = get_result(3);
	best_6 = get_result(4);
	best_7 = get_result(5);
	best_8 = get_result(6);
	best_9 = get_result(7);
	best_10 = get_result(8);

	init_getputch();
	srand(time(NULL));			/* �����̎��ݒ� */

	do {
		score = go();			/* �g���[�j���O���s �g���[�j���O�ɂ����������Ԃ�score�ɑ�������*/

			if (score < best) {
				printf("�ō����_�i���v���ԁj���X�V���܂���!!\n");
				best = score;		/* �ō����_�X�V */
			}
			else if (best < best_2 && score < best_2) {
				best_2 = score;
				
			}
			else if (best_2 < best_3 && score < best_3) {
				best_3 = score;
				
			}
			else if (best_3 < best_4 && score < best_4)
			{
				best_4 = score;
				
			}
			else if (best_4 < best_5 && score < best_5)
			{
				best_5 = score;
				
			}
			else if (best_5 < best_6 && score < best_6)
			{
				best_6 = score;
				
			}
			else  if (best_6 < best_7 && score < best_7) {
				best_7 = score;
				
			}
			else if (best_7 < best_8 && score < best_8)
			{
				best_8 = score;
				
			}
			else if (best_8 < best_9 && score < best_9)
			{
				best_9 = score;
				
			}
			else if (best_9 < best_10 && score < best_10)
			{
				best_10 = score;
				
			}
			else
				;

			recored = time_record(score);
			if (recored == -1) {
				time_record_reset();
			}

		printf("������x���܂��� �c (0)������ (1)�͂��F");
		scanf("%d", &retry);

	} while (retry == 1);



	put_data(best,best_2,best_3,best_4,best_5,best_6,best_7,best_8,best_9,best_10);				/* ����̓��t�E�����E���_���������� */

	term_getputch();

	return 0;

}
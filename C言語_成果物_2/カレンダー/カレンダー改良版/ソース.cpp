#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- �e���̓��� ---*/
int mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/*--- year�Nmonth��day���̗j�������߂� ---*/
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}

/*--- year�N�͉[�N���H�i0�c���N�^1�c�[�N�j ---*/
int is_leap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- year�Nmonth���̓����i28�`31�j ---*/
int monthdays(int year, int month)
{
	if (month-- != 2)						/* month���Q���łȂ��Ƃ� */
		return mday[month];
	return mday[month] + is_leap(year);		/* month���Q���ł���Ƃ� */
}

/*--- y�Nm���̃J�����_�[���Q�����z��s�Ɋi�[ ---*/
void make_calendar(int y, int m, char s[7][22])
{
	int i, k;
	int wd = dayofweek(y, m, 1);		/* y�Nm��1���̗j�� */
	int mdays = monthdays(y, m);		/* y�Nm���̓��� */
	char tmp[4];
	int a = 0;

	sprintf(s[0], "%10d / %02d      ", y, m);	/* �^�C�g���i�N�^���j */

	for (k = 1; k < 7; k++)				/* �^�C�g���ȊO�̃o�b�t�@���N���A */
		s[k][0] = '\0';

	k = 1;
	sprintf(s[k], "%*s", 3 * wd, "");	/* 1���̍������󔒕����Ŗ��߂� */

	for (i = 1; i <= mdays; i++) {
		sprintf(tmp, "%3d", i);
		strcat(s[k], tmp);				/* i���̓��t��ǉ� */
		if (++wd % 7 == 0)				/* �y�j�����i�[������ */
			k++;						/* ���̍s�֐i�� */
	}

	if (wd % 7 == 0)
		k--;
	else {
		for (wd %= 7; wd < 7; wd++)		/* �ŏI���̉E���ɋ󔒕�����ǉ� */
			strcat(s[k], "   ");
	}
	while (++k < 7)						/* ���g�p�s���󔒕����Ŗ��߂��� */
		sprintf(s[k], "%21s", "");
	a = a + 1;
}

/*--- �R�����z��sbuf�Ɋi�[���ꂽ�J�����_�[������n���ׂĕ\�� ---*/
void print(char sbuf[3][7][22], int n)
{
	FILE* fp;
	int i, j;
	fp = fopen("calendar.txt", "a+");		/*�e�L�X�g�t�@�C����ǂݍ��݂Ə������ݗ����ŊJ��*/

	if (n == 3) {
		for (i = 0; i < 2; i++)
			fprintf(fp,"%21s   ", sbuf[i][0]);
		fprintf(fp,"%21s", sbuf[2][0]);

		fprintf(fp,"\n");

		for (i = 0; i < 2; i++)
			fprintf(fp,"  �� �� �� �� �� �� �y  ");

		fprintf(fp," �� �� �� �� �� �� �y ");	/*�R�������Ƃɋ󔒕��������Ȃ�*/
		fprintf(fp,"\n");

		for (i = 0; i < 2; i++)
			fprintf(fp,"----------------------  ");
		fprintf(fp,"---------------------");		/*3�������Ƃɋ󔒕���������Ȃ�*/
		fprintf(fp,"\n");

		for (i = 1; i < 7; i++) {
			for (j = 0; j < 2; j++)
				fprintf(fp,"%-22s  ", sbuf[j][i]);

			fprintf(fp,"%-22s", sbuf[2][i]);	/*3�������Ƃɋ󔒕��������Ȃ�*/

			if (i == 5) {
				if (*sbuf[0][6] == *sbuf[1][6] && *sbuf[1][6] == *sbuf[2][6])	/*3���������ׂĂ�5�s�ŏI��鎞6�s�ڈȍ~��ǉ����Ȃ�*/
					i = i + 2;
			}
			fprintf(fp,"\n");
		}

		fprintf(fp,"\n");

	}
	else {									/*�\����3���������̏ꍇ��else�̕����ŏ�������*/
		for (i = 0; i < n; i++)
			fprintf(fp,"%22s   ", sbuf[i][0]);
		fprintf(fp,"\n");

		for (i = 0; i < n; i++)
			fprintf(fp,"  �� �� �� �� �� �� �y  ");
		fprintf(fp,"\n");

		for (i = 0; i < n; i++)
			fprintf(fp,"----------------------  ");
		fprintf(fp,"\n");

		for (i = 1; i < 7; i++) {
			for (j = 0; j < n; j++)
				fprintf(fp,"%-22s  ", sbuf[j][i]);
			fprintf(fp,"\n");
		}

		fprintf(fp,"\n");

	}
	fclose(fp);
}

/*--- y1�Nm1������y2�Nm2���܂ł̃J�����_�[��\�� ---*/
void put_calendar(int y1, int m1, int y2, int m2)
{

	int y = y1;
	int m = m1;
	int n = 0;						/* �o�b�t�@�ɒ~���Ă��錎�� */
	char sbuf[3][7][22];			/* �J�����_�[������̃o�b�t�@ */

	while (y <= y2) {
		if (y == y2 && m > m2) break;
		make_calendar(y, m, sbuf[n++]);
		if (n == 3) {				/* �R���������܂�����\�� */

			print(sbuf, n);
			n = 0;
		}
		m++;						/* ���̌��� */
		if (m == 13 && y < y2) {	/* �N���J��z�� */
			y++;
			m = 1;
		}
	}
	if (n)							/* ���\����������� */
		print(sbuf, n);				/* ������\������ */
}

int main(void)
{
	int y1, m1, y2, m2;

	printf("�J�����_�[��\�����܂��B\n");

	printf("�J�n�N������͂���B\n");
	printf("�N�F ");	  scanf("%d", &y1);
	do {
		if (y1 < 1970) {
			printf("\n1970�N����\�����邱�Ƃ��ł��܂��B\n1970�N�ȍ~����͂��Ă��������B\n");
			printf("�N: ");
			scanf("%d", &y1);
		}
		else if (y1 >= 1970) {
			break;
		}
	} while (1);
	printf("�� �F");	  scanf("%d", &m1);
	do {
		if (1 <= m1 && m1 <= 12) {
			break;
		}
		else {
			printf("1������12���܂ł������݂��܂����\n1�`12�̊Ԃœ��͂��Ă��������B\n");
			printf("��: ");
			scanf("%d", &m1);
		}

	} while (1);


	printf("�I���N������͂���B\n");
	printf("�N�F ");	  scanf("%d", &y2);
	do {
		if (y2 < y1) {
			printf("\n�J�n�N�����傫�Ȓl�������͓����l����͂��Ă��������B\n�J�n�N����%d�N�ł����B\n", y1);
			printf("�N: ");
			scanf("%d", &y2);
		}
		else if (y1 <= y2) {
			break;
		}
	} while (1);

	printf("���F ");	  scanf("%d", &m2);
	do {
		if (m1 <= m2 && m2 <= 12) {
			break;
		}
		else {
			printf("�J�n�N����蓯�����A������傫���l��\n1�`12�̊Ԃœ��͂��Ă��������B\n�J�n�N����%d�N%d���ł���\n", y1, m1);
			printf("��: ");
			scanf("%d", &m2);
		}

	} while (1);

	putchar('\n');

	put_calendar(y1, m1, y2, m2);

	return 0;
}

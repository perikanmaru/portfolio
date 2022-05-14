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
	else{
		if (a % 3 != 0) {					/*3�̔{���ȊO�̌��͋󔒕�����ǉ�����*/
			for (wd %= 7; wd < 7; wd++)		/* �ŏI���̉E���ɋ󔒕�����ǉ� */
				strcat(s[k], "   ");
		}
	}
	while (++k < 7)						/* ���g�p�s���󔒕����Ŗ��߂��� */
		sprintf(s[k], "%21s", "");
	a++;
}

/*--- �R�����z��sbuf�Ɋi�[���ꂽ�J�����_�[������n���ׂĕ\�� ---*/
void print(char sbuf[3][7][22], int n)
{
	int i, j;

	for (i = 0; i < n; i++)					/* �^�C�g���i�N�^���j��\�� */
		printf("%s   ", sbuf[i][0]);
	putchar('\n');

	for (i = 0; i < n; i++)
		printf(" �� �� �� �� �� �� �y   ");
	putchar('\n');

	for (i = 0; i < n; i++)
		printf("----------------------  ");
	putchar('\n');

	for (i = 1; i < 7; i++) {				/* �J�����_�[�{�̕��� */
		for (j = 0; j < n; j++)				/* ����n���ׂ� */
			printf("%s   ", sbuf[j][i]);	/* �\�� */
		putchar('\n');
	}
	putchar('\n');
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
	printf("�N�F");	  scanf("%d", &y1);
	printf("���F");	  scanf("%d", &m1);

	printf("�I���N������͂���B\n");
	printf("�N�F");	  scanf("%d", &y2);
	printf("���F");	  scanf("%d", &m2);

	putchar('\n');

	put_calendar(y1, m1, y2, m2);

	return 0;
}

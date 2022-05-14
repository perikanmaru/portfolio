#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<time.h>

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

int strncmpx(const char* s1, const char* s2, size_t n)
{
	while (n && toupper(*s1) && toupper(*s2)) {
		if (toupper(*s1) != toupper(*s2))			/* �������Ȃ� */
			return (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
		n--;
	}
	if (!n)	 return 0;
	if (*s1) return 1;
	return -1;
}

/*--- �����񂩂猎�̒l�𓾂� ---*/
int get_month(char* s)
{
	int i;
	int m;		/* �� */
	const char* month[] = { "", "January", "February", "March", "April",
						   "May", "June", "July", "August", "September",
							"October", "November", "December" };

	m = atoi(s);
	if (m >= 1 && m <= 12)			/* �����\�L�F"1", "2", �c, "12" */
		return m;

	for (i = 1; i <= 12; i++)		/* �p��\�L */
		if (strncmpx(month[i], s, 3) == 0)
			return i;

	return -1;						/* �ϊ����s */
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
	int i, j;

	if (n == 3) {
		for (i = 0; i < 2; i++)
			printf("%21s   ", sbuf[i][0]);
		printf("%21s", sbuf[2][0]);

		printf("\n");

		for (i = 0; i < 2; i++)
			printf("  �� �� �� �� �� �� �y  ");

		printf(" �� �� �� �� �� �� �y ");	/*�R�������Ƃɋ󔒕��������Ȃ�*/
		printf("\n");

		for (i = 0; i < 2; i++)
			printf("----------------------  ");
		printf("---------------------");		/*3�������Ƃɋ󔒕���������Ȃ�*/
		printf("\n");

		for (i = 1; i < 7; i++) {
			for (j = 0; j < 2; j++)
				printf("%-22s  ", sbuf[j][i]);

			printf("%-22s", sbuf[2][i]);	/*3�������Ƃɋ󔒕��������Ȃ�*/

			if (i == 5) {
				if (*sbuf[0][6] == *sbuf[1][6] && *sbuf[1][6] == *sbuf[2][6])	/*3���������ׂĂ�5�s�ŏI��鎞6�s�ڈȍ~��ǉ����Ȃ�*/
					i = i + 2;
			}
			printf("\n");
		}

		printf("\n");

	}
	else {									/*�\����3���������̏ꍇ��else�̕����ŏ�������*/
		for (i = 0; i < n; i++)
			printf("%22s   ", sbuf[i][0]);
		printf("\n");

		for (i = 0; i < n; i++)
			printf("  �� �� �� �� �� �� �y  ");
		printf("\n");

		for (i = 0; i < n; i++)
			printf("----------------------  ");
		printf("\n");

		for (i = 1; i < 7; i++) {
			for (j = 0; j < n; j++)
				printf("%-22s  ", sbuf[j][i]);
			printf("\n");
		}

		printf("\n");
	}

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


int main(int argc, char* argv[])
{
	int  y1, m1,y2,m2;							/*�\���̎w��̎d����*/
	time_t t = time(NULL);				/* ���݂̎������擾 */
	struct tm* local = localtime(&t);	/* �v�f�ʂ̎����i�n�����j�ɕϊ� */

	y1 = local->tm_year + 1900;			/* �����̔N */
	m1 = local->tm_mon + 1;				/* �����̌� */

	if (argc >= 2) {				/* argv[1]�̉�� */
		m1 = get_month(argv[1]);
		if (m1 < 0 || m1 > 12) {
			fprintf(stderr, "���̒l���s���ł��B\n");
			return 1;
		}
	}
	if (argc >= 3) {				/* argv[2]�̉�� */
		y1 = atoi(argv[2]);
		if (y1 < 0) {
			fprintf(stderr, "�N�̒l���s���ł��B\n");
			return 1;
		}
	}

	if (argc >= 4) {				/* argv[3]�̉�� */
		m2 = get_month(argv[3]);
		if (m2 < 0 || m2 > 12) {
			fprintf(stderr, "���̒l���s���ł��B\n");
			return 1;
		}
	}
	if (argc >= 5) {				/* argv[4]�̉�� */
		y2 = atoi(argv[4]);
		if (y2 < 0) {
			fprintf(stderr, "�N�̒l���s���ł��B\n");
			return 1;
		}
	}
	printf("%d�N%d������%d�N%d���܂ŕ\�����܂�\n\n", y1, m1,y2,m2);

	put_calendar(y1, m1,y2,m2);		/* y�Nm���̃J�����_�[��\�� */

	return 0;
}
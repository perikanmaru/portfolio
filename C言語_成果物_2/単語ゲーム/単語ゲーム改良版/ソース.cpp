#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	CNO		4		/* �I�����̐� */

#define swap(type, x, y)   do { type t = x; x = y; y = t; } while (0)

int	QNO;				/* �P��̐� */
char** jptr;			/* ���{��P��ւ̃|�C���^�̔z�� */
char** eptr;			/* �p�@��P��ւ̃|�C���^�̔z�� */

/*--- �I������\�� ---*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d) %s  ", i, sw ? jptr[c[i]] : eptr[c[i]]);
	printf("�F");
}

/*--- �I�����𐶐����Đ����̓Y����Ԃ� ---*/
int make_cand(int c[], int n)
{
	int i, j, x;

	c[0] = n;						/* �擪�v�f�ɐ��������� */

	for (i = 1; i < CNO; i++) {
		do {						/* �d�����Ȃ��悤�ɗ����𐶐� */
			x = rand() % QNO;
			for (j = 0; j < i; j++)
				if (c[j] == x)		/* ���ɓ����������������� */
					break;
		} while (i != j);
		c[i] = x;
	}

	j = rand() % CNO;
	if (j != 0)
		swap(int, c[0], c[j]);	/* �������ړ� */

	return j;
}

/*--- �P���ǂݍ��� ---*/
int read_tango(void)
{
	int	i = 0;
	FILE* fp;

	if ((fp = fopen("TANGO", "r")) == NULL) return 1;

	fscanf(fp, "%d", &QNO);			/* �P�ꐔ��ǂݍ��� */

	if ((jptr = (char **)calloc(QNO, sizeof(char*))) == NULL) return -1;
	if ((eptr = (char **)calloc(QNO, sizeof(char*))) == NULL) return -1;

	for (i = 0; i < QNO; i++) {
		char etemp[1024];
		char jtemp[1024];

		fscanf(fp, "%s%s", etemp, jtemp);
		if ((eptr[i] = (char *)malloc(strlen(etemp) + 1)) == NULL) return i;
		if ((jptr[i] = (char *)malloc(strlen(jtemp) + 1)) == NULL) return i;
		strcpy(eptr[i], etemp);
		strcpy(jptr[i], jtemp);
	}
	fclose(fp);

	return 0;/*��������0��Ԃ�*/
}

int main(void)
{
	int i;
	int j;
	int nq, pq;			/* ���ԍ��E�O��̖��ԍ� */
	int na;				/* �����̔ԍ� */
	int sw;				/* ���̌���i0�F���{��^1�F�p��j */
	int retry;			/* �Ē��킷�邩�H */
	int cand[CNO];		/* �I�����̔ԍ� */
	int clean = 0;		/*����������p�ϐ�*/
	int k = 0;
	
		k = read_tango();

		switch (k)
		{
		case 0:/*�t�@�C���̓ǂݍ��݂ɐ���*/
			break;
		case 1:
			/*���������t�@�C�����J���Ȃ������ꍇ�̏���*/
			printf("\a�P��t�@�C���̓Ǎ��݂Ɏ��s���܂����B\n");
			return 1;
			break;
		case -1:
			/*������(�̈�)�̊m�ۂ��ł��Ȃ������ꍇ*/
			printf("\a�P��t�@�C���̓Ǎ��݂Ɏ��s���܂����B\n");
			return 1;
			break;
		default:
			/*������(�̈�)�̊m�ۂ͂ł�����������̃�����(�̈�)�̊m�ۂ����s�����ꍇ*/
			printf("\a�P��t�@�C���̓Ǎ��݂Ɏ��s���܂����B\n�P��w�K�\�t�g���I�����܂�...");
			for (clean = 0; clean < k; clean++) {
				free(eptr[i]);
				free(jptr[i]);
			}
			free(eptr);
			free(jptr);
			return 1;
			break;
		}

	srand(time(NULL));	/* �����̎��ݒ� */

	pq = QNO;			/* �O��̖��ԍ��i���݂��Ȃ��ԍ��j */

	do {
		int no;

		do {						/* �o�肷��P��̔ԍ������� */
			nq = rand() % QNO;
		} while (nq == pq);			/* �����P���A�����ďo�肵�Ȃ� */

		na = make_cand(cand, nq);	/* �I�����𐶐� */
		sw = rand() % 2;

		printf("%s�͂ǂ�ł����H\n", sw ? eptr[nq] : jptr[nq]);

		do {
			print_cand(cand, sw);	/* �I������\�� */
			scanf("%d", &no);
			if (no != na)
				puts("�Ⴂ�܂��B");
		} while (no != na);
		puts("�����ł��B");

		pq = nq;

		printf("������x�H 0-�������^1-�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < QNO; i++) {
		free(eptr[i]);
		free(jptr[i]);
	}
	free(jptr);
	free(eptr);

	return 0;
}

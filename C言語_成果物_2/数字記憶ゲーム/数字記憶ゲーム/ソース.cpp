#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE	10							/* �X�e�[�W�� */

/*--- x�~���b�o�߂���̂�҂� ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* �G���[ */
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int stage;
	int success = 0;						/* ���� */
	clock_t start, end;

	int k, L;									/*�������킹�p�ϐ�*/
	int correct = 0;
	srand(time(NULL));						/* �����̎��ݒ� */

	printf("�S���̐��l���L������4���̂����w�����ꂽ1�𓚂��Ă��������B\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {

		int o, p, q, r = 0;	                   /*���͗p�ϐ�*/
		int k = 0;								/*���͂��鐔���w���p*/

		int a, b, c, d = 0;						/*�l���̗������� (a>1)*/
		a = 1 + rand() % 9;
		b = 0 + rand() % 10;
		c = 0 + rand() % 10;
		d = 0 + rand() % 10;

		printf("%d%d%d%d", a, b, c, d);
		fflush(stdout);
		sleep(2000);

		k = rand() % 4;                        /*0�`�R�̐����𐶐�*/

		switch (k)
		{
		case 0:
			printf("\r1���ڂ���͂��� :");
			fflush(stdout);
			scanf("%d", &o);

			if (o == a) {
				printf("�����ł��B\n");
				success++;
				break;
			}
			else
				printf("�ԈႢ�ł��B");
			break;

		case 1:
			printf("\r2���ڂ���͂��� :");
			fflush(stdout);
			scanf("%d", &p);

			if (p == b) {
				printf("�����ł��B\n");
				success++;
				break;
			}
			else
				printf("�ԈႢ�ł��B");
			break;

		case 2:
			printf("\r3���ڂ���͂��� :");
			fflush(stdout);
			scanf("%d", &q);

			if (q == c) {
				printf("�����ł��B\n");
				success++;
				break;
			}
			else
				printf("�ԈႢ�ł��B");
			break;

		case 3:
			printf("\r4���ڂ���͂��� :");
			fflush(stdout);
			scanf("%d", &r);

			if (r == d) {
				printf("�����ł��B\n");
				success++;
				break;
			}
			else
				printf("�ԈႢ�ł��B");
			break;
		default:
			break;
		}
	}

	end = clock();

	printf("%d��%d�񐬌����܂����B\n", MAX_STAGE, success);
	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;

}
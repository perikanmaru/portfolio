#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE	10      /* �X�e�[�W�� */

/*--- x�~���b�o�߂���̂�҂� ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}


int main(void)
{
	int i, stage;

	int k = 0;							/*swhic���p�ϐ�*/
	char a[128];						/*���딻��p������*/

	int success = 0;		         /* ���� */
	clock_t start, end;		         /* �J�n�����E�I������ */

	srand(time(NULL));		         /* �����̎��ݒ� */

	printf("���l�L���g���[�j���O\n");
	printf("�w�肳�ꂽ4�����̂���1��������͂��Ă��������B\n");

	start = clock();				/*�v���J�n*/

	for (stage = 0; stage < MAX_STAGE; stage++) {

		char no[4 + 1];				/* �����̕��� */
		char x[4 * 2];				/* �ǂ݂��ސ����̕���(�v���C���[����) */

		no[0] = '1' + rand() % 9;			/* �擪������'1'�`'9' */

		for (i = 1; i < 4; i++)
			no[i] = '0' + rand() % 10;		/* ����ȍ~��'0'�`'9' */

		no[4] = '\0';

		printf("%s", no);
		fflush(stdout);
		sleep(2000);					/* ���񎦂�1500�~���b */

		k = rand() % 4;
										
		switch (k) {
		case 0:
			printf("\r1�����ڂ���͂��Ă��������B");
			fflush(stdout);
			scanf("%s",x);
			a[0] = no[0];							/*no��k�Ԃ߂̕������a�̈�ԍŏ��Ɏ����Ă���A������v���C���[���͂����̂��r*/
		
			if (a[0]==x[0]) {						/*���딻��*/
				printf("�����ł��B\n");
				success++;
				break;
			}
			else
				printf("�ԈႢ�ł��B\n");
			break;
		case 1:
			printf("\r2�����ڂ���͂��Ă��������B");
			fflush(stdout);
			scanf("%s",x);
			a[0] = no[1];
			if (a[0]==x[0]) {
				printf("�����ł��B\n");
				success++;
				break;
			}
			else
			printf("�ԈႢ�ł��B\n");
			break;

		case 2:
			printf("\r3�����ڂ���͂��Ă��������B");
			fflush(stdout);
			scanf("%s", x);
			a[0] = no[2];
			if (a[0]==x[0]) {
				printf("�����ł��B\n");
				success++;
				break;
			}
			else
				printf("�ԈႢ�ł��B\n");
			break;

		case 3:
			printf("\r4�����ڂ���͂��Ă��������B");
			fflush(stdout);
			scanf("%s", x);
			a[0] = no[3];
			if (a[0]==x[0]) {
				printf("�����ł��B\n");
				success++;
				break;
			}
			else
				printf("�ԈႢ�ł��B\n");
			break;

			default:
			break;
		}
	}

	end = clock();						/*�v���I��*/

	printf("%d��%d�񐬌����܂����B\n", MAX_STAGE, success);
	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

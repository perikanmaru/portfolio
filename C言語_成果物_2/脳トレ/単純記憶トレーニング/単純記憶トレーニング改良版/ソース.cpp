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
	                                
	int k = 0;						/*�t�����p�ϐ�*/
	char a[4 * 2];

	int success = 0;		         /* ���� */
	clock_t start, end;		         /* �J�n�����E�I������ */

	srand(time(NULL));		         /* �����̎��ݒ� */

	printf("���l�L���g���[�j���O\n");

	
	printf("4���̐��l���L�����܂��傤�B\n");
	printf("���l���t�����ɓ��͂��Ă�������\n");
	                            
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

		printf("\r���͂���F");
		scanf("%s", x);

		for (k = 0; k < 4; k++) {         /*�z����t�����ɂ���B(�v���C���[�͋t�����ɓ��͂��Ă���͂��Ȃ̂ŋt�����ɂ���Δz��̕��т������ɂȂ�B)*/
			a[k] = x[3 - k];
		}

		a[4] = '\0';                    /*�t�ɂ����z��̍Ō�̓i������*/


		if (strcmp(no,a)==0) {			/*���딻��*/
			printf("�����ł��B\n");
			success++;
		}
		else
			printf("�ԈႢ�ł��B\n");

	}

	end = clock();						/*�v���I��*/

	printf("%d��%d�񐬌����܂����B\n", MAX_STAGE, success);
	printf("%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

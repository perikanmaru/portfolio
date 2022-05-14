#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	

static void init_getputch(void) { /* �� */ }

static void term_getputch(void) { /* �� */ }


#define MAX_STAGE	5			/* ����� */
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	int i, j, stage;
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8];
	double jikan;				/* ���� */
	clock_t start, end;			/* �J�n�����E�I������ */

	srand(time(NULL));			/* �����̎��ݒ� */

	printf("�����Ă��鐔������͂��Ă��������B\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* 0�`8�̗����𐶐� */
		int no = 10;					/* �ǂݍ��񂾒l */
		int k = 0;
		int n = 0;
		i = j = 0;
		while (i < 9) {			/* dgt[x]���΂��ăR�s�[ */
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {			/* �z��a���V���b�t�� */
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++) {		/* �S�v�f��\�� */
			k = rand() % 4;

				switch (k)
				{
				case 0:
					for (n = 0; n < 3; n++) {
						printf("   ");
					}
					printf("%d", a[i]);
					break;
				case 1:
					printf("%d",a[i]);
					break;
				case 2:
					for (n = 0; n < 5; n++) {
						printf(" ");
					}
					printf("%d", a[i]);
					break;
				case 3:
					for (n = 0; n < 1; n++) {
						printf("  ");
					}
					printf("%d", a[i]);
					break;
				default:
					printf("%d",a[i]);
					break;
				}

				if (i == 2)
					printf("\n");
				else if (i == 5)
					printf("\n");
				else if (i == 7)
					printf("\n");
		}
		printf("\n : ");
		do {
			no = getch();
			putch(no);
			printf("\n");	/* ���s */
		} while (no != dgt[x] + 48);		/* ���������͂����܂ŌJ��Ԃ�no���{48����Ă�̂�48��dgx�ɑ���*/
		printf("\n");
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

	return 0;
}
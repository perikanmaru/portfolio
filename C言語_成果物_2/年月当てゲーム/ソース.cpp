#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void) {


	int a = 0;
	int b = 0;
	int c = 0;
	int break_loop = 0;
	int year = 0;
	int month = 0;
	int day = 0;

	int correct_year = 0;
	int correct_month = 0;
	int correct_day = 0;

	clock_t start, end;

	srand(time(NULL));

	printf("�����ăQ�[�����J�n���܂��I\n");

	year  = rand() % 300 + 1970;
	month = rand() % 12 + 1;
	day   = rand() % 31 + 1;

	printf("%d\n%d\n%d\n", year, month, day);

	do {
		start = clock();

		if ( correct_year == 0) {						/*�N�A���A���̓��́@��������Ɠ��͂𖳎�����*/
			printf("\n�N����͂��Ă��������B\n�N : ");
			scanf("%d", &a);
		}
		else {
			;
		}

		if (correct_month == 0) {
			printf("\n������͂��Ă��������B\n�� : ");
			scanf("%d", &b);
		}
		else {
			;
		}

		if (correct_day == 0) {
			printf("\n������͂��Ă��������B\n�� : ");
			scanf("%d", &c);
		}
		else {
			;
		}

		if (a > year&&correct_year==0) {				/*����J�n*/
			printf("�����Ə������ł���\n");
		}
		else if (a < year) {
			printf("�����Ƒ傫���ł���\n");
		}
		else if(correct_year==0){
			printf("�����ł�\n");
			correct_year = 1;
		}
		else
			;

		if (b > month && correct_month == 0) {
			printf("�����Ə������ł���\n");
		}
		else if (b < month) {
			printf("�����Ƒ傫���ł���\n");
		}
		else if (correct_month == 0) {
			printf("�����ł�\n");
			correct_month = 1;
		}
		else
			;

		if (c > day && correct_day == 0) {
			printf("�����Ə������ł���\n");
		}
		else if (c < day) {
			printf("�����Ƒ傫���ł���\n");
		}
		else if (correct_day == 0) {
			printf("�����ł�\n");
			correct_day = 1;
		}
		else
			;

		break_loop = (correct_year + correct_month + correct_day);			/*���ׂĐ������������肷�邽�߂̕ϐ��ɑ��*/


	} while (break_loop<=2);	/*���[�v�𔲂��邩����*/

	end = clock();

	printf("\n���ׂĂɐ������܂����I������%d�N%d��%d���ł���\n",year,month,day);
	printf("�����ɂ����������Ԃ�%.1f�b�ł����B\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
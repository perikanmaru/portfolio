#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int kuji;
	int retry;

		srand((unsigned int)time(NULL));

		do {
			kuji = rand() % 199;
			
			if (kuji < 1)
				printf("���߂łƂ��������܂��I1���ł��B\n");
			else if (kuji < 5)
				printf("���߂łƂ��������܂��I2���ł��B\n");
			else if (kuji < 21)
				printf("���߂łƂ��������܂��I3���ł��B\n");
			else
				printf("�͂���ł��B\n");
			printf("������x�����܂����H\n");
			scanf("%d", &retry);
		} while (retry != 0);
		return 0;

}
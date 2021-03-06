#include <time.h>
#include <float.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>

#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

const char* Japanese[] = {
	"1月",
	"2月",
	"3月",
	"4月",
	"5月",
	"6月",
	"7月",
	"8月",
	"9月",
	"10月",
	"11月",
	"12月",
};

const char* English[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"Novemver",
	"December",

};


void shuffle(int array[], int size) {

	for (int i = 0; i < size; i++) {
		int j = rand() % size;
		int t = array[i];
		array[i] = array[j];
		array[j] = t;
	}
}

int main(void) {

	int issue[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	int sucsess_question[12] = { 0 };
	int miss_question[12] = { 0 };
	int k = 0;
	int n = 0;
	int a = 0;
	int t = 0;
	int s = 0;
	int m = 0;
	int b = 0;
	int miss = 0;
	int print_English = 0;
	char answer[10];
	int success = 0;
	int stage = 0;

	srand(time(NULL));								/* 乱数の種を初期化 */

	shuffle(issue, 12);

	for (stage = 0; stage < 12; stage++) {
		k = issue[stage];

		do {
			printf("%s : ", Japanese[k]);
			fflush(stdout);
			scanf("%s", answer);

			if (strcmp(answer, English[k]) != 0) {
				printf("違います\n");

				if (miss <= 4) {
					printf("答えを表示しますか？ YES...1 / NO...0 : ");
					scanf("%d", &print_English);
					if (print_English == 1) {
						printf("%s\n", English[k]);
						miss++;
					}
					else
						;
				}
				if (miss >= 5) {
					printf("%s\n", English[k]);
				}
			}
			else {
				printf("正解です\n");
				success = 1;
			}

		} while (success < 1);

		if (miss == 0) {
			sucsess_question[t] = issue[stage];
			t++;
			s++;
		}
		else {
			miss_question[m] = issue[stage];
			m++;
		}

		miss = 0;
		a = 0;
		success = 0;
	}
	printf("12問中%d問正解しました\n", s);

	for (k = 0; k < t; k++) {
		printf("%d月 ", sucsess_question[k] + 1);
	}
	printf("\n");
	for (b = 0; b < m; b++) {
		printf("%d月 ", miss_question[b] + 1);
	}

}
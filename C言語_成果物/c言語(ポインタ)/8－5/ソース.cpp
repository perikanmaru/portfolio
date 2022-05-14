#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>	
#include<ctype.h>

static void init_getputch(void) { /* ‹ó */ }

static void term_getputch(void) { /* ‹ó */ }

const char* Alfabet[] = {
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"N",
	"M",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z"
};

int main(void) {

	init_getputch();

	srand(time(NULL));								/* —”‚Ìí‚ğİ’è */

	int i = 0;
	int k = 0;
	int j = 0;
	int n = 0;
	int mno = 0;
	int tno = 0;
	int misstype[20] = { 0 };
	int mistake = 0;				/* ƒ~ƒX‰ñ” */
	int str;
	int str_2[128];
	const char* english[128] = {};

	init_getputch();

	for (i = 0; i < 5; i++) {
	k=rand() % 25;
	english[i] = Alfabet[k];
	}

	for (n = 0; n < 5; n++) {
		printf("%s", english[n]);
	}
	printf("\n");
	for (i = 0; i < 5; i++) {
		printf("%s \r", english[i]);
		fflush(stdout);
		while (getch() != english[i][j]);
	}
	return 0;

}
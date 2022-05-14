#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>	

static void init_getputch(void) { /* �� */ }

static void term_getputch(void) { /* �� */ }


#define	NO			15			/* �g���[�j���O�� */
#define	KTYPE		16			/* �u���b�N�� */
#define	POS_LEN		10			/* �|�W�V�����g���[�j���O�̕����� */

/*���K���j���[*/
typedef enum { Term, KeyPos, KeyPosComp, Clang, Conversation, Expected, Blocktype2, Blocktype3, Invalid } Menu;

int jpn = -1; /*���{���\�����邩���ʂ��鎞�Ɏg���ϐ�*/
char q2[21];
char q3[41];

/*�e��Q�[���Z�[�u�p�f�[�^�t�@�C��*/
char data_file[] = "pos_traning.txt";
char data_file2[] = "pos_training2.txt";
char data_file3[] = "word_trainig(c).txt";
char data_file4[] = "word_trainig(English).txt";
char data_file5[] = "word_trainig(English_Plus).txt";
char data_file6[] = "key_expect.txt";
char data_file7[] = "blocktype_2.txt";
char data_file8[] = "blocktype_3.txt";

/*�e�u���b�N�̃L�[*/
const char* kstr[] = {
	"12345",  "67890-^\\",		/* ��P�i         */
	"!\"#$%", "&'()=~|",		/* ��P�i [Shift] */
	"qwert",  "yuiop@[",		/* ��Q�i         */
	"QWERT",  "YUIOP`{",		/* ��Q�i [Shift] */
	"asdfg",  "hjkl;:]",		/* ��R�i         */
	"ASDFG",  "HJKL+*}",		/* ��R�i [Shift] */
	"zxcvb",  "nm,./\\",		/* ��S�i         */
	"ZXCVB",  "NM<>?_",			/* ��S�i [Shift] */
};

/*�b����̃L�[���[�h�ƃ��C�u�����֐�*/
const char* cstr[] = {
	"auto",		"break",	"case",		"char",		"const",	"continue",
	"default",	"do",		"double",	"else",		"enum",		"extern",
	"float",	"for",		"goto",		"if",		"int",		"long",
	"register",	"return",	"short",	"signed",	"sizeof",	"static",
	"struct",	"switch",	"typedef",	"union",	"unsigned",	"void",
	"volatile",	"while",
	"abort",	"abs",		"acos",		"asctime",	"asin",		"assert",
	"atan",		"atan2",	"atexit",	"atof",		"atoi",		"atol",
	"bsearch",	"calloc",	"ceil",		"clearerr",	"clock",	"cos",
	"cosh",		"ctime",	"difftime",	"div",		"exit",		"exp",
	"fabs",		"fclose",	"feof",		"ferror",	"fflush",	"fgetc",
	"fgetpos",	"fgets",	"floor",	"fmod",		"fopen",	"fprintf",
	"fputc",	"fputs",	"fread",	"free",		"freopen",	"frexp",
	"fscanf",	"fseek",	"fsetpos",	"ftell",	"fwrite",	"getc",
	"getchar",	"getenv",	"gets",		"gmtime",	"isalnum",	"isalpha",
	"iscntrl",	"isdigit",	"isgraph",	"islower",	"isprint",	"ispunct",
	"isspace",	"isupper",	"isxdigit",	"labs",		"ldexp",	"ldiv",
	"localeconv",			"localtime","log",		"log10",	"longjmp",
	"malloc",	"memchr",	"memcmp",	"memcpy",	"memmove",	"memset",
	"mktime",	"modf",		"perror",	"pow",		"printf",	"putc",
	"putchar",	"puts",		"qsort",	"raise",	"rand",		"realloc",
	"remove",	"rename",	"rewind",	"scanf",	"setbuf",	"setjmp",
	"setlocale","setvbuf",	"signal",	"sin",		"sinh",		"sprintf",
	"sqrt",		"srand",	"sscanf",	"strcat",	"strchr",	"strcmp",
	"strcoll",	"strcpy",	"strcspn",	"strerror",	"strftime",	"strlen",
	"strncat",	"strncmp",	"strncpy",	"strpbrk",	"strrchr",	"strspn",
	"strstr",	"strtod",	"strtok",	"strtol",	"strtoul",	"strxfrm",
	"system",	"tan",		"tanh",		"time",		"tmpfile",	"tmpnam",
	"tolower",	"toupper",	"ungetc",	"va_arg",	"va_end",	"va_start",
	"vfprintf", "vprintf",	"vsprintf"
};

/*�p��b*/
const char* vstr[] = {
	"Hello!",							/* ����ɂ��́B*/
	"How are you?",						/* �����C�ł����B */
	"Fine thanks.",						/* �͂����C�ł��B */
	"I can't complain, thanks.",		/* �܂��A���Ƃ��B */
	"How do you do?",					/* ���߂܂��āB */
	"Good bye!",						/* ���悤�Ȃ�B */
	"Good morning!",					/* ���͂悤�B */
	"Good afternoon!",					/* ����ɂ��́B */
	"Good evening!",					/* ����΂�́B */
	"See you later!",					/* ���悤�Ȃ�i�܂��ˁj�B */
	"Go ahead, Please.",				/* ����ɂǂ����B */
	"Thank you.",						/* ���肪�Ƃ��B */
	"No, thank you.",					/* ���������\�ł��B */
	"May I have your name?",			/* �����O�́H */
	"I'm glad to meet you.",			/* ���ڂɂ�����Č��h�ł��B */
	"What time is it now?",				/* �����ł����B */
	"It's about seven.",				/* ��̂V�����炢�ł��B */
	"I must go now.",					/* ���������Ȃ�����B */
	"How much?",						/* ��������H */
	"Where is the restroom?",			/* ����􂢂͂ǂ���ł����B */
	"Excuse me.",						/* ���炵�܂��i��l�j�B*/
	"Excuse us.",						/* ���炵�܂��i��l�ȏ�j�B*/
	"I'm sorry.",						/* ���߂�Ȃ����B */
	"I don't know.",					/* �����A�m��Ȃ���B */
	"I have no change with me.",		/* ���K���Ȃ��̂ł��B */
	"I will be back.",					/* �܂��߂��ė��܂��B */
	"Are you going out?",				/* �o������́H */
	"I hope I'm not disturbing you.",	/* ���ז�����Ȃ���΂����̂ł����B*/
	"I'll offer no excuse.",			/* �ى��������͂���܂���B */
	"Shall we dance?",					/* �x��܂��񂩁B */
	"Will you do me a favor?",			/* ������Ƃ��肢�������̂ł����B */
	"It's very unseasonable.",			/* ����͋G�ߊO�ꂾ�ˁB */
	"You are always welcome.",			/* ���ł����}���܂���B */
	"Hold still!",						/* �����Ƃ��āI */
	"Follow me.",						/* �t���ė��āB */
	"Just follow my lead.",				/* �l�̂���Ƃ���ɂ�邾������B */
	"To be honest with you,",			/* �����Ɍ����Ɓc */
};

/*���{���*/
const char* vstr_japanese[] = {
	"����ɂ��́B",
	"�����C�ł����B",
	"�͂����C�ł��B",
	"�܂��A���Ƃ��B",
	"���߂܂��āB",
	"���悤�Ȃ�B",
	"���͂悤�B",
	"����ɂ��́B",
	"����΂�́B",
	"���悤�Ȃ�i�܂��ˁj�B",
	"����ɂǂ����B",
	"���肪�Ƃ��B",
	"���������\�ł��B",
	"�����O�́H",
	" ���ڂɂ�����Č��h�ł��B ",
	"�����ł����B",
	"��̂V�����炢�ł��B",
	"���������Ȃ�����B",
	"��������H",
	"����􂢂͂ǂ���ł����B",
	"���炵�܂��i��l�j�B",
	"���炵�܂��i��l�ȏ�j�B",
	"���߂�Ȃ����B",
	"�����A�m��Ȃ���B",
	"���K���Ȃ��̂ł��B",
	"�܂��߂��ė��܂��B",
	"�o������́H",
	"���ז�����Ȃ���΂����̂ł����B",
	"�ى��������͂���܂���B",
	"�x��܂��񂩁B",
	"������Ƃ��肢�������̂ł����B",
	"����͋G�ߊO�ꂾ�ˁB",
	"���ł����}���܂���B ",
	"�����Ƃ��āI",
	"�t���ė��āB",
	"�l�̂���Ƃ���ɂ�邾������B ",
	"�����Ɍ����Ɓc"
};

double save_data(int n, double type_time, double type_rate, int type_miss) {

	FILE* fp;
	if (jpn == -1) {
		n = 2;
	}
	else if (jpn == 0) {
		n = 3;
	}
	else if (jpn == 1) {
		n = 4;
	}

	switch (n)
	{
	case 0:
		if ((fp = fopen(data_file, "a+")) == NULL) {
			printf("�ۑ�����t�@�C�����쐬���܂����B�@���񂩂�ۑ����J�n����܂�\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 1:
		if ((fp = fopen(data_file2, "a+")) == NULL) {
			printf("�ۑ�����t�@�C�����쐬���܂����B�@���񂩂�ۑ����J�n����܂�\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 2:
		if ((fp = fopen(data_file3, "a+")) == NULL) {
			printf("�ۑ�����t�@�C�����쐬���܂����B�@���񂩂�ۑ����J�n����܂�\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 3:
		if ((fp = fopen(data_file4, "a+")) == NULL) {
			printf("�ۑ�����t�@�C�����쐬���܂����B�@���񂩂�ۑ����J�n����܂�\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 4:
		if ((fp = fopen(data_file5, "a+")) == NULL) {
			printf("�ۑ�����t�@�C�����쐬���܂����B�@���񂩂�ۑ����J�n����܂�\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 5:
		if ((fp = fopen(data_file6, "a+")) == NULL) {
			printf("�ۑ�����t�@�C�����쐬���܂����B�@���񂩂�ۑ����J�n����܂�\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 6:
		if ((fp = fopen(data_file7, "a+")) == NULL) {
			printf("�ۑ�����t�@�C�����쐬���܂����B�@���񂩂�ۑ����J�n����܂�\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 7:
		if ((fp = fopen(data_file8, "a+")) == NULL) {
			printf("�ۑ�����t�@�C�����쐬���܂����B�@���񂩂�ۑ����J�n����܂�\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;

	default:
		;
		break;
	}
	return 0;
}

/*������str���^�C�v���K�i�~�X�񐔂�Ԃ��j*/
int go(const char* str, int no)
{
	int i;
	int len = strlen(str);			/* ������ */
	int mistake = 0;				/* �~�X�� */

	switch (jpn) {
	case 0:
		for (i = 0; i < len; i++) {
			/* str[i]�ȍ~��\�����ăJ�[�\����擪�֖߂� */
			printf("%s \r", &str[i]);
			fflush(stdout);
			while (getch() != str[i]) {
				mistake++;
			}
		}
		break;
	case 1:	/*jpn��1�Ȃ���{�����\��*/
		for (i = 0; i < len; i++) {
			/* str[i]�ȍ~��\�����ăJ�[�\����擪�֖߂� */
			printf("%s  %s        \r", vstr_japanese[no], &str[i]);
			fflush(stdout);
			while (getch() != str[i]) {
				mistake++;
			}
		}
		break;
	}
	return (mistake);
}

/*�P���|�W�V�����g���[�j���O*/
void pos_training(int k)
{
	int i;
	int stage;
	int temp, line;
	int len;						/* ���̃u���b�N�̃L�[�� */
	int qno, pno;					/* ���ԍ��E�O��̖��ԍ� */
	int tno, mno;					/* �������E�~�X�� */
	double timer;

	clock_t	start, end;				/* �J�n�����E�I������ */

	printf("\n�P���|�W�V�����g���[�j���O���s���܂��B\n");
	printf("���K����u���b�N��I�����Ă��������B\n");
	printf("��1�i (1) �� %-8s    (2) �E %-8s\n", kstr[0], kstr[1]);
	printf("��2�i (3) �� %-8s    (4) �E %-8s\n", kstr[4], kstr[5]);
	printf("��3�i (5) �� %-8s    (6) �E %-8s\n", kstr[8], kstr[9]);
	printf("��4�i (7) �� %-8s    (8) �E %-8s\n", kstr[12], kstr[13]);

	/* �u���b�N��I�������� */
	do {
		printf("�ԍ��i���K���~��99�j�F");
		scanf("%d", &temp);
		if (temp == 99) return;				/* ���K���~ */
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("%s�̖���%d����K���܂��B\n", kstr[line], NO);

	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;

	tno = mno = 0;						/* �������E�~�X�񐔂��N���A */
	len = strlen(kstr[line]);			/* ���K����u���b�N�̃L�[�� */

	start = clock();						/* �J�n���� */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++)	/* ��蕶������쐬 */
			str[i] = kstr[line][rand() % len];
		str[i] = '\0';

		mno += go(str, 0);						/* ���K���s */
		tno += strlen(str);
	}

	end = clock();							/* �I������ */

	printf("���F%d�����^�~�X�F%d��\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f�b�ł����B\n", timer);
	printf("1����������̃^�C�v���x��%.2f(�b/����)�A1���Ԃ̃^�C�v�ʂ�%.1f(����/��)�ł��B\n", (double)timer / tno, (double)tno * 60 / timer);

	save_data(k, timer, (double)tno * 60 / timer, mno);		/*�Z�[�u�p�֐��ɏ���`���鏇�Ԃ�(�@switch�p�ϐ��@���v���ԁ@1���ԓ�����̃^�C�v���x�@�@�~�X��)*/
}

/*--- �����|�W�V�����g���[�j���O ---*/
void pos_training2(int k)
{
	int i;
	int stage;
	int temp, line;
	int sno;						/* �I�΂ꂽ�u���b�N�� */
	int select[KTYPE];				/* �I�΂ꂽ�u���b�N */
	int len[KTYPE];					/* ���̃u���b�N�̃L�[�� */
	int tno, mno;					/* �������E�~�X�� */
	clock_t	start, end;				/* �J�n�����E�I������ */
	double timer;
	const char* format = "��%d�i (%2d) �� %-8s (%2d) �E %-8s "
		"(%2d)[��] %-8s (%2d)[�E] %-8s\n";

	printf("\n�����|�W�V�����g���[�j���O���s���܂��B\n");
	printf("���K����u���b�N��I�����Ă��������i�����I�ׂ܂��j�B\n");

	for (i = 0; i < 4; i++) {
		int k = i * 4;
		printf(format, i + 1, k + 1, kstr[k], k + 2, kstr[k + 1],
			k + 3, kstr[k + 2], k + 4, kstr[k + 3]);
	}

	/* �u���b�N���d���������ɑI��������i�ő�16�j */
	sno = 0;
	while (1) {
		printf("�ԍ��i�I���I����50�^���K���~��99�j�F");

		do {
			scanf("%d", &temp);
			if (temp == 99) return;			/* ���K���~ */
		} while ((temp < 1 || temp > KTYPE) && temp != 50);

		if (temp == 50)
			break;
		for (i = 0; i < sno; i++)
			if (temp == select[i]) {
				printf("\a���̒i�͊��ɑI�΂�Ă��܂��B\n");
				break;
			}
		if (i == sno)
			select[sno++] = temp;			/* �I�΂ꂽ�u���b�N��o�^ */
	}

	if (sno == 0)							/* ����I�΂�Ȃ����� */
		return;

	printf("�ȉ��̃u���b�N�̖���%d����K���܂��B\n", NO);

	for (i = 0; i < sno; i++)
		printf("%s ", kstr[select[i] - 1]);

	printf("\n�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;

	tno = mno = 0;							/* �������E�~�X�񐔂��N���A */
	for (i = 0; i < sno; i++)
		len[i] = strlen(kstr[select[i] - 1]);	/* �u���b�N�̃L�[�� */

	start = clock();						/* �J�n���� */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++) {		/* ��蕶������쐬 */
			int q = rand() % sno;
			str[i] = kstr[select[q] - 1][rand() % len[q]];
		}
		str[i] = '\0';

		mno += go(str, 0);						/* ���K���s */
		tno += strlen(str);
	}

	end = clock();							/* �I������ */

	printf("���F%d�����^�~�X�F%d��\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f�b�ł����B\n", timer);
	printf("1����������̃^�C�v���x��%.2f(�b/����)�A1���Ԃ̃^�C�v�ʂ�%.1f(����/��)�ł��B\n", (double)timer / tno, (double)tno * 60 / timer);
	save_data(k, timer, (double)tno * 60 / timer, mno);
}

/*--- �b����^�p��b�g���[�j���O ---*/
void word_training(const char* mes, const char* str[], int n)
{
	int stage;
	int qno, pno;					/* ���ԍ��E�O��̖��ԍ� */
	int tno, mno;					/* �������E�~�X�� */
	int i, ch, memory[128];
	double timer;
	clock_t	start, end;				/* �J�n�����E�I������ */

	printf("\n%s��%d���K���܂��B\n", mes, NO);

	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;

	tno = mno = 0;					/* �������E�~�X�񐔂��N���A */
	pno = n;						/* �O��̖��ԍ��i���݂��Ȃ��ԍ��j */

	start = clock();				/* �J�n���� */

	for (stage = 0; stage < NO; stage++) {
		do {						/* ��������A�����ďo�肵�Ȃ� */
			ch = 0;
			qno = rand() % n;
			for (i = 0; i < stage; i++) {
				if (memory[i] == qno && stage > 0)	/*���ԍ���1��ł��o�Ă�����̂ł���΂�蒼��*/
					ch++;
			}
		} while (ch != 0);
		memory[stage] = qno;		/*���ԍ���memory�ɋL��*/


		mno += go(str[qno], qno);		/* ����str[qno] */
		tno += strlen(str[qno]);
	}

	end = clock();					/* �I������ */

	printf("���F%d�����^�~�X�F%d��\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f�b�ł����B\n", timer);
	printf("1����������̃^�C�v���x��%.2f(�b/����)�A1���Ԃ̃^�C�v�ʂ�%.1f(����/��)�ł��B\n", (double)timer / tno, (double)tno * 60 / timer);
	save_data(10,timer, (double)tno * 60 / timer, mno);
}

/*�L�[�z�u�A�z�^�C�s���O�g���[�j���O*/
void keyexpect(int k)
{
	int i, stage, mno;
	double timer;
	clock_t start, end;
	init_getputch();
	srand(time(NULL));
	printf("�L�[�ʒu�A�z�^�C�s���O���K���n�߂܂��B\n");
	printf("�H�ŉB���ꂽ�������^�C�v���Ă��������B\n");
	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	fflush(stdout);
	while (getch() != ' ')
		;
	start = clock();
	mno = 0;
	for (stage = 0; stage < NO; stage++) {
		int k, p, key;
		char temp[10];
		do {
			k = rand() % KTYPE;
			p = rand() % strlen(kstr[k]);
			key = kstr[k][p];
		} while (key == ' ');
		strcpy(temp, kstr[k]);
		temp[p] = '?';
		printf("%s", temp);
		fflush(stdout);
		while (getch() != key)
			mno++;
		putchar('\n');
	}
	end = clock();
	printf("���F%d��^�~�X�F%d��\n", stage, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f�b�ł����B\n", timer);
	printf("1����������̃^�C�v���x��%.2f(�b/����)�A1���Ԃ̃^�C�v�ʂ�%.1f(����/��)�ł��B\n", (double)timer / stage, (double)stage * 60 / timer);
	save_data(k, timer, (double)stage * 60 / timer, mno);
	term_getputch();
}

/*�u���b�N�^�C�s���O�i2���q�j�̖��쐬*/
void question2(char ks2, char ks1)
{
	int i;
	for (i = 0; i < 5; i++) {
		q2[i * 2] = ks1;
		q2[i * 2 + 1] = ks2;
	}
	q2[10] = ' ';
	for (i = 5; i < 10; i++) {
		q2[i * 2 + 1] = ks2;
		q2[i * 2 + 2] = ks1;
	}
}

/*�u���b�N�^�C�s���O���K�i2���q�j*/
void blocktype_2(int k)
{
	int retry, str, qno, mno, tno, no;
	int i, j;
	double timer;
	clock_t start, end;
	srand(time(NULL));
	printf("�^�C�s���O���K���s���܂��B\n");
	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;
	mno = 0;
	tno = 0;
	no = rand() % 16;
	start = clock();
	str = strlen(kstr[no]);
	for (i = 0; i < str - 1; i++) {
		for (j = i + 1; j < str; j++) {
			question2(kstr[no][j], kstr[no][i]);
			tno += strlen(q2);
			mno += go(q2, 0);
		}
	}
	end = clock();
	printf("���F%d�����^�~�X�F%d��\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f�b�ł����B\n", timer);
	printf("1����������̃^�C�v���x��%.2f(�b/����)�A1���Ԃ̃^�C�v�ʂ�%.1f(����/��)�ł��B\n", (double)timer / tno, (double)tno * 60 / timer);
	save_data(k, timer, (double)tno * 60 / timer, mno);
}

/*�u���b�N�^�C�s���O�i3���q�j�̖��쐬*/
void question3(char ks1, char ks2, char ks3)	/*�z����쐬*/
{
	int i = 0, j, p, no;
	char ks_123[3] = { ks1,ks2,ks3 };
	char ks_132[3] = { ks1,ks3,ks2 };
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 6; j++) {
			p = j % 3 + i;
			if (p > 2)
				p %= 3;
			q3[j + (14 * i)] = ks_123[p];
			if (j * 7 - 1 > 0)
				q3[j * 7 - 1] = ' ';
		}
		for (j = 0; j < 6; j++) {
			p = j % 3 - i;
			if (p < 0)
				p += 3;
			q3[j + 14 * i + 7] = ks_132[p];
		}
	}
}

/*�u���b�N�^�C�s���O���K�i3���q�j*/
void blocktype_3(int select)
{
	int retry, str, qno, mno, tno, no;
	int i, j, k;
	double timer;
	clock_t start, end;
	srand(time(NULL));
	printf("�^�C�s���O���K���s���܂��B\n");
	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')
		;
	mno = 0;
	tno = 0;
	no = rand() % 16;
	start = clock();
	str = strlen(kstr[no]);
	for (i = 0; i < str - 2; i++) {
		for (j = i + 1; j < str - 1; j++) {
			for (k = j + 1; k < str; k++) {
				question3(kstr[no][i], kstr[no][j], kstr[no][k]);	/*�S�Ă̒ʂ�̃^�C�s���O���K���s��*/
				tno += strlen(q3);
				mno += go(q3, 0);
			}
		}
	}
	end = clock();
	printf("���F%d�����^�~�X�F%d��\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f�b�ł����B\n", timer);
	printf("1����������̃^�C�v���x��%.2f(�b/����)�A1���Ԃ̃^�C�v�ʂ�%.1f(����/��)�ł��B\n", (double)timer / tno, (double)tno * 60 / timer);
	save_data(select, timer, (double)tno * 60 / timer, mno);
}

/*�z��̃V���b�t��*/
void shuffle(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int j = rand() % size;
		int t = array[i];
		array[i] = array[j];
		array[j] = t;
	}
}


/*--- ���j���[�I�� ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n���K��I�����Ă��������B\n");
		printf("(1) �P���|�W�V����  \n(2) �����|�W�V����  \n(3) �b����̒P��\n");
		printf("(4) �p��b  \n(5) �L�[�z�u�A�z�^�C�s���O�g���[�j���O\n");
		printf("(6) �u���b�N�^�C�s���O���K�i2���q�j\n(7) �u���b�N�^�C�s���O���K�i3���q�j\n(0) �I��:");
		scanf("%d", &ch);
	} while (ch < Term || ch >= Invalid);

	return ((Menu)ch);
}

int main(void)
{
	Menu menu;										/* ���j���[ */
	int cn = sizeof(cstr) / sizeof(cstr[0]);		/* �b����̒P�ꐔ */
	int vn = sizeof(vstr) / sizeof(vstr[0]);		/* �p��b�̕����� */

	init_getputch();

	srand(time(NULL));								/* �����̎�������� */

	do {
		switch (menu = SelectMenu()) {

		case KeyPos:						/* �P���|�W�V�����g���[�j���O */
			pos_training(0);
			break;

		case KeyPosComp:					/* �����|�W�V�����g���[�j���O */
			pos_training2(1);
			break;

		case Clang:						/* �b����̒P�� */
			word_training("�b����̒P��", cstr, cn);
			break;

		case Conversation:				/* �p��b */
			printf("���{����\�����܂����H�i0�c������/1�c�͂��j:");
			do {
				scanf("%d", &jpn);
			} while (jpn > 1 || jpn < 0);
			word_training("�p��b�̕���", vstr, vn);
			break;
		case Expected:						/*�L�[�z�u�A�z�^�C�s���O���K*/
			keyexpect(5);
			break;
		case Blocktype2:
			blocktype_2(6);			/*�i2���q�j*/
			break;
		case Blocktype3:
			blocktype_3(7);			/*�i3���q�j*/
			break;
		}
		jpn = 0;
	} while (menu != Term);

	term_getputch();

	return (0);
}
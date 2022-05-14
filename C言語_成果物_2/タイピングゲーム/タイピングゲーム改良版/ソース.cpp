#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>	

static void init_getputch(void) { /* 空 */ }

static void term_getputch(void) { /* 空 */ }


#define	NO			15			/* トレーニング回数 */
#define	KTYPE		16			/* ブロック数 */
#define	POS_LEN		10			/* ポジショントレーニングの文字数 */

/*練習メニュー*/
typedef enum { Term, KeyPos, KeyPosComp, Clang, Conversation, Expected, Blocktype2, Blocktype3, Invalid } Menu;

int jpn = -1; /*日本語を表示するか判別する時に使う変数*/
char q2[21];
char q3[41];

/*各種ゲームセーブ用データファイル*/
char data_file[] = "pos_traning.txt";
char data_file2[] = "pos_training2.txt";
char data_file3[] = "word_trainig(c).txt";
char data_file4[] = "word_trainig(English).txt";
char data_file5[] = "word_trainig(English_Plus).txt";
char data_file6[] = "key_expect.txt";
char data_file7[] = "blocktype_2.txt";
char data_file8[] = "blocktype_3.txt";

/*各ブロックのキー*/
const char* kstr[] = {
	"12345",  "67890-^\\",		/* 第１段         */
	"!\"#$%", "&'()=~|",		/* 第１段 [Shift] */
	"qwert",  "yuiop@[",		/* 第２段         */
	"QWERT",  "YUIOP`{",		/* 第２段 [Shift] */
	"asdfg",  "hjkl;:]",		/* 第３段         */
	"ASDFG",  "HJKL+*}",		/* 第３段 [Shift] */
	"zxcvb",  "nm,./\\",		/* 第４段         */
	"ZXCVB",  "NM<>?_",			/* 第４段 [Shift] */
};

/*Ｃ言語のキーワードとライブラリ関数*/
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

/*英会話*/
const char* vstr[] = {
	"Hello!",							/* こんにちは。*/
	"How are you?",						/* お元気ですか。 */
	"Fine thanks.",						/* はい元気です。 */
	"I can't complain, thanks.",		/* まあ、何とか。 */
	"How do you do?",					/* 初めまして。 */
	"Good bye!",						/* さようなら。 */
	"Good morning!",					/* おはよう。 */
	"Good afternoon!",					/* こんにちは。 */
	"Good evening!",					/* こんばんは。 */
	"See you later!",					/* さようなら（またね）。 */
	"Go ahead, Please.",				/* お先にどうぞ。 */
	"Thank you.",						/* ありがとう。 */
	"No, thank you.",					/* いいえ結構です。 */
	"May I have your name?",			/* お名前は？ */
	"I'm glad to meet you.",			/* お目にかかれて光栄です。 */
	"What time is it now?",				/* 何時ですか。 */
	"It's about seven.",				/* 大体７時くらいです。 */
	"I must go now.",					/* もういかなくちゃ。 */
	"How much?",						/* おいくら？ */
	"Where is the restroom?",			/* お手洗いはどちらですか。 */
	"Excuse me.",						/* 失礼します（一人）。*/
	"Excuse us.",						/* 失礼します（二人以上）。*/
	"I'm sorry.",						/* ごめんなさい。 */
	"I don't know.",					/* さあ、知らないよ。 */
	"I have no change with me.",		/* 小銭がないのです。 */
	"I will be back.",					/* また戻って来ます。 */
	"Are you going out?",				/* 出かけるの？ */
	"I hope I'm not disturbing you.",	/* お邪魔じゃなければいいのですが。*/
	"I'll offer no excuse.",			/* 弁解するつもりはありません。 */
	"Shall we dance?",					/* 踊りませんか。 */
	"Will you do me a favor?",			/* ちょっとお願いしたいのですが。 */
	"It's very unseasonable.",			/* それは季節外れだね。 */
	"You are always welcome.",			/* いつでも歓迎しますよ。 */
	"Hold still!",						/* じっとして！ */
	"Follow me.",						/* 付いて来て。 */
	"Just follow my lead.",				/* 僕のするとおりにやるだけだよ。 */
	"To be honest with you,",			/* 正直に言うと… */
};

/*日本語訳*/
const char* vstr_japanese[] = {
	"こんにちは。",
	"お元気ですか。",
	"はい元気です。",
	"まあ、何とか。",
	"初めまして。",
	"さようなら。",
	"おはよう。",
	"こんにちは。",
	"こんばんは。",
	"さようなら（またね）。",
	"お先にどうぞ。",
	"ありがとう。",
	"いいえ結構です。",
	"お名前は？",
	" お目にかかれて光栄です。 ",
	"何時ですか。",
	"大体７時くらいです。",
	"もういかなくちゃ。",
	"おいくら？",
	"お手洗いはどちらですか。",
	"失礼します（一人）。",
	"失礼します（二人以上）。",
	"ごめんなさい。",
	"さあ、知らないよ。",
	"小銭がないのです。",
	"また戻って来ます。",
	"出かけるの？",
	"お邪魔じゃなければいいのですが。",
	"弁解するつもりはありません。",
	"踊りませんか。",
	"ちょっとお願いしたいのですが。",
	"それは季節外れだね。",
	"いつでも歓迎しますよ。 ",
	"じっとして！",
	"付いて来て。",
	"僕のするとおりにやるだけだよ。 ",
	"正直に言うと…"
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
			printf("保存するファイルを作成しました。　次回から保存が開始されます\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 1:
		if ((fp = fopen(data_file2, "a+")) == NULL) {
			printf("保存するファイルを作成しました。　次回から保存が開始されます\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 2:
		if ((fp = fopen(data_file3, "a+")) == NULL) {
			printf("保存するファイルを作成しました。　次回から保存が開始されます\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 3:
		if ((fp = fopen(data_file4, "a+")) == NULL) {
			printf("保存するファイルを作成しました。　次回から保存が開始されます\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 4:
		if ((fp = fopen(data_file5, "a+")) == NULL) {
			printf("保存するファイルを作成しました。　次回から保存が開始されます\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 5:
		if ((fp = fopen(data_file6, "a+")) == NULL) {
			printf("保存するファイルを作成しました。　次回から保存が開始されます\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 6:
		if ((fp = fopen(data_file7, "a+")) == NULL) {
			printf("保存するファイルを作成しました。　次回から保存が開始されます\n");
		}
		else {
			fprintf(fp, "%.1f %.1f %d", type_time, type_rate, type_miss);
		}
		fclose(fp);
		break;
	case 7:
		if ((fp = fopen(data_file8, "a+")) == NULL) {
			printf("保存するファイルを作成しました。　次回から保存が開始されます\n");
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

/*文字列strをタイプ練習（ミス回数を返す）*/
int go(const char* str, int no)
{
	int i;
	int len = strlen(str);			/* 文字数 */
	int mistake = 0;				/* ミス回数 */

	switch (jpn) {
	case 0:
		for (i = 0; i < len; i++) {
			/* str[i]以降を表示してカーソルを先頭へ戻す */
			printf("%s \r", &str[i]);
			fflush(stdout);
			while (getch() != str[i]) {
				mistake++;
			}
		}
		break;
	case 1:	/*jpnが1なら日本語訳も表示*/
		for (i = 0; i < len; i++) {
			/* str[i]以降を表示してカーソルを先頭へ戻す */
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

/*単純ポジショントレーニング*/
void pos_training(int k)
{
	int i;
	int stage;
	int temp, line;
	int len;						/* 問題のブロックのキー数 */
	int qno, pno;					/* 問題番号・前回の問題番号 */
	int tno, mno;					/* 文字数・ミス回数 */
	double timer;

	clock_t	start, end;				/* 開始時刻・終了時刻 */

	printf("\n単純ポジショントレーニングを行います。\n");
	printf("練習するブロックを選択してください。\n");
	printf("第1段 (1) 左 %-8s    (2) 右 %-8s\n", kstr[0], kstr[1]);
	printf("第2段 (3) 左 %-8s    (4) 右 %-8s\n", kstr[4], kstr[5]);
	printf("第3段 (5) 左 %-8s    (6) 右 %-8s\n", kstr[8], kstr[9]);
	printf("第4段 (7) 左 %-8s    (8) 右 %-8s\n", kstr[12], kstr[13]);

	/* ブロックを選択させる */
	do {
		printf("番号（練習中止は99）：");
		scanf("%d", &temp);
		if (temp == 99) return;				/* 練習中止 */
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("%sの問題を%d回練習します。\n", kstr[line], NO);

	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;						/* 文字数・ミス回数をクリア */
	len = strlen(kstr[line]);			/* 練習するブロックのキー数 */

	start = clock();						/* 開始時刻 */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++)	/* 問題文字列を作成 */
			str[i] = kstr[line][rand() % len];
		str[i] = '\0';

		mno += go(str, 0);						/* 練習実行 */
		tno += strlen(str);
	}

	end = clock();							/* 終了時刻 */

	printf("問題：%d文字／ミス：%d回\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f秒でした。\n", timer);
	printf("1文字あたりのタイプ速度は%.2f(秒/文字)、1分間のタイプ量は%.1f(文字/分)です。\n", (double)timer / tno, (double)tno * 60 / timer);

	save_data(k, timer, (double)tno * 60 / timer, mno);		/*セーブ用関数に情報を伝える順番は(　switch用変数　所要時間　1分間当たりのタイプ速度　　ミス回数)*/
}

/*--- 複合ポジショントレーニング ---*/
void pos_training2(int k)
{
	int i;
	int stage;
	int temp, line;
	int sno;						/* 選ばれたブロック数 */
	int select[KTYPE];				/* 選ばれたブロック */
	int len[KTYPE];					/* 問題のブロックのキー数 */
	int tno, mno;					/* 文字数・ミス回数 */
	clock_t	start, end;				/* 開始時刻・終了時刻 */
	double timer;
	const char* format = "第%d段 (%2d) 左 %-8s (%2d) 右 %-8s "
		"(%2d)[左] %-8s (%2d)[右] %-8s\n";

	printf("\n複合ポジショントレーニングを行います。\n");
	printf("練習するブロックを選択してください（複数選べます）。\n");

	for (i = 0; i < 4; i++) {
		int k = i * 4;
		printf(format, i + 1, k + 1, kstr[k], k + 2, kstr[k + 1],
			k + 3, kstr[k + 2], k + 4, kstr[k + 3]);
	}

	/* ブロックを重複させずに選択させる（最大16個） */
	sno = 0;
	while (1) {
		printf("番号（選択終了は50／練習中止は99）：");

		do {
			scanf("%d", &temp);
			if (temp == 99) return;			/* 練習中止 */
		} while ((temp < 1 || temp > KTYPE) && temp != 50);

		if (temp == 50)
			break;
		for (i = 0; i < sno; i++)
			if (temp == select[i]) {
				printf("\aその段は既に選ばれています。\n");
				break;
			}
		if (i == sno)
			select[sno++] = temp;			/* 選ばれたブロックを登録 */
	}

	if (sno == 0)							/* 一つも選ばれなかった */
		return;

	printf("以下のブロックの問題を%d回練習します。\n", NO);

	for (i = 0; i < sno; i++)
		printf("%s ", kstr[select[i] - 1]);

	printf("\nスペースキーで開始します。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;							/* 文字数・ミス回数をクリア */
	for (i = 0; i < sno; i++)
		len[i] = strlen(kstr[select[i] - 1]);	/* ブロックのキー数 */

	start = clock();						/* 開始時刻 */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++) {		/* 問題文字列を作成 */
			int q = rand() % sno;
			str[i] = kstr[select[q] - 1][rand() % len[q]];
		}
		str[i] = '\0';

		mno += go(str, 0);						/* 練習実行 */
		tno += strlen(str);
	}

	end = clock();							/* 終了時刻 */

	printf("問題：%d文字／ミス：%d回\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f秒でした。\n", timer);
	printf("1文字あたりのタイプ速度は%.2f(秒/文字)、1分間のタイプ量は%.1f(文字/分)です。\n", (double)timer / tno, (double)tno * 60 / timer);
	save_data(k, timer, (double)tno * 60 / timer, mno);
}

/*--- Ｃ言語／英会話トレーニング ---*/
void word_training(const char* mes, const char* str[], int n)
{
	int stage;
	int qno, pno;					/* 問題番号・前回の問題番号 */
	int tno, mno;					/* 文字数・ミス回数 */
	int i, ch, memory[128];
	double timer;
	clock_t	start, end;				/* 開始時刻・終了時刻 */

	printf("\n%sを%d個練習します。\n", mes, NO);

	printf("スペースキーで開始します。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;					/* 文字数・ミス回数をクリア */
	pno = n;						/* 前回の問題番号（存在しない番号） */

	start = clock();				/* 開始時刻 */

	for (stage = 0; stage < NO; stage++) {
		do {						/* 同じ問題を連続して出題しない */
			ch = 0;
			qno = rand() % n;
			for (i = 0; i < stage; i++) {
				if (memory[i] == qno && stage > 0)	/*問題番号が1回でも出ているものであればやり直す*/
					ch++;
			}
		} while (ch != 0);
		memory[stage] = qno;		/*問題番号をmemoryに記憶*/


		mno += go(str[qno], qno);		/* 問題はstr[qno] */
		tno += strlen(str[qno]);
	}

	end = clock();					/* 終了時刻 */

	printf("問題：%d文字／ミス：%d回\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f秒でした。\n", timer);
	printf("1文字あたりのタイプ速度は%.2f(秒/文字)、1分間のタイプ量は%.1f(文字/分)です。\n", (double)timer / tno, (double)tno * 60 / timer);
	save_data(10,timer, (double)tno * 60 / timer, mno);
}

/*キー配置連想タイピングトレーニング*/
void keyexpect(int k)
{
	int i, stage, mno;
	double timer;
	clock_t start, end;
	init_getputch();
	srand(time(NULL));
	printf("キー位置連想タイピング練習を始めます。\n");
	printf("？で隠された文字をタイプしてください。\n");
	printf("スペースキーで開始します。\n");
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
	printf("問題：%d問／ミス：%d回\n", stage, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f秒でした。\n", timer);
	printf("1文字あたりのタイプ速度は%.2f(秒/文字)、1分間のタイプ量は%.1f(文字/分)です。\n", (double)timer / stage, (double)stage * 60 / timer);
	save_data(k, timer, (double)stage * 60 / timer, mno);
	term_getputch();
}

/*ブロックタイピング（2拍子）の問題作成*/
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

/*ブロックタイピング練習（2拍子）*/
void blocktype_2(int k)
{
	int retry, str, qno, mno, tno, no;
	int i, j;
	double timer;
	clock_t start, end;
	srand(time(NULL));
	printf("タイピング練習を行います。\n");
	printf("スペースキーで開始します。\n");
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
	printf("問題：%d文字／ミス：%d回\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f秒でした。\n", timer);
	printf("1文字あたりのタイプ速度は%.2f(秒/文字)、1分間のタイプ量は%.1f(文字/分)です。\n", (double)timer / tno, (double)tno * 60 / timer);
	save_data(k, timer, (double)tno * 60 / timer, mno);
}

/*ブロックタイピング（3拍子）の問題作成*/
void question3(char ks1, char ks2, char ks3)	/*配列を作成*/
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

/*ブロックタイピング練習（3拍子）*/
void blocktype_3(int select)
{
	int retry, str, qno, mno, tno, no;
	int i, j, k;
	double timer;
	clock_t start, end;
	srand(time(NULL));
	printf("タイピング練習を行います。\n");
	printf("スペースキーで開始します。\n");
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
				question3(kstr[no][i], kstr[no][j], kstr[no][k]);	/*全ての通りのタイピング練習を行う*/
				tno += strlen(q3);
				mno += go(q3, 0);
			}
		}
	}
	end = clock();
	printf("問題：%d文字／ミス：%d回\n", tno, mno);
	timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.1f秒でした。\n", timer);
	printf("1文字あたりのタイプ速度は%.2f(秒/文字)、1分間のタイプ量は%.1f(文字/分)です。\n", (double)timer / tno, (double)tno * 60 / timer);
	save_data(select, timer, (double)tno * 60 / timer, mno);
}

/*配列のシャッフル*/
void shuffle(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int j = rand() % size;
		int t = array[i];
		array[i] = array[j];
		array[j] = t;
	}
}


/*--- メニュー選択 ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n練習を選択してください。\n");
		printf("(1) 単純ポジション  \n(2) 複合ポジション  \n(3) Ｃ言語の単語\n");
		printf("(4) 英会話  \n(5) キー配置連想タイピングトレーニング\n");
		printf("(6) ブロックタイピング練習（2拍子）\n(7) ブロックタイピング練習（3拍子）\n(0) 終了:");
		scanf("%d", &ch);
	} while (ch < Term || ch >= Invalid);

	return ((Menu)ch);
}

int main(void)
{
	Menu menu;										/* メニュー */
	int cn = sizeof(cstr) / sizeof(cstr[0]);		/* Ｃ言語の単語数 */
	int vn = sizeof(vstr) / sizeof(vstr[0]);		/* 英会話の文書数 */

	init_getputch();

	srand(time(NULL));								/* 乱数の種を初期化 */

	do {
		switch (menu = SelectMenu()) {

		case KeyPos:						/* 単純ポジショントレーニング */
			pos_training(0);
			break;

		case KeyPosComp:					/* 複合ポジショントレーニング */
			pos_training2(1);
			break;

		case Clang:						/* Ｃ言語の単語 */
			word_training("Ｃ言語の単語", cstr, cn);
			break;

		case Conversation:				/* 英会話 */
			printf("日本語訳を表示しますか？（0…いいえ/1…はい）:");
			do {
				scanf("%d", &jpn);
			} while (jpn > 1 || jpn < 0);
			word_training("英会話の文書", vstr, vn);
			break;
		case Expected:						/*キー配置連想タイピング練習*/
			keyexpect(5);
			break;
		case Blocktype2:
			blocktype_2(6);			/*（2拍子）*/
			break;
		case Blocktype3:
			blocktype_3(7);			/*（3拍子）*/
			break;
		}
		jpn = 0;
	} while (menu != Term);

	term_getputch();

	return (0);
}
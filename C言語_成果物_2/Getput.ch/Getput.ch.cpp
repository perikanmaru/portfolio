﻿// Getput.ch.cpp : スタティック ライブラリ用の関数を定義します。
//

#include "pch.h"
#include "framework.h"

#ifndef __GETPUTCH

#define __GETPUTCH

#if defined(_MSC_VER) || (__TURBOC__) || (LSI_C)

  /* MS-Windows／MS-DOS（Visual C++, Borland C++, LSI-C 86 etc ...） */

#include <conio.h>

static void init_getputch(void) { /* 空 */ }

static void term_getputch(void) { /* 空 */ }


#else

  /* Cursesライブラリが提供されるUNIX／Linux／OS X */

#include <curses.h>

#undef putchar
#undef puts
#undef printf
static char __buf[4096];

/*--- __putchar：putchar関数と同等（改行を[改行＋復帰]で出力）---*/
static int __putchar(int ch)
{
	if (ch == '\n')
		putchar('\r');
	return putchar(ch);
}

/*--- putch：１文字表示してバッファを掃き出す ---*/
static int putch(int ch)
{
	int result = putchar(ch);

	fflush(stdout);
	return result;
}

/*--- __printf：printf関数と同等（改行を[改行＋復帰]で出力）---*/
static int __printf(const char* format, ...)
{
	va_list	ap;
	int 	count;

	va_start(ap, format);
	vsprintf(__buf, format, ap);
	va_end(ap);

	for (count = 0; __buf[count]; count++) {
		putchar(__buf[count]);
		if (__buf[count] == '\n')
			putchar('\r');
	}
	return count;
}

/*--- __puts：puts関数と同等（改行を[改行＋復帰]で出力）---*/
static int __puts(const char* s)
{
	int i, j;

	for (i = 0, j = 0; s[i]; i++) {
		__buf[j++] = s[i];
		if (s[i] == '\n')
			__buf[j++] = '\r';
	}
	return puts(__buf);
}

/*--- ライブラリ初期処理 ---*/
static void init_getputch(void)
{
	initscr();
	cbreak();
	noecho();
	refresh();
}

/*--- ライブラリ終了処理 ---*/
static void term_getputch(void)
{
	endwin();
}

#define putchar	__putchar
#define	printf	__printf
#define puts	__puts

#endif

#endif
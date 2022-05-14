#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>	
#include<ctype.h>

static void init_getputch(void) { /* 空 */ }

static void term_getputch(void) { /* 空 */ }

#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int r = 5;
    int n = 0;
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char a[128];
 
   srand(time(NULL));			/* 乱数の種を設定 */

   for (k = 0; k < 5; k++) {
       int n = rand() % 25;
       a[k] = str[n];
   }


   for (i = 5; i > 0; i--) {			/* 配列aをシャッフル */
       int j = rand() % (i + 1);
       if (i != j)
           swap(int, a[i], a[j]);
   }

   printf("%s", a);
}
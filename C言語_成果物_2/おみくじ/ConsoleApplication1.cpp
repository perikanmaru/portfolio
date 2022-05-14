#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int k;

    srand((unsigned int)time(NULL));

    printf("おみくじを始めます...\n\n");

        k= rand() % 6;

        while (1)
        {
            printf("おみくじの結果は→");

            switch (k)
            {
            case 0:
                printf("大吉\n");
                break;

            case 1:
                printf("中吉\n");
                break;

            case 2:
                printf("小吉\n");
                break;

            case 3:
                printf("吉\n");
                break;

            case 4:
                printf("末吉\n");
                break;

            case 5:
                printf("凶\n");
                break;

            case 6:
                printf("大凶\n");
                break;
            }
            break;
        }

        return 0;
}

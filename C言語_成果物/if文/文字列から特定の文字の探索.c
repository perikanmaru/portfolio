#include <stdio.h>

int string_char(const char s[],int c)
{
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==c) 
		return i;
    }
    return -1;
}

int main(void)
{
    int index;
    char string[128];

    printf("��������͂��Ă��������B\n");
	scanf("%s",string);

    index=string_char(string,'c');

    if(index == -1){
        printf("�����uc�v�͊܂܂�Ă��܂���B\n");
    }
	else{
        printf("����c�͗��%d�Ԗڂɂ���܂��B\n", index);
    }

    return 0;
}
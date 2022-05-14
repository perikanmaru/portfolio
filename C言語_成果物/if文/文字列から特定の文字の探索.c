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

    printf("文字を入力してください。\n");
	scanf("%s",string);

    index=string_char(string,'c');

    if(index == -1){
        printf("文字「c」は含まれていません。\n");
    }
	else{
        printf("文字cは列の%d番目にあります。\n", index);
    }

    return 0;
}
#include<stdio.h>

int main(void)
{
	FILE *FilePoint;
	
	char filename[256];
	
	printf("�t�@�C��������͂��Ă��������B\n");
	scanf("%s",filename);
	
	FilePoint=fopen(filename,"r");
	
	if(FilePoint==NULL){
		printf("���̃t�@�C���͑��݂��܂���B\n");
	}
	else{
		printf("���̃t�@�C���͑��݂��܂��B\n");
		fclose(FilePoint);
	}
	
	return 0;
}
	
	
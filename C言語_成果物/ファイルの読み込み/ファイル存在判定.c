#include<stdio.h>

int main(void)
{
	FILE *FilePoint;
	
	char filename[256];
	
	printf("ファイル名を入力してください。\n");
	scanf("%s",filename);
	
	FilePoint=fopen(filename,"r");
	
	if(FilePoint==NULL){
		printf("そのファイルは存在しません。\n");
	}
	else{
		printf("そのファイルは存在します。\n");
		fclose(FilePoint);
	}
	
	return 0;
}
	
	
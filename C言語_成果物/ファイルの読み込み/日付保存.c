#include<stdio.h>
#include<time.h>

char data_file[]="jikan.bin";
char save_data[]="save.bin";

void read_data(void)
{
	FILE *fp;
	struct tm timer;
	
	if((fp=fopen(data_file,"rb"))==NULL){
	printf("�{�v���O���������s����̂͏��߂Ăł��ˁB\n");
	}else{
		fread(&timer,sizeof(struct tm),1,fp);
		printf("�O���%d�N%d��%d��%d��%d��%d�b�ł����B\n",timer.tm_year + 1900, timer.tm_mon + 1, timer.tm_mday,timer.tm_hour, timer.tm_min, timer.tm_sec);
		fclose(fp);
	}
	
	if((fp=fopen(save_data,"wb"))==NULL){
		;
	}else{
		fwrite(&timer,sizeof(struct tm),1,fp);
		fclose(fp);
	}
}

void write_data(void)
{
	FILE *fp;
	time_t t;
	struct tm *JST;
	
	time(&t);
	JST=localtime(&t);
	
	if((fp=fopen(data_file,"wb"))==NULL){
		printf("�t�@�C�����I�[�v���ł��܂���B\n");
		}else{
		fwrite(JST,sizeof(struct tm),1,fp);
		fclose(fp);
		}
}

int main(void)
{
	read_data();
	write_data();
	
	return 0;
}
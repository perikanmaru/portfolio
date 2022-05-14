#include <time.h>
#include <stdio.h>

char data_file[] = "memo.txt";

void get_data(){
    FILE *fp;

    if((fp = fopen(data_file, "r")) == NULL){
        printf("�{�v���O���������s����̂͏��߂Ăł���\n");
    }else{
	
        int year, month, day, h, m, s;
        char feel[256];
        fscanf(fp, "%d%d%d%d%d%d%s", &year, &month, &day, &h, &m, &s, feel);
        printf("�O���%d�N%d��%d��%d��%d��%d�b�ŁA�C����%s�ł���\n", year, month, day, h, m, s, feel);

        fclose(fp);
    }
}

void put_data(){
    FILE *fp;
    time_t current=time(NULL);
    struct tm *timer=localtime(&current);
    char feel[256];

    if((fp=fopen(data_file,"w"))==NULL){
        printf("�t�@�C�����I�[�v���ł��܂���\n");
		}else{
			fopen(data_file,"r+");
			printf("���̋C������͂��Ă�������\n");
			scanf("%s",feel);
			fprintf(fp,"%d %d %d %d %d %d %s\n",timer->tm_year+1900, timer->tm_mon + 1, timer->tm_mday, timer->tm_hour, timer->tm_min, timer->tm_sec, feel);
			fclose(fp);
		}
}

int main(){

    get_data();

    put_data();

    return 0;
}
#include <stdio.h>

int fcopy(const char* fnamer, const char* fnamew);

int main(void)
{
	//fcopy�֐��̎��s
	const char* fnamer = "test_file.txt"; //�R�s�[���̃t�@�C����
	const char* fnamew = "test_copy.txt"; //�R�s�[��̃t�@�C����
	fcopy(fnamer, fnamew); //fcopy�֐��̎��s

	return 0;
}

//fcopy�֐��i�e�L�X�g�t�@�C�����R�s�[����֐��j
int fcopy(const char* fnamer, const char* fnamew)
{
	int c;
	int k = -1;
	FILE* fpr = fopen(fnamer, "rb");
	FILE* fpw = fopen(fnamew, "wb");
	if (fpr == NULL || fpw == NULL) {
		printf("file open error!\n");
		return -1;
	}
	printf("�㏑���ۑ����܂����H YES(0) NO(1) :");
	do {
		scanf("%d",&k);
		if (k == 0 || k == 1)
			break;
	} while (1);

	if (k == 0) {
		printf("�t�@�C�����㏑���ۑ����܂���");
		while ((c = fgetc(fpr)) != EOF) {
			fputc(c, fpw);					//fputc�֐��Ńt�@�C���|�C���^[fpw]��1�o�C�g���������Ȃ���f�[�^[c]���i�[���Ă���
		}
	}
	fclose(fpw);
	fclose(fpr);

	return 0;
}
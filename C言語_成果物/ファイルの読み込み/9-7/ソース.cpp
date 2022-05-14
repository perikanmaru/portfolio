#include <stdio.h>

int fcopy(const char* fnamer, const char* fnamew);

int main(void)
{
	//fcopy関数の実行
	const char* fnamer = "test_file.txt"; //コピー元のファイル名
	const char* fnamew = "test_copy.txt"; //コピー後のファイル名
	fcopy(fnamer, fnamew); //fcopy関数の実行

	return 0;
}

//fcopy関数（テキストファイルをコピーする関数）
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
	printf("上書き保存しますか？ YES(0) NO(1) :");
	do {
		scanf("%d",&k);
		if (k == 0 || k == 1)
			break;
	} while (1);

	if (k == 0) {
		printf("ファイルを上書き保存しました");
		while ((c = fgetc(fpr)) != EOF) {
			fputc(c, fpw);					//fputc関数でファイルポインタ[fpw]を1バイトずつ動かしながらデータ[c]を格納していく
		}
	}
	fclose(fpw);
	fclose(fpr);

	return 0;
}
#include "encryption.h"

void encryptFile(const char* srcFilePath, const char* destFilePath) {
	srand(time(NULL));
	FILE* fp1;
	FILE* fp2;
	errno_t err1, err2;
	if ((err1 = fopen_s(&fp1, srcFilePath, "r"))!=0 || (err2 = fopen_s(&fp2, destFilePath, "w"))!=0) {
		printf("无法打开此文件\n");            
		return ;
	}
	char ch;
	while ((ch = fgetc(fp1)) != EOF) {
		//# 35  无损转码为short类型
		//0000 0000 0010 0011
		//0000 0010 0011 0000 左移4位(无损)，全是偶数
		//1000 0010 0011 0000 与0x8000或，将数据转成负数
		//1000 0010 0011 1001  加上随机数0-15，奇数和偶数都会出现
		short temp = (short)ch;
		temp = temp << 4;  
		temp = temp | 0x8000;  
		temp += rand() % 16; 

		//printf("%d\n", temp);
		fprintf(fp2, "%hd", temp);
		
	}
	printf("文件加密完成\n");
	fclose(fp1);
	fclose(fp2);
}

void decryptFil(const char* srcFilePath, const char* destFilePath) {
	FILE* fp1;
	FILE* fp2;
	errno_t err1, err2;
	if ((err1 = fopen_s(&fp1, srcFilePath, "r")) != 0 || (err2 = fopen_s(&fp2, destFilePath, "w")) != 0) {
		printf("无法打开此文件\n");
		return;
	}
	short temp;
	while (!feof(fp1)) {
		fscanf_s(fp1, "%hd", &temp);
		temp = temp << 1; //去掉符号位
		temp = temp >> 5; //去掉后4位随机数
		char ch = (char)temp; //还原位char
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("文件解密完成\n");
}
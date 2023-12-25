#include "encryption.h"

void encryptFile(const char* srcFilePath, const char* destFilePath) {
	srand(time(NULL));
	FILE* fp1;
	FILE* fp2;
	errno_t err1, err2;
	if ((err1 = fopen_s(&fp1, srcFilePath, "r"))!=0 || (err2 = fopen_s(&fp2, destFilePath, "w"))!=0) {
		printf("�޷��򿪴��ļ�\n");            
		return ;
	}
	char ch;
	while ((ch = fgetc(fp1)) != EOF) {
		//# 35  ����ת��Ϊshort����
		//0000 0000 0010 0011
		//0000 0010 0011 0000 ����4λ(����)��ȫ��ż��
		//1000 0010 0011 0000 ��0x8000�򣬽�����ת�ɸ���
		//1000 0010 0011 1001  ���������0-15��������ż���������
		short temp = (short)ch;
		temp = temp << 4;  
		temp = temp | 0x8000;  
		temp += rand() % 16; 

		//printf("%d\n", temp);
		fprintf(fp2, "%hd", temp);
		
	}
	printf("�ļ��������\n");
	fclose(fp1);
	fclose(fp2);
}

void decryptFil(const char* srcFilePath, const char* destFilePath) {
	FILE* fp1;
	FILE* fp2;
	errno_t err1, err2;
	if ((err1 = fopen_s(&fp1, srcFilePath, "r")) != 0 || (err2 = fopen_s(&fp2, destFilePath, "w")) != 0) {
		printf("�޷��򿪴��ļ�\n");
		return;
	}
	short temp;
	while (!feof(fp1)) {
		fscanf_s(fp1, "%hd", &temp);
		temp = temp << 1; //ȥ������λ
		temp = temp >> 5; //ȥ����4λ�����
		char ch = (char)temp; //��ԭλchar
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("�ļ��������\n");
}
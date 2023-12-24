#include <stdio.h>
#include <stdlib.h>
#include "configPaser.h"
#include <windows.h>
int main() {
	char file_path[] = "./config.txt";
	int len = getFileLines(file_path);
	printf("�ļ�����Ч����Ϊ��%d\n", len);
	
	ConfigInfo* configInfoArr = NULL;
	parseConfig(file_path, len, &configInfoArr);
	//printf("configInfoArr addr:%d\n", configInfoArr);

	printf("heroId=%s\n", getInfoByKey("heroId", configInfoArr, len));
	printf("heroName=%s\n", getInfoByKey("heroName", configInfoArr, len));
	printf("heroAtk=%s\n", getInfoByKey("heroAtk", configInfoArr, len));
	printf("heroDef=%s\n", getInfoByKey("heroDef", configInfoArr, len));
	SetConsoleOutputCP(65001);  //����ͷ�ļ�<windows.h>�͵���API����SetConsoleOutputCP(65001)�����ÿ���̨��������Ĵ���ҳ����Ϊutf-8��ʽ
	printf("heroInfo=%s\n", getInfoByKey("heroInfo", configInfoArr, len));

	free(configInfoArr);
	configInfoArr = NULL;
}
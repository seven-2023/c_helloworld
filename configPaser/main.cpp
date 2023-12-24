#include <stdio.h>
#include <stdlib.h>
#include "configPaser.h"
#include <windows.h>
int main() {
	char file_path[] = "./config.txt";
	int len = getFileLines(file_path);
	printf("文件的有效行数为：%d\n", len);
	
	ConfigInfo* configInfoArr = NULL;
	parseConfig(file_path, len, &configInfoArr);
	//printf("configInfoArr addr:%d\n", configInfoArr);

	printf("heroId=%s\n", getInfoByKey("heroId", configInfoArr, len));
	printf("heroName=%s\n", getInfoByKey("heroName", configInfoArr, len));
	printf("heroAtk=%s\n", getInfoByKey("heroAtk", configInfoArr, len));
	printf("heroDef=%s\n", getInfoByKey("heroDef", configInfoArr, len));
	SetConsoleOutputCP(65001);  //增添头文件<windows.h>和调用API函数SetConsoleOutputCP(65001)，设置控制台程序输出的代码页编码为utf-8格式
	printf("heroInfo=%s\n", getInfoByKey("heroInfo", configInfoArr, len));

	free(configInfoArr);
	configInfoArr = NULL;
}
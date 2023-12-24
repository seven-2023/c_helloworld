#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ConfigInfo
{
	char key[64];
	char val[64];
};
int getFileLines(char* file_path);
int isValidLine(char* str);
//�����ļ�
void parseConfig(char* file_path, int lines, struct ConfigInfo** configinfoP);

//ͨ��keyֵ����ȡvalueֵ
char* getInfoByKey(const char* key, struct ConfigInfo* configinfo, int fileno);
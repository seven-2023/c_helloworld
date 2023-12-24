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
//解析文件
void parseConfig(char* file_path, int lines, struct ConfigInfo** configinfoP);

//通过key值，获取value值
char* getInfoByKey(const char* key, struct ConfigInfo* configinfo, int fileno);
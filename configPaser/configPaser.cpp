#include "configPaser.h"

int getFileLines(char *file_path) {
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, file_path, "r")) != 0) {
		printf("无法打开此文件\n");            //如果打不开，就输出打不开
		return 0;
	}
	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf, 1024, fp)!=NULL) {
		if (isValidLine(buf)) {
			lines++;
			memset(buf, 0, 1024);
		}
	}
	fclose(fp);
	return lines;
}

int isValidLine(char* str) {
	if (strchr(str, ':') == nullptr) {
		return 0;
	}
	return 1;
}

//解析文件
void parseConfig(char * file_path, int lines, struct ConfigInfo **configinfoP) {
	struct ConfigInfo *info= (ConfigInfo*)malloc(sizeof(struct ConfigInfo) * lines);
	if (info == NULL) {
		return;
	}
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, file_path, "r")) != 0) {
		printf("无法打开此文件\n");            //如果打不开，就输出打不开
		return ;
	}
	char buf[64] = { 0 };
	int index = 0; //info的下标
	while (fgets(buf, 64, fp)) {
		if (isValidLine(buf)) {
			char* pos = strchr(buf, ':');
			strncpy_s(info[index].key, buf, pos - buf);
			strncpy_s(info[index].val, pos + 1, strlen(pos+1)-1);
			index++;
		}
		memset(buf, 0, 64);
	}
	*configinfoP = info; //这里是浅拷贝，不能释放info，否则configinfoP也变成了空了 //free(info);
}



//通过key值，获取value值
char* getInfoByKey(const char* key, struct ConfigInfo* configinfo, int len) {
	for (int i = 0; i < len; i++) {
		if (strcmp(key, configinfo[i].key) == 0) {
			return configinfo[i].val;
		}
	}
	return NULL;
}
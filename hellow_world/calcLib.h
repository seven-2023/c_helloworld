#include <stdio.h>
#ifndef __CALCLIB__
#define __CALCLIB__
int myAdd(int, int);
//�ⲿ���� / ��������
__declspec(dllexport) void printAdd(int a, int b);
__declspec(dllexport) int mySub(int a, int b);
__declspec(dllexport) int myMulti(int a, int b);
__declspec(dllexport) int myDiv(int a, int b);

#endif // !__CALCLIB__


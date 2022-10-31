#ifndef _MYSTDLIB_H_
#define _MYSTDLIB_H_

#include <stdio.h>
#include <string.h>

/*--------------------输入类函数-----------------------------------------------*/
char *sgets(char *str, int n);/*键盘输入文字程序*/
int FileGets(char *str,int n, FILE *fp);/*从文件输入文字程序(仅限txt文件)*/

/*--------------------字符串类函数----------------------------------------------*/
int CompareStr(char *str1, char *str2, int LONG);/*字符串对比*/

/*--------------------链表函数-------------------------------------------------*/




#endif
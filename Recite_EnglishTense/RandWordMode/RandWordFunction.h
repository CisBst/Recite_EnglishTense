#ifndef _RANDWORDFUNCTION_H_
#define _RANDWORDFUNCTION_H_

#include<stdio.h>
#include"/Users/wuyuhang/Desktop/C_Project/Recite_EnglishTense/Public_Function/MyStdlib.h"

#define WORDLONG 20
#define WordNumber 7
#define SIMPLE 5
#define NORMAO 10
#define DIFFICULT 15

//从指定文件夹中读取单词
void WordScanFromFile(char (*word)[WORDLONG],FILE *fp,int WordTotalLong);


#endif
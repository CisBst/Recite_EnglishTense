#ifndef _RECITEFUNCTION_H_
#define _RECITEFUNCTION_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<wchar.h>
#include<locale.h>

#define MAX_NUMBER 147      //文件中单词原型的总数
#define ChuTiShu 30         //出题量
#define LONG_WORD 100       //字符串最长长度

struct Word{
    char YuanXing[LONG_WORD];
    char GuoQuShi[LONG_WORD];
    char GuoQuFenCi[LONG_WORD];
    char XianZaiFenCi[LONG_WORD];
};//单词

struct PlayerAnswer{
    char GuoQuShi[LONG_WORD];
    char GuoQuFenCi[LONG_WORD];
    char XianZaiFenCi[LONG_WORD];
};//使用者的回答

void ReciteWord(void);//默写单词模块
void InputWord(struct Word *word,int n,FILE *fp);//将英语单词输入到程序中
void SuiJiShuZi(int *numbers);//随机生成一组数字
void SuiJiChuTiAndAnswer(int *numbers,struct Word *word);//随机出题并由玩家回答
void PlayerEnter(struct Word *word,int *score,int *ZuoCUoShu,int *YiZUoTiShu);//玩家输入答案，正确返回1，错误返回0
char *s_gets(char *str,int n);//输入字符串函数
void ShowSaoHua(void);//显示骚话
void ChengJiLuRu(double score);//成绩录入

#endif
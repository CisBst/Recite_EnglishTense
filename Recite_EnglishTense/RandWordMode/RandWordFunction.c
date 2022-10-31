#include"RandWordFunction.h"

//从指定文件夹中读取单词
void WordScanFromFile(char (*word)[WORDLONG],FILE *fp,int WordTotalLong)
{
    int i=0;
    for(i=0;i<WordTotalLong;i++)
        FileGets(word[i],WORDLONG,fp);
}
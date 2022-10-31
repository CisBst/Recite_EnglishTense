#include "MyStdlib.h"


/*--------------------输入类函数-----------------------------------------------*/
char *sgets(char *str,int n)/*键盘输入文字程序*/
{
    char *ret_val=NULL;     //定义一个指向字符串的指针，用来判断fgets()是否接受输入
    char *position=NULL;    //定义一个指向字符串的指针，用来寻找字符串str中的'\n'的位置
    ret_val=fgets(str,n,stdin);//通过鼠标输入字符
    
    if(ret_val)
    {
        position=strchr(str,'\n');
        if(position)                //如果找到'\n'在字符串中的位置，就把'\n'换成'\0'
            *position='\0';
        else
            while(getchar()!='\n')  //如果没找到就继续接受输入，直到输入'\n'，并且清空多余的输入
                continue;
        
    }

    return ret_val;
}

int FileGets(char *str,int n, FILE *fp)/*从文件输入文字程序(仅限txt文件)*/
{
    char word;//定义一个字符型变量，用来存储从文件中获取的值。
    int Long=0;//定义一个整型变量，用来确定从文件中读取的字母存储在字符串中的位置
    for(;Long<n;Long++)
    {
        word=getc(fp);//从文件中读取一个字母
        if((word==' '||word=='\n'||word==EOF)&&Long==0)
        {
            Long-=1;
            continue;
        }
        else if(word==' '||word=='\n'||word==EOF)
            break;
        str[Long]=word;//在字符串中的相应位置存入字母word
    }    
    str[Long]='\0';//在字符串结尾加上结束标志符

    return 0;
}

/*--------------------字符串类函数----------------------------------------------*/

int CompareStr(char *str1, char *str2, int Length)/*字符串对比*/
{
    if(Length>strlen(str1))
        return 3;//要求对比长度超过第一个字符串长度
    else if(Length>strlen(str2))
        return 4;//要求对比长度超过第二个字符串长度
    for(int i=0;i<Length;i++)
    {
        if(str1[i]>str2[i])         //如果出现第一个数组中的某一个字符比第二个字符串同位置的大，返回1
            return 1;
        else if(str1[i]<str2[i])    //如果出现第二个数组中的某一个字符比第一个字符串同位置的大，返回2
            return 2;
    }
    return 0;
}

/*--------------------链表函数-------------------------------------------------*/
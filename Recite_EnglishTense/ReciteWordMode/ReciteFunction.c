#include "ReciteFunction.h"

void InputWord(struct Word *word,int n,FILE *fp)//将英语单词输入到程序中
{
	int i;
	//char *find;
/*********************************依次将单词输入程序***********************************/
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s %s %s %s",word[i].YuanXing,word[i].GuoQuShi,word[i].GuoQuFenCi,word[i].XianZaiFenCi);
        //从指定的文件中读取内容，并储存

	/*	find=strchr(word[i].YuanXing,'\n');
		if(find)
			find='\0';
		find=strchr(word[i].GuoQuShi,'\n');
		if(find)
			find='\0';
		find=strchr(word[i].GuoQuFenCi,'\n');
		if(find)
			find='\0';
		find=strchr(word[i].XianZaiFenCi,'\n');
		if(find)
			find='\0';*/
	}
/*	for(i=0;i<20;i++)
		printf("%-4d",word[140].GuoQuFenCi[i]);*/
}

void SuiJiShuZi(int *numbers)//随机生成一组数字
{
	int i;//循环
	srand((unsigned)time(NULL));//随机数种子
	for(i=0;i<ChuTiShu;i++)
	{
		numbers[i]=rand()%(MAX_NUMBER+1);//使用随机数字来出题
		/*if(numbers[i]>=MAX_NUMBER)//如果某一题题号大于最大的题目编号就重新开始出题
		{
			i=0;
			continue;
		}*/
		if(i>0)
		{
			int j;
			for(j=0;j<i;)
			{
				if((numbers[j]==numbers[i])||(numbers[i]>=MAX_NUMBER))//如果出现题号一样，就重新出题，然后再一次寻找是否有重复题号
				{
					numbers[i]=rand()%(MAX_NUMBER+1);
					j=0;
					continue;
				}
				j++;
			}
		}
	}
/**************************冒泡排序*************************************/
/*	for(i=0;i<ChuTiShu-1;i++)
	{
		int t,j;
		for(j=0;j<ChuTiShu-i-1;j++)
		{
			if(numbers[j]>numbers[j+1])
			{
				t=numbers[j];
				numbers[j]=numbers[j+1];
				numbers[j+1]=t;
			}
		}
	}*/
/***********************输出生成的数字**********************************/
/*	for(i=0;i<ChuTiShu;i++)
	{
		printf("%-4d ",numbers[i]);
		if((i+1)%10==0&&i!=0)
			printf("\n");
	}
	printf("\n");*/
}

void SuiJiChuTiAndAnswer(int *numbers,struct Word *word)//随机出题并由玩家回答
{
	int i,score,ZuoCuoShu,YiZuoTiShu,a;//定义分数，做题数，已做题数
	double ZhengQueLv;                 //双精度 正确率

	ZuoCuoShu=0;                       //初始化做题数
	YiZuoTiShu=0;                      //初始化已做题目
	score=0;                           //初始化分数
	ZhengQueLv=0;                      //初始化正确率

	srand((unsigned int)time(NULL));   //随机数种子

	for(i=0;i<ChuTiShu;i++)
	{
		printf("question%d.\n",i+1);
		printf("%s\n",word[numbers[i]].YuanXing);
		PlayerEnter(&word[numbers[i]],&score,&ZuoCuoShu,&YiZuoTiShu);
		//printf("score=%d,ZuoCuoShu=%d,YiZuoTiShu=%d",score,ZuoCuoShu,YiZuoTiShu);
		ZhengQueLv=((double)score/(double)YiZuoTiShu)*100;//求正确率
		printf("\nhad finished %d  rigth: %d  false %d  right rate: %.2lf%%\n",YiZuoTiShu,score,ZuoCuoShu,ZhengQueLv);//显示已做几题，正确几题，错误几题，正确率
		/*printf("\nPlease Enter to continue ");
		getchar();//按下回车继续
		system("cls");//清空屏幕*/
        getchar();
        system("clear");
	}
	ChengJiLuRu(ZhengQueLv);//将正确率录入

/************************根据分数来判定接下来显示什么话******************************/
	if(score!=90)//如果没有做全对，开始嘲讽
	{
		a=rand()%3;
		if(a==0)
			printf("You can't be admitted anyone university\n");
		else if(a==1)
			printf("I think you can't got enough score to any university\n");
		else if(a==2)
			printf("What's wrong with you?uh? That question is so easy!\n");
	}
	else
		printf("Don't mistake at exam!!!\n");
	sleep(5);//给玩家五秒反思时间，反思一下怎么会错这么多
	//system("cls");//清空屏幕
}

void PlayerEnter(struct Word *word,int *score,int *ZuoCuoShu,int *YiZuoTiShu)//玩家输入答案，正确返回1，错误返回0
{

	struct PlayerAnswer pa;

/********************************提示玩家输入过去式***********************************/
	printf("Enter did:_________\b\b\b\b\b\b\b\b\b");//让玩家输入动词的过去式
	s_gets(pa.GuoQuShi,LONG_WORD);
	(*YiZuoTiShu)++;
	//printf(" %lu %lu",strlen(word->GuoQuShi),strlen(pa.GuoQuShi)-1);



/***将玩家的输入与答案进行对比，如果正确提示正确，如果错误，提示错误并告知正确答案****/
	if((strncmp(word->GuoQuShi,pa.GuoQuShi,strlen(word->GuoQuShi))==0)\
	&&(strlen(word->GuoQuShi)==strlen(pa.GuoQuShi)))//对指定长度(答案长度)范围内字符串的对比，玩家输入字符串和答案字符串长度的对比
	{
		printf("right\n");
		(*score)++;
	}
	else 
	{
		printf("false    rigth answer:%s\n",word->GuoQuShi);
		(*ZuoCuoShu)++;
	}




/*****************************提示玩家输入过去分词************************************/
	printf("done:_________\b\b\b\b\b\b\b\b\b");
	s_gets(pa.GuoQuFenCi,LONG_WORD);
	(*YiZuoTiShu)++;//已做题目总数加一




/***将玩家的输入与答案进行对比，如果正确提示正确，如果错误，提示错误并告知正确答案****/
//对指定长度(答案长度)范围内字符串的对比，玩家输入字符串和答案字符串长度的对比。或者如果题目答案为'~'，则寻找玩家的答案中
//是否有"~!@#$%^&*()_+"或是不是输入了空格或回车。
	if(((strncmp(word->GuoQuFenCi,pa.GuoQuFenCi,strlen(word->GuoQuFenCi))==0)\
	&&(strlen(word->GuoQuFenCi)==strlen(pa.GuoQuFenCi)))||\
	((strpbrk(pa.GuoQuFenCi,"~!@#$%^&*()_+")||strcmp(pa.GuoQuFenCi,"\0")==0||\
	strcmp(pa.GuoQuFenCi," ")==0)&&(strcmp(word->GuoQuFenCi,"~")==0)))
	{
		printf("right\n");
		(*score)++;
	}
	else 
	{
		printf("false    rigth answer:%s\n",word->GuoQuFenCi);
		(*ZuoCuoShu)++;
	}




/*****************************提示玩家输入现在分词************************************/
	printf("doing:_________\b\b\b\b\b\b\b\b\b");
	s_gets(pa.XianZaiFenCi,LONG_WORD);
	(*YiZuoTiShu)++;//已做题目总数加一



/***将玩家的输入与答案进行对比，如果正确提示正确，如果错误，提示错误并告知正确答案****/
//对指定长度(答案长度)范围内字符串的对比，玩家输入字符串和答案字符串长度的对比。或者如果题目答案为'~'，则寻找玩家的答案中
//是否有"~!@#$%^&*()_+"或是不是输入了空格或回车。
	if(((strncmp(word->XianZaiFenCi,pa.XianZaiFenCi,strlen(word->XianZaiFenCi))==0)\
	&&(strlen(word->XianZaiFenCi)==strlen(pa.XianZaiFenCi)))\
	||((strpbrk(pa.XianZaiFenCi,"!@#$%^&*()")||strcmp(pa.XianZaiFenCi,"\0")==0\
	||strcmp(pa.XianZaiFenCi," ")==0)&&(strcmp(word->XianZaiFenCi,"~")==0)))
	{
		printf("right\n");
		(*score)++;
	}
	else
	{
		printf("false   rigth answer:%s\n",word->XianZaiFenCi);
		(*ZuoCuoShu)++;//已做题目总数加一
	}
}

void ChengJiLuRu(double score)//成绩录入
{
	FILE *fp;
	char *NowTime;
	time_t SystemTime;

	time(&SystemTime);//从系统获取时间
	NowTime=ctime(&SystemTime);//将time_t类型的时间转化成char类型
	fp=fopen("/Users/wuyuhang/Desktop/C_Project/Recite_EnglishTense/ReciteWordMode/score.txt","r+");
	setbuf(fp,NULL);
	fseek(fp,0L,SEEK_END);
	if(fp)
	{
		if(fprintf(fp,"%s  ",NowTime)&&fprintf(fp,"%.2lf%%\n",score))
			printf("score entry\n");
		else 
			printf("score not entry");
		sleep(2);
		//system("cls");
	}
    fclose(fp);
}

char *s_gets(char *str,int n)//输入字符串函数
{
	char *ret_val;
	char *find;
	ret_val=fgets(str,n,stdin);
	if(ret_val)
	{
		find=strchr(ret_val,'\n');
		if(find)
			*find='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return ret_val;

}

void ReciteWord(void)//默写单词模块
{
    FILE *fp;//定义一个指向文件的指针
    struct Word word[MAX_NUMBER];//定义一个结构体为word，记录单词的原型，过去式，过去分词，现在分词
    int numbers[ChuTiShu];//定义一个数组用来记录要出的题的编号
    char answer[3];       //定义一个字符串数组，记录玩家回答是否再来一遍的回答                      

    fp=fopen("/Users/wuyuhang/Desktop/C_Project/Recite_EnglishTense/ReciteWordMode/source/word.txt","r");//打开相应的写有单词的文件
    if(fp==NULL)        //如果打开失败，直接退出
    {
        printf("The file can't open");
        exit(0);
    }
    InputWord(word,MAX_NUMBER,fp);//录入单词
/*******************************依次显示输入程序的单词*********************************/
/*  for(i=0;i<149;i++)
        printf("%s %s %s %s\n",word[i].YuanXing,word[i].GuoQuShi,word[i].GuoQuFenCi,word[i].XianZaiFenCi);*/
	//system("cls");
	while(1)
	{
		SuiJiShuZi(numbers);           //随机数字
		SuiJiChuTiAndAnswer(numbers,word);      //根据记录在数组number中的数字出题目，并让玩家回答
		printf("once again?(yes or no ?):___\b\b\b");//询问玩家是否愿意再做一遍
		s_gets(answer,3);              //接受玩家答案
		if(strcmp(answer,"no")==0)     //如果玩家回答no，结束循坏
		{
            fclose(fp);
            break;
        }
		else
			printf("New question hope you right!\n");
        system("clear");
		
	}
}
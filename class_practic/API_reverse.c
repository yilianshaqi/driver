/*************************************************************************
    > File Name: API_reverse.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月04日 星期日 14时34分22秒
 ************************************************************************/
//函数的功能：对字符串中以单词反转
//第一个参数：要反转的字符串
//函数返回值：操作成功返回0；操作失败返回-1
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
int reverse(char *string)
{
#define BUF_SIZE 1024
#define MAX 256
	if(NULL == string)
	{
		return -1;
	}
	char *temp = NULL;
	int total_length = strlen(string);
	char delim[]=" ";
	char *temp_buf=NULL;
	char t_buf[MAX]="";
	char *buf=malloc(BUF_SIZE);
	if(NULL == buf)
	{
		return -1;
	}
//	int set = (int)' ';
//	memset(buf,set,BUF_SIZE);
	bzero(buf,BUF_SIZE);
	temp_buf = buf+total_length;
	temp = strtok(string,delim);
	while(temp != NULL)
	{
		/*
		if(temp==string)
		{
			temp_buf=temp_buf - strlen(temp);
			strcpy(temp_buf,temp);
			
		}
		else{
			temp_buf=temp_buf - strlen(temp)-1;
			strncpy(temp_buf,temp,strlen(temp));
		}
		temp = strtok(NULL,delim);*/
		bzero(t_buf,MAX);
		strcpy(t_buf,temp);
		if(temp != string)
		{	
			strcat(t_buf," ");
		}
		temp_buf=temp_buf - strlen(t_buf);
		strncpy(temp_buf,t_buf,strlen(t_buf));
		temp = strtok(NULL,delim);

	}
	strcpy(string,buf);
	free(buf);
#undef MAX 
#undef BUF_SIZE
	return 0;
}

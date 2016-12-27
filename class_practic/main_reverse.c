/*************************************************************************
    > File Name: main_reverse.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月04日 星期日 14时55分26秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define BUF_SIZE   256

extern int reverse(char *);
int main(int argc ,char *argv[])
{
//	char string[]="this is a test";
	char string[BUF_SIZE]="";
	for(int i=1;i<argc;i++)
	{
		strcat(string,argv[i]);
		strcat(string," ");
	}
	string[strlen(string)-1]='\0';
	printf("%s\n",string);  
//	printf("strcat ok!\n"); 
	if(reverse(string))
	{
		printf("reverse error\n");
		return -1;
	}
	printf("%s\n",string);
	return 0;
}


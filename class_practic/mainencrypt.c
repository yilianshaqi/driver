/*************************************************************************
    > File Name: mainencrypt.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月04日 星期日 14时00分00秒
 ************************************************************************/

#include<stdio.h>
extern int encrypt(char *);
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("input error\n");
		return  -1;
	}
	if(encrypt(argv[1])){
		printf("encrypt error\n");
		return -1;
	}
	return 0;
}

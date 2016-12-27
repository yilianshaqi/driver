/*************************************************************************
    > File Name: maincopy.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月04日 星期日 11时58分34秒
 ************************************************************************/

#include<stdio.h>
extern int copy(char *,char *);
int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("input error\n");
		return -1;
	}
	int ret = copy(argv[1],argv[2]);
	if(ret <0)
	{
		printf("copy error\n");
		return -1;
	}
	return 0;
}

/*************************************************************************
    > File Name: API_encrypt.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月04日 星期日 12时34分00秒
 ************************************************************************/

//函数的功能：对文件加密
//第一个参数：要加密的文件路径名
//返回值    ：返回-1表示加密失败，返回0表示加密成功
#include <stdio.h>
int encrypt(const char *pathname)
{
	if(NULL == pathname)
	{
		return -1;
	}
	FILE *sfd = fopen(pathname,"r");
	if(NULL==sfd)
	{
		return -1;
	}
	FILE *dfd = fopen("temp","w");
	if(NULL == dfd)
	{
		return -1;
	}
	int buf,ret;
	while(!feof(sfd))
	{
		buf = fgetc(sfd);
		buf=~buf;
		ret = fputc(buf,dfd);
		if(ret < 0)
		{
			return -1;
		}
	}
	fclose(sfd);
	fclose(dfd);
	if(rename("temp",pathname))
	{
		return -1;
	}

	return 0;
}


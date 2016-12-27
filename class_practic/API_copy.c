/*************************************************************************
    > File Name: API_copy.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月04日 星期日 11时31分23秒
 ************************************************************************/

//函数的功能：文件复制
//第一个参数：要复制的文件路径名
//第二个参数：复制后的文件路径名
//返回值    ：返回-1表示复制失败，返回0表示复制成功
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include <stdio.h>
#define BUF_SIZE  256
int copy(const char *src,const char *dest)
{
	if(NULL==src || NULL==dest)
	{
		return -1;
	}
	int sfd = open(src,O_RDONLY);
	if(sfd < 0)
	{
		return -1;
	}
	int dfd = open(dest,O_WRONLY | O_CREAT,0666);
	if(dfd < 0)
	{
		return -1;
	}
	char buf[BUF_SIZE]="";
	int rret = 0;
	int wret = 0;
	while((rret = read(sfd,buf,BUF_SIZE))> 0)
	{
		printf("rret = %d,read : %s\n",rret,buf);
		wret = write(dfd,buf,rret);
		if(wret < 0)
		{
			return -1;
		}
		bzero(buf,BUF_SIZE);
	}
	if(rret ==-1 )
	{
		return -1;
		close(sfd);
		close(dfd);
		remove(dest);
	}
#undef BUF_SZIE
	close(sfd);
	close(dfd);
	return 0;
}

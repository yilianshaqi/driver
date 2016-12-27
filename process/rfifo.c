/*************************************************************************
    > File Name: rfifo.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月01日 星期四 20时36分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE  30
int main()
{
	int fd = open("/home/hy/practice/process/fifo",O_RDWR);
	if(fd<0)
	{
		perror("open fifo error:\n");
		return -1;
	}
	char buf[BUF_SIZE]="";
	read(fd,buf,BUF_SIZE);
	printf("read:%s\n",buf);
	return 0;
}

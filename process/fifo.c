/*************************************************************************
    > File Name: fifo.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月01日 星期四 20时25分56秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	if(mkfifo("/home/hy/practice/process/fifo",0664))
	{
		perror("mkfifo error:\n");
		return -1;
	}
	int fd =open("/home/hy/practice/process/fifo",O_RDWR);
	if(fd<0)
	{
		perror("open error\n");
		return -1;
	}
	int ret = write(fd,"hello",10);
	printf("ret =%d\n",ret);
	sleep(10);
	close(fd);
	return 0;
}

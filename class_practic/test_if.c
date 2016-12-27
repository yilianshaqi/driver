/*************************************************************************
    > File Name: test_if.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月19日 星期一 15时17分57秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
 #include <unistd.h>

int main()
{
	int fd  = open("testfile",O_WRONLY | O_CREAT,0666);
	if(fd <= 0)
	{
		printf("open file error\n");
	}
	int ret = lseek(fd ,100,SEEK_SET);
	printf("ret = %d\n",ret );
	write(fd,"test",4);
}

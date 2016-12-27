/*************************************************************************
  > File Name: fasync.c
  > Author: huang yang
  > Mail: huangyangwork@sina.com 
  > Created Time: 2016年11月22日 星期二 19时53分54秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



#define BUF_SIZE 20
char buf[BUF_SIZE]="";
int fd;
void handler(int signo)
{
	printf("before read\n");
	int ret = read(fd,buf,BUF_SIZE);
	printf("read : %s\n",buf);
}


int main()
{
	 fd=open("/dev/test_dev",O_RDWR);
	if(fd<0)
	{
		perror("open file");
		return -1;
	}
	printf("open file ok\n");
	signal(SIGIO,handler);
	fcntl(fd,F_SETOWN,getpid());
	fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | FASYNC);
	printf("before while\n");
	while(1);
	return 0;
}	


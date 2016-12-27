/*************************************************************************
    > File Name: test_vfork.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月20日 星期二 08时57分15秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
       #include <unistd.h>
#include <stdlib.h>
/*
int main()
{
	int count = 9;
	int pid = vfork();
	if(pid < 0)
	{
		return 0;
	}
	 if(pid == 0)
	{
		count++;
		printf("children count = %d,%p\n",count,&count);
		sleep(3);
		exit(0);
	}
	else
	{
		count++;
		printf("father count:%d,%p\n",count,&count);
		printf("father end\n");
	}
}
*/
int main()
{
	int i = 10;
	int pid = fork();
	if(pid < 0)
	{
		return 0;
	}
	if(pid ==0)
	{
		printf("children i:%p\n",&i);
		i++;
		printf("children i = %d,%p\n",i,&i);
	}
	if(pid>0)
	{
		printf("father i:%p\n",&i);
		i++;
		printf("father i = %d,%p\n",i,&i);
		
	}
}

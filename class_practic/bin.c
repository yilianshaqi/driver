/*************************************************************************
    > File Name: bin.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月10日 星期六 09时03分00秒
 ************************************************************************/

#include<stdio.h>
int exchange(int num);
int main()
{
	exchange(-3);
}

int exchange(int num)
{
	char buf[32]="";
	for(int i = 0;i<32;i++)
	{
		sprintf(buf+i,"%d",(num>>i)&1);
	}
	for(int i=31;i>=0;i--)
	{
		printf("%c",*(buf+i));
	}
	return 0;
}

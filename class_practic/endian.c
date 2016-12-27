/*************************************************************************
    > File Name: endian.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 17时08分24秒
 ************************************************************************/

#include<stdio.h>
int b=0x12345678;
int main()
{
	int a=0x12345678;
	char *pa=NULL;
	pa=(char *)&a;
	printf("endian=%x\n",*pa);

	char *p=(char *)&b;
	printf("end=%x\n",*p);


}

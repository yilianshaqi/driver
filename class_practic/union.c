/*************************************************************************
    > File Name: union.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 11时11分01秒
 ************************************************************************/

#include<stdio.h>
typedef union 
{
	char a;
	int b;
}Data;
int main()
{
	Data test;
	test.b=0x12345678;
	printf("char %0x,int %x\n",test.a,test.b);
}

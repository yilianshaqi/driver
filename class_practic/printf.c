/*************************************************************************
    > File Name: printf.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月06日 星期二 09时24分22秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int a =2;
	int b = 0;
	b = a++ + a;
	int i =9;
	b = i++ + ++i;
	printf("b=%d\n",b);
	printf("a=%d\t,a=%d\n",a,a++);
	return 0;
}

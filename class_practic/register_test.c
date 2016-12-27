/*************************************************************************
    > File Name: register_test.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月19日 星期一 10时49分21秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int array = 9;
	register int * p=&array;
	printf("*p =%d\n",*p);

}

/*************************************************************************
    > File Name: main.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 19时15分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
//extern int insert(int *,int ,int ); 
//extern int select(int *,int ,int );
//extern int calculator(int (*pfunc)(int ,int ,float *),int ,int ,float *);
//extern int add(int ,int ,float *);
//extern int sub(int ,int ,float *);
//extern int mul(int ,int ,float *);
//extern int divi(int ,int ,float *);
#include"API.h"
#define MAX 5
int main(int argc ,char *argv[])
{
	if(argc != 4)
	{
		printf ("input error\n");
		return -1;
	}
	int ret ;
	float result = 0;
	 int (*pfunc)(int ,int ,float *);
	switch(*argv[2])
	{
		case '+':
			pfunc=add;
			break;
		case '-':
			pfunc = sub;
			break;
		case '*':
			pfunc =mul;
			break;
		case '/':
			pfunc = divi;
			break;
		default :
			return -1;
	}
	ret = calculator(pfunc,atoi(argv[1]),atoi(argv[3]),&result);
	if(ret == -1)
	{
		printf("Wrong operation\n");
		return -1;
	}
	printf("result = %f\n",result);
	return 0;
#undef MAX
}

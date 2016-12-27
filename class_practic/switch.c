/*************************************************************************
    > File Name: switch.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 13时38分39秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
int main(int agrc,char *agrv[])
{
	if(agrc!=4)
	{
		printf("input error\n");
		return -1;
	}
	 float ret =0;
	switch(*agrv[2])
	{
		case  '+':
			ret = atoi(agrv[1]) + atoi(agrv[3]);
			break;
		case '-':
			ret = atoi(agrv[1]) - atoi(agrv[3]);
			break;
		case '*':
			ret = atoi(agrv[1]) * atoi(agrv[3]);
			break;
		case '/':
			if(atoi(agrv[3])==0)
			{
				printf("input error\n");
				return -1;
			}
			ret = atoi(agrv[1]) / atoi(agrv[3]);
			break;
		default :
			printf("input error\n");
			return -1;


	}
	printf("ret = %f\n",ret);
	return 0;
}

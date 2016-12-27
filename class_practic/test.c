/*************************************************************************
    > File Name: test.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月06日 星期二 15时05分35秒
 ************************************************************************/

#include<stdio.h>
void main()
{
	int i,sum = 0;
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0:
				case 1: sum++;
			case 3: sum++;
			case 4: sum--;
			
			break;
		}
	}
	printf("%d\n",sum);
}


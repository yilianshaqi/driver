/*************************************************************************
    > File Name: inset.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 10时12分40秒
 ************************************************************************/

#include<stdio.h>
#define MAX 5
int insert (int *,int );
int main()
{
	int a[MAX]={23,78,56,12,90};
	insert(a,MAX);
	for(int i=0 ;i<MAX;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
int insert(int *a,int max)
{
	if(NULL==a)
	{
		perror("malloc :\n");
		return -1;
	}
	int temp=0;
	int i,j;
	for(i=1;i<max;i++)
	{
		temp=a[i];
		for( j=i-1;j>-1;j--)
		{
			/*
			if(temp < a[j])
			{
				a[j+1]=a[j];
				continue;
			}
			break; */
			if(temp>a[j])
			{
				break;
			}
				a[j+1]=a[j];

		}
		a[j+1]=temp;
	}
	return 0;
}

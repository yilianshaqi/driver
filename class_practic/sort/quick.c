/*************************************************************************
    > File Name: quick.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月07日 星期三 12时21分27秒
 ************************************************************************/

#include<stdio.h>
int quick(int *array,int head,int tail)
{
	if(NULL==array || head>=tail)
	{
		return -1;
	}
	int i=head,j=tail;
	int temp = array[head];
	while(i<j)
	{
		while(i<j)
		{
			if(array[j]<temp)
			{
				array[i]=array[j];
				i++;
				break;
			}
			j--;
		}
		while(i<j)
		{
			if(array[i]>temp)
			{
				array[j]=array[i];
				j--;
				break;
			}
			i++;
		}
	}
	array[i]=temp;
	quick(array,head,i-1);
	quick(array,i+1,tail);
	return 0;
}
int main()
{
	int buf[]={26,90,67,34,67};
	quick(buf,0,4);
	for(int i =0;i<5;i++)
	{
		printf("%d\t",buf[i]);
	}
	puts("");
	return 0;
}

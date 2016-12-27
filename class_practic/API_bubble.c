/*************************************************************************
    > File Name: API_bubble.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月02日 星期五 19时58分02秒
 ************************************************************************/

//函数的功能：对int型数组进行排序
//第一个参数：int型的数组名
//第二个参数：数组的长度
//第三个参数：数组排序的方式，mode = 0 为升序，mode ！= 0 为降序
//返回值    ：返回-1表示排序失败，返回0表示排序成功
int bubble(int *array,int max,int mode)
{
	if(!array)
	{
		return -1;
	}
	int i,j,temp;
	if(max>1 && mode ==0)
	{
		for(i=0;i<max-1;i++)
		{
			for(j=i;j+1<max;j++)
			{
				if(array[j]>array[j+1])
				{
					temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
			}
		}
	}
	else if(max>1 && mode !=0)
	{
		for(i=0;i<max-1;i++)
		{
			for(j=i;j+1<max;j++)
			{
				if(array[j]<array[j+1])
				{
					temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
			}
		}
	}
	return 0;
}

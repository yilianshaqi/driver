/*************************************************************************
    > File Name: function.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月05日 星期一 18时53分52秒
 ************************************************************************/
#include"head.h"
Data *creat(int_t *value)
{
	if(value==NULL)
	{
		return NULL;
	}
	Data *ptemp = malloc(sizeof(Data));
	if(NULL == ptemp)
	{
		return NULL;
	}
	bzero(ptemp,sizeof(Data));
	ptemp->data=*value;
	return ptemp;
}
//头插
int insert(Data *ptemp,Data *phead)
{
	if(NULL == ptemp || NULL == phead)
	{
		return -1;
	}
	ptemp->pnext = phead->pnext;
	phead->pnext = ptemp;
	return 0;
}
//删除制定位置的数据
int delet(int num,Data *phead)
{
	if(NULL == phead)
	{
		return -1;
	}
	int i=1;
	Data *ptemp = phead;
	for(;i<num;i++)
	{
		ptemp = ptemp->pnext;
		if(NULL == ptemp)
		{
			return -1;
		}
	}
	Data *pdel=NULL;
	pdel = ptemp->pnext;
	if(NULL == pdel)
	{
		return -1;
	}
	ptemp->pnext = pdel->pnext;
	free(pdel);
	pdel=NULL;
	return 0;
}

int update(int num,int_t *value,Data *phead)
{
	if(NULL == phead)
	{
		return -1;
	}
	int i=0;
	Data *ptemp = phead;
	for(;i<num;i++)
	{
		ptemp = ptemp->pnext;
		if(NULL == ptemp )
		{
			return -1;
		}
	}
	ptemp->data = *value;
	return 0;
}
Data *find(int_t *value,Data *phead)
{
	if(NULL == phead)
	{
		return NULL;
	}
	Data *ptemp = phead->pnext;
	while(ptemp)
	{
		if(ptemp->data == *value)
		{
			break;
		}
		ptemp = ptemp->pnext;
	}
	return ptemp;
}
int show(Data *phead)
{
	if(NULL== phead)
	{
		return -1;
	}
	Data *ptemp=phead->pnext;
	while(ptemp)
	{
		printf("%d\t",ptemp->data);
		ptemp = ptemp->pnext;
	}
	puts("");
	return 0;
}

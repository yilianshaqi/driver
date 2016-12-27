/*************************************************************************
    > File Name: head.h
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月05日 星期一 18时50分08秒
 ************************************************************************/
#ifndef  __LINK_HEAD__
#define  __LINK_HEAD__
#include<stdio.h>
 #include <stdlib.h>
#include <strings.h>
typedef int int_t;
typedef struct DATA
{
	int_t data;
	struct DATA *pnext;
}Data;

Data *creat(int_t *value);

int insert(Data *ptemp,Data *phead);
int delet(int num,Data *phead);
int update(int num,int_t *value,Data *phead);
Data *find(int_t *value,Data *phead);
int show(Data *phead);
enum {
	INSERT=1,
	DELETE,
	UPDATE,
	FIND ,
	SHOW,
	EXIT,
};
#endif 

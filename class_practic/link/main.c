/*************************************************************************
    > File Name: main.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月05日 星期一 19时21分09秒
 ************************************************************************/
#include"head.h"
int main()
{
	Data phead;
	bzero(&phead,sizeof(Data));
	int operation ;
	int_t value;
	Data *ptemp;
	int position;
	while(1)
	{
		printf("please select operation\n");
		printf("insert Linked list data----------------1\n");
		printf("delete Linked list data----------------2\n");
		printf("update Linked list data----------------3\n");
		printf("find   Linked list data----------------4\n");
		printf("show   Linked list data----------------5\n");
		printf("Exit program---------------------------6\n");
		scanf("%d",&operation);
		switch(operation)
		{
			case 1:
				printf("please input a value\n");
				scanf("%d",&value);
				if(insert(creat(&value),&phead))
				{
					printf("operation failed\n");
				}
				break;
			case DELETE:
				printf("Enter the location to be deleted\n");
				scanf("%d",&position);
				if(delet(position,&phead))
				{
					printf("operation failed\n");
				}
				break;
			case UPDATE:
				printf("Please enter the location and values to be modified\n");
				scanf("%d%d",&position,&value);
				if(update(position,&value,&phead))
				{
					printf("operation failed\n");
				}
				break;
			case FIND:
				printf("Enter the value you want to find\n");
				scanf("%d",&value);
				ptemp = find(&value,&phead);
				if(NULL == ptemp)
				{
					printf("not find\n");
				}
				printf("Find this value:%d\n",ptemp->data);
				break;
			case SHOW:
				if(show(&phead))
				{
					printf("operation failed\n");
				}
				break;
			case EXIT :
				goto exit;
				break;
			default :
				break;
		}

	}
exit:
	return 0;
	
}

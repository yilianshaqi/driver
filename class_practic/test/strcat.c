/*************************************************************************
    > File Name: strcat.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月07日 星期三 09时04分08秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int cat(char *,char *);
int main()
{
	char buf1[15]="hello";
	char buf2[]="world";
	if(cat(buf1,buf2))
	{
		printf("cat error\n");
		return -1;

	}
	printf("cat:%s\n",buf1);
	return 0;
}
int cat(char *dest,char *src)
{
	if(NULL == dest || NULL == src)
	{
		return -1;
	}
	int length= strlen(dest);
	for(int i=0;i<=strlen(src);i++)
	{
		dest[length+i]=src[i];
	}
	return 0;
}

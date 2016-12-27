/*************************************************************************
    > File Name: test_second.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月23日 星期五 14时37分04秒
 ************************************************************************/

#include<stdio.h>
nclude <stdio.h>

typedef union Tag_Node

{


	char a;

	char b;

	char c;

	char d;

	int i;	

}Node;

int main(int argc, char *argv[])

{


	Node node;

	node.a = 1;

	node.b = 2;

	node.c = 3;

	node.d = 4;

	printf("%x\n", node.i);	



	return 0;

}

